#include "inventory.h"
#include <stdio.h>

void inventory(inProgressList l, Stack s, map m,  UangWaktu c){
    AvailableGadget AG;
    InventoryGadget IG;
    CreateAvailableGadget(&AG);
    displayAvailableGadget(AG);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    adv();
    readCommand();
    readNumberfromChar();
}