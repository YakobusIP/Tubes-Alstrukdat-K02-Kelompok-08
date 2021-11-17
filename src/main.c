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


// Jangan dihapus ya gais :D
#include "ADT Lain/UangWaktu.c"
#include "ADT Lain/Ability.c"
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
#include "pcolor/pcolor.c"

/* Include command code */
// P.S: Keliatannya kalo ini udah banyak yang implementasi kode buat command, yang include di atas ilangin aja
// karena udah pasti di include sama header commandnya
#include "../src/COMMAND/buy.h"
#include "../src/COMMAND/return_to_sender.h"
#include "../src/COMMAND/loadFile.h"
#include "../src/COMMAND/drop_off.h"
#include "../src/COMMAND/help.h"
#include "../src/COMMAND/inventory.h"
#include "../src/COMMAND/in_progress.h"
#include "../src/COMMAND/move.h"
#include "../src/COMMAND/pick_up.h"
#include "../src/COMMAND/saveFile.h"
#include "../src/COMMAND/to_do.h"
#include "../src/COMMAND/start.h"

#include "../src/COMMAND/buy.c"
#include "../src/COMMAND/return_to_sender.c"
#include "../src/COMMAND/loadFile.c"
#include "../src/COMMAND/drop_off.c"
#include "../src/COMMAND/help.c"
#include "../src/COMMAND/inventory.c"
#include "../src/COMMAND/in_progress.c"
#include "../src/COMMAND/move.c"
#include "../src/COMMAND/pick_up.c"
#include "../src/COMMAND/saveFile.c"
#include "../src/COMMAND/to_do.c"
#include "../src/COMMAND/start.c"

int main(){
    /* Kamus */    
    Token currentCommand;
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
    boolean failToLoad;
    int addMoveTime = 0;      // waktu tambahan jika membawa heavy item, dapat menumpuk
    int waktu = 0;
    struct items val;
    Ability ability; //struct ability
    boolean isReturn; // Digunakan untuk mengetahui apakah ada ability is return to sender
    // Jika telah menerima item VIP, ubah isReturn ke True
    boolean newGame; // Boolean untuk menampilkan apakah game sukses dimulai atau tidak, jika sukses, akan menjadi true

    failToLoad = false;
    newGame = false;
    isReturn = false;

    /* Algoritma */

    // Membuat konstruktor yang ada
    CreateUangWaktu(&u);
    CreateStack(&s);
    CreateAvailableGadget(&AG);
    CreateInventoryGadget(&IG);
    CreateToDoList(&TDL);
    CreatePrioQueue(&pq);
    CreateInProgressList(&IPL);
    CreateAbility(&ability);

    // Main Menu
    mainMenu();
    readCommand(&currentCommand);
    if(isStringEqual(currentCommand,"1")){
        start_game(&pq, &m, &AM);
        // fromRLtoTDL(&pq, &TDL, WAKTU(u));
        printf("Harap tunggu sebentar...\n");
        delay(2);
        printf("Permainan anda sedang disiapkan...\n");
        delay(2);
        printf("Ini dia!\n");
        delay(1);
        printf("Enjoy the Game!\n");
        newGame = true;
        Mobita = *CoordByName(m, '8');
        UANG(u) = 20000;
    }else if(isStringEqual(currentCommand, "2") ){
        load(&pq, &m, &AM, &failToLoad, &u, &Mobita);
        if(failToLoad == false) {
            /* displayQueue(pq);
            printf("%d\n", WAKTU(u)); */
            // fromRLtoTDL(&pq, &TDL, WAKTU(u));
            printf("Harap tunggu sebentar...\n");
            delay(2);
            printf("Permainan anda sedang diload...\n");
            delay(2);
            printf("Ini dia!\n");
            delay(1);
            printf("Game anda berhasil diload! Selamat bermain!\n");   
            newGame = true;
        } else {
            newGame = false;
        }
    }else if(isStringEqual(currentCommand, "3")){
        newGame = false;
        printf("Anda keluar dari game.\n");
    }

    /* Start mesin kata untuk membaca config file dan input konfigurasi */
    // readConfigFile(&pq, &m, &AM);


    // Masuk ke permainan utama
    while(newGame) {
        speed_boost(&ability, &waktu, &u, &IPL);
         increase_capacity(ability, &s);
        fromRLtoTDL(&pq, &TDL, WAKTU(u));
        printf("Uang anda sekarang adalah: %d", UANG(u));
        printf("\nWaktu sekarang adalah: %d", WAKTU(u));
        printf("\nENTER COMMAND: ");
        readCommand(&currentCommand);
        if(isStringEqual(currentCommand,"MOVE")) {
            move(&s, &IPL, &Mobita, m,  AM, &u, &ability, &waktu, addMoveTime);
        } else if (isStringEqual(currentCommand,"PICK_UP")) {
            pick_up(&TDL, &s, &IPL, Mobita.nama, &addMoveTime, &u);
        } else if (isStringEqual(currentCommand,"DROP_OFF")) {
            drop_off(&IPL, &s, Mobita.nama, &u, &ability, &addMoveTime);
        } else if (isStringEqual(currentCommand,"MAP")) {
            DisplayMap(m, AM, Mobita, IPL, TDL);
        } else if (isStringEqual(currentCommand,"TO_DO")) {
            // fromRLtoTDL(&pq, &TDL, WAKTU(u));
            to_do(&TDL);
        } else if (isStringEqual(currentCommand,"IN_PROGRESS")) {
           in_progress(&IPL);
        } else if(isStringEqual(currentCommand,"BUY")) {
            buy(&u, AG, &IG, G);
        }  else if (isStringEqual(currentCommand,"INVENTORY")) {
            inventory(&IG, &IPL, &s, &u, &C, m, AM);
        } else if (isStringEqual(currentCommand,"HELP")) {
            Help();
        } else if (isStringEqual(currentCommand,"SAVE_GAME")) {
            save(m, AM, TDL, u, Mobita);
            printf("Permainan anda sedang disimpan...\n");
            delay(2);
            printf("Permainan anda berhasil disimpan!\n");
        } else if (isStringEqual(currentCommand,"RETURN")) {
            if(AbilityType(ability,2)) {
                if(EFFECT(s) == 3) {
                    printf("Maaf, return to sender tidak bisa digunakan untuk VIP Item\n");
                } else {
                    return_to_sender(&ability, &IPL, &s, &TDL, u);
                    AbilityType(ability,2) = false;
                }
            } else {
                printf("Maaf, anda tidak memiliki return to sender\n");
            }
        } else if (isStringEqual(currentCommand,"EXIT")){
            newGame = false;
            printf("Sampai jumpa di permainan berikutnya\n");
        } else {
            printf("COMMAND yang anda masukkan salah!\n");
        }
    } 
    return 0;
}