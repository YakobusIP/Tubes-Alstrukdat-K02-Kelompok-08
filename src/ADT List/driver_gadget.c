#include <stdio.h>
#include "Gadget.c"
#include "InventoryGadget.c"

int main() {
    AvailableGadget AG;
    CreateAvailableGadget(&AG);
    displayAvailableGadget(AG);
    printf("\n");
    InventoryGadget IG;
    CreateInventoryGadget(&IG);
    displayInventory(IG);
    printf("\n");
    addGadget(&IG, ELMT(AG, 2));    // menambahkan senter pembesar ke inventory
    addGadget(&IG, ELMT(AG, 3));    // menambahkan senter pembesar ke inventory
    displayInventory(IG);
    deleteGadget(&IG, ELMT(AG, 2));
    displayInventory(IG);
}