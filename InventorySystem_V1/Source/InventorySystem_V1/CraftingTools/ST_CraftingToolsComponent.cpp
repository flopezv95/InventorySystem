// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_CraftingToolsComponent.h"

// Sets default values for this component's properties
UST_CraftingToolsComponent::UST_CraftingToolsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UST_CraftingToolsComponent::UpdateToolsCraft()
{
	for (int i = 0; i < toolsForCraft.Num(); i++)
	{
		for (int j = 0; j < toolsForCraft[i].toolsInThisType.Num(); j++)
		{
			for (int k = 0; k < toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool.Num(); k++)
			{
				for (int l = 0; l < rawMaterialInTheInventory.Num(); l++)
				{
					if (rawMaterialInTheInventory[l].rawMaterial == toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool[k].rawMaterial)
					{
						if (rawMaterialInTheInventory[l].numOfTheRawMaterialInTheInventory <= toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool[k].numOfTheRawMaterialNecessaryForTheTool)
						{
							toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool[k].IsAlreadyEnougthMaterial = true;
						}

					}
				}
			}
		}
	}
}

void UST_CraftingToolsComponent::UpdateNumOfRawMaterials(UClass * rawMaterial)
{
	if (rawMaterial)
	{
		if (rawMaterialInTheInventory.Num() == 0)
		{
			FRawMaterialsInTheInventory  structToSave;
			structToSave.rawMaterial = rawMaterial;
			structToSave.numOfTheRawMaterialInTheInventory = 0;
			rawMaterialInTheInventory.Add(structToSave);
		}
		for (int i = 0; i < rawMaterialInTheInventory.Num(); i++)
		{
			if (rawMaterialInTheInventory[i].rawMaterial == rawMaterial)
			{
				rawMaterialInTheInventory[i].numOfTheRawMaterialInTheInventory++;
			}
			else
			{
				FRawMaterialsInTheInventory  structToSave;
				structToSave.rawMaterial = rawMaterial;
				structToSave.numOfTheRawMaterialInTheInventory = 0;
				rawMaterialInTheInventory.Add(structToSave);
			}
		}
		UpdateToolsCraft();
	}
}

int UST_CraftingToolsComponent::GetNumOfRawMaterial(UClass * rawMaterial)
{
	if (rawMaterial)
	{
		for (int i = 0; i < rawMaterialInTheInventory.Num(); i++)
		{
			if (rawMaterialInTheInventory[i].rawMaterial == rawMaterial)
			{
				return rawMaterialInTheInventory[i].numOfTheRawMaterialInTheInventory;
			}
		}
	}
	return 0;
}

void UST_CraftingToolsComponent::CraftTool(int toolTypeIndex, int toolIndex)
{
	if (toolsForCraft[toolTypeIndex].toolsInThisType[toolIndex].IsReadyToCraft)
	{

	}
	else
	{
		//MESSAGE THAT SAY THAT THERE ISN'T ENOUGTH MATERIAL TO CRAFT TME TOOL
	}
}

void UST_CraftingToolsComponent::IsToolReadyToCraft()
{
	int countOfRawMaterialsReady;
	for (int i = 0; i < toolsForCraft.Num(); i++)
	{
		for (int j = 0; j < toolsForCraft[i].toolsInThisType.Num(); j++)
		{
			for (int k = 0; k < toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool.Num(); k++)
			{
				if (toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool[k].IsAlreadyEnougthMaterial)
				{
					countOfRawMaterialsReady++;
				}
			}
			if (countOfRawMaterialsReady >= toolsForCraft[i].toolsInThisType[j].itemsForCraftTheTool.Num())
			{
				toolsForCraft[i].toolsInThisType[j].IsReadyToCraft = true;
			}
			countOfRawMaterialsReady = 0;
		}
	}
}

TArray<FTools> UST_CraftingToolsComponent::GetToolsByType(EToolType toolType)
{
	TArray<FTools> arrayRet;
	for (int i = 0; i < toolsForCraft.Num(); i++)
	{
		if (toolsForCraft[i].toolType == toolType)
		{
			return toolsForCraft[i].toolsInThisType;
		}
	}
	return arrayRet;
}

void UST_CraftingToolsComponent::ShowTheCraftToolsWindow()
{
	ShowCraftTools();
}

void UST_CraftingToolsComponent::UpdateRawMaterial(int toolIndex)
{
	UpdateTheRawMaterials(toolIndex);
}

// Called when the game starts
void UST_CraftingToolsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UST_CraftingToolsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

