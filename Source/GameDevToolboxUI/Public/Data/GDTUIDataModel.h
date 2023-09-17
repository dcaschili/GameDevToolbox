#pragma once

#include "UObject/Object.h"

#include "GDTUIDataModel.generated.h"

/**
TODO: add documentation
*/
UCLASS(Abstract, BlueprintType)
class GAMEDEVTOOLBOXUI_API UGDTUIDataModel : public UObject
{
    GENERATED_BODY()
public:

    UPROPERTY(BlueprintReadOnly, Category="GDTUI|Data")
    FName Key{};

    FORCEINLINE bool operator==(const UGDTUIDataModel* Other) const { return Other && Key.IsEqual(Other->Key); }
};

// USTRUCT(BlueprintType) 
// struct FAggroData { 
//     GENERATED_USTRUCT_BODY() 
// public:
//    /*Sort Key: This is the aggro value for this enemy*/ 
//    UPROPERTY(BlueprintReadWrite, Category = "Aggro") int32 Aggro;
//    /*This is the enemy we sensed*/ 4
//    UPROPERTY(BlueprintReadWrite, Category = "Aggro") ABaseCreature* Enemy;
//    /*This is the last known position of the enemy*/ 
//    UPROPERTY(BlueprintReadWrite, Category = "Aggro") FVector LastSensePosition;
//    /*This is the last known velocity of the enemy*/
//    UPROPERTY(BlueprintReadWrite, Category = "Aggro") FVector LastSenseVelocity;
//    /*This is how old the last sense time was*/
//    UPROPERTY(BlueprintReadWrite, Category = "Aggro") float LastSenseAge;
//    //override the "<" operator so that this object can be sorted 
//    FORCEINLINE bool operator<(const FAggroData &Other) const { return Aggro < Other.Aggro; }
//    //check to see if the aggro record matches another aggro record by overloading the "==" operator.
//    FORCEINLINE bool operator==(const FAggroData &Other) const { return Enemy == Other.Enemy; } 
// };
   //ABaseCreature Class header: TArray<FAggroData> SensedEnemies;
   //ABaseCreature Tick: 
   //This will sort the list of sensed enemies based on the overloaded "<" operator. In this case, our sort
   //scheme will put the creature with the highest aggro at the very front of the list. If we want to change the sort //order, we can just swap the operands in the "<" operator overload SensedEnemies.Sort();