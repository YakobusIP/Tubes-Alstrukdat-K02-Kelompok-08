#include <stdio.h>
#include "map.h"
#include "../boolean.h"

void CreateMap(map *M, int nRow, int nCol)
{
    nRow(*M) = nRow;
    nCol(*M) = nCol;

    for(int i = 1; i < nRow + 1; i++)
    {
        for(int j = 1; j < nCol + 1; j++)
        {
            CoordPointer(*M,i,j) = NULL;
        }
    }
}

void ReadMap(map *M, Coordinate *C)
{
        CoordPointer(*M, row(*C), col(*C)) = C;
}

void DisplayMap(map M, adjMatrix A, Coordinate Mobita, in_progress_list ipl, to_do_List tdl)
{
    char x, dropoff, pickup;
    int nRow = nRow(M), nCol = nCol(M);
    Address drop, pick;
    drop = FIRST(ipl);
    pick = FIRST(tdl);
    if(drop != NULL) dropoff = INFO(drop).dropOff;
    else dropoff = NONE;
    if(pick != NULL) pickup = INFO(pick).pickUp;
    else pickup = NONE;

    for(int i = 0; i < nRow + 2; i++)
    {
        for(int j = 0; j < nCol + 2; j++)   
        {
            if (j == 0 || j == nCol + 1 || i == 0 || i == nRow + 1) // * pembatas
            {
                printf("*");
            }
            else
            {
                if(CoordPointer(M, i, j) != NULL)
                {
                    x = CoordNama(M, i, j);
                    if (x == nama(Mobita))
                    {
                        print_yellow(x);
                    }
                    
                    else if (x == pickup)
                    {
                        print_red(x);
                    }
                    else if (x == dropoff)
                    {
                        print_blue(x);
                    }

                    else if(checkAdjacency(A, nama(Mobita), x))
                    {
                        print_green(x);
                    }
                    else 
                    {
                        x = CoordNama(M, i, j);
                        printf("%c", x);
                    }
                    
                }
                else printf (" ");            
            }
        }
        printf("\n");
    }
}

Coordinate* CoordByName(map m, char nama)
{
    int i = 1, j = 1;
    boolean found = false;

    while (!found && (i < nRow(m) + 1))
    {
        while (!found && (j < nCol(m) + 1))
        {               
            if(CoordPointer(m,i,j) != NULL) 
            {
                if(CoordNama(m,i,j) == nama)
                {
                    found = true;
                }
                else j++;
            }
            
            else 
            {
                j++;
            }
           
        }
        if (!found)
        {
            j = 1;
            i++;
        }
    }
    if (found) return CoordPointer(m, i, j);
    else return NULL;
}
