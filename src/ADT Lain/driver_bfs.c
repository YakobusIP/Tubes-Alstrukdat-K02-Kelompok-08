#include "bfs.c"
#include <stdio.h>
#include "../ADT Matriks/map.h"
#include "../ADT Matriks/map.c"
#include "../ADT Matriks/adjMatriks.h"
#include "../ADT Point/point.c"
#include "../ADT Point/point.h"
#include "../pcolor/pcolor.c"
#include "../pcolor/pcolor.h"
#include "../ADT Matriks/adjMatriks.c"
int main()
{
    Coordinate A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, Mobita;
    map m;
    adjMatrix Ad;

    
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
    createAdjMatrix(&Ad, 18);
    for(int i = 0; i < 18; i++)
        {
            for(int j = 0; j < 18; j++)
            {
                if(i != j && (i != 15 && j != 16)) ReadAdjMatrix(&Ad, i, j, 1);
            }
        }
    int waktu = 0; //bisa pakai waktu yang ada di adt waktu, hati-hati kalau ada ability
    bfsQueue Qu; //wajib
    CreateBFSQueue(&Qu); //wajib //Mobita nanti sudah didefinisikan di main, tidak perlu dibuat lagi
    DisplayMap(m, Ad, Mobita, NULL, NULL);
    Coordinate dest = *CoordByName(m, 'Q'); //Posisi Mobita akan dipindah ke P
    bfs(&m, &Qu, &waktu, Ad, Mobita, dest); 
    printf("\n%d\n", waktu);
}