#include <stdio.h>
#include <stdlib.h>
#include "todoQueue.h"

/**** KREATOR ****/
void CreateQueue(Queue *q) {
/* Membuat sebuah Queue kosong */
/* NEXTHEAD bernilai NULL */
/* NEXTTAIL bernilai NULL */    
    /* ALGORITMA */
    HEAD(*q) = NULL;
    TAIL(*q) = NULL;
}

/**** TEST QUEUE KOSONG ****/
boolean isEmpty(Queue q) {
/* Mengirim true jika queue kosong */
    /* ALGORITMA */
    return ((HEAD(q) == NULL) && (TAIL(q) == NULL));
}

int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */ 
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
void enqueue(Queue *q, toDoList val) {
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
        // Jika reqIn head awal lebih besar daripada reqIn baru, maka insert node di awal queue
        if (INFO(o).reqIn > val.reqIn) {
            NEXT(p) = HEAD(*q);
            PREV(HEAD(*q)) = p;
            HEAD(*q) = p;
        } else {
            // Mencari posisi penyisipan elemen ke dalam queue
            while ((NEXT(o) != NULL) && (INFO(NEXT(o)).reqIn <= val.reqIn)) {
                o = NEXT(o);
            }

            // Penyisipan elemen (insertAt)
            NEXT(p) = NEXT(o);
            PREV(p) = o;
            NEXT(o) = p;
            PREV(NEXT(o)) = p;
            TAIL(*q) = NEXT(p);
        }
    }
    // MASIH ERROR KALAU NILAI REQIN SAMA, DIA INPUTNYA KEBALIK 
        
}

void dequeue(Queue *q, toDoList *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD queue, HEAD mundur; 
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
        PREV(HEAD(*q)) = NULL;
    }
}


/**** Display Queue ****/
void displayQueue(Queue q) {
/* I.S. q boleh kosong */
/* F.S. Output q sesuai dengan contoh */
    /* KAMUS */
    int i;
    toDoList val;
    /* ALGORITMA */
    i = 1;
    printf("Pesanan pada To Do List:");
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

/**** Display To Do List ****/
void displayToDo(Queue q, int time) {
/* I.S. q boleh kosong */
/* F.S. Output to do list sesuai dengan time yang dimasukkan */
    /* KAMUS */
    int i;
    Address p;
    toDoList val;
    /* ALGORITMA */
    i = 1;
    p = HEAD(q);
    while ((p != NULL) && (INFO(p).reqIn <= time)) {
        printf("%d. ", i);
        i++;
        val = INFO(p);
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
        p = NEXT(p);
    }
}