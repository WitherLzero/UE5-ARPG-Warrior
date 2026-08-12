// Paul Lyn All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RPGFramework/AnimInstance/RPGCoreCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * Warrior Hero 专属动画实例基类(Hero AnimBP 的 C++ 基类)。
 * 继承 RPGCore 通用角色动画实例,未来可放置 Hero 特定动画逻辑。
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public URPGCoreCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "AnimData|References")
	TObjectPtr<AWarriorHeroCharacter> OwningHeroChar;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	float EnterRelaxThreshold = 5.f;
	
	float IdleElapsedTime = 0.f;
	
	
};