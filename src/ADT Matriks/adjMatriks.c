#include <stdio.h>
#include "adjMatriks.h"


void createAdjMatrix(adjMatrix *A)
{
    int i, j;
    for(i = 0; i < 18; i++)
    {
        for(j = 0; j < 18; j++)
        {
            adjacent(*A, i, j) = 0;
        }
    }
}

void ReadAdjMatrix(adjMatrix *A)
{
    int i, j;
    for(i = 0; i < 18; i++)
    {
        for(j = 0; j < 18; j++)
        {
            if (j % 2 == 0) adjacent(*A, i, j) = 1;
            else if (j % 3 == 0) adjacent(*A, i, j) = 1;
            //Adjacent(A) dari mesin karakter
        }
    }
}

void DisplayAdjMatrix(adjMatrix A)
{
    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 18; j++)
        {
            printf("%d ", adjacent(A, i, j));
        }
        printf("\n");
    }
}

boolean checkAdjacency(adjMatrix A, char vertexName, char testName)
{
    int row = 0, col = 0;

    if(vertexName != '8')
    {
        row = (int)(vertexName - '@'); //A - @ = 1, B - @ = 2, C - @ = 3, dst.
    }

    if(testName != '8')
    {
        col = (int)(testName - '@');
    }

    return (adjacent(A, row, col));
}



