#include "Ability.h"


void CreateAbility(Ability *A)
{
    for(int i = 0; i < 3; i++)
    {
        AbilityType(*A, i) = false;
    }
}

void speed_boost(Ability *A, int* waktu, UangWaktu *U, in_progress_list *IPL)
{
    if(AbilityType(*A, 0) && !isHeavyinIPL(*IPL) && *waktu != 10)
    {
        if (*waktu % 2 == 0)
        {
            ChangeWaktu(U, 1);
        }
    }
    else{
        *waktu = 0;
        AbilityType(*A, 0) = false;
    }
}
void increase_capacity(Ability A, Stack *S)
{
    if(AbilityType(A, 1))
    {
        MAKSIMUM(*S) += 1;
    }
}
void return_to_sender(Ability *A, in_progress_list *IPL /* Tambah kalau kurang*/)
{
    ipAddress p = FIRST(*IPL);

    if(AbilityType(*A, 2) && INFO(p).type != 'V')
    {
        /*Pesanan dikembalikan ke to do list terakhir*/
        /*if items = perishable, reset timelimit*/

    }
    else
    {
        AbilityType(*A, 2) = false;
    }
}