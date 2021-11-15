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
    // adv();
    while ((currentChar != MARK) && (currentChar != BLANK) && (currentChar != NEXTLINE)) {
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
    while ((currentChar != MARK) && (currentChar != BLANK) && (currentChar != NEXTLINE) && (i < CAPACITYTOKENMACHINE)) {
        currentToken.contents[i] = currentChar;
        advUserInput();
        i++;
    }
    ignoreBlank();
    currentToken.length = i;
}

void readCommandLoad() {
/* Membaca command dari input user */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    startUserInput();
    ignoreBlank();

    i=0;
    while ((currentChar != BLANK) && (currentChar != NEXTLINE) && (i < CAPACITYTOKENMACHINE)) {
        currentToken.contents[i] = currentChar;
        advUserInput();
        i++;
    }
    ignoreBlank();
    currentToken.length = i;
}

/* Cara penggunaan: isStringEqual(currentToken, "Command yang ingin dipakai"), contoh isStringEqual(currentToken, "BUY"), kalau dia true berarti bisa masuk ke dalam if-nya */
boolean isStringEqual(Token input, const char* compare) {
/* Membandingkan apakah kedua string yang dimasukkan sama */
    /* KAMUS */
    int i;
    boolean flag;
    /* ALGORITMA */
    i = 0;
    int c = 0;
    while (compare[c] != '\0') {
        c++;
    }
    if (input.length != c/*  (sizeof(compare)/sizeof(compare[0])) */) {
        flag = false;
    } else {
        flag = true;
        while ((i < input.length) && (flag)) {
            if (input.contents[i] != compare[i]) {
                flag = false;
            } else {
                i++;
            }
        }
    }
    
    return flag;

}

/* Cara penggunaan: sama seperti strcpy biasa 
        char string[] = "Testing123";
        char variable[50];
        copyString(variable, string));
*/
char* copyString(char* variable, const char* string) {
/* Implementasi fungsi strcpy di cstring.h */
    /* KAMUS */
    char* pointer;
    /* ALGORITMA */
    pointer = variable;

    // Ketika string belum sampai akhir (di C, akhir string memiliki '\0')
    while (*string != '\0') {
        *variable = *string;
        variable++;
        string++;
    }

    // Tambah bagian '\0' ke akhir string variabel
    *variable = '\0';
    return pointer;
}

// READ CONFIG FILE BELUM SELESAI, HARUS DISESUAIN SAMA MODUL LAIN
void readConfigFile(PrioQueue *q, map *M, adjMatrix *A) {
/* Membaca file config secara penuh */
    /* KAMUS */
    requestList val;
    int i, p;
    int inreqIn, intimeLimit;
    char inpickUp, indropOff, intype;
    /* ALGORITMA */
    // START READ CONFIG FILE
    start(configFileName);
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
}

void saveToFile(PrioQueue *q) {
/* Save state game ke dalam sebuah file */   
    /* KAMUS */
    requestList val;
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
    requestList val;
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
        enqueueRL(q, val);
    }
} 
