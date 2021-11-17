/* COMMAND UNTUK TO_DO */

#include <stdio.h>
#include "to_do.h"

// Fungsi untuk memindahkan isi dari daftar pesanan ke dalam to do list sesuai waktu sekarang
// Asumsi waktu request in > 0
void fromRLtoTDL(PrioQueue *q, to_do_List *tdl, int time) {
    /* KAMUS */
    int i;
    requestList val_in;
    toDoList val_out;
    int reqIn_in, timeLimit_in;
    char pickUp_in, dropOff_in, type_in;
    boolean canMove;
    /* ALGORITMA */
    canMove = false;
    if (time > 0) {
        canMove = true;
    }
    while (canMove) {
      
        dequeue(q, &val_in);
        reqIn_in = val_in.reqIn;
        pickUp_in = val_in.pickUp;
        dropOff_in = val_in.dropOff;
        type_in = val_in.type;
        timeLimit_in = val_in.timeLimit;
        // Kalau reqIn_in > time, maka kita akan kembalikan item tersebut ke dalam queue lagi, sehingga tidak diproses
        if (reqIn_in > time) {
            enqueueRL(q, val_in);
            canMove = false;
        }

        // Insert ke dalam todolist sesuai waktu sekarang
        if (reqIn_in <= time) {
            canMove = true;
            val_out.reqIn = reqIn_in;
            val_out.pickUp = pickUp_in;
            val_out.dropOff = dropOff_in;
            val_out.type = type_in;
            val_out.timeLimit = timeLimit_in;

            insertLastTD(tdl, val_out);
        } else if (isQueueEmpty(*q)) {
            canMove = false;
        } else {
            canMove = false;
        }
    }
}

// Fungsi untuk display to do list ketika diminta
void to_do(to_do_List *tdl) {
    displayToDo(*tdl);
}