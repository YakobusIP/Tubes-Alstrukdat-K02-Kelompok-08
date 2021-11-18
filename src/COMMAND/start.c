#include <stdio.h>
#include "start.h"
#include <time.h>
#include<sys/stat.h>

void start_game(PrioQueue *q, map *M, adjMatrix *A) {
/* Membaca file config secara penuh */
    /* KAMUS */
    Token currentCommand;
    requestList val;
    int i, p;
    int inreqIn, intimeLimit;
    char inpickUp, indropOff, intype;
    struct stat buffer;
    int exist;
    /* ALGORITMA */
    // START READ CONFIG FILE
    printf("Masukkan nama file konfigurasi: ");
    readCommand(&currentCommand);
    exist = stat(currentCommand.contents,&buffer);
    if(exist == 0) {
        start(&currentCommand.contents);
        ignoreBlank();
        ignoreNext();
    
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
    } else {
        printf("File konfigurasi tidak ada\n");
    }
}

void mainMenu(){
    //Prosedur Tulis Main Menu//
    printf(".88b  d88.  .d88b.  d8888b. d888888b d888888b  .d8b.       \n");
    printf("88'YbdP`88 .8P  Y8. 88  `8D   `88'   `~~88~~' d8' `8b      \n");
    printf("88  88  88 88    88 88oooY'    88       88    88ooo88      \n");
    printf("88  88  88 88    88 88~~~b.    88       88    88~~~88      \n");
    printf("88  88  88 `8b  d8' 88   8D   .88.      88    88   88      \n");
    printf("YP  YP  YP  `Y88P'  Y8888P' Y888888P    YP    YP   YP      \n");
    printf("===============   WELCOME TO MOBITA   ===============\n");
    printf("==============       LET'S PLAY        ==============\n");
    printf("============            MENU             ============\n");
    printf("1. NEW_GAME\n");
    printf("2. LOAD_GAME\n");
    printf("3. EXIT\n");
    printf("Masukkan pilihan anda: ");
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}