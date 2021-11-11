#include <stdio.h>
#include "ADT Lain/UangWaktu.h"
#include "ADT List/InventoryGadget.h"
#include "ADT List/Gadget.h"
#include "ADT Lain/UangWaktu.c"
#include "ADT List/InventoryGadget.c"
#include "ADT List/Gadget.c"

int main() {
    UangWaktu c;
    AvailableGadget g;
    InventoryGadget IG;
    struct Gadget G;
    int ID;
    CreateUangWaktu(&c);
    CreateAvailableGadget(&g);
    CreateInventoryGadget(&IG);
    printf("Uang anda sekarang: %d Yen\n", UANG(c));
    printf("Gadget yang tersedia: \n");
    displayAvailableGadget(g);
    printf("Gadget mana yang ingin kamu beli? (ketik 0 jika ingin kembali)\n");
    scanf("%d", &ID);
    if(ID == 0) {
        printf("Anda tidak jadi membeli gadget\n");
    } else if (ID > 5 || ID < 0) {
        printf("Nomor yang anda masukkan tidak tepat!\n");
    } else {
        CreateGadget(&G, ID);
        if(PRICE(G) <= UANG(c)) {
            if(NEFF(IG) < 5) {
                ChangeUang(&c, PRICE(G) * -1);
                addGadget(&IG, G);
                printf("%s berhasil dibeli!\n", NAME(G));
                printf("Uang anda sekarang: %d Yen\n", UANG(c));
            } else {
                printf("Inventory anda sudah penuh\n");
            }

        } else {
            printf("Uang anda tidak cukup untuk membeli gadget!\n");
        }
    }
    return 0;
}