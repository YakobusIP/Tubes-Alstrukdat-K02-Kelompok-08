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
    Address next_node;
    Address prev_node;
} Node;

/* SELEKTOR UNIVERSAL */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next_node
#define PREV(p) (p)->prev_node

Address newNode(toDoList val);

#endif