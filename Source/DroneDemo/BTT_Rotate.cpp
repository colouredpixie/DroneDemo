// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Rotate.h"
#include "AIController.h"
#include "Turret.h"

EBTNodeResult::Type UBTT_Rotate::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AAIController* Controller = Cast<AAIController>(OwnerComp.GetOwner()))
	{
		if (ATurret* Character = Cast<ATurret>(Controller->GetPawn()))
		{
			FRotator CurrentRotation = Character->GetActorRotation();

			FRotator NewRotation = FRotator::ZeroRotator;
			NewRotation.Yaw = CurrentRotation.Yaw + 90.f;

			Character->SetActorRotation(FMath::Lerp(CurrentRotation, NewRotation, 0.005f));
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}