// Paul Lyn All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

struct FInputActionValue;
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
	
private:
#pragma region Components
	
	UPROPERTY(visibleAnywhere,BlueprintReadOnly,Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(visibleAnywhere,BlueprintReadOnly,Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
#pragma endregion
};
