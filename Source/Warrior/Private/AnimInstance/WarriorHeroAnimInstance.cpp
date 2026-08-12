// Paul Lyn All Rights Reserved

#include "AnimInstance/WarriorHeroAnimInstance.h"

#include "Characters/Player/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (OwningCharacter)
	{
		OwningHeroChar = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
	
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime>= EnterRelaxThreshold);
	}
}
