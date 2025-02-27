﻿// Copyright GuardiansW. All Rights Reserved.


#pragma once


#include "../UserWidgetBase.h"
#include "../../Skill/SkillManager.h"
#include "../../Character/CharacterPC.h"
#include "SkillUpgradeUI.generated.h"


// =============================================================
// 스킬타입과 업그레이드타입에 따라 캐릭터가 가지고 있는 SkillManager의 값을 바꿔주는 함수를 등록한다.
// SkillType		=>	TMap<ESkillType, bool> SkillType; SkillManager가 가지고있는 티맵
// UpgradeTypeName	=>	ESkillType 이넘클래스의 인수들
// =============================================================
#define DECLARE_SKILLMANAGER_SETTYPE(SkillType, UpgradeTypeName)					\
private:																			\
	UFUNCTION()																		\
	void Plus##SkillType##UpgradeTypeName()											\
	{																				\
		++DpGetPlayer()->PCSkillManager.SkillType[E##SkillType::UpgradeTypeName];	\
		AfterClick();																\
	}																				\


class UTextBlock;
class UButton;

UCLASS()
class DIESELPUNK_API USkillUpgradeUI : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UButton*	Button_Left;					// 왼쪽 버튼
	UTextBlock* Text_Skill_Left;				// 왼쪽 스킬 할당키
	UTextBlock* Text_SkillName_Left;			// 왼쪽 스킬 이름
	UTextBlock* Text_SkillUpgradeName_Left;		// 왼쪽 스킬 특성 이름
	UTextBlock* Text_SkillUpgradeExpl_Left;		// 왼쪽 스킬 특성 설명

	UButton*	Button_Middle;					// 중간 버튼
	UTextBlock* Text_Skill_Middle;				// 중간 스킬 할당키
	UTextBlock* Text_SkillName_Middle;			// 중간 스킬 이름
	UTextBlock* Text_SkillUpgradeName_Middle;	// 중간 스킬 특성 이름
	UTextBlock* Text_SkillUpgradeExpl_Middle;	// 중간 스킬 특성 설명

	UButton*	Button_Right;					// 오른쪽 버튼
	UTextBlock* Text_Skill_Right;				// 오른쪽 스킬 할당키
	UTextBlock* Text_SkillName_Right;			// 오른쪽 스킬 이름
	UTextBlock* Text_SkillUpgradeName_Right;	// 오른쪽 스킬 특성 이름
	UTextBlock* Text_SkillUpgradeExpl_Right;	// 오른쪽 스킬 특성 설명
	
public:
	// UI를 생성한다.
	static USkillUpgradeUI* CreateUI();

	// 난수값 저장용 인티저
	int8 RandomNum;

	// 난수값에 따라 위젯을 세팅합니다.
	void SetControls();
	
protected:
	
	// 생성자
	virtual void OnCreated() override;

	// 소멸자
	virtual void BeginDestroy() override;

	// 화면에 보이는 시점에 호출되는 함수
	virtual void OnAppeared() override;

	// 화면에서 사라지는 시점에 호출되는 함수
	virtual void OnDisappeared() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

private:
	// 위젯을 초기화한다.
	void _InitControls();

	// 왼쪽 버튼이 클릭되었을 때 호출되는 함수
	UFUNCTION()
	void LeftButtonClick();
	
	// 중간 버튼이 클릭되었을 때 호출되는 함수
	UFUNCTION()
	void MiddleButtonClick();
	
	// 오른쪽 버튼이 클릭되었을 때 호출되는 함수
	UFUNCTION()
	void RightButtonClick();

	// 공통적인 후처리 Task를 처리하는 함수
	void AfterClick();

	// 스킬 특성에따라 텍스트를 세팅합니다.
	void SetText(int inNum);

private:
	// SoldierMouseLMUpgradeType
	DECLARE_SKILLMANAGER_SETTYPE(SoldierMouseLMUpgradeType, DamageUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierMouseLMUpgradeType, CastSpeedUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierMouseLMUpgradeType, StackingPercentage);
	// SoldierMouseRMUpgradeType
	DECLARE_SKILLMANAGER_SETTYPE(SoldierMouseRMUpgradeType, DamageUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierMouseRMUpgradeType, StackingDamageUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierMouseRMUpgradeType, CoolDown);
	// SoldierShiftUpgradeType
	DECLARE_SKILLMANAGER_SETTYPE(SoldierShiftUpgradeType, DashDistance);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierShiftUpgradeType, CoolDown);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierShiftUpgradeType, SpeedUp);
	// SoldierSkillQUpgradeType
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillQUpgradeType, DamageUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillQUpgradeType, CoolDown);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillQUpgradeType, AddProjectile);
	// SoldierSkillEUpgradeType
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillEUpgradeType, DamageUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillEUpgradeType, CoolDown);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillEUpgradeType, StackUp);
	// SoldierSkillRUpgradeType
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillRUpgradeType, DamageUp);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillRUpgradeType, CoolDown);
	DECLARE_SKILLMANAGER_SETTYPE(SoldierSkillRUpgradeType, WideRange);
	
};

