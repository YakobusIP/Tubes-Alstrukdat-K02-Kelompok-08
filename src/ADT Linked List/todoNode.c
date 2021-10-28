/* File: node.c */
/* Implementasi Node */

#include "todoNode.h"
#include <stdlib.h>

Address newNode(toDoList val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}