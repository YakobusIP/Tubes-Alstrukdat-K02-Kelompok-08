#ifndef ABILITY_H
#define ABILITY_H

#include "../boolean.h"
#include "../ADT Lain/UangWaktu.h"
#include "../ADT Stack/stack.h"
#include "../ADT Linked List/todoList.h"
#include "../ADT Linked List/inprogressList.h"

typedef struct {
    boolean type[3]; //sesuai urutan spek
    int totalVip;
} Ability;

#define AbilityType(A, i) (A).type[(i)]
#define TotalVIP(A) (A).totalVip

void CreateAbility(Ability *A);
void speed_boost(Ability *A, int* waktu, UangWaktu *U, in_progress_list *IPL);
void increase_capacity(Ability A, Stack *S);
void return_to_sender(Ability *A, in_progress_list *IPL, Stack *s, to_do_List *tdl, UangWaktu u);
#endif
