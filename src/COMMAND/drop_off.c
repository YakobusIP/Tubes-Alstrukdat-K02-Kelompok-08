/* COMMAND UNTUK DROP OFF */

#include <stdio.h>
#include "drop_off.h"

void drop_off(in_progress_list *pl, Stack *s, char currentLocation, UangWaktu *u) {
    if (isEmptyStack(*s)) {
        printf("Tidak ada pesanan yang perlu diantarkan\n");
    }
    else {
        inProgressList dropoff_item;
        struct items delStackItem;
        inProgressList delProgressItem;
        dropoff_item.type = TOP(*s).type;

        // mencari data drop off item dari progress list
        ipAddress p = FIRST(*pl);
        int idx = 0;
        boolean found = false;
        do {
            if (INFO(p).type == dropoff_item.type) {
                dropoff_item.dropOff = INFO(p).dropOff;
                found = true;
            }
            else {
                p = NEXT(p);
                idx++;
            }
        } while (p != NULL && !found);

        /* Cek dulu apakah lokasi dropoff item tumpukan teratas sesuai dengan lokasi sekarang */
        if (dropoff_item.dropOff != currentLocation) {
            printf("Tidak ada pesanan yang perlu diantarkan ke lokasi ini\n");
        }
        else {
            int addUang = HARGA(*s);
            popStack(s, &delStackItem);
            deleteAtIP(pl, idx, &delProgressItem);
            ChangeUang(u, addUang);
            printf("Pesanan %c berhasil diantarkan\n", dropoff_item.type);
            printf("Uang yang didapatkan: %d yen\n", addUang);
        }
    }
}