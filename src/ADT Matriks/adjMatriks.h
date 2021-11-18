#ifndef ADJMATRIKS_H
#define ADJMATRIKS_H


#include "../boolean.h"


typedef struct {
   int contents[27][27]; //27 = hq + (A-Z)
   int adjLength;
} adjMatrix;

#define adjacent(A,i,j) (A).contents[(i)][(j)]
#define adjLength(A) (A).adjLength

void createAdjMatrix(adjMatrix *A, int length);
/*I.S. adjMatrix A sembarang*/
/*F.S. Membuat Adjacency Matriks kosong (semua elemen nol) */
void ReadAdjMatrix(adjMatrix *A, int row, int col, int adj);
/*I.S. adjMatrix A terdefinisi*/
/*F.S. Memasukkan nilai adjMatrix dari mesin kata */
void DisplayAdjMatrix(adjMatrix A);
/*I.S. adjMatrix A terdefinisi*/
/*F.S. Menampilkan Adj Matrix ke layar */
boolean checkAdjacency(adjMatrix A, char vertexName, char testName);
/*I.S. adjMatrix A terdefinisi, testName adalah nama koordinat yang ingin dicek adjacency-nya thdp vertexName*/
/*F.S. Bernilai true jika koordinat bernama testName adjacent dengan koordinat bernama vertexName, bernilai false selainnya */
#endif
