#include <stdio.h>
#include "adjList.h"

void CreateAdjList(adjList *l)
{
    int i = 0;
    for(i; i < 18; i++)
    {
        ElmtPointer(*l, i) = NULL;
    }
}
void AdjList(map m, adjList *l, adjMatrix A, char vertexName)
{
    int row = 0;
    char testName;
    
    if(vertexName != '8')
    {
        row = (int)(vertexName - '@'); //A - @ = 1, B - @ = 2, C - @ = 3, dst.
    }

    for(int i = 0; i < 18; i++)
    {
        if(adjacent(A, row, i) == 1)
        {
            if(i != 0)
            {
                testName = i + '@';
            }
            else testName = '8';
            insertLastAdjList(m, l, testName);
        }
    }
}

int lengthAdjList(adjList l)
{
    int i = 0;
    while(ElmtPointer(l,i) != NULL && (i < 18))
    {
        i++;
    }
    return i;
}



void insertLastAdjList(map m, adjList *l, char val)
{
    Coordinate* C;
    C = CoordByName(m, val);

    if(C != NULL)
    {
        ElmtPointer(*l, lengthAdjList(*l)) = C;
    }
}

boolean isEmptyAdjList(adjList l)
/* Mengirim true jika list kosong */
{
    return ElmtPointer(l, 0) == NULL;
}

void DisplayAdjList(adjList l)
{
    if(isEmptyAdjList(l))
    {
        printf("[]");
    }
    else
    {
        int i = 0;
        printf("[");
        for(i; i < lengthAdjList(l); i++)
        {
            DisplayCoord(*ElmtPointer(l, i));
            if (i != lengthAdjList(l) - 1) printf(", ");           
        }
        printf("]");
    }
}

boolean isIdxValid(adjList l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >=  0 && i < 18);
}
boolean isIdxEff(adjList l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return (i >= 0 && i <= (lengthAdjList(l)-1));
}