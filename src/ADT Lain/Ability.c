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
void return_to_sender(Ability *A, in_progress_list *IPL, Stack *s, to_do_List *tdl, UangWaktu u)
{
    ipAddress p = FIRST(*IPL);

    if(AbilityType(*A, 2) && INFO(p).type != 'V')
    {
        inProgressList ipl;
        struct items val;
        toDoList value;
        deleteLastIP(IPL, &ipl);
        popStack(s,&val);
        value.reqIn = WAKTU(u);
        value.dropOff = ipl.dropOff;
        value.pickUp = ipl.pickUp;
        value.timeLimit = ipl.startTime;
        value.type = ipl.type;
        insertLastTD(tdl, value);
        printf("Item berhasil dikembalikan ke Pick Up Point %s\n", value.pickUp);
    }
    else
    {
        AbilityType(*A, 2) = false;
    }
}