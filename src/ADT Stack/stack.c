#include "../boolean.h"
#include <stdio.h>
#include "stack.h"
#include <string.h>

void CreateStack(Stack *s){
    MAKSIMUM(*s) = 3;
    IDX_TOP(*s) = IDX_UNDEF;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s){
    return IDX_TOP(s) == IDX_UNDEF;
}
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullStack(Stack s){
    return IDX_TOP(s) == MAKSIMUM(s)-1;
}
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, int val){
    (IDX_TOP(*s))++;
    if(val == 1){
        copyString(NAMA(*s), "Normal Item");
        HARGA(*s) = 200;
        EFFECT(*s) = IDX_UNDEF;
        copyString(TYPE(*s), "N");
        copyString(REWARD(*s), "");
    }else if(val == 2){
        copyString(NAMA(*s), "Heavy Item");
        HARGA(*s) = 400;
        EFFECT(*s) = 1;
        copyString(TYPE(*s), "H");
        copyString(REWARD(*s), "Speed Boost");
    }else if(val == 3){
        copyString(NAMA(*s), "Perishable Item");
        HARGA(*s) = 400;
        EFFECT(*s) = 2;
        copyString(TYPE(*s), "P");
        copyString(REWARD(*s), "Increase Capacity");
    }else if(val == 4){
        copyString(NAMA(*s), "VIP Item");
        HARGA(*s) = 600;
        EFFECT(*s) = 3;
        copyString(TYPE(*s), "V");
        copyString(REWARD(*s), "Return To Sender");
    }
    
}
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack *s, struct items *val){
    *val = TOP(*s);
    (IDX_TOP(*s))--;
}
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */