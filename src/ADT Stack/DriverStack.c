#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"
#include <string.h>

int main(){
    Stack S;
    int in;
    struct items out;
    CreateStack(&S);
    in = 1;
    pushStack(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    in = 2;
    pushStack(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    in = 3;
    pushStack(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    in = 4;
    pushStack(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    popStack(&S, &out);
    printf("%d\n", out.price);
    
    return 0;
}