#ifndef PICK_UP_H
#define PICK_UP_H

#include "../ADT Queue/requestList.h"
#include "../ADT Stack/stack.h"
#include "../ADT Lain/UangWaktu.h"
#include "../ADT Linked List/inprogressList.h"
#include "../ADT Linked List/todoList.h"

boolean foundVIP(to_do_List l);
/* Mengecek apakah ada item VIP di To Do List */

void foundPickupInLoc(to_do_List *l, char currentLocation, boolean *found, int *val, toDoList *pickup_item);
/* Mengecek apakah ada pesanan yang harus di pick-up di currentLocation */

void pick_up(to_do_List *tdl, Stack *s, in_progress_list *pl, char currentLocation, int *addMoveTime);
/* Melakukan pickup item di lokasi sekarang jika ada pesanan */

#endif
