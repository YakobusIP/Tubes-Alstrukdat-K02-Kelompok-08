#ifndef TODOQUEUE_H
#define TODOQUEUE_H

#include "../boolean.h"
#include "todoNode.h"

#define IDX_UNDEF (-1)

typedef struct {
    Address head;
    Address tail;
} PrioQueue;

/* SELEKTOR */
#define HEAD(q) (q).head
#define TAIL(q) (q).tail

/**** KREATOR ****/
void CreatePrioQueue(PrioQueue *q);
/* Membuat sebuah PrioQueue kosong */
/* NEXTHEAD bernilai NULL */
/* NEXTTAIL bernilai NULL */

/**** TEST PrioQueue KOSONG ****/
boolean isEmpty(PrioQueue q);
/* Mengirim true jika PrioQueue kosong */

int length(PrioQueue q);
/* Mengirimkan banyaknya elemen PrioQueue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueToDo(PrioQueue *q, toDoList val, int time);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void enqueueFull(PrioQueue *q, toDoList val);


void dequeue(PrioQueue *q, toDoList *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

/**** Display PrioQueue ****/
void displayQueue(PrioQueue q);
/* I.S. q boleh kosong */
/* F.S. Output q sesuai dengan contoh */

/* *** Display To Do List *** */
void displayToDo(PrioQueue q);
/* I.S. q boleh kosong */
/* F.S. Output to do list sesuai dengan time yang dimasukkan */

#endif
