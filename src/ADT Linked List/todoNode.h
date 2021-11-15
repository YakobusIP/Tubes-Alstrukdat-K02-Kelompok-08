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

typedef struct tdnode* tdAddress;
typedef struct tdnode {
    toDoList info;
    tdAddress next;
} tdNode;

/* SELEKTOR UNIVERSAL */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

tdAddress newToDoNode(toDoList val);

#endif