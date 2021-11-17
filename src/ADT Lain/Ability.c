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
    static int last_waktu = -1;
    if(AbilityType(*A, 0) && !isHeavyinIPL(*IPL) && *waktu <= 10 && last_waktu != *waktu)
    {
        if (*waktu % 2 == 0 && *waktu != 0)
        {
            ChangeWaktu(U, 1);
            last_waktu = *waktu;
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
    printf("Item berhasil dikembalikan ke Pick Up Point %c\n", value.pickUp);
}
