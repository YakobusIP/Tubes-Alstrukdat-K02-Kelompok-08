#include <stdio.h>
#include<sys/stat.h>
#include "loadFile.h"

void load(PrioQueue *q, map *M, adjMatrix *Al, boolean *failToLoad, UangWaktu *u) {
/* Membaca file config secara penuh */
    /* KAMUS */
    requestList val;
    static char *loadFile[200];
    int i, p;
    int inreqIn, intimeLimit;
    char inpickUp, indropOff, intype;
    struct stat buffer;
    int exist;
    int uang, waktu;
    /* ALGORITMA */
    // START READ CONFIG FILE
    printf("Masukkan nama load file dalam permainan : ");
    readCommand();
    exist = stat(currentToken.contents,&buffer);
    if(exist == 0) {
        CreateUangWaktu(u);
        start(&currentToken.contents);
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

        ignoreBlank();
        uang = readNumberfromChar();
        ignoreBlank();
        waktu = readNumberfromChar();
        ignoreNext();
        UANG(*u) = uang;
        WAKTU(*u) = waktu;

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
        createAdjMatrix(Al, coordLength + 1);

        for(int j = 0; j < coordLength + 1; j++)
        {
            ignoreNext();
            ignoreBlank();
            for(int k = 0; k < coordLength + 1; k++)
            {
                ignoreBlank();
                adj = readNumberfromChar();
                ReadAdjMatrix(Al, j, k, adj);
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
            // printf("%d %c %c %c %d\n", inreqIn, inpickUp, indropOff, intype, intimeLimit);
            // INPUT VAL YANG SUDAH DIBENTUK KE DALAM QUEUE
            enqueueRL(q, val);
            }
            adv();
            if(eot) {
                break;
            }
            ignoreNext();
        } while (!eot);
    } else {
        *failToLoad = true;
        printf("Maaf, nama file yang anda masukkan tidak ada!\n");
    }
    
}

/*  */