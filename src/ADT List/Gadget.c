#include <String.h> // lagi dicari alternatif buat strcpy
#include "Gadget.h"

void CreateGadget(struct Gadget *G, int ID) {
    ID(*G) = ID;
    if (ID == 1) {
        strcpy(NAME(*G), "Kain Pembungkus");
        PRICE(*G) = 800;
    } else if (ID == 2) {
        strcpy(NAME(*G), "Senter Pembesar");
        PRICE(*G) = 1200;
    } else if (ID == 3) {
        strcpy(NAME(*G), "Pintu Kemana Saja");
        PRICE(*G) = 1500;
    } else if (ID == 4) {
        strcpy(NAME(*G), "Mesin Waktu");
        PRICE(*G) = 3000;
    } else if (ID == 5) {
        strcpy(NAME(*G), "Senter Pengecil");
        PRICE(*G) = 800;
    } 
}

void CreateAvailableGadget(AvailableGadget *AG) {
    int i;
    for (i=0; i<CAPACITY; i++) {
        CreateGadget(&ELMT(*AG, i), i+1);
    }
}


void displayGadget(struct Gadget G, int i) {
    printf("%d. %s (%d Yen)\n", i, NAME(G), PRICE(G));
}

void displayAvailableGadget(AvailableGadget AG) {
    int i;
    for (i=0; i<CAPACITY; i++) {
        displayGadget((AG).Buffer[i], i+1);
    }
}