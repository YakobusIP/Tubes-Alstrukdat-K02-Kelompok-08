#ifndef INPROGRESSNODE_H
#define INPROGRESSNODE_H

#include <stdlib.h>

typedef struct {
    char pickUp;
    char dropOff;
    char type;
    int timeLimit;
    int startTime;
} inProgressList;

typedef struct node* Address;
typedef struct node {
    inProgressList info;
    Address next;
} Node;

/* SELEKTOR UNIVERSAL */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newInProgressNode(inProgressList val);

#endif