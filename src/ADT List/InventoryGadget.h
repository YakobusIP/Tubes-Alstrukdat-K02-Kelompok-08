/* File : InventoryGadget.h */
/* Definisi ADT InventoryGadget
(penyimpanan Gadget yang dimiliki Mobita)
dengan representasi array static rapat kiri*/

#ifndef INVENTORYGADGET_H
#define INVENTORYGADGET_H

#include "../boolean.h"
#include "Gadget.h"

#define CAPACITY 5

typedef struct{
    struct Gadget Buffer[CAPACITY];
    int NEFF;
} InventoryGadget;


/* ********* AKSES (Selektor) ********* */
// #define ELMT(IG, i) (IG).Buffer[(i)]
#define NEFF(IG) (IG).NEFF

/* *** Konstruktor*** */
void CreateInventoryGadget(InventoryGadget *IG);
/* I.S. sembarang; */
/* F.S. InventoryGadget teralokasi dengan NEFF = 0 */

int getLastIdx(InventoryGadget IG) {
    return NEFF(IG)-1;
}

boolean isFull(InventoryGadget IG);
/* mereturn True jika Inventory penuh, NEFF=CAPACITY */

boolean isEmpty(InventoryGadget IG);
/* mereturn True jika Inventory kosong, NEFF=0 */

int indexOf(InventoryGadget IG, struct Gadget G);
/* Mereturn index dimana G dipertemukan pertama kali pada inventory ,
jika tidak ada return -1 */

boolean isInInventory (InventoryGadget IG, struct Gadget G);
/* Mereturn True jika Gadget G tersedia dalam inventory */

/* *** Operasi Pada Inventory*** */
void addGadget(InventoryGadget *IG, struct Gadget G);
/* I.S. Inventory tidak penuh */
/* F.S. Gadget G ditambahkan ke Inventory */

void deleteGadget(InventoryGadget *IG, struct Gadget G);
/* I.S. Inventory tidak kosong, G valid ada pada inventory */
/* F.S. Gadget G dihapus dari Inventory */

void displayInventory (InventoryGadget IG);
/* Menampilkan daftar Gadget pada inventory */


#endif