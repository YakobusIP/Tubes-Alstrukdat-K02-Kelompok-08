/* Mobita dapat memiliki 2 gadget yang sama sekaligus
selama masih ada slot di inventory */

#include <stdio.h>
#include "InventoryGadget.h"

void CreateInventoryGadget(InventoryGadget *IG) {
    NEFF(*IG) = 0;
}

int getLastIdx(InventoryGadget IG) {
    return NEFF(IG)-1;
}

boolean isFull(InventoryGadget IG) {
    return NEFF(IG) == CAPACITY;
}

boolean isEmpty(InventoryGadget IG) {
    return NEFF(IG) == 0;
}

int indexOf(InventoryGadget IG, Gadget G) {
    boolean found = false;
    int i = 0;
    while (i <= getLastIdx(IG) && !found) {
        if (ELMT(IG, i).ID == G.ID) {
            found = true;
        } else {
            i++;
        }
    }
    return found ? i : -1;
}

boolean isInInventory (InventoryGadget IG, Gadget G) {
    return indexOf(IG, G) != -1;
}

void addGadget(InventoryGadget *IG, Gadget G) {
    ELMT(*IG, NEFF(*IG)) = G;
    NEFF(*IG)++;
}

void deleteGadget(InventoryGadget *IG, Gadget G) {
    int i;
    for (i=indexOf(*IG,G); i<getLastIdx(*IG); i++) {
        ELMT(*IG,i) = ELMT(*IG,i+1);
    }
    NEFF(*IG)--;
}

void displayInventory (InventoryGadget IG) {
    int i;
    for (i=0; i<=getLastIdx(IG); i++) {
        displayGadget(ELMT(IG, i), i+1);
    }
    for (i=getLastIdx(IG)+1; i<CAPACITY; i++) {
        printf("%d. -\n", i+1);
    }
}

void displayInventoryWithPrice (InventoryGadget IG) {
    int i;
    for (i=0; i<=getLastIdx(IG); i++) {
        displayGadgetWithPrice(ELMT(IG, i), i+1);
    }
    for (i=getLastIdx(IG)+1; i<CAPACITY; i++) {
        printf("%d. -\n", i+1);
    }
}