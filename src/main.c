#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "boolean.h"

#include "ADT Lain/UangWaktu.h"
#include "ADT Linked List/inprogressList.h"
#include "ADT Linked List/inprogressNode.h"
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
#include "pcolor/pcolor.h"

/*
#include "ADT Lain/UangWaktu.c"
#include "ADT Linked List/inprogressList.c"
#include "ADT Linked List/inprogressNode.c"
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
#include "pcolor/pcolor.c" */

/* Include command code */
// P.S: Keliatannya kalo ini udah banyak yang implementasi kode buat command, yang include di atas ilangin aja
// karena udah pasti di include sama header commandnya
//#include "../src/COMMAND/to_do.h"
//#include "../src/COMMAND/in_progress.h"
#include "../src/COMMAND/buy.h"
#include "../src/COMMAND/buy.c"
#include "../src/COMMAND/return_to_sender.h"
#include "../src/COMMAND/return_to_sender.c" 

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
    Coordinate C; // ADT untuk menyimpan koordinat
    requestList RL;
    PrioQueue pq;
    adjMatrix AM;
    struct items val;
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
    createInProgressList(&IPL);

    /* Start mesin kata untuk membaca config file dan input konfigurasi */
    readConfigFile(&pq, &m, &AM);
    // Fungsi newGame
    while(newGame) {
        printf("ENTER COMMAND: ");
        readCommand();
        if(isStringEqual(currentToken,"MOVE")) {

        } else if (isStringEqual(currentToken,"PICK_UP")) {

        } else if (isStringEqual(currentToken,"DROP_OFF")) {

        } else if (isStringEqual(currentToken,"MAP")) {

        } else if (isStringEqual(currentToken,"TO_DO")) {
            //fromRLtoTDL(&pq, &TDL, &u);
            //to_do(TDL);
        } else if (isStringEqual(currentToken,"IN_PROGRESS")) {
           // in_progress(&IPL);
        } else if(isStringEqual(currentToken,"BUY")) {
            buy(&u, AG, &IG, G);
            adv();
        }  else if (isStringEqual(currentToken,"INVENTORY")) {
            
        } else if (isStringEqual(currentToken,"HELP")) {

        } else if (isStringEqual(currentToken,"SAVE_GAME")) {
            //save(m, AM, TDL);
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
