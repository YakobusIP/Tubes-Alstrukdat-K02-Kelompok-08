#include "point.h"
#include "point.c"
#include "../boolean.h"
#include <stdio.h>

int main()
{
    Coordinate Mobita;
    Mobita = *CreateCoord('8', 1, 5);
    DisplayCoord(Mobita);
    if(IsIdxCoordValid(Mobita)) printf("True");
    if(IsCoordEff(Mobita, 10, 10)) printf("True");
    return 0;
}