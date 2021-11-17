#ifndef LOAD_H
#define LOAD_H

#include "../boolean.h"
#include "../ADT Lain/UangWaktu.h"
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

void load(PrioQueue *q, map *M, adjMatrix *A, boolean *failToLoad, UangWaktu *u, Coordinate *Mobita, Stack *s, InventoryGadget *IG, int *itemCounter, int *waktu, Ability *ability, in_progress_list *IPL);

#endif