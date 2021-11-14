#include <stdio.h>
#include "todoList.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateToDoList(to_do_List *l) {
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isListEmpty(to_do_List l) {
/* Mengirim true jika list kosong */
    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
toDoList getElmtTD(to_do_List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS */
    Address p;
    int i;
    /* ALGORITMA */
    p = FIRST(l);
    i = 0;
    while (i < idx) {
        i++;
        p = NEXT(p);
    }
    return (INFO(p));
}


void setElmtTD(to_do_List *l, int idx, toDoList val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS */
    Address p;
    int i;
    /* ALGORITMA */
    p = FIRST(*l);
    i = 0;
    while (i < idx) {
        i++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstTD(to_do_List *l, toDoList val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLastTD(to_do_List *l, toDoList val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */   
    /* KAMUS */
    Address p, prev;
    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            prev = FIRST(*l);
            while (NEXT(prev) != NULL) {
                prev = NEXT(prev);
            }
            NEXT(prev) = p;
        } 
    }
}

void insertAtTD(to_do_List *l, toDoList val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */    
    /* KAMUS */
    Address p, prev;
    int i;
    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            prev = FIRST(*l);
            i = 0;
            while (i < (idx-1)) {
                i++;
                prev = NEXT(prev);
            }
            NEXT(p) = NEXT(prev);
            NEXT(prev) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstTD(to_do_List *l, toDoList *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
}

void deleteLastTD(to_do_List *l, toDoList *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    Address p, prev;
    /* ALGORITMA */
    p = FIRST(*l);
    prev = NULL;
    while (NEXT(p) != NULL) {
        prev = p;
        p = NEXT(p);
    }
    if (prev == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(prev) = NULL;
    }
    *val = INFO(p);
}

void deleteAtTD(to_do_List *l, int idx, toDoList *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS */
    Address p, prev;
    int i;
    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        i = 0;
        prev = FIRST(*l);
        while (i < (idx-1)) {
            i++;
            prev = NEXT(prev);
        }
        p = NEXT(prev);
        *val = INFO(p);
        NEXT(prev) = NEXT(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayToDo(to_do_List l) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */   
    /* KAMUS */
    int i;
    toDoList val;
    /* ALGORITMA */
    i = 1;
    printf("Pesanan pada To Do List:\n");
    while (length(l) > 0) {
        printf("%d. ", i);
        i++;
        deleteFirst(&l, &val);
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
