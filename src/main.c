#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "boolean.h"

#include "ADT Lain/UangWaktu.h"
#include "ADT Lain/Ability.h"
#include "ADT Linked List/inprogressList.h"
#include "ADT Linked List/inprogressNode.h"
#include "ADT Linked List/todoList.h"
#include "ADT Linked List/todoNode.h" 
#include "ADT List/adjList.h"
#include "ADT List/Gadget.h"
#include "ADT List/InventoryGadget.h"
#include "ADT Matriks/adjMatriks.h"
#include "ADT Matriks/map.h"
#include "ADT Mesin Kata/charmachine.h"
#include "ADT Mesin Kata/tokenmachine.h"
#include "ADT Point/point.h"
#include "ADT Stack/stack.h"
#include "ADT Queue/requestList.h"
#include "ADT Lain/bfs.h"
#include "pcolor/pcolor.h"

#include "ADT Lain/UangWaktu.c"
#include "ADT Linked List/inprogressList.c"
#include "ADT Linked List/inprogressNode.c"
#include "ADT Linked List/todoList.c"
#include "ADT Linked List/todoNode.c"
#include "ADT List/adjList.c" 
#include "ADT List/Gadget.c"
#include "ADT List/InventoryGadget.c"
#include "ADT Matriks/adjMatriks.c"
#include "ADT Matriks/map.c"
#include "ADT Mesin Kata/charmachine.c"
#include "ADT Mesin Kata/tokenmachine.c"
#include "ADT Point/point.c"
#include "ADT Stack/stack.c"
#include "ADT Queue/requestList.c"
// #include "ADT Lain/bfs.c"
#include "pcolor/pcolor.c" 

/* Include command code */
// P.S: Keliatannya kalo ini udah banyak yang implementasi kode buat command, yang include di atas ilangin aja
// karena udah pasti di include sama header commandnya
#include "../src/COMMAND/buy.h"
#include "../src/COMMAND/return_to_sender.h"
#include "../src/COMMAND/loadFile.h"
// #include "../src/COMMAND/drop_off.h"
#include "../src/COMMAND/help.h"
// #include "../src/COMMAND/inventory.h"
#include "../src/COMMAND/in_progress.h"
#include "../src/COMMAND/move.h"
#include "../src/COMMAND/pick_up.h"
#include "../src/COMMAND/saveFile.h"
#include "../src/COMMAND/to_do.h"

#include "../src/COMMAND/buy.c"
#include "../src/COMMAND/return_to_sender.c"
#include "../src/COMMAND/loadFile.c"
// #include "../src/COMMAND/drop_off.c"
#include "../src/COMMAND/help.c"
// #include "../src/COMMAND/inventory.c"
#include "../src/COMMAND/in_progress.c"
#include "../src/COMMAND/move.c"
#include "../src/COMMAND/pick_up.c"
#include "../src/COMMAND/saveFile.c"
#include "../src/COMMAND/to_do.c"




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
    /* Kamus */    
    UangWaktu u; // ADT untuk membaca uang dan waktu
    AvailableGadget AG; // ADT yang menampilkan gadget yang tersedia
    InventoryGadget IG; // ADT untuk menampilkan gadget yang telah dimiliki
    Gadget G; // Struct untuk menampilkan info gadget
    to_do_List TDL; // ADT untuk menampilkan to_do_list yang harus dikerjakan
    in_progress_list IPL; // ADT untuk menampilkan daftar pekerjaan yang sedang dikerjakan
    Stack s; // ADT untuk tas
    map m; // ADT untuk menyimpan map
    Coordinate C, Mobita; // ADT untuk menyimpan koordinat
    requestList RL;
    PrioQueue pq;
    adjMatrix AM;

    char currentLocation;
    int addMoveTime = 0;      // waktu tambahan jika membawa heavy item, dapat menumpuk
    struct items val;
    Ability ability; //struct ability
    boolean isReturn; // Digunakan untuk mengetahui apakah ada ability is return to sender
    // Jika telah menerima item VIP, ubah isReturn ke True
    boolean newGame; // Boolean untuk menampilkan apakah game sukses dimulai atau tidak, jika sukses, akan menjadi true
    /* Algoritma */
    newGame = true;
    isReturn = false;
    CreateUangWaktu(&u);
    CreateAvailableGadget(&AG);
    CreateInventoryGadget(&IG);
    CreateToDoList(&TDL);
    CreateInProgressList(&IPL);
    // load(&pq, &m,&AM);
    /* Start mesin kata untuk membaca config file dan input konfigurasi */
    // readConfigFile(&pq, &m, &AM);
    for(int i = 0; i < 3; i++){
        ability.type[i] = false; //awal game diinisiasi tanpa ability
    }
    // Mobita = *CoordByName(m, '8');
    // Fungsi newGame
    while(newGame) {
        printf("ENTER COMMAND: ");
        readCommand();
        printf("%s\n", currentToken);
        if(isStringEqual(currentToken,"MOVE")) {
            move(&Mobita, m, AM, &u);
        } else if (isStringEqual(currentToken,"PICK_UP")) {
            pick_up(&TDL, &s, &IPL, currentLocation, &addMoveTime, &u);
        } else if (isStringEqual(currentToken,"DROP_OFF")) {
            // drop_off(&IPL, &s, currentLocation, &u, &ability);
        } else if (isStringEqual(currentToken,"MAP")) {
            DisplayMap(m, AM, Mobita, IPL, TDL);
        } else if (isStringEqual(currentToken,"TO_DO")) {
            fromRLtoTDL(&pq, &TDL, &u);
            to_do(TDL);
        } else if (isStringEqual(currentToken,"IN_PROGRESS")) {
           in_progress(&IPL);
        } else if(isStringEqual(currentToken,"BUY")) {
            buy(&u, AG, &IG, G);
            adv();
        }  else if (isStringEqual(currentToken,"INVENTORY")) {
            // inventory(&IG, &IPL, &s, &u, &C, m, AM);
        } else if (isStringEqual(currentToken,"HELP")) {
            Help();
        } else if (isStringEqual(currentToken,"SAVE_GAME")) {
            save(m, AM, TDL);
        } else if (isStringEqual(currentToken,"RETURN")) {
            if(EFFECT(s) == 3) {
                printf("Maaf, return to sender tidak bisa digunakan untuk VIP Item\n");
            } else {
                return_to_sender(&s, &IPL, &TDL, u);
                isReturn = false;
            }
        } else if (isStringEqual(currentToken,"EXIT")){
            newGame = false;
            printf("Sampai jumpa di permainan berikutnya\n");
        } else {
            printf("COMMAND yang anda masukkan salah!\n");
        }
    } 
        
    return 0;
}