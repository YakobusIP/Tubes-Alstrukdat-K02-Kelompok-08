/* driver ADT Gadget dan Ivnetory Gadget */

#include <stdio.h>

#include "../ADT Lain/UangWaktu.c"
#include "../ADT Linked List/inprogressList.c"
#include "../ADT Linked List/inprogressNode.c"
#include "../ADT Linked List/todoNode.c"
#include "../ADT List/adjList.c" 
#include "../ADT List/Gadget.c"
#include "../ADT List/InventoryGadget.c"
#include "../ADT Matriks/adjMatriks.c"
#include "../ADT Matriks/map.c"
#include "../ADT Mesin Kata/charmachine.c"
#include "../ADT Mesin Kata/tokenmachine.c"
#include "../ADT Point/point.c"
#include "../ADT Stack/stack.c"
#include "../ADT Queue/requestList.c"
#include "../pcolor/pcolor.c"

int main() {
    AvailableGadget AG;
    InventoryGadget IG;
    CreateInventoryGadget(&IG);
    CreateAvailableGadget(&AG);

    printf("Berikut gadget yang tersedia pada sistem:\n");
    displayAvailableGadget(AG);
    printf("\n");
    
    // invetory masih kosong
    displayInventory(IG);
    printf("\n");

    addGadget(&IG, ELMT(AG, 2));    // menambahkan senter pembesar ke inventory
    addGadget(&IG, ELMT(AG, 3));    // menambahkan pintu kemana saja ke inventory
    printf("Inventory seletah ditambahkan gadget:\n");
    displayInventory(IG);
    deleteGadget(&IG, ELMT(AG, 2)); // menghapus senter pembesar dari inventory
    printf("Inventory setelah ada gadget yang dihapus:\n");
    displayInventoryWithPrice(IG);
    printf("%d %d\n", isEmpty(IG), isFull(IG));
}