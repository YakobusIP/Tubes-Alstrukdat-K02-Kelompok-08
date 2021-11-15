#include <stdio.h>
#include "./saveFile.h"

void save(map m, adjMatrix adjM, to_do_List tdl){
    /* KAMUS */
    toDoList val;
    tdAddress p;
    Coordinate c;
    static FILE *saveFile;
    int i, len;
    int count;
    /* ALGORITMA */
    printf("Masukkan nama save file dalam permainan : ");
    readCommand();
    saveFile = fopen(currentToken.contents,"a");
    /* for(int i = 0; i < 10; i++) {
        fprintf(saveFile, "%d\n", i);
    } */
    fprintf(saveFile, "9999\n");
    fprintf(saveFile, "%d %d\n", nRow(m), nCol(m));
    c = *CoordByName(m, '8');
    fprintf(saveFile, "%d %d\n", row(c), col(c));
    count = 0;
    // Mencari tahu banyak koordinat
    for(int i = 1; i < nRow(m) + 1; i++)
    {
        for(int j = 1; j < nCol(m) + 1; j++)
        {
            if(CoordPointer(m, i, j) != NULL)
            {
                count += 1;
            }
        }
    }
    fprintf(saveFile, "%d\n", count);
    for(int i = 1; i < nRow(m) + 1; i++)
    {
        for(int j = 1; j < nCol(m) + 1; j++)
        {
            if(CoordPointer(m, i, j) != NULL)
            {
                fprintf(saveFile, "%c %d %d\n", nama(*CoordPointer(m, i, j)), row(*CoordPointer(m, i, j)), col(*CoordPointer(m, i, j)));
            }
        }
    }

    for(int i = 0; i < adjLength(adjM); i++)
    {
        for(int j = 0; j < adjLength(adjM); j++)
        {
            fprintf(saveFile, "%d ", adjacent(adjM, i, j));
        }
        fprintf(saveFile,"\n");
    }
    p = FIRST(tdl);
    while(p != NULL) {
        val = INFO(p);
        if(val.timeLimit > 0) {
            fprintf(saveFile,"%d %c %c %c %d\n", val.reqIn, val.pickUp, val.dropOff, val.type, val.timeLimit);
        } else {
            fprintf(saveFile, "%d %c %c %c\n", val.reqIn, val.pickUp, val.dropOff, val.type);
        }
        p = NEXT(p);
    }
/* 
    // Print banyaknya pesanan
    fprintf(saveFile, "%d\n", length(q));

    // Print everything inside Daftar Pesanan or To Do List
    len = length(q);
    for (i=0;i<len;i++) {
        dequeue(&q, &val);
        fprintf(saveFile, "%d ", val.reqIn);
        fprintf(saveFile, "%c ", val.pickUp);
        fprintf(saveFile, "%c ", val.dropOff);
        fprintf(saveFile, "%c", val.type);

        if (val.type == 'P') {
            fprintf(saveFile, " %d\n", val.timeLimit);
        } else {
            fprintf(saveFile, "\n");
        }
        if (i==len) {
            fprintf(saveFile, "");
        }
    } */

    fclose(saveFile); 
}