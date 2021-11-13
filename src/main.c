#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "boolean.h"

#include "../src/ADT Lain/UangWaktu.h"
#include "../src/ADT Linked List/inprogressNode.h"
#include "../src/ADT Linked List/inprogressList.h"
#include "../src/ADT Linked List/todoNode.h"
#include "../src/ADT Linked List/todoList.h"
#include "../src/ADT List/adjList.h"
#include "../src/ADT List/Gadget.h"
#include "../src/ADT List/InventoryGadget.h"
#include "../src/ADT Matriks/adjMatriks.h"
#include "../src/ADT Matriks/map.h"
#include "../src/ADT Mesin Kata/charmachine.h"
#include "../src/ADT Mesin Kata/tokenmachine.h"
#include "../src/ADT Point/point.h"
#include "../src/ADT Stack/stack.h"
#include "../src/ADT Queue/requestList.h"

/* Include command code */
// P.S: Keliatannya kalo ini udah banyak yang implementasi kode buat command, yang include di atas ilangin aja
// karena udah pasti di include sama header commandnya
#include "../src/COMMAND/to_do.h"
#include "../src/COMMAND/in_progress.h"
#include "../src/COMMAND/buy.h"

int main(){
    /* Kamus */    
    Token currentToken; // Membaca command
    UangWaktu u; // ADT untuk membaca uang dan waktu
    AvailableGadget AG; // ADT yang menampilkan gadget yang tersedia
    InventoryGadget IG; // ADT untuk menampilkan gadget yang telah dimiliki
    struct Gadget G; // Struct untuk menampilkan info gadget
    to_do_List TDL; // ADT untuk menampilkan to_do_list yang harus dikerjakan
    inProgressList IPL; // ADT untuk menampilkan daftar pekerjaan yang sedang dikerjakan
    Stack s; // ADT untuk tas
    map m; // ADT untuk menyimpan map
    Coordinate C; // ADT untuk menyimpan koordinat
    requestList RL;
    PrioQueue pq;
    adjMatrix AM;
    boolean newGame; // Boolean untuk menampilkan apakah game sukses dimulai atau tidak, jika sukses, akan menjadi true
    /* Algoritma */
    newGame = true;
    CreateUangWaktu(&u);
    CreateAvailableGadget(&AG);
    CreateInventoryGadget(&IG);
    CreateToDoList(&TDL);
    createInProgressList(&IPL);

    /* Start mesin kata untuk membaca config file dan input konfigurasi */
    readConfigFile(&pq, &m, &AM);
    // Fungsi newGame
    while(newGame) {
        printf("ENTER COMMAND: ");
        readCommand();
        if(currentToken.contents == "MOVE") {
            ;
        } else if(currentToken.contents == "PICK_UP") {
            ;
        } else if(currentToken.contents == "DROP_OFF") {
            ;
        } else if(currentToken.contents == "MAP") {
            ;
        } else if(currentToken.contents == "TO_DO") {
            to_do(&pq, &TDL, &u);
        } else if(currentToken.contents == "IN_PROGRESS") {
            in_progress(&IPL);
        } else if(currentToken.contents == "BUY") {
            buy(u, AG, IG, G);
        } else if(currentToken.contents == "INVENTORY") {
            ;
        } else if(currentToken.contents == "HELP") {
            ;
        } else if(currentToken.contents == "SAVE_GAME") {
            ;
        } else if(currentToken.contents == "RETURN") {
            ;
        } else {
            printf("Command tidak dikenal, silahkan ulangi penulisan");
        }
    }
    return 0;
}
