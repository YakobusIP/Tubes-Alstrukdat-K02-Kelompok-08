#ifndef MOVE_H
#define MOVE_H

#include "../ADT Point/point.h"
#include "../ADT Matriks/map.h"
#include "../ADT Matriks/adjMatriks.h"
#include "../ADT List/adjList.h"
#include "../ADT Lain/UangWaktu.h"
#include "../ADT Mesin Kata/tokenmachine.h"
#include "../ADT Lain/ability.h"
#include "../ADT Stack/stack.h"

void move(Stack *s, in_progress_list *IPL, Coordinate *src, map m, adjMatrix A, UangWaktu *u, Ability *ability, int *waktu);
#endif
