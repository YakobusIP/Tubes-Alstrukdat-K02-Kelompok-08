#include <stdio.h>
#include "adjMatriks.h"


void createAdjMatrix(adjMatrix *A, int length)
{
    int i, j;
    adjLength(*A) = length;
    for(i = 0; i < length; i++)
    {
        for(j = 0; j < length; j++)
        {
            adjacent(*A, i, j) = 0;
        }
    }
}

void ReadAdjMatrix(adjMatrix *A, int row, int col, int adj)
{
    int i, j;
    for(i = 0; i < adjLength(*A); i++)
    {
        for(j = 0; j < adjLength(*A); j++)
        {
            if(i == row && j == col)
            {
                adjacent(*A, i, j) = adj;
            }
        }
    }
}

void DisplayAdjMatrix(adjMatrix A)
{
    for(int i = 0; i < adjLength(A); i++)
    {
        for(int j = 0; j < adjLength(A); j++)
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



