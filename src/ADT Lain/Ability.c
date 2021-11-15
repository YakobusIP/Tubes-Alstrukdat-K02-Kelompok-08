#include "Ability.h"


void CreateAbility(Ability *A)
{
    for(int i = 0; i < 3; i++)
    {
        AbilityType(*A, i) = false;
    }
}
