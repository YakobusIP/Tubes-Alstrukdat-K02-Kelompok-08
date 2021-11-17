#include <stdio.h>
#include<sys/stat.h>
#include "loadFile.h"

void load(PrioQueue *q, map *M, adjMatrix *Al, boolean *failToLoad, UangWaktu *u, Coordinate *Mobita, Stack *s, InventoryGadget *IG, int *itemCounter, int *waktu, Ability *ability, in_progress_list *IPL) {
    // Kamus Lokal
    requestList val;
    Token currentCommand;
    inProgressList value;
    static char *loadFile[200];
    int i, p, b;
    int inreqIn, intimeLimit, instarttime;
    char inpickUp, indropOff, intype, nama;
    struct stat buffer;
    struct items I;
    int exist;
    int uang, waktu1;
    int lokRow, lokCol;
    int temp, ID;
    Gadget G;
    int angka;
    boolean pass;
    /* ALGORITMA */
    // START READ CONFIG FILE
    printf("Apakah file yang anda masukkan terdapat konfigurasi awal? (YES/NO) \n");
    readCommand(&currentCommand);
    if(currentCommand.length == 3) {
        pass = true;
    } 
    printf("Masukkan nama file yang akan diload: ");
    readCommand(&currentCommand);
    exist = stat(currentCommand.contents,&buffer);
    if(exist == 0) {
        start(&currentCommand.contents);
        ignoreBlank();
        ignoreNext();
        do
        {
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
        createAdjMatrix(Al, coordLength + 1);

        for(int j = 0; j < coordLength + 1; j++)
        {   ignoreBlank();
            ignoreNext();
            ignoreBlank();
            for(int k = 0; k < coordLength + 1; k++)
            {
                ignoreBlank();
                adj = readNumberfromChar();
                ReadAdjMatrix(Al, j, k, adj);
            }
        }
        ignoreNext();
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
        ignoreNext();
        if(!pass) {
                ignoreBlank();
                uang = readNumberfromChar();
                ignoreBlank();
                waktu1 = readNumberfromChar();
                ignoreNext();
                UANG(*u) = uang;
                WAKTU(*u) = waktu1;
              
                ignoreBlank();
                nama = currentChar;
                adv();
                ignoreBlank();
                lokRow = readNumberfromChar();
                ignoreBlank();
                lokCol = readNumberfromChar();
                *Mobita = *CreateCoord(nama, lokRow, lokCol);
                ignoreNext();
     
                ignoreBlank();
                temp = readNumberfromChar();
                MAKSIMUM(*s) = temp;
                ignoreNext();
                
                ignoreBlank();
                *itemCounter = readNumberfromChar();
                ignoreNext();
             
                ignoreBlank();
                temp = readNumberfromChar();
                if(temp == 0) {
                    AbilityType(*ability, 0) = false;
                } else {
                    AbilityType(*ability,0) = true;
                }
                ignoreBlank();
                temp = readNumberfromChar();
                *waktu = temp;
                ignoreNext();
               
                ignoreBlank();
                temp = readNumberfromChar();
                if(temp == 0) {
                    AbilityType(*ability, 2) = false;
                } else {
                    AbilityType(*ability,2) = true;
                }
                ignoreBlank();
                temp = readNumberfromChar();
                (*ability).totalVip = temp;
                ignoreNext();
               
                ignoreBlank();
                for (int z = 0; z < 5; z++)
                {
                    ID = readNumberfromChar();
                    if(ID != 0) {
                        CreateGadget(&G, ID);
                        addGadget(&IG, G);
                    }
                    ignoreBlank();
                }
                ignoreNext();
                p = readNumberfromChar();
                
                for(b = 0;b<p;b++) {
                    
                    ignoreNext();
                    ignoreBlank();
                    // READ LOKASI PICK UP ITEM
                    inpickUp = currentChar;
                    value.pickUp = inpickUp;
                    adv();

                    ignoreBlank();
                    // READ LOKASI DROP OFF ITEM
                    indropOff = currentChar;
                    value.dropOff = indropOff;
                    adv();

                    ignoreBlank();
                    // READ TIPE ITEM
                    intype = currentChar;
                    value.type = intype;
                    adv();

                    ignoreBlank();
                    temp = readNumberfromChar();
                    value.timeLimit = temp;
                    adv();

                    ignoreBlank();
                    temp = readNumberfromChar();
                    value.startTime = temp;
                    insertLastIP(IPL, value);  
                    if(value.type == 'N') {
                        angka = 1;
                    } else if (value.type == 'H') {
                        angka = 2;
                    } else if (value.type == 'P') {
                        angka = 3;
                    } else if (value.type == 'V') {
                        angka = 4;
                    }
                    pushStack(s,angka);
                }
                adv();
            } else {
                pass = false;
            } 
            if(eot) {
                break;
            } else {
                while(!isQueueEmpty(*q)) {
                    dequeue(q, &val);
                }
                while(!isIPListEmpty(*IPL)) {
                    deleteFirstIP(IPL, &value);
                }
                while(!isEmptyStack(*s)) {
                    popStack(s, &I);
                }
            }
            ignoreNext();
        } while (!eot);
    } else {
        *failToLoad = true;
        printf("Maaf, nama file yang anda masukkan tidak ada!\n");
    }
}

/*  */