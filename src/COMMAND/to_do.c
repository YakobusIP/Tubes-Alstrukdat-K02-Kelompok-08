/* COMMAND UNTUK TO_DO */

#include <stdio.h>
#include "../ADT Queue/requestList.h"
#include "../ADT Linked List/todoQueue.h"

void to_do(PrioQueue *q, to_do_List *tdl) {
    /* KAMUS */
    requestList val_in;
    toDoList val_out;
    int reqIn_in, timeLimit_in;
    char pickUp_in, dropOff_in, type_in;
    /* ALGORITMA */
    dequeue(q, &val_in);
    reqIn_in = val_in.reqIn;
    pickUp_in = val_in.pickUp;
    dropOff_in = val_in.dropOff;
    type_in = val_in.type;
    timeLimit_in = val_in.timeLimit;

    val_out.reqIn = reqIn_in;
    val_out.pickUp = pickUp_in;
    val_out.dropOff = dropOff_in;
    val_out.type = type_in;
    val_out.timeLimit = timeLimit_in;

    insertLast(*tdl, val_out);
    displayToDo(tdl);
}