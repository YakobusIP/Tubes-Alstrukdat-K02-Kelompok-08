#include <stdio.h>
#include "boolean.h"
#include "ADT Mesin Kata/tokenmachine.h"
#include "ADT Mesin Kata/tokenmachine.c"
#include "ADT Mesin Kata/charmachine.h"
#include "ADT Mesin Kata/charmachine.c"
#include "ADT Linked List/todoQueue.h"
#include "ADT Linked List/todoQueue.c"
#include "ADT Linked List/todoNode.h"
#include "ADT Linked List/todoNode.c"
Token currentToken;
int main(){
    /* KAMUS */
    toDoList val;
    PrioQueue q;
    int i, len;
    /* ALGORITMA */
    printf("Masukkan nama save file dalam permainan : ");
    readCommand();
    saveFile = fopen(currentToken.contents,"a");
    for(int i = 0; i < 10; i++) {
        fprintf(saveFile, "%d\n", i);
    }
    printf("Sukses");
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