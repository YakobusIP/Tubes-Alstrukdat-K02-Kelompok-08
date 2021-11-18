/* File : Gadget.h */
/* Definisi ADT Gadget*/

#ifndef GADGET_H
#define GADGET_H

#include "../boolean.h"
#include "../ADT Mesin Kata/tokenmachine.h"

#define CAPACITYGADGET 5

typedef struct {
    int ID;             // ID Gadget untuk mempermudah akses elemen
    char Name[25];
    int Price;
    // Akses Effect pada command menggunakan ID
} Gadget;

typedef struct {
    Gadget Buffer[CAPACITYGADGET]; /* tabel penyimpan gadget yang tersedia pada sistem */
} AvailableGadget;

/* *** Selektor *** */
#define ID(G) (G).ID
#define NAME(G) (G).Name
#define PRICE(G) (G).Price
#define ELMT(AG, i) (AG).Buffer[(i)]

void CreateGadget(Gadget *G, int ID);

void CreateAvailableGadget(AvailableGadget *AG);

void displayGadget(Gadget G, int i);

void displayGadgetWithPrice(Gadget G, int i);

void displayAvailableGadget(AvailableGadget AG);

#endif