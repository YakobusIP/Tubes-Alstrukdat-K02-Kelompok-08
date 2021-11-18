/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "../boolean.h"

#define MARK1 EOF // Set mark "end of file"
#define MARK2 '\n' // Set mark untuk "enter"

/* Char Engine State */
extern char currentChar;
extern boolean eot;

// Start pembacaan dari file
void start(const char* filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void startUserInput();
/* Start mesin karakter untuk membaca input dari user */

void adv();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void advUserInput();
/* Memajukan pita satu karakter untuk input dari user */

#endif