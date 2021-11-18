/* File: node.c */
/* Implementasi Node */

#include "todoNode.h"
#include <stdlib.h>

tdAddress newToDoNode(toDoList val) {
    tdAddress p = (tdAddress)malloc(sizeof(tdNode));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}