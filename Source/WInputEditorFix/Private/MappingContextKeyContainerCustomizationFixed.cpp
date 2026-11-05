// Copyright Wiz Productions. All Rights Reserved.


#include "MappingContextKeyContainerCustomizationFixed.h"
#include "ActionMappingsNodeBuilderExFixed.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "InputMappingContext.h"


TSharedRef<IPropertyTypeCustomization> FMappingContextKeyContainerCustomizationFixed::MakeInstance()
{
	return MakeShareable(new FMappingContextKeyContainerCustomizationFixed());
}

void FMappingContextKeyContainerCustomizationFixed::CustomizeHeader(
	TSharedRef<IPropertyHandle> PropertyHandle,
	FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& CustomizationUtils
)
{
	MappingsArrayHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FInputMappingContextMappingData, Mappings));
	
	HeaderRow.NameContent()
	[
		PropertyHandle->CreatePropertyNameWidget()
	];
	
	HeaderRow.ValueContent()
	[
		PropertyHandle->CreatePropertyValueWidget()
	];
}

void FMappingContextKeyContainerCustomizationFixed::CustomizeChildren(
	TSharedRef<IPropertyHandle> PropertyHandle,
	IDetailChildrenBuilder& ChildBuilder,
	IPropertyTypeCustomizationUtils& CustomizationUtils
)
{
	if (!ensure(MappingsArrayHandle.IsValid()))
	{
		return;
	}
	
	MappingsArrayHandle->MarkHiddenByCustomization();

	const TSharedRef<FActionMappingsNodeBuilderExFixed> ActionMappingsBuilder = MakeShareable(new FActionMappingsNodeBuilderExFixed(MappingsArrayHandle));
	ChildBuilder.AddCustomBuilder(ActionMappingsBuilder);
}
