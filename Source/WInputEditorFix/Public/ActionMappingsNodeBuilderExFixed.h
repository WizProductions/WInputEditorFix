// Copyright Epic Games, Inc. All Rights Reserved.
// Edited by Wiz Productions
// Unreal Engine 5.7.3 - On 5.8 the builder has been changed.

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomNodeBuilder.h"
#include "InputEditor/Private/ActionMappingDetails.h"

//#############################################################################
//##-------------------------------- STRUCTURE ------------------------------##
//#############################################################################

struct FActionMappingsNodeBuilderExFixed : public IDetailCustomNodeBuilder, public TSharedFromThis<FActionMappingsNodeBuilderExFixed>
{
	FActionMappingsNodeBuilderExFixed(const TSharedPtr<IPropertyHandle>& InPropertyHandle);
	virtual ~FActionMappingsNodeBuilderExFixed() override;
	
//#############################################################################
//##--------------------------------- FIELDS --------------------------------##
//#############################################################################
	
	/** Called to rebuild the children of the detail tree */
	FSimpleDelegate OnRebuildChildren;

	/** Property handle to associated Action Mappings */
	TSharedPtr<IPropertyHandle> ActionMappingsPropertyHandle;

	TArray<ActionMappingDetails::FMappingSet> GroupedMappings;

	TArray<TPair<const UInputAction*, bool>> DelayedGroupExpansionStates;

	/** A map of Input Action's that have been renamed. This map is a map of the New Name to the Old Name. */
	TMap<FName, FName> ActionsBeingRenamed;

//#############################################################################
//##--------------------------------- METHODS -------------------------------##
//#############################################################################

public:
	/** IDetailCustomNodeBuilder interface */
	virtual void SetOnRebuildChildren(FSimpleDelegate InOnRebuildChildren) override { OnRebuildChildren = InOnRebuildChildren; }
	virtual bool RequiresTick() const override { return true; }
	virtual void Tick(float DeltaTime) override;
	virtual void GenerateHeaderRowContent(FDetailWidgetRow& NodeRow) override;
	virtual void GenerateChildContent(IDetailChildrenBuilder& ChildrenBuilder) override;
	virtual bool InitiallyCollapsed() const override { return true; };
	virtual FName GetName() const override { return FName(TEXT("ActionMappings")); }

	int32 GetNumGroupedMappings() const;
	int32 GetNumMappings() const;

	enum class EReorderMode : uint8
	{
		Group,
		Single
	};
	void ReorderMappings(int32 OriginalIndex, int32 NewIndex, EReorderMode ReorderMode);
private:
	void AddActionMappingButton_OnClick();
	void ClearActionMappingButton_OnClick();
	void OnActionMappingActionChanged(const FAssetData& AssetData, const ActionMappingDetails::FMappingSet MappingSet);
	void AddActionMappingToGroupButton_OnClick(const ActionMappingDetails::FMappingSet MappingSet);
	void RemoveActionMappingGroupButton_OnClick(const ActionMappingDetails::FMappingSet MappingSet);

	bool GroupsRequireRebuild() const;
	void RebuildGroupedMappings();
	void RebuildChildren()
	{
		OnRebuildChildren.ExecuteIfBound();
	}
	/** Makes sure that groups have their expansion set after any rebuilding */
	void HandleDelayedGroupExpansion();

	/** Returns true if the "Adds Action Mapping" button can be pressed */
	bool CanAddNewActionMapping() const;

	/** The tooltip attribute for the "Adds Action Mapping" button */
	FText GetAddNewActionTooltip() const;

	/**
	 * Called by the asset registry when an asset is renamed. Replaces any references to the old Input Action with
	 * the new one
	 */
	void OnAssetRenamed(const FAssetData& AssetData, const FString& OldName);
};
