/* COMMAND UNTUK DROP OFF */

#include <stdio.h>
#include "drop_off.h"
// #include "../ADT Lain/UangWaktu.c"
// #include "../ADT Linked List/inprogressList.c"
// #include "../ADT Linked List/inprogressNode.c"
// #include "../ADT Linked List/todoNode.c"
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
// #include "../ADT Lain/Ability.h"

void drop_off(in_progress_list *pl, Stack *s, char currentLocation, UangWaktu *u, Ability *A, int *addMoveTime) {
    if (isEmptyStack(*s)) {
        printf("Tidak ada pesanan yang perlu diantarkan\n");
    }
    else {
        inProgressList dropoff_item;
        dropoff_item.type =  TYPE(*s);

        // data item pada progress list sinkron dengan pada stack, pada elemen terakhir
        int idx = lengthIPL(*pl) - 1;
        dropoff_item.dropOff = getElmtIP(*pl,idx).dropOff;

        /* Cek dulu apakah lokasi dropoff item tumpukan teratas sesuai dengan lokasi sekarang */
        if (dropoff_item.dropOff != currentLocation) {
            printf("Lokasi drop off pesanan teratas bukan pada lokasi ini\n");
        }
        else {
            struct items delStackItem;
            inProgressList delProgressItem;

            int addUang = HARGA(*s);
            popStack(s, &delStackItem);
            deleteAtIP(pl, idx, &delProgressItem);
            ChangeUang(u, addUang);

            if (delStackItem.effect == 1) {AbilityType(*A, 0) = true; *addMoveTime -= 1;}   // heavy item
            else if (delStackItem.effect == 2) {AbilityType(*A, 1) = true;}                 // perishable item
            else if (delStackItem.effect == 3) {AbilityType(*A, 2) = true;}                 // VIP Item

            // kasus penggunaan senter pengecil, efek senter pengecil nya hilang saat di drop (kembali seperti semula)
            // reward tetap aktif
            if ((delStackItem.effect == IDX_UNDEF) && (delStackItem.type == 'H')) {
                delStackItem.effect = 1;
                AbilityType(*A, 0) = true;
            }

            printf("Pesanan %s berhasil diantarkan\n", delStackItem.name);
            if (delStackItem.effect != IDX_UNDEF) {
                printf("Ability %s berhasil didapatkan\n", delStackItem.reward);
            }
            printf("Uang yang didapatkan: %d yen\n", addUang);
        }
    }
}