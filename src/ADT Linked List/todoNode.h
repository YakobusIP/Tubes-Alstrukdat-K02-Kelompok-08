/* NODE UNTUK DAFTAR PESANAN */
/* MENGGUNAKAN DOUBLY LINKED LIST */

#ifndef TODONODE_H
#define TODONODE_H

#include <stdlib.h>

typedef struct {
    int reqIn;
    char pickUp; // UBAH NANTI
    char dropOff; // UBAH NANTI
    char type;
    int timeLimit;
} toDoList;

typedef struct node* Address;
typedef struct node {
    toDoList info;
    Address next;
} Node;

/* SELEKTOR UNIVERSAL */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(toDoList val);

#endif