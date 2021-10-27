#ifndef TODOQUEUE_H
#define TODOQUEUE_H

#include "../boolean.h"
#include "todoNode.h"

#define IDX_UNDEF (-1)

typedef struct {
    Address head;
    Address tail;
} Queue;

/* SELEKTOR */
#define HEAD(q) (q).head
#define TAIL(q) (q).tail

/**** KREATOR ****/
void CreateQueue(Queue *q);
/* Membuat sebuah Queue kosong */
/* NEXTHEAD bernilai NULL */
/* NEXTTAIL bernilai NULL */

/**** TEST QUEUE KOSONG ****/
boolean isEmpty(Queue q);
/* Mengirim true jika queue kosong */

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, toDoList val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, toDoList *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

/**** Display Queue ****/
void displayQueue(Queue q);
/* I.S. q boleh kosong */
/* F.S. Output q sesuai dengan contoh */

/* *** Display To Do List *** */
void displayToDo(Queue q, int time);
/* I.S. q boleh kosong */
/* F.S. Output to do list sesuai dengan time yang dimasukkan */

#endif
