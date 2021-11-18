#include "Ability.h"

#include <stdio.h>
#include "../boolean.h"
#include "UangWaktu.h"
#include "../ADT Linked List/inprogressList.h"
#include "../ADT Linked List/todoList.h"
#include "../ADT Linked List/inprogressList.h"
#include "../ADT Stack/stack.h"
int main()
{
    Ability A;
    AbilityType(A, 0) = true;
    AbilityType(A, 1) = true;
    AbilityType(A, 2) = false;
    for(int i = 0; i < 3; i++) if(AbilityType(A, i)) printf("Ability %d nyala", i+1);
    return 0;
}