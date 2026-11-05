// Copyright Epic Games, Inc. All Rights Reserved.

#include "WInputEditorFix.h"
#include "InputMappingContext.h"
#include "MappingContextKeyContainerCustomizationFixed.h"

#define LOCTEXT_NAMESPACE "FWInputEditorFixModule"

void FWInputEditorFixModule::StartupModule()
{
	FModuleManager::LoadModuleChecked<IModuleInterface>("InputEditor");
	FPropertyEditorModule& PM = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FName StructName = FInputMappingContextMappingData::StaticStruct()->GetFName();
	PM.UnregisterCustomPropertyTypeLayout(StructName);
	PM.RegisterCustomPropertyTypeLayout(StructName,
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMappingContextKeyContainerCustomizationFixed::MakeInstance));
	PM.NotifyCustomizationModuleChanged();
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FWInputEditorFixModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWInputEditorFixModule, WInputEditorFix)