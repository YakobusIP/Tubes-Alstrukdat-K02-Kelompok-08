#ifndef SAVE_H
#define SAVE_H

#include "../boolean.h"
#include "../ADT Lain/UangWaktu.h"
#include "../ADT Lain/Ability.h"
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

void save(map m, adjMatrix adjM, to_do_List tdl, UangWaktu u, Coordinate Mobita, Stack s, InventoryGadget IG, int itemCounter, int waktu, Ability ability, in_progress_list IPL);

#endif