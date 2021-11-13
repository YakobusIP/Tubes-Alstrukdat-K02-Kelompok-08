#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "boolean.h"

/* #include "../src/ADT Lain/UangWaktu.h"
#include "../src/ADT Linked List/inprogressList.h"
#include "../src/ADT Linked List/inprogressNode.h"
#include "../src/ADT Linked List/todoNode.h"
#include "../src/ADT List/adjList.h"
#include "../src/ADT Linked List/todoQueue.h"
#include "../src/ADT List/Gadget.h"
#include "../src/ADT List/InventoryGadget.h"
#include "../src/ADT Matriks/adjMatriks.h"
#include "../src/ADT Matriks/map.h"
#include "../src/ADT Mesin Kata/charmachine.h"
#include "../src/ADT Mesin Kata/tokenmachine.h"
#include "../src/ADT Point/point.h"
#include "../src/ADT Stack/stack.h"
#include "../src/ADT Queue/requestList.h"  */

#include "COMMAND/buy.h"
#include "COMMAND/buy.c"

void print_mainmenu(){
    //Prosedur Tulis Main Menu//
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME\n");
    printf("3. EXIT");
}

void newGame(){
    
}

void Exit(){
    printf("Thanks For Playing !");
    exit(0);
}

int main(){
    // Kamus
    UangWaktu u; // ADT untuk membaca uang dan waktu
    AvailableGadget AG; // ADT yang menampilkan gadget yang tersedia
    InventoryGadget IG; // ADT untuk menampilkan gadget yang telah dimiliki
    struct Gadget G; // Struct untuk menampilkan info gadget //
    // ADT untuk menampilkan to_do_list yang harus dikerjakan
    Stack s; // ADT untuk tas
     // inProgressList val; // ADT untuk menampilkan daftar pekerjaan yang sedang dikerjakna
    map m; // ADT untuk menyimpan map
    Coordinate C; // ADT untuk menyimpan koordinat
    requestList RL;
    boolean newGame; // Boolean untuk menampilkan apakah game sukses dimulai atau tidak, jika sukses, akan menjadi true
    // Algoritma
    newGame = true;
    CreateUangWaktu(&u);
    CreateAvailableGadget(&AG);
    CreateInventoryGadget(&IG);
    // Fungsi newGame
    while(newGame) {
        printf("ENTER COMMAND: ");
        readCommand();
        if(isStringEqual(currentToken,"MOVE")) {

        } else if (isStringEqual(currentToken,"PICK_UP")) {

        } else if (isStringEqual(currentToken,"DROP_OFF")) {

        } else if (isStringEqual(currentToken,"MAP")) {

        } else if (isStringEqual(currentToken,"TO_DO")) {

        } else if (isStringEqual(currentToken,"IN_PROGRESS")) {

        } else if(isStringEqual(currentToken,"BUY")) {
            buy(&u, AG, &IG, G);
        }  else if (isStringEqual(currentToken,"INVENTORY")) {
            
        } else if (isStringEqual(currentToken,"HELP")) {

        } else if (isStringEqual(currentToken,"SAVE_GAME")) {

        } else if (isStringEqual(currentToken,"RETURN")) {

        } else if (isStringEqual(currentToken,"EXIT")){
            newGame = false;
            printf("Sampai jumpa di permainan berikutnya\n");
        } else {
            printf("COMMAND yang anda masukkan salah!\n");
        }
        adv();
    } 
    return 0;
}
