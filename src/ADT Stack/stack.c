#include "../boolean.h"
#include <stdio.h>
#include "stack.h"

void CreateStack(Stack *s){
    IDX_TOP(*s) = IDX_UNDEF;
    MAKSIMUM(*s) = 3;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmpty(Stack s){
    return IDX_TOP(s) == IDX_UNDEF;
}
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFull(Stack s){
    return IDX_TOP(s) == MAKSIMUM(s)-1;
}
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElType val){
    (IDX_TOP(*s))++;
    if(val == 1) {
        PRICE(*s) = 1000;
    }
    
}
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ElType *val){
    *val = TOP(*s);
    (IDX_TOP(*s))--;
}
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */