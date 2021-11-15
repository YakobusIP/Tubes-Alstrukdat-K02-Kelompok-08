#include <stdio.h>
#include "inprogressList.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateInProgressList(in_progress_list *l) {
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG DAN PANJANG LIST ******************/
boolean isIPListEmpty(in_progress_list l) {
/* Mengirim true jika list kosong */
    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

int lengthIPL(in_progress_list l) {
/* Mengirim panjang list, 0 jika kosong */
    /* ALGORITMA */
    ipAddress p;
    p = FIRST(l);
    int i = 0;
    while (p != NULL) {
        i++;
        p = NEXT(p);
    }
    return i;
}

/****************** GETTER SETTER ******************/
inProgressList getElmtIP(in_progress_list l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS */
    ipAddress p;
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

void setElmtIP(in_progress_list *l, int idx, inProgressList val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS */
    ipAddress p;
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
void insertFirstIP(in_progress_list *l, inProgressList val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    ipAddress p;
    /* ALGORITMA */
    p = newInProgressNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLastIP(in_progress_list *l, inProgressList val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */   
    /* KAMUS */
    ipAddress p, prev;
    /* ALGORITMA */
    if (isIPListEmpty(*l)) {
        insertFirstIP(l, val);
    } else {
        p = newInProgressNode(val);
        if (p != NULL) {
            prev = FIRST(*l);
            while (NEXT(prev) != NULL) {
                prev = NEXT(prev);
            }
            NEXT(prev) = p;
        } 
    }
}

void insertAtIP(in_progress_list *l, inProgressList val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */    
    /* KAMUS */
    ipAddress p, prev;
    int i;
    /* ALGORITMA */
    if (idx == 0) {
        insertFirstIP(l, val);
    } else {
        p = newInProgressNode(val);
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
void deleteFirstIP(in_progress_list *l, inProgressList *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    ipAddress p;
    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
}

void deleteLastIP(in_progress_list *l, inProgressList *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    ipAddress p, prev;
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

void deleteAtIP(in_progress_list *l, int idx, inProgressList *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS */
    ipAddress p, prev;
    int i;
    /* ALGORITMA */
    if (idx == 0) {
        deleteFirstIP(l, val);
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
void displayInProgress(in_progress_list l) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */    
    /* KAMUS */
    ipAddress p;
    int i;
    char typeCheck;
    /* ALGORITMA */
    i = 1;
    printf("Pesanan yang sedang diantarkan:\n");
    p = FIRST(l);
    while (p != NULL) {
        printf("%d. ", i);
        i++;
        typeCheck = INFO(p).type;

        if (typeCheck == 'N') {
            printf("Normal Item");
        } else if (typeCheck == 'H') {
            printf("Heavy Item");
        } else if (typeCheck == 'P') {
            printf("Perishable Item");
        } else if (typeCheck == 'V') {
            printf("VIP Item");
        }

        printf("(Tujuan: %c)", INFO(p).dropOff);
        printf("\n");
        p = NEXT(p);
    }
}