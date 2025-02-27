// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAnimInstace.h"

#include "../Util/UtilEnum.h"
#include "../Skill/MeleeAttack.h"
#include "../Character/CharacterNPC.h"

#include <Animation/AnimMontage.h>

UMonsterAnimInstace::UMonsterAnimInstace(){}

// 틱마다 호출되는 함수
void UMonsterAnimInstace::NativeUpdateAnimation(float InDeltaSeconds)
{
	Super::NativeUpdateAnimation(InDeltaSeconds);
}

// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
UAnimMontage* UMonsterAnimInstace::GetMontageByAbilityType(EAbilityType InAbilityType)
{
	return LoadSoftObject<UAnimMontage>(MonsterMontage);
}

// 몽타주를 재생합니다.
float UMonsterAnimInstace::PlayMontage(EAbilityType InAbilityType, EMonsterSkillMontageType InSectionType, float InPlayRate/* = 1.f*/)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if (!animMontage)
		return 0.f;

	//TODO InSectionType 고쳐야됨 근데 Default로 읽어지긴하는듯?
	FName sectionName = *ENUM_TO_STRING( EMonsterSkillMontageType, InSectionType );
	Montage_Play(animMontage, InPlayRate);
	Montage_JumpToSection(sectionName, animMontage);
	
	return animMontage->GetSectionLength(animMontage->GetSectionIndex(sectionName));
}

// 몽타주 재생을 정지합니다.
void UMonsterAnimInstace::StopMontage(EAbilityType InAbilityType, float InBlendOutTime)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Stop(InBlendOutTime, animMontage);
}

// 몽타주 재생을 일시 정지합니다.
void UMonsterAnimInstace::PauseMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Pause(animMontage);
}

// 몽타주를 다시 재생합니다.
void UMonsterAnimInstace::ResumeMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Resume(animMontage);
}

void UMonsterAnimInstace::AnimNotify_NotifyMeleeAttack() const
{
	auto ownerPawn = Cast<ACharacterNPC>(GetOwningActor());
	
	UMeleeAttack *MA = nullptr;
	if(ownerPawn->MeleeAttack)
		MA = Cast<UMeleeAttack>(ownerPawn->MeleeAttack);
	
	if(MA != nullptr)
		MA->SkillTriggered();
}

void UMonsterAnimInstace::SetSpineRotation()
{
	
}
