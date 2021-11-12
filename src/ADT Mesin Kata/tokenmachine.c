#include <stdio.h>
#include "tokenmachine.h"

static char configFileName[] = "config.conf";
static char saveFileName[] = "savefile.dat";

static FILE *saveFile;
Token currentToken;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* ALGORITMA */
    while (currentChar == BLANK) {
        adv();
    }
}

void ignoreNext() {
/* Mengabaikan satu atau beberapa NEXTLINE, NEXTLINE adalah \n */
    /* ALGORITMA */
    while (currentChar == NEXTLINE) {
        adv();
    }
}

int readNumberfromChar() {
/* Membaca digit angka dari bentuk char ke bentuk integer */
    /* KAMUS */
    int num;
    /* ALGORITMA */
    num = 0;
    ignoreBlank();
    ignoreNext();
    while ((currentChar != BLANK) && (currentChar != NEXTLINE)) {
        num = num*10 + (currentChar - '0');
        adv();
    }
    return num;
}

void readCommand() {
/* Membaca command dari input user */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    startUserInput();
    ignoreBlank();

    i=0;
    while ((currentChar != BLANK) && (currentChar != NEXTLINE) && (i < CAPACITY)) {
        currentToken.contents[i] = currentChar;
        advUserInput();
        i++;
    }
    currentToken.length = i;
}

// READ CONFIG FILE BELUM SELESAI, HARUS DISESUAIN SAMA MODUL LAIN
void readConfigFile(PrioQueue *q) {
/* Membaca file config secara penuh */
    /* KAMUS */
    toDoList val;
    int i, p;
    int inreqIn, intimeLimit;
    char inpickUp, indropOff, intype;
    /* ALGORITMA */
    // START READ CONFIG FILE
    start(configFileName);
    ignoreBlank();
    ignoreNext();

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
        enqueueToDo(q, val, 10);
    }
}

void saveToFile(PrioQueue *q) {
/* Save state game ke dalam sebuah file */   
    /* KAMUS */
    toDoList val;
    int i, len;
    /* ALGORITMA */
    saveFile = fopen(saveFileName,"w");

    // Print banyaknya pesanan
    fprintf(saveFile, "%d\n", length(*q));

    // Print everything inside Daftar Pesanan or To Do List
    len = length(*q);
    for (i=0;i<len;i++) {
        dequeue(q, &val);
        fprintf(saveFile, "%d ", val.reqIn);
        fprintf(saveFile, "%c ", val.pickUp);
        fprintf(saveFile, "%c ", val.dropOff);
        fprintf(saveFile, "%c", val.type);

        if (val.type == 'P') {
            fprintf(saveFile, " %d\n", val.timeLimit);
        } else {
            fprintf(saveFile, "\n");
        }
        if (i==len) {
            fprintf(saveFile, "");
        }
    }

    fclose(saveFile);
}


void loadFromFile(PrioQueue *q) {
/* Load state game dari sebuah file */
    /* KAMUS */
    toDoList val;
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
        enqueueToDo(q, val, 10);
    }
} 