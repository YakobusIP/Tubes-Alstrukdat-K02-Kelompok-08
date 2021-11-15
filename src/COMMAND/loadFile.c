#include <stdio.h>
#include "loadFile.h"

// Ini gw ganti dari int main pake void load, soalnya kalo int main ga akan bisa di run dari main.c nya
void load() {
    /* KAMUS */
    requestList val;
    PrioQueue q;
    int i, p;
    int inreqIn, intimeLimit;
    char inpickUp, indropOff, intype;
    /* ALGORITMA */
    // START READ SAVE FILE
    start(saveFileName);
    ignoreBlank();
    ignoreNext();

    // READ DAFTAR PESANAN DAN INPUT KE TO DO LIST
    p = readNumberfromChar();
    
    CreatePrioQueue(&q);
    for (i=0;i<p;i++) {
        ignoreNext();
        ignoreBlank();
        // READ WAKTU PESANAN MASUK
        inreqIn = readNumberfromChar();
        val.reqIn = inreqIn;

        ignoreBlank();
        // READ LOKASI PICK UP ITEM
        inpickUp = currentChar;
        val.pickUp = inpickUp;
        adv();

        ignoreBlank();
        // READ LOKASI DROP OFF ITEM
        indropOff = currentChar;
        val.dropOff = indropOff;
        adv();

        ignoreBlank();
        // READ TIPE ITEM
        intype = currentChar;
        val.type = intype;
        adv();

        ignoreBlank();
        // READ WAKTU HANGUS ITEM JIKA ITEM PERISHABLE
        if (intype == 'P') {
            intimeLimit = readNumberfromChar();
        } else {
            intimeLimit = 0;
        }
        val.timeLimit = intimeLimit;

        // INPUT VAL YANG SUDAH DIBENTUK KE DALAM QUEUE
        enqueueRL(&q, val);
    }
}