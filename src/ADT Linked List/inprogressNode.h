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

typedef struct ipnode* ipAddress;
typedef struct ipnode {
    inProgressList info;
    ipAddress next;
} ipNode;

/* SELEKTOR UNIVERSAL */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

ipAddress newInProgressNode(inProgressList val);

#endif