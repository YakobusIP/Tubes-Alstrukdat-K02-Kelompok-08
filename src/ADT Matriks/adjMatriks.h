#ifndef ADJMATRIKS_H
#define ADJMATRIKS_H


#include "../boolean.h"


typedef struct {
   int contents[18][18]; //18 = hq + (A-Q)
} adjMatrix;

#define adjacent(A,i,j) (A).contents[(i)][(j)]


void createAdjMatrix(adjMatrix *A);
void ReadAdjMatrix(adjMatrix *A);
void DisplayAdjMatrix(adjMatrix A);
boolean checkAdjacency(adjMatrix A, char vertexName, char testName);

#endif
