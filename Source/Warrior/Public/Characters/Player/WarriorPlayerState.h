// Paul Lyn All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RPGFramework/Player/RPGPlayerState.h"
#include "WarriorPlayerState.generated.h"

/**
 * Warrior 项目玩家 PlayerState：复用 RPGCore ARPGPlayerState（ASC + VitalAttributeSet + Level/XP）。
 */
UCLASS()
class WARRIOR_API AWarriorPlayerState : public ARPGPlayerState
{
	GENERATED_BODY()

public:
	AWarriorPlayerState();
};
