#include "Gadget.h"
#include <stdio.h>

void CreateGadget(Gadget *G, int ID) {
    ID(*G) = ID;
    if (ID == 1) {
        // copyString(variable, string)
        copyString(NAME(*G), "Kain Pembungkus Waktu");
        PRICE(*G) = 800;
    } else if (ID == 2) {
        copyString(NAME(*G), "Senter Pembesar");
        PRICE(*G) = 1200;
    } else if (ID == 3) {
        copyString(NAME(*G), "Pintu Kemana Saja");
        PRICE(*G) = 1500;
    } else if (ID == 4) {
        copyString(NAME(*G), "Mesin Waktu");
        PRICE(*G) = 3000;
    } else if (ID == 5) {
        copyString(NAME(*G), "Senter Pengecil");
        PRICE(*G) = 800;
    } 
}

void CreateAvailableGadget(AvailableGadget *AG) {
    int i;
    for (i=0; i<CAPACITYGADGET; i++) {
        CreateGadget(&ELMT(*AG, i), i+1);
    }
}


void displayGadget(Gadget G, int i) {
    printf("%d. %s\n", i, NAME(G));
}

void displayGadgetWithPrice(Gadget G, int i) {
    printf("%d. %s (%d Yen)\n", i, NAME(G), PRICE(G));
}

void displayAvailableGadget(AvailableGadget AG) {
    int i;
    for (i=0; i<CAPACITYGADGET; i++) {
        displayGadgetWithPrice((AG).Buffer[i], i+1);
    }
}