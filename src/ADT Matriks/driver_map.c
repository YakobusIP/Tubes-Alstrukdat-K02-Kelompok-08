#include <stdio.h>
#include "map.h"
#include "adjMatriks.h"
#include "../ADTList/adjList.h"
int main()
{
    Coordinate A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, Mobita;
    map m;
    adjList l;
    adjMatrix Ad;
    CreateAdjList(&l);
    
    Mobita = *CreateCoord('8', 1, 6);
    A = *CreateCoord('A', 1, 20);
    B = *CreateCoord('B', 3, 9);
    C = *CreateCoord('C', 2, 3);
    D = *CreateCoord('D', 7, 3);
    E = *CreateCoord('E', 15, 5);
    F = *CreateCoord('F', 18, 16); 
    G = *CreateCoord('G', 12, 15); 
    H = *CreateCoord('H', 1, 11); 
    I = *CreateCoord('I', 2, 15); 
    J = *CreateCoord('J', 3, 4); 
    K = *CreateCoord('K', 4, 17); 
    L = *CreateCoord('L', 5, 4); 
    M = *CreateCoord('M', 6, 19); 
    N = *CreateCoord('N', 18, 3); 
    O = *CreateCoord('O', 19, 1); 
    P = *CreateCoord('P', 11, 7); 
    Q = *CreateCoord('Q', 16, 15); 
    CreateMap(&m, 20, 30); 
    ReadMap(&m, &Mobita);
    ReadMap(&m, &A);
    ReadMap(&m, &B);
    ReadMap(&m, &F);
    ReadMap(&m, &G);
    ReadMap(&m, &H);
    ReadMap(&m, &I);
    ReadMap(&m, &J);
    ReadMap(&m, &K);
    ReadMap(&m, &L);
    ReadMap(&m, &M);
    ReadMap(&m, &N);
    ReadMap(&m, &O);
    ReadMap(&m, &P);
    ReadMap(&m, &Q);
    ReadMap(&m, &C);
    ReadMap(&m, &D);
    ReadMap(&m, &E);
        
    createAdjMatrix(&Ad);
    ReadAdjMatrix(&Ad);
    DisplayMap(m, Ad, Mobita);
    DisplayAdjMatrix(Ad);
    AdjList(m, &l, Ad, '8');
    DisplayAdjList(l);
    return 0;
}