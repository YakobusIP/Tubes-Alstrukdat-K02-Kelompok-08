#include <stdio.h>
#include "move.h"


void move(Coordinate *src, map m, adjMatrix A, int *waktu)
{
    char c;
    adjList l;
    CreateAdjList(&l);
    int num;


    c = nama(*src);
    printf("Posisi yang dapat dicapai: \n");
    AdjList(m, &l, A, c);
    for(int i = 0; i < lengthAdjList(l); i++)
    {
        printf("%d. ", i+1);
        DisplayCoord(*ElmtPointer(l, i));
        printf("\n");
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    scanf("%d", &num);
    *src = *ElmtPointer(l, num-1);
    printf("Mobita sekarang berada di titik ");
    DisplayCoord(*src);
    printf("!\n");
    *waktu += 1;
}

