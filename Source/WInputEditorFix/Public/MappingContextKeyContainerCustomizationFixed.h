// Copyright Wiz Productions. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//#############################################################################
//##-------------------------------- STRUCTURE ------------------------------##
//#############################################################################

struct FMappingContextKeyContainerCustomizationFixed : IPropertyTypeCustomization
{
	
//#############################################################################
//##---------------------------------- FIELDS -------------------------------##
//#############################################################################

private:
	TSharedPtr<IPropertyHandle> MappingsArrayHandle;
	
//#############################################################################
//##--------------------------------- METHODS -------------------------------##
//#############################################################################

public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	
	virtual void CustomizeHeader(
		TSharedRef<IPropertyHandle> PropertyHandle,
		FDetailWidgetRow& HeaderRow,
		IPropertyTypeCustomizationUtils& CustomizationUtils) override;
		
	virtual void CustomizeChildren(
		TSharedRef<IPropertyHandle> PropertyHandle,
		IDetailChildrenBuilder& ChildBuilder,
		IPropertyTypeCustomizationUtils& CustomizationUtils) override;

};
