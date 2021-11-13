/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

struct items {
    char name[20];
    int price;
    int effect;
    char type[20]; // Untuk mengidentifikasi item
    char reward[20];
};
typedef int ElType;
typedef struct {
  int CapacityNow;
  struct items buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define MAKSIMUM(s) (s).CapacityNow
#define TOP(s) (s).buffer[(s).idxTop]
#define NAMA(s) (s).buffer[(s).idxTop].name
#define HARGA(s) (s).buffer[(s).idxTop].price
#define TYPE(s) (s).buffer[(s).idxTop].type
#define EFFECT(s) (s).buffer[(s).idxTop].effect
#define REWARD(s) (s).buffer[(s).idxTop].reward

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullStack(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, int val); // Time berguna untuk perishable items, jika bukan, isi dengan 0
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack *s, struct items *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

#endif