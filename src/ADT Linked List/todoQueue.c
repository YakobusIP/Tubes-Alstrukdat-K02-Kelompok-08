#include <stdio.h>
#include <stdlib.h>
#include "todoQueue.h"

/**** KREATOR ****/
void CreatePrioQueue(PrioQueue *q) {
/* Membuat sebuah PrioQueue kosong */
/* NEXTHEAD bernilai NULL */
/* NEXTTAIL bernilai NULL */    
    /* ALGORITMA */
    HEAD(*q) = NULL;
    TAIL(*q) = NULL;
}

/**** TEST PrioQueue KOSONG ****/
boolean isEmpty(PrioQueue q) {
/* Mengirim true jika PrioQueue kosong */
    /* ALGORITMA */
    return ((HEAD(q) == NULL) && (TAIL(q) == NULL));
}

int length(PrioQueue q) {
/* Mengirimkan banyaknya elemen PrioQueue. Mengirimkan 0 jika q kosong. */ 
    /* KAMUS */
    Address p;
    int len;
    /* ALGORITMA */
    p = HEAD(q);
    len = 0;
    while (p != NULL) {
        len++;
        p = NEXT(p);
    }
    return len;
}

/* *** Primitif Add/Delete *** */
// 
// UNSURE, CHECK BEFORE PUSH
//
void enqueueToDo(PrioQueue *q, toDoList val, int time) {
/* Proses: Menambahkan val pada q */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. Membentuk node baru diisi dengan val, lalu diinsert sesuai dengan nilai reqIn,
        mengecek apakah nilai reqIn pada val lebih kecil daripada time sekarang */ 
    /* KAMUS */
    Address o, p;
    toDoList temp;
    /* ALGORITMA */
    o = HEAD(*q);
    p = newNode(val);
    if (INFO(p).reqIn <= time) {
        if (isEmpty(*q)) {
            HEAD(*q) = p;
            TAIL(*q) = p;
        } else {
            // Jika reqIn head awal lebih besar daripada reqIn baru, maka insert node di awal PrioQueue
            if (INFO(o).reqIn > val.reqIn) {
                NEXT(p) = HEAD(*q);
                HEAD(*q) = p;
            } else {
                // Mencari posisi penyisipan elemen ke dalam PrioQueue
                while ((NEXT(o) != NULL) && (INFO(NEXT(o)).reqIn <= val.reqIn)) {
                    o = NEXT(o);
                }

                // Penyisipan elemen (insertAt)
                NEXT(p) = NEXT(o);
                NEXT(o) = p;
                TAIL(*q) = NEXT(p);
            }
        }  
    }
        
}

// 
// UNSURE, CHECK BEFORE PUSH
//
void enqueueFull(PrioQueue *q, toDoList val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. Membentuk node baru diisi dengan val, lalu diinsert sesuai dengan nilai reqIn  */ 
    /* KAMUS */
    Address o, p;
    toDoList temp;
    /* ALGORITMA */
    o = HEAD(*q);
    p = newNode(val);
    if (isEmpty(*q)) {
        HEAD(*q) = p;
        TAIL(*q) = p;
    } else {
        // Jika reqIn head awal lebih besar daripada reqIn baru, maka insert node di awal PrioQueue
        if (INFO(o).reqIn > val.reqIn) {
            NEXT(p) = HEAD(*q);
            HEAD(*q) = p;
        } else {
            // Mencari posisi penyisipan elemen ke dalam PrioQueue
            while ((NEXT(o) != NULL) && (INFO(NEXT(o)).reqIn <= val.reqIn)) {
                o = NEXT(o);
            }

            // Penyisipan elemen (insertAt)
            NEXT(p) = NEXT(o);
            NEXT(o) = p;
            TAIL(*q) = NEXT(p);
        }
    }
}

void dequeue(PrioQueue *q, toDoList *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD PrioQueue, HEAD mundur; 
        q mungkin kosong */    
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = HEAD(*q);
    *val = INFO(p);
    if (NEXT(p) == NULL) {
        HEAD(*q) = NULL;
    } else {
        HEAD(*q) = NEXT(p);
    }
}


/**** Display PrioQueue ****/
void displayQueue(PrioQueue q) {
/* I.S. q boleh kosong */
/* F.S. Output q sesuai dengan contoh */
    /* KAMUS */
    int i;
    toDoList val;
    /* ALGORITMA */
    i = 1;
    printf("Pesanan pada To Do List:\n");
    while (length(q) > 0) {
        printf("%d. ", i);
        i++;
        dequeue(&q, &val);
        printf("%d,", val.reqIn);
        printf("%c,", val.pickUp);
        printf("%c,", val.dropOff);

        if (val.type == 'N') {
            printf("Normal Item");
        } else if (val.type == 'H') {
            printf("Heavy Item");
        } else if (val.type == 'V') {
            printf("VIP Item");
        } else {
            printf("Perishable Item, sisa waktu %d", val.timeLimit);
        }
        printf("\n");
    }
}

/**** Display To Do List ****/
void displayToDo(PrioQueue q) {
/* I.S. q boleh kosong */
/* F.S. Output to do list sesuai dengan time yang dimasukkan */
    /* KAMUS */
    int i;
    toDoList val;
    /* ALGORITMA */
    i = 1;
    printf("Pesanan pada To Do List:\n");
    while (length(q) > 0) {
        printf("%d. ", i);
        i++;
        dequeue(&q, &val);
        printf("%c ", val.pickUp);
        printf("-> ");
        printf("%c ", val.dropOff);

        if (val.type == 'N') {
            printf("(Normal Item)");
        } else if (val.type == 'H') {
            printf("(Heavy Item)");
        } else if (val.type == 'V') {
            printf("(VIP Item)");
        } else {
            printf("(Perishable Item, sisa waktu %d)", val.timeLimit);
        }
        printf("\n");
    }
}