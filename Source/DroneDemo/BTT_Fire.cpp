// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Fire.h"
#include "Turret.h"

UBTT_Fire::UBTT_Fire(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Fire";
}

EBTNodeResult::Type UBTT_Fire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AAIController* Controller = Cast<AAIController>(OwnerComp.GetOwner()))
	{
		if (ATurret* Turret = Cast<ATurret>(Controller->GetPawn()))
		{
			Turret->Fire();
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}