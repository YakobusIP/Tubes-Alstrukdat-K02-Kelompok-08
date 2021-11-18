#include <stdio.h>
#include "adjMatriks.h"
#include "map.h"
#include "../ADTList/adjList.h"

int main(){
    adjMatrix A;
    adjList l;
    CreateAdjList(&l);
    Coordinate C, D, E, Mobita, F;
    map M;
    Mobita = *CreateCoord('8', 1, 9);
    C = *CreateCoord('C', 1, 5);
    D = *CreateCoord('D', 7, 3);
    E = *CreateCoord('E', 15, 5);
    CreateMap(&M, 20, 20); 
    ReadMap(&M, &Mobita);
    ReadMap(&M, &C);
    ReadMap(&M, &D);
    ReadMap(&M, &E);

    
    //F = *CoordByName(M, 'E');
   // DisplayCoord(F);
    printf("\n");

    createAdjMatrix(&A);
    ReadAdjMatrix(&A);
    DisplayMap(M, A, Mobita);
    DisplayAdjMatrix(A);
    AdjList(M, &l, A, '8');
    DisplayAdjList(l);
    return 0;
}