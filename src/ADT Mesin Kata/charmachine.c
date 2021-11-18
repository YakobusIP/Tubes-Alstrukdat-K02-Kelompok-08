/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar; // Current character
boolean eot; // End of tape

static FILE * tape;
static int retval;

void start(const char* filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	 /* ALGORITMA */
    tape = fopen(filename,"r");
    eot = false;
	adv();
}

void startUserInput() {
/* Start mesin karakter untuk membaca input dari user */
    /* ALGORITMA */
    tape = stdin;
    eot = false;
    adv();
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* ALGORITMA */
	retval = fscanf(tape,"%c",&currentChar);
    if (retval == MARK1) {
        eot = true;
        fclose(tape);
 	}
}

void advUserInput() {
/* Memajukan pita satu karakter untuk input dari user */
    /* ALGORITMA */
    retval = fscanf(tape,"%c",&currentChar);
    if (retval == MARK2) {
        eot = true;
        fclose(tape);
    }

}