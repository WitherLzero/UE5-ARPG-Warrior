// Paul Lyn All Rights Reserved


#include "Characters/Player/WarriorHeroCharacter.h"

#include "WarriorDebugHelper.h"

// Sets default values
AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Debug::Print(TEXT("Hero Character BeginPlay"));
	
}

