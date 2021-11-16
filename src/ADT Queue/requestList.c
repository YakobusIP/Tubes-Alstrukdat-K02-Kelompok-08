#include <stdio.h>
#include "requestList.h"
#include "../boolean.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    /* ALGORITMA */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isQueueEmpty(PrioQueue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    /* ALGORITMA */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isQueueFull(PrioQueue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* ALGORITMA */
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITYREQUESTLIST-1));
}

int length(PrioQueue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* KAMUS */
    int length = 0;
    /* ALGORITMA */
    if (isQueueEmpty(q)) {
        length = 0;
    } else {
        length = (IDX_TAIL(q) - IDX_HEAD(q)) + 1;
    }
    return length;
}

/* *** Primitif Add/Delete *** */
void enqueueRL(PrioQueue *q, requestList val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS */
    int i,j;
    /* ALGORITMA */
    if (isQueueEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        // Jika reqIn head awal lebih besar daripada reqIn baru, maka insert val di awal PrioQueue
        if (HEAD(*q).reqIn > val.reqIn) {
            // Jika index head awal sudah 0, lakukan penggeseran 1 elemen ke kanan
            if (IDX_HEAD(*q) == 0) {
                for(i=IDX_HEAD(*q);i<IDX_TAIL(*q);i++) {
                    (*q).buffer[i+1] = (*q).buffer[i];
                }
                IDX_TAIL(*q)++;
                // Tambah elemen ke depan queue
                HEAD(*q) = val;
            } else {
                IDX_HEAD(*q)--;
                HEAD(*q) = val;
            }
        } else {
            i = IDX_HEAD(*q);
            while ((i <= IDX_TAIL(*q)) && ((*q).buffer[i].reqIn <= val.reqIn)) {
                i++;
            }
            // Penggeseran elemen ke kanan
            if (i != IDX_TAIL(*q)+1) {
                for(j=IDX_TAIL(*q)+1;j>i;j--) {
                    (*q).buffer[j] = (*q).buffer[j-1];
                }
            }
            (*q).buffer[i] = val;
            IDX_TAIL(*q)++;
        }
    }
        
}

void dequeue(PrioQueue *q, requestList *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    /* ALGORITMA */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

/* *** Display Queue *** */
void displayQueue(PrioQueue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    /* KAMUS */
    int i,j;
    requestList val;
    /* ALGORITMA */
    printf("Pesanan yang masuk ke sistem: \n");
    if (isQueueEmpty(q)) {
        printf("Tidak ada pesanan yang masuk");
    } else {
        j = 1;
        for (i=IDX_HEAD(q);i<=IDX_TAIL(q);i++) {
            printf("%d. ", j);
            j++;
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
            } else if (val.type == 'P') {
                printf("Perishable Item, sisa waktu %d", val.timeLimit);
            }
            printf("\n");
        }
    }
    
}