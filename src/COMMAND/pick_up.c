#include <stdio.h>
#include "pick_up.h"
// #include "../ADT Lain/UangWaktu.c"
// #include "../ADT Linked List/inprogressList.c"
// #include "../ADT Linked List/inprogressNode.c"
// #include "../ADT Linked List/todoNode.c"
// #include "../ADT Linked List/todoList.c"
// #include "../ADT List/adjList.c" 
// #include "../ADT List/Gadget.c"
// #include "../ADT List/InventoryGadget.c"
// #include "../ADT Matriks/adjMatriks.c"
// #include "../ADT Matriks/map.c"
// #include "../ADT Mesin Kata/charmachine.c"
// #include "../ADT Mesin Kata/tokenmachine.c"
// #include "../ADT Point/point.c"
// #include "../ADT Stack/stack.c"
// #include "../ADT Queue/requestList.c"
// #include "../pcolor/pcolor.c"
// #include "../boolean.h"

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

void foundPickupInLoc(to_do_List *tdl, char currentLocation, boolean *found, int *val, int *idxTD, toDoList *pickup_item) {
    /* Mengecek apakah ada pesanan yang harus di pick-up di currentLocation */
    *idxTD = 0;
    tdAddress p = FIRST(*tdl);
    do {
        if (INFO(p).pickUp ==  currentLocation) {
            *pickup_item = INFO(p);
            if ((*pickup_item).type == 'N') {*val = 1;}
            else if ((*pickup_item).type == 'H') {*val = 2;}
            else if ((*pickup_item).type == 'P') {*val = 3;}
            else if ((*pickup_item).type == 'V') {*val = 4;}
            *found = true;
        }
        else {
            *idxTD += 1;
            p = NEXT(p);
        }
    } while (!(*found) && p!=NULL);
}

void pick_up(to_do_List *tdl, Stack *s, in_progress_list *pl, char currentLocation, int *addMoveTime, UangWaktu *u) {
    if (isTDListEmpty(*tdl)) {
        printf("Tidak ada pesanan di To Do list!\n");
    }

    else {
        toDoList pickup_item;
        inProgressList progress_item;
        ElType val;
        int idxTD;
        boolean found = false;

        foundPickupInLoc(tdl, currentLocation, &found, &val, &idxTD, &pickup_item);
        if (!found) {                               // tidak ada pesanan pickup di lokasi tsb
            printf("Tidak ada pesanan pada lokasi ini!\n");
        }
        else {
            if (foundVIP(*tdl) && pickup_item.type != 'V') {      // ada VIP namun tidak dilokasi ini
                printf("Tidak bisa mempick-up pesanan di lokasi ini karena ada item VIP di lokasi lain!\n");
            }
            else {
                toDoList deletedTD;
                if (isFullStack(*s)) {
                    printf("Tidak dapat mempick-up pesanan karena tas sudah penuh\n");
                }
                else {
                    pushStack(s, val);                           // item dimasukkan ke dalam Tas
                    progress_item.dropOff = pickup_item.dropOff;
                    progress_item.pickUp = pickup_item.pickUp;
                    progress_item.timeLimit = pickup_item.timeLimit;
                    progress_item.type = pickup_item.type;
                    progress_item.startTime = WAKTU(*u);
                    insertLastIP(pl, progress_item);
                    deleteAtTD(tdl, idxTD, &deletedTD);

                    if (pickup_item.type == 'H') {*addMoveTime += 1;}
                    /* Efek Perishable Item dihandle MOVE karna bergantung waktu pengantaran */
                    char item_name[20];
                    if (pickup_item.type == 'N') {copyString(item_name, "Normal Item");}
                    if (pickup_item.type == 'H') {copyString(item_name, "Heavy Item");}
                    if (pickup_item.type == 'P') {copyString(item_name, "Perishable Item");}
                    if (pickup_item.type == 'V') {copyString(item_name, "VIP Item");}
                    printf("Tujuan Pesanan: %c\n", pickup_item.dropOff);
                    printf("Pesanan berupa %s berhasil diambil!\n", item_name);
                }
            }
        }
    }
}