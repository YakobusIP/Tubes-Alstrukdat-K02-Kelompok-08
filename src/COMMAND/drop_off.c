/* COMMAND UNTUK DROP OFF,
notes : identifikasi lokasi perlu penyesuaian lagi mau gimana,
reward belum aktif */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT Linked List/todoQueue.h"
#include "../ADT Stack/stack.h"
#include "../ADT Lain/UangWaktu.h"

void drop_off(PrioQueue *q, Stack *s, char currentLocation, UangWaktu *u) {
    toDoList dropoff_item;
    char type_item;
    ElType val;

    // akses items dengan identifikasi effect agar lebih mudah dibanding mengcompare nama
    if (EFFECT(*s) == IDX_UNDEF) {type_item = 'N';}
    else if (EFFECT(*s) == 1) {type_item = 'H';}
    else if (EFFECT(*s) == 2) {type_item = 'P';}
    else if (EFFECT(*s) == 3) {type_item = 'V';}

    Address p = HEAD(*q);
    boolean found = false;
    do {
        if (INFO(p).type = type_item) {
            dropoff_item = INFO(p);
            found = true;
        }
        else {
            p = NEXT(p);
        }
    } while (p != NULL && !found);

    /* Cek dulu apakah lokasi dropoff item tumpukan teratas sesuai dengan lokasi sekarang */
    if (dropoff_item.dropOff != currentLocation) {
        printf("Tidak ada pesanan yang perlu diantarkan ke lokasi ini\n");
    }
    else {
        pop(s, &val);
        if (val == 1) {
            ChangeUang(u, 200);
        } else if (val == 2) {
            ChangeUang(u, 400);
        } else if (val == 3) {
            ChangeUang(u, 400);
        } else if (val == 4) {
            ChangeUang(u, 600);
        }
        printf("Pesanan %c berhasil diantarkan\n", dropoff_item.type);
        printf("Uang yang didapatkan: %d yen");
    }

}