#ifndef BUY_H
#define BUY_H

#include "../ADT Lain/UangWaktu.h"
/* #include "../src/ADT Linked List/inprogressList.h"
#include "../src/ADT Linked List/inprogressNode.h"
#include "../src/ADT Linked List/todoNode.h"
#include "../src/ADT List/adjList.h"
#include "../src/ADT Linked List/todoQueue.h" */
#include "../ADT List/Gadget.h"
#include "../ADT List/InventoryGadget.h"
#include "../ADT Matriks/adjMatriks.h"
#include "../ADT Matriks/map.h"
#include "../ADT Mesin Kata/charmachine.h"
#include "../ADT Mesin Kata/tokenmachine.h"
#include "../ADT Point/point.h"
#include "../ADT Stack/stack.h"
#include "../ADT Queue/requestList.h"
#include "../pcolor/pcolor.h"

#include "../ADT Lain/UangWaktu.c"
/* #include "../src/ADT Linked List/inprogressList.h"
#include "../src/ADT Linked List/inprogressNode.h"
#include "../src/ADT Linked List/todoNode.h"
#include "../src/ADT List/adjList.h"
#include "../src/ADT Linked List/todoQueue.h" */
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

void buy(UangWaktu c, AvailableGadget AG, InventoryGadget IG, struct Gadget G);

#endif