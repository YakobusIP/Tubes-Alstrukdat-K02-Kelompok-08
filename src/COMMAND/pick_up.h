#ifndef PICK_UP_H
#define PICK_UP_H

#include "../ADT Lain/UangWaktu.h"
#include "../ADT Linked List/inprogressList.h"
#include "../ADT Linked List/inprogressNode.h"
#include "../ADT Linked List/todoNode.h"
#include "../ADT Linked List/todoList.h"
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

boolean foundVIP(to_do_List l);
/* Mengecek apakah ada item VIP di To Do List */

void foundPickupInLoc(to_do_List *l, char currentLocation, boolean *found, int *val, int *idxTD, toDoList *pickup_item);
/* Mengecek apakah ada pesanan yang harus di pick-up di currentLocation */

void pick_up(to_do_List *tdl, Stack *s, in_progress_list *pl, char currentLocation, int *addMoveTime, UangWaktu *u);
/* Melakukan pickup item di lokasi sekarang jika ada pesanan */

#endif
