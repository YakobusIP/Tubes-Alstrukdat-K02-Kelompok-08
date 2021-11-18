#ifndef ADJLIST_H
#define ADJLIST_H

#include <stdlib.h>
#include "../boolean.h"
#include "../ADT Point/point.h"
#include "../ADT Matriks/map.h"
#include "../ADT Matriks/adjMatriks.h"


typedef struct {
    Coordinate *contents[18];
} adjList;

#define ElmtPointer(l, i) (l).contents[(i)]

void CreateAdjList(adjList *l);
void AdjList(map m, adjList *l, adjMatrix A, char vertexName);
int lengthAdjList (adjList l);
void insertLastAdjList(map m, adjList *l, char val);
boolean isEmptyAdjList(adjList l);
void DisplayAdjList(adjList l);
boolean isIdxValid(adjList l, int i);
boolean isIdxEff(adjList l, int i);

#endif
