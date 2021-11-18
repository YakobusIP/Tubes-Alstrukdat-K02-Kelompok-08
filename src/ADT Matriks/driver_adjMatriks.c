#include <stdio.h>
#include "adjMatriks.h"
#include "adjMatriks.c"
int main()
{
    adjMatrix Ad;

    createAdjMatrix(&Ad, 18);
    for(int i = 0; i < 18; i++)
        {
            for(int j = 0; j < 18; j++)
            {
                if(i != j) ReadAdjMatrix(&Ad, i, j, 1);
            }
        }
    DisplayAdjMatrix(Ad);

    return 0;
}