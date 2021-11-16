/* COMMAND UNTUK TO_DO */

#include <stdio.h>
#include "to_do.h"

// Fungsi untuk memindahkan isi dari daftar pesanan ke dalam to do list sesuai waktu sekarang
void fromRLtoTDL(PrioQueue *q, to_do_List *tdl, UangWaktu *u) {
    /* KAMUS */
    int i;
    requestList val_in;
    toDoList val_out;
    int reqIn_in, timeLimit_in;
    char pickUp_in, dropOff_in, type_in;
    /* ALGORITMA */
    while (!isQueueEmpty(*q)) {
        dequeue(q, &val_in);
        reqIn_in = val_in.reqIn;
        pickUp_in = val_in.pickUp;
        dropOff_in = val_in.dropOff;
        type_in = val_in.type;
        timeLimit_in = val_in.timeLimit;

        // Insert ke dalam todolist sesuai waktu sekarang
        if (reqIn_in <= 10) {
            val_out.reqIn = reqIn_in;
            val_out.pickUp = pickUp_in;
            val_out.dropOff = dropOff_in;
            val_out.type = type_in;
            val_out.timeLimit = timeLimit_in;

            insertLastTD(tdl, val_out);
        }
    }
}

// Fungsi untuk display to do list ketika diminta
void to_do(to_do_List *tdl) {
    displayToDo(*tdl);
}