// Paul Lyn All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RPGFramework/AnimInstance/RPGCoreLinkedAnimLayer.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

class UWarriorHeroAnimInstance;

/**
 * Warrior Hero 的 Linked Anim Layer 基类。
 * 提供从 Linked Layer 反查主 Hero AnimInstance 的桥接(在核心层 GetCharacterAnimInstance
 * 基础上做 Warrior 项目层的二次 Cast,返回具体的 Hero 类型)。
 */
UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public URPGCoreLinkedAnimLayer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};