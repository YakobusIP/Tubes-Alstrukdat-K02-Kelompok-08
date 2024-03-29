#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "boolean.h"

// ADT
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

// COMMAND
#include "../src/COMMAND/buy.h"
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


int main(){
    /* Kamus */    
    // Deklarasi ADT
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
    Ability ability; 

    char currentLocation;
    boolean failToLoad;
    int addMoveTime = 0;      // waktu tambahan jika membawa heavy item, dapat menumpuk
    int waktu = 0;
    int itemCounter = 0; // Jumlah item yang sukses
    struct items val;
    boolean newGame; // Boolean untuk menampilkan apakah game sukses dimulai atau tidak, jika sukses, akan menjadi true

    /* Algoritma */

    failToLoad = false; // Jika file yang ingin di load tidak ada, maka akan muncul pesan error
    newGame = false; // Jika true, maka akan masuk ke permainan utama

    // Membuat konstruktor yang ada
    CreateUangWaktu(&u);
    CreateStack(&s);
    CreateAvailableGadget(&AG);
    CreateInventoryGadget(&IG);
    CreateToDoList(&TDL);
    CreatePrioQueue(&pq);
    createInProgressList(&IPL);
    CreateAbility(&ability);

    // Main Menu
    mainMenu();
    readCommand(&currentCommand);
    if(isStringEqual(currentCommand,"1")){
        start_game(&pq, &m, &AM);
        printf("Harap tunggu sebentar...\n");
        delay(2);
        printf("Permainan anda sedang disiapkan...\n");
        delay(2);
        printf("Ini dia!\n");
        delay(1);
        printf("Enjoy the Game!\n");
        newGame = true;
        Mobita = *CoordByName(m, '8');
    }else if(isStringEqual(currentCommand, "2") ){
        load(&pq, &m, &AM, &failToLoad, &u, &Mobita, &s, &IG, &itemCounter, &waktu, &ability, &IPL);
        if(failToLoad == false) {
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

    // Masuk ke permainan utama
    while(newGame) {
        speed_boost(&ability, &waktu, &u, &IPL);
        increase_capacity(ability, &s);
        fromRLtoTDL(&pq, &TDL, WAKTU(u));
        printf("Uang anda sekarang adalah: %d", UANG(u));
        printf("\nWaktu sekarang adalah: %d\n", WAKTU(u));
        printf("\nENTER COMMAND: ");
        readCommand(&currentCommand);
        if(isStringEqual(currentCommand,"MOVE")) {
            move(&s, &IPL, &Mobita, m,  AM, &u, &ability, &waktu, addMoveTime);
        } else if (isStringEqual(currentCommand,"PICK_UP")) {
            pick_up(&TDL, &s, &IPL, Mobita.nama, &addMoveTime, &u);
        } else if (isStringEqual(currentCommand,"DROP_OFF")) {
            drop_off(&IPL, &s, Mobita.nama, &u, &ability, &addMoveTime, &itemCounter);
        } else if (isStringEqual(currentCommand,"MAP")) {
            DisplayMap(m, AM, Mobita, IPL, TDL);
        } else if (isStringEqual(currentCommand,"TO_DO")) {
            to_do(&TDL);
        } else if (isStringEqual(currentCommand,"IN_PROGRESS")) {
           in_progress(&IPL, WAKTU(u));
        } else if(isStringEqual(currentCommand,"BUY")) {
            buy(&u, AG, &IG, G);
        }  else if (isStringEqual(currentCommand,"INVENTORY")) {
            inventory(&IG, &IPL, &TDL, &s, &u, m, AM, &Mobita, &addMoveTime);
        } else if (isStringEqual(currentCommand,"HELP")) {
            Help();
        } else if (isStringEqual(currentCommand,"SAVE_GAME")) {
            save(pq, m, AM, TDL, u, Mobita, s, IG, itemCounter, waktu, ability, IPL);
            printf("Permainan anda sedang disimpan...\n");
            delay(2);
            printf("Permainan anda berhasil disimpan!\n");
        } else if (isStringEqual(currentCommand,"RETURN")) {
            if(TotalVIP(ability) > 0) {
                if(isEmptyStack(s) && isIPListEmpty(IPL)) {
                    printf("Tas anda kosong! Return to sender tidak dapat digunakan\n");
                } else {
                        if(EFFECT(s) == 3) {
                        printf("Maaf, return to sender tidak bisa digunakan untuk VIP Item\n");
                    } else {
                        return_to_sender(&ability, &IPL, &s, &TDL, u);
                        TotalVIP(ability) -= 1;
                        if(TotalVIP(ability) == 0) {
                            AbilityType(ability,2) = false;
                        }
                    }
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

        // Kondisi ketika Final Game, yaitu to do list kosong, in progress list kosong, dan berada di headquarter
        if(isIPListEmpty(IPL) && isTDListEmpty(TDL) && Mobita.nama == '8' && WAKTU(u) > 0) {
            newGame = false;
            printf("Selamat! Anda telah berhasil menyelesaikan game ini!\n");
            printf("Sedang menghitung total item yang berhasik terantar...\n");
            delay(2);
            printf("Total item yang telah diantarkan: %d\n", itemCounter);
            delay(1);
            printf("Total waktu yang telah dilalui: %d\n", WAKTU(u));
            delay(1);
            printf("Kami menunggu anda untuk bermain kembali!\n");
        }
    } 
    return 0;
}
