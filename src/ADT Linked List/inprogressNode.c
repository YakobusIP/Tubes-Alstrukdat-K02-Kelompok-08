/* Implementasi inProgressNode */

#include <stdio.h>
#include <stdlib.h>
#include "inprogressNode.h"

Address newInProgressNode(inProgressList val) {
    Address p = (Address) malloc(sizeof(ipNode));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}