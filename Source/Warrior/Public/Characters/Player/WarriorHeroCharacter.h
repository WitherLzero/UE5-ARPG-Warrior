// Paul Lyn All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorHeroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
