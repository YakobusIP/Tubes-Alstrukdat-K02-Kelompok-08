#include <stdio.h>
#include "../ADT Linked List/todoQueue.h"
#include "./ADT Mesin Kata/tokenmachine.h"

int main() {
    /* KAMUS */
    PrioQueue q;
    /* ALGORITMA */
    // READ INPUT FROM CONFIG FILE
    //readConfigFile(&q);
    //displayQueue(q);
    //displayToDo(q,5);

    // READ INPUT FROM USER
    readCommand();
    for(int i=0;i<currentToken.length;i++) {
        printf("%c", currentToken.contents[i]);
    }
    return 0;
}