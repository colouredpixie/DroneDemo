// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AIController.h"
#include "BTT_Fire.generated.h"

/**
 * 
 */
UCLASS()
class DRONEDEMO_API UBTT_Fire : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	UBTT_Fire(const FObjectInitializer& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
