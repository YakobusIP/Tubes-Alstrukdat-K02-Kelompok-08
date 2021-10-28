/* DRIVER UTAMA TO DO LIST */
/* TO DO LIST DI OUTPUT SECARA BERURUTAN SESUAI URUTAN MASUKNYA */

#include <stdio.h>
#include "todoQueue.h"

int main() {
    /* KAMUS */
    PrioQueue tdList;
    toDoList val, val2;
    int i,p;
    int reqIn, timeLimit;
    char pickUp, dropOff, type;
    /* ALGORITMA */
    CreateQueue(&tdList);
    scanf("%d", &p);
    for(i = 0;i < p;i++) {
        scanf("%d ", &reqIn);
        scanf("%c ", &pickUp);
        scanf("%c ", &dropOff);
        scanf("%c", &type);
        if (type == 'P') {
            scanf(" %d", &timeLimit);
        } else {
            timeLimit = 0;
        }
        val.reqIn = reqIn;
        val.pickUp = pickUp;
        val.dropOff = dropOff;
        val.type = type;
        val.timeLimit = timeLimit;
        enqueue(&tdList, val);
    }

    displayToDo(tdList);
    return 0;
}