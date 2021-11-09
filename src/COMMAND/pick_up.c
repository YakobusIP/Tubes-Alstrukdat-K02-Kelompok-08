/* COMMAND UNTUK PICK UP,
notes : identifikasi lokasi perlu penyesuaian lagi mau gimana,
        isEmpty Queue sama isEmpty Stack nabrak :( */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT Linked List/todoQueue.h"
#include "../ADT Stack/stack.h"
#include "../ADT Lain/UangWaktu.h"

void pick_up(PrioQueue *q, Stack *s, char pickupLocation, UangWaktu *u) {
    // displayToDo(*q);
    if (isQueueEmpty(*q)) {
        printf("Pesanan tidak ditemukan!\n");
    }

    else {
        toDoList pickup_item;
        ElType val;
        boolean found = false;

        Address p = HEAD(*q);
        do {
            if (INFO(p).pickUp ==  pickupLocation) {
                pickup_item = INFO(p);
                if (pickup_item.type = 'N') {val = 1;}
                else if (pickup_item.type = 'H') {val = 2;}
                else if (pickup_item.type = 'P') {val = 3;}
                else if (pickup_item.type = 'V') {val = 4;}
                found = true;
            }
            else {
                p = NEXT(p);
            }
        } while (!found && p!=NULL);

        if (!found) {                               // tidak ada pesanan pickup di lokasi tsb
            printf("Pesanan tidak ditemukan!\n");
        } else {
            push(s, val);
            printf("Tujuan Pesanan: %c\n", pickup_item.dropOff);
            printf("Pesanan berupa %c berhasil diambil!\n", pickup_item.type);
        }
    }
}