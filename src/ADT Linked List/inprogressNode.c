/* Implementasi inProgressNode */

#include <stdio.h>
#include <stdlib.h>
#include "inprogressNode.h"

ipAddress newInProgressNode(inProgressList val) {
    ipAddress p = (ipAddress)malloc(sizeof(ipNode));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}