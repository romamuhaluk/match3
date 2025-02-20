// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "Match3BlockGrid.h"
#include "Gem.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Match3Block.generated.h"

class AGem;
extern AMatch3Block* ActiveBlock;

/** A block that can be clicked */
UCLASS(minimalapi)
class AMatch3Block : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BlockMesh;

public:
	AMatch3Block();

	/** Are we currently active? */
	bool bIsActive;

	/** Grid that owns us */
	//UPROPERTY()
	//class AMatch3BlockGrid* OwningGrid;

	UPROPERTY(EditAnywhere)
	int columnInGrid;

	UPROPERTY(EditAnywhere)
	int rowInGrid;

	/** Pointer to white material used on the focused block */
	UPROPERTY()
	class UMaterial* BaseMaterial;

	/** Pointer to blue material used on inactive blocks */
	UPROPERTY()
	class UMaterialInstance* BlueMaterial;

	/** Pointer to orange material used on active blocks */
	UPROPERTY()
	class UMaterialInstance* OrangeMaterial;

	/** Handle the block being clicked */
	UFUNCTION()
	void BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	/** Handle the block being touched  */
	UFUNCTION()
	void OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	void HandleClicked();

	void Highlight(bool bOn);

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }

	//FORCEINLINE class USceneComponent* GetGemRoot() const { return GemRoot; }
	/** Returns BlockMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetBlockMesh() const { return BlockMesh; }

};