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

void drop_off(in_progress_list *pl, Stack *s, char currentLocation, UangWaktu *u, Ability ability) {
    if (isEmptyStack(*s)) {
        printf("Tidak ada pesanan yang perlu diantarkan\n");
    }
    else {
        inProgressList dropoff_item;
        copyString(&dropoff_item.type, TOP(*s).type);

        // mencari data drop off item dari progress list
        int idx = lengthIPL(*pl) - 1;
        boolean flag = false;
        while (idx>=0 && !flag) {
            if (getElmtIP(*pl,idx).type == dropoff_item.type) {
                dropoff_item.dropOff = getElmtIP(*pl,idx).dropOff;
                flag = true;
            }
            else {
                idx--;
            }
        }

        /* Cek dulu apakah lokasi dropoff item tumpukan teratas sesuai dengan lokasi sekarang */
        if (dropoff_item.dropOff != currentLocation) {
            printf("Tidak ada pesanan yang perlu diantarkan ke lokasi ini\n");
        }
        else {
            struct items delStackItem;
            inProgressList delProgressItem;

            int addUang = HARGA(*s);
            popStack(s, &delStackItem);
            deleteAtIP(pl, idx, &delProgressItem);
            ChangeUang(u, addUang);

            if (delStackItem.type == "H") {ability.type[0] = true;}
            else if (delStackItem.type == "P") {ability.type[1] = true;}
            else if (delStackItem.type == "V") {ability.type[2] = true;}

            printf("Pesanan %s berhasil diantarkan\n", delStackItem.name);
            printf("Uang yang didapatkan: %d yen\n", addUang);
        }
    }
}

// int main() {
//     printf("yey");
// }