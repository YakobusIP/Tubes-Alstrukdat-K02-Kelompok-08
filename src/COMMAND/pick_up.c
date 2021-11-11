/* COMMAND UNTUK PICK UP */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT Linked List/todoQueue.h"
#include "../ADT Stack/stack.h"
#include "../ADT Lain/UangWaktu.h"
#include "../ADT Linked List/inprogressList.h"

// addMoveTime = waktu tambahan saat move jika membawa heavy item, dapat menumpuk

boolean foundVIP(PrioQueue q) {
    /* Mengecek apakah ada item VIP di To Do List */
    Address p = HEAD(q);
    boolean foundVip = false;
    do {
        if (INFO(p).type ==  'V') {
            foundVip = true;
        }
        else {
            p = NEXT(p);
        }
    } while (!foundVip && p!=NULL);
    
    return foundVip;
}

boolean foundPickupInLoc(PrioQueue *q, char currentLocation, boolean *found, int *val, toDoList *pickup_item) {
    /* Mengecek apakah ada pesanan yang harus di pick-up di currentLocation */
    Address p = HEAD(*q);
    do {
        if (INFO(p).pickUp ==  currentLocation) {
            *pickup_item = INFO(p);
            if ((*pickup_item).type = 'N') {val = 1;}
            else if ((*pickup_item).type = 'H') {val = 2;}
            else if ((*pickup_item).type = 'P') {val = 3;}
            else if ((*pickup_item).type = 'V') {val = 4;}
            *found = true;
        }
        else {
            p = NEXT(p);
        }
    } while (!(*found) && p!=NULL);
}

void pick_up(PrioQueue *q, Stack *s, UangWaktu *u, List *l, char currentLocation, int *addMoveTime) {
    // displayToDo(*q);
    if (isQueueEmpty(*q)) {
        printf("Pesanan tidak ditemukan!\n");
    }

    else {
        toDoList pickup_item;
        inProgressList progress_item;
        ElType val;
        boolean found = false;
        foundPickupInLoc(q, currentLocation, &found, &val, &pickup_item);

        if (!found) {                               // tidak ada pesanan pickup di lokasi tsb
            printf("Pesanan tidak ditemukan!\n");
        }
        else {
            if (foundVIP(*q) && pickup_item.type != 'V') {      // ada VIP namun tidak dilokasi ini
                printf("Tidak bisa mempick-up pesanan di lokasi ini karena ada item VIP di lokasi lain!\n");
            }
            else {
                push(s, val);                           // item dimasukkan ke dalam Tas
                progress_item.dropOff = pickup_item.dropOff;
                progress_item.pickUp = pickup_item.pickUp;
                // progress_item.startTime
                progress_item.timeLimit = pickup_item.timeLimit;
                progress_item.type = pickup_item.type;
                insertLast(l, progress_item);

                if (pickup_item.type == 'H') {*addMoveTime++;}
                /* Efek Perishable Item dihandle MOVE karna bergantung waktu pengantaran */

                printf("Tujuan Pesanan: %c\n", pickup_item.dropOff);
                printf("Pesanan berupa %c berhasil diambil!\n", pickup_item.type);
            }
        }
    }
}