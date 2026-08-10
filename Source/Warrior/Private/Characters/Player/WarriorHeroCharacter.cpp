// Paul Lyn All Rights Reserved


#include "Characters/Player/WarriorHeroCharacter.h"

#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "RPGFramework/Types/RPGGameplayTags.h"

#include "WarriorDebugHelper.h"


// Sets default values
AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f,96.f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f,55.f,65.f);
	CameraBoom->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,500.f,0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

// Called when the game starts or when spawned
void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Debug::Print(TEXT("Hero Character BeginPlay"));
	
}

bool AWarriorHeroCharacter::HandleNativeInput(FGameplayTag Tag, ERPGInputEvent EventType, FInputActionValue Value)
{
	return OnNativeInput(Tag, EventType, Value);
}

bool AWarriorHeroCharacter::OnNativeInput_Implementation(FGameplayTag Tag, ERPGInputEvent EventType, FInputActionValue Value)
{
	const FRPGGameplayTags& GameplayTags = FRPGGameplayTags::Get();
	
	if (Tag == GameplayTags.Inputs_Move)
	{
		if (EventType == ERPGInputEvent::IE_Held)
		{
			Move(Value.Get<FVector2D>());
		}
		return true;
	}
	
	if (Tag == GameplayTags.Inputs_Look)
	{
		if (EventType == ERPGInputEvent::IE_Held)
		{
			Look(Value.Get<FVector2D>());
		}
		return true;
	}
	
	return false;
}

void AWarriorHeroCharacter::Move(const FVector2D& InputAxis)
{
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	
	if (InputAxis.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, InputAxis.Y);
	}
	
	if (InputAxis.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, InputAxis.X);
	}
}

void AWarriorHeroCharacter::Look(const FVector2D& InputAxis)
{
	if (InputAxis.X != 0.f)
	{
		AddControllerYawInput(InputAxis.X);
	}
	
	if (InputAxis.Y != 0.f)
	{
		AddControllerPitchInput(InputAxis.Y);
	}
}