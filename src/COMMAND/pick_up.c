/* COMMAND UNTUK PICK UP */

#include <stdio.h>
#include "pick_up.h"

// addMoveTime = waktu tambahan saat move jika membawa heavy item, dapat menumpuk

boolean foundVIP(to_do_List l) {
    tdAddress p = FIRST(l);
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

void foundPickupInLoc(to_do_List *tdl, char currentLocation, boolean *found, int *val, toDoList *pickup_item) {
    /* Mengecek apakah ada pesanan yang harus di pick-up di currentLocation */
    tdAddress p = FIRST(*tdl);
    do {
        if (INFO(p).pickUp ==  currentLocation) {
            *pickup_item = INFO(p);
            if ((*pickup_item).type = 'N') {*val = 1;}
            else if ((*pickup_item).type = 'H') {*val = 2;}
            else if ((*pickup_item).type = 'P') {*val = 3;}
            else if ((*pickup_item).type = 'V') {*val = 4;}
            *found = true;
        }
        else {
            p = NEXT(p);
        }
    } while (!(*found) && p!=NULL);
}

void pick_up(to_do_List *tdl, Stack *s, in_progress_list *pl, char currentLocation, int *addMoveTime) {
    if (isTDListEmpty(*tdl)) {
        printf("Pesanan tidak ditemukan!\n");
    }

    else {
        toDoList pickup_item;
        inProgressList progress_item;
        ElType val;
        boolean found = false;
        foundPickupInLoc(tdl, currentLocation, &found, &val, &pickup_item);

        if (!found) {                               // tidak ada pesanan pickup di lokasi tsb
            printf("Pesanan tidak ditemukan!\n");
        }
        else {
            if (foundVIP(*tdl) && pickup_item.type != 'V') {      // ada VIP namun tidak dilokasi ini
                printf("Tidak bisa mempick-up pesanan di lokasi ini karena ada item VIP di lokasi lain!\n");
            }
            else {
                pushStack(s, val);                           // item dimasukkan ke dalam Tas
                progress_item.dropOff = pickup_item.dropOff;
                progress_item.pickUp = pickup_item.pickUp;
                // progress_item.startTime
                progress_item.timeLimit = pickup_item.timeLimit;
                progress_item.type = pickup_item.type;
                insertLastIP(pl, progress_item);

                if (pickup_item.type == 'H') {*addMoveTime++;}
                /* Efek Perishable Item dihandle MOVE karna bergantung waktu pengantaran */

                printf("Tujuan Pesanan: %c\n", pickup_item.dropOff);
                printf("Pesanan berupa %c berhasil diambil!\n", pickup_item.type);
            }
        }
    }
}