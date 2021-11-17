#include <stdio.h>
#include "./saveFile.h"

void save(map m, adjMatrix adjM, to_do_List tdl, UangWaktu u, Coordinate Mobita){
    /* KAMUS */
    toDoList val;
    tdAddress p;
    Token currentCommand;
    Coordinate c;
    FILE *saveFile;
    int i, len;
    int count;
    /* ALGORITMA */
    printf("Masukkan nama save file dalam permainan : ");
    readCommand(&currentCommand);
    saveFile = fopen(currentCommand.contents,"a");
    if(saveFile == NULL) {
        printf("Failed to save\n");
    } 
    fprintf(saveFile, "%d %d\n", nRow(m), nCol(m));
    // fprintf(saveFile, "%d %d\n", UANG(u), WAKTU(u));
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
    p = tdl;
    fprintf(saveFile, "%d\n", lengthTD(tdl));
    while(p != NULL) {
        if(INFO(p).timeLimit > 0) {
            fprintf(saveFile,"%d %c %c %c %d\n", INFO(p).reqIn, INFO(p).pickUp, INFO(p).dropOff, INFO(p).type, INFO(p).timeLimit);
        } else {
            fprintf(saveFile, "%d %c %c %c\n", INFO(p).reqIn, INFO(p).pickUp, INFO(p).dropOff, INFO(p).type);
        }
        p = NEXT(p);
    } 
    fprintf(saveFile, "%d %d\n", UANG(u), WAKTU(u));
    fprintf(saveFile, "%c %d %d\n", nama(Mobita), row(Mobita), col(Mobita));
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