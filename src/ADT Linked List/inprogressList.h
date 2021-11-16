#ifndef INPROGRESSLIST_H
#define INPROGRESSLIST_H

#include "../boolean.h"
#include "inprogressNode.h"

typedef ipAddress in_progress_list;

#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void createInProgressList(in_progress_list *l);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG DAN PANJANG LIST ******************/
boolean isIPListEmpty(in_progress_list l);
/* Mengirim true jika list kosong */

int lengthIPL(in_progress_list l);
/* Mengirim panjang list, 0 jika kosong */

/****************** GETTER SETTER ******************/
inProgressList getElmtIP(in_progress_list l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtIP(in_progress_list *l, int idx, inProgressList val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstIP(in_progress_list *l, inProgressList val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastIP(in_progress_list *l, inProgressList val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtIP(in_progress_list *l, inProgressList val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstIP(in_progress_list *l, inProgressList *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastIP(in_progress_list *l, inProgressList *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtIP(in_progress_list *l, int idx, inProgressList *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

boolean isHeavyinIPL(in_progress_list l);
/* Fungsi mengembalikan true jika terdapat heavy item di dalam in progress list */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayInProgress(in_progress_list l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */    
#endif