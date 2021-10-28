#include <stdio.h>
#include "UangWaktu.h"

void CreateUangWaktu(UangWaktu *u){
    UANG(*u) = 0;
    WAKTU(*u) = 0;
}

boolean isUangValid(UangWaktu u, int uang){
    return UANG(u) + uang >= 0;
}

void ChangeUang(UangWaktu *u, int uang){
    if(isUangValid(*u, uang)){
        UANG(*u) += uang;
    }
}

void ChangeWaktu(UangWaktu *u, int waktu){
    WAKTU(*u) += waktu;
}