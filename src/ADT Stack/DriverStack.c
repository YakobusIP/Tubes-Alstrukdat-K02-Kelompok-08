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
    push(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    in = 2;
    push(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    in = 3;
    push(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    in = 4;
    push(&S, in);
    printf("%d %s\n", PRICE(S), NAME(S));
    pop(&S, &out);
    printf("%d\n", out.price);
    
    return 0;
}