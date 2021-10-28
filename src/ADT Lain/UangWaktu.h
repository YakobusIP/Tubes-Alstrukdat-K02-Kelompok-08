#ifndef UANGWAKTU_H
#define UANGWAKTU_H

#include "../boolean.h"

typedef struct{
    int waktu;
    int uang;
}UangWaktu;

/* ********* AKSES (Selektor) ********* */
#define UANG(u) (u).uang
#define WAKTU(u) (u).waktu

/* *** Konstruktor/Kreator *** */
void CreateUangWaktu(UangWaktu *u);
/* I.S. sembarang; */
/* F.S. Membuat UANG WAKTU u dengan kondisi sbb: */
/* - UANG bernilai 0 dan WAKTU bernilai 0 */
/* Proses : Melakukan alokasi, membuat sebuah u kosong */

boolean isUangValid(UangWaktu u, int uang);
/* Mengirim true jika UANG pada u ditambah uang >= 0 */

void ChangeUang(UangWaktu *u, int uang);
/* Mengubah UANG pada u sesuai dengan nilai uang */
/* I.S. uang mungkin negatif, yang berarti mobita berbelanja */
/* F.S. UANG mungkin bertambah atau UANG mungkin tetap jika UANG pada u
dikurangi uang < 0 */
void ChangeWaktu(UangWaktu *u, int waktu);
/* Mengubah WAKTU pada u sesuai dengan nilai waktu */
/* I.S. waktu diasumsikan lebih dari 0 */
/* F.S. WAKTU pada u bertambah sebesar waktu */

#endif
