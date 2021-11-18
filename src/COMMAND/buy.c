#include <stdio.h>
#include "buy.h"

void buy(UangWaktu *c, AvailableGadget AG, InventoryGadget *IG, Gadget G) {
    int ID;
    ID = 0;
    printf("Uang anda sekarang: %d Yen\n", UANG(*c));
    printf("Gadget yang tersedia: \n");
    displayAvailableGadget(AG);
    printf("Gadget mana yang ingin kamu beli? (ketik 0 jika ingin kembali)\n");
    ID = readNumberfromSTDIN();
    if(ID == 0) {
        printf("Anda tidak jadi membeli gadget\n");
    } else if (ID > 5 || ID < 0) {
        printf("Nomor yang anda masukkan tidak tepat!\n");
    } else {
        CreateGadget(&G, ID);
        if(G.Price <= UANG(*c)) {
            if(NEFF(*IG) < 5) {
                ChangeUang(c, G.Price * -1);
                addGadget(IG, G);
                printf("%s berhasil dibeli!\n", G.Name);
                printf("Uang anda sekarang: %d Yen\n", UANG(*c));
            } else {
                printf("Inventory anda sudah penuh\n");
            }

        } else {
            printf("Uang anda tidak cukup untuk membeli gadget!\n");
        }
    }
}