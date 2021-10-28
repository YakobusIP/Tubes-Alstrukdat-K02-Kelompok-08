#include <stdio.h>
#include "UangWaktu.c"
#include "UangWaktu.h"

int main(){
    UangWaktu U;
    int uang, waktu;
    CreateUangWaktu(&U);
    uang = 100;
    waktu = 2;
    ChangeUang(&U, uang);
    ChangeWaktu(&U, waktu);
    printf("%d %d\n", UANG(U), WAKTU(U));
    uang = -200;
    ChangeUang(&U, uang);
    printf("%d %d\n", UANG(U), WAKTU(U));
    return 0;
}