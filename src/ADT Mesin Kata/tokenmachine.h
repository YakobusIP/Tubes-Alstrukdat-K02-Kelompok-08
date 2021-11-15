/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "../boolean.h"
#include "charmachine.h"
#include "../ADT Queue/requestList.h"
#include "../ADT Matriks/adjMatriks.h"
#include "../ADT Matriks/map.h"
#include "../ADT Point/point.h"


#define CAPACITYTOKENMACHINE 100
#define BLANK ' '
#define NEXTLINE '\n'

typedef struct {
   char contents[CAPACITYTOKENMACHINE]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Token;

/* Word Engine State */
extern Token currentToken;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void ignoreNext();
/* Mengabaikan satu atau beberapa NEXTLINE, NEXTLINE adalah \n */

void ignoreBlankUserInput();
/* Mengabaikan BLANK dari input user di terminal */

void ignoreNextUserInput();
/* Mengabaikan satu atau beberapa NEXTLINE dari input user di terminal, NEXTLINE adalah \n */

int readNumberfromChar();
/* Membaca digit angka dari bentuk char ke bentuk integer */

int readNumberfromSTDIN();
/* Membaca digit angka dari bentuk char ke bentuk integer, data diambil dari input user di terminal */

void readCommand();
/* Membaca command dari input user */

int isStringEqual(const char* input, const char* compare);
/* Membandingkan apakah kedua string yang dimasukkan sama */

char* copyString(char* variable, const char* string);
/* Implementasi fungsi strcpy di cstring.h */

void readConfigFile(PrioQueue *q, map *M, adjMatrix *A);
/* Membaca file config secara penuh */

void saveToFile(PrioQueue *q);
/* Save state game ke dalam sebuah file */

void loadFromFile(PrioQueue *q);
/* Load state game dari sebuah file */

#endif
