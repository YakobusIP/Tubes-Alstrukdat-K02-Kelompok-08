#include <stdio.h>
#include <stdlib.h>
#include "adjList.h"

int main(){
    adjMatrix A;
    adjList l;
    CreateAdjList(&l);
    Coordinate C, D, E, Mobita, F;
    map M;
    Mobita = *CreateCoord('8', 1, 6);
    C = *CreateCoord('C', 1, 5);
    D = *CreateCoord('D', 7, 3);
    E = *CreateCoord('E', 15, 5);
    CreateMap(&M, 20, 20); 
    ReadMap(&M, &Mobita);
    ReadMap(&M, &C);
    ReadMap(&M, &D);
    ReadMap(&M, &E);

    createAdjMatrix(&A);
    ReadAdjMatrix(&A);
    DisplayAdjMatrix(A);
    AdjList(M, &l, A, '8');
    DisplayAdjList(l);
    return 0;
}