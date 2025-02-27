// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillGunnerQ.generated.h"

/**
 *
 */
class AProjectileGranade;

UCLASS()
class DIESELPUNK_API USkillGunnerQ : public UPlayerSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileGranade> ProjectileGranadeClass;

	UPROPERTY()
	AProjectileGranade *ProjectileGranade;

	FTimerHandle ZoomTHandle;
public:
	// 생성자
	USkillGunnerQ();

protected:
	virtual void BeginPlay() override;
	//줌인
	void ZoomIn();
	//줌아웃
	void ZoomOut();
	
public:
	virtual void SkillTriggered() override;
	
};
