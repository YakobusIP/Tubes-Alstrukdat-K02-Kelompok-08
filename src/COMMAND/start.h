#ifndef START_H
#define START_H

#include "../boolean.h"
#include "../ADT Queue/requestList.h"
#include "../ADT Matriks/adjMatriks.h"
#include "../ADT Matriks/map.h"
#include "../ADT Mesin Kata/charmachine.h"
#include "../ADT Mesin Kata/tokenmachine.h"
#include "../ADT Point/point.h"

void start_game(PrioQueue *q, map *M, adjMatrix *A);

void mainMenu();

void delay(int number_of_seconds);

#endif