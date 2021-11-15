#ifndef ABILITY_H
#define ABILITY_H

#include "../boolean.h"


typedef struct {
    boolean type[3]; //sesuai urutan spek
} Ability;

#define AbilityType(A, i) (A).type[(i)]


void CreateAbility(Ability *A);
#endif
