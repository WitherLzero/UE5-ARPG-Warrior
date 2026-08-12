// Paul Lyn All Rights Reserved

#include "AnimInstance/WarriorHeroLinkedAnimLayer.h"

#include "AnimInstance/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetCharacterAnimInstance());
}