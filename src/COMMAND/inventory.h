#ifndef INVENTORY_H
#define INVENTORY_H

#include "../ADT Lain/UangWaktu.h"
#include "../ADT Linked List/inprogressList.h"
#include "../ADT Linked List/inprogressNode.h"
#include "../ADT Linked List/todoNode.h"
#include "../ADT List/adjList.h" 
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
#include "../boolean.h"

void inventory(InventoryGadget *IG, in_progress_list *ipl, Stack *s, UangWaktu *c, Coordinate *src, map m, adjMatrix A);

#endif