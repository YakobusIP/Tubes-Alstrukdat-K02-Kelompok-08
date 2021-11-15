#include <stdio.h>
#include "loadFile.h"

void load(PrioQueue *q, map *M, adjMatrix *A) {
/* Membaca file config secara penuh */
    /* KAMUS */
    requestList val;
    static FILE *loadFile;
    int i, p;
    int mark;
    int inreqIn, intimeLimit;
    char inpickUp, indropOff, intype;
    /* ALGORITMA */
    // START READ CONFIG FILE
    printf("Masukkan nama load file dalam permainan : ");
    readCommand();
    loadFile = fopen(currentToken.contents,"w");
    
    start(loadFile);
    ignoreBlank();
    ignoreNext();
   

    do
    {
        //READ MAP SIZE
    int mapRow, mapCol, hqRow, hqCol, coordLength, coordRow, coordCol, adj;
    char coordName;
    ignoreBlank();
    mapRow = readNumberfromChar();
    ignoreBlank();
    mapCol = readNumberfromChar();
    ignoreNext();
    CreateMap(M, mapRow, mapCol);

    //KOORDINAT HQ
    ignoreBlank();
    hqRow = readNumberfromChar();
    ignoreBlank();
    hqCol = readNumberfromChar();
    ignoreNext();
    Coordinate *C = CreateCoord('8', hqRow, hqCol);
    ReadMap(M, C);


   
    //CEK KOORDINAT
    ignoreBlank();
    coordLength = readNumberfromChar();
    for(int j = 0; j < coordLength; j++)
    {
        ignoreNext();
        ignoreBlank();
        coordName = currentChar;
        adv();
        coordRow = readNumberfromChar();
        coordCol = readNumberfromChar();
        Coordinate *C = CreateCoord(coordName, coordRow, coordCol);
        ReadMap(M, C);
    }

    //READ ADJ MATRIX
    createAdjMatrix(A, coordLength + 1);

    for(int j = 0; j < coordLength + 1; j++)
    {
        ignoreNext();
        ignoreBlank();
        for(int k = 0; k < coordLength + 1; k++)
        {
            ignoreBlank();
            adj = readNumberfromChar();
            ReadAdjMatrix(A, j, k, adj);
        }
    }
    // READ DAFTAR PESANAN DAN INPUT KE TO DO LIST
    p = readNumberfromChar();
    //printf("%d,", p);
    CreatePrioQueue(q);
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
        enqueueRL(q, val);
        }
        ignoreNext();
        mark = readNumberfromChar();
    } while (mark == 9999);
    
}

/*  */