#include <stdio.h>
#include "inventory.h"

void movePintuKemanaSaja(map m, Coordinate *Mobita, adjMatrix A, InventoryGadget *IG, Gadget G, in_progress_list *ipl, to_do_List *tdl) {
    DisplayMap(m, A, *Mobita, *ipl, *tdl);
    printf("Ingin pindah ke lokasi mana? ");
    char newLoc = readChar();
    Coordinate *dest = CoordByName(m, newLoc);
    if (dest != NULL) {
        move_loc(Mobita, *dest, &m);
        printf("Mobita sekarang berada di titik ");
        DisplayCoord(*Mobita);
        printf("!\n");
        printf("%s berhasil digunakan\n", NAME(G));
    }
    else {
        printf("%s terbuang sia-sia karena input tidak valid\n", NAME(G));
    }
    deleteGadget(IG, G);
}

void inventory(InventoryGadget *IG, in_progress_list *ipl, to_do_List *tdl, Stack *s, UangWaktu *c, map m, adjMatrix A, Coordinate *Mobita, int *addMoveTime){
    int x;
    displayInventory(*IG);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    x = readNumberfromSTDIN();
    if(x == 0) {
        printf("Tidak ada gadget yang jadi digunakan\n");
    } else if(x < 0 || x > 5) {
        printf("Nomor yang anda masukkan tidak tepat!\n");
    } else {
        if (x <= NEFF(*IG)) { // Kondisi ketika Gadget tersebut ada
            Gadget G;
            G = ELMT(*IG, x-1);
            if (ID(G) == 1) {
                // kain pembungkus waktu
                struct items perishItem;
                if (TOP(*s).type == 'P') {
                    // Posisi item tersebut pada progress list sinkron dengan pada stack, elemen terakhir
                    int i = lengthIPL(*ipl) - 1;
                    // printf("old perishable start time: %d \n",getElmtIP(*ipl, i).startTime);
                    inProgressList newIPL = getElmtIP(*ipl,i);
                    newIPL.startTime = WAKTU(*c);       // durasi sisanya jadi kembali seperti semula
                    setElmtIP(ipl, i, newIPL);
                    // printf("new perishable start time:  %d \n",getElmtIP(*ipl, i).startTime);
                    printf("%s berhasil digunakan\n", NAME(G));
                }
                else {
                    printf("%s terbuang sia-sia karena item teratas bukan perishable item\n", NAME(G));
                }
                deleteGadget(IG, G);
            }
            
            else if (ID(G) == 2) {
                // senter pembesar
                if(MAKSIMUM(*s) * 2 > CAPACITYSTACK){
                    printf("%s terbuang sia-sia karena melebihi kapasitas maksimum\n", NAME(G));
                }else{
                    MAKSIMUM(*s) *= 2;
                    printf("%s berhasil digunakan\n", NAME(G));
                }
                deleteGadget(IG, G);
            }
            
            else if (ID(G) == 3) {
                // pintu kemana saja
                movePintuKemanaSaja(m, Mobita, A, IG, G, ipl, tdl);
            }
            
            else if (ID(G) == 4) {
                // mesin waktu
                if(WAKTU(*c) < 50){
                    WAKTU(*c) = 0;
                }else{
                    WAKTU(*c) = WAKTU(*c) - 50;
                }
                printf("%s berhasil digunakan\n", NAME(G));
                deleteGadget(IG, G);
            }

            else if (ID(G) == 5) {
                // senter pengecil, menghilangkan efek heavy item
                if (TYPE(*s) == 'H') {
                    inProgressList tempProgress;        // mengubah status di progress list
                    deleteLastIP(ipl, &tempProgress);
                    tempProgress.type = 'N';
                    insertLastIP(ipl, tempProgress);
                    TOP(*s).type = 'N';
                    copyString(TOP(*s).name, "Normal Item");
                    *addMoveTime -= 1;

                    printf("%s berhasil digunakan\n", NAME(G));
                }
                else {
                    printf("%s terbuang sia-sia karena item teratas bukan Heavy Item!\n", NAME(G));
                }
                deleteGadget(IG, G);
            }
        } else {
            // Kondisi ketika Gadget tersebut tidak ada
            printf("Gadget yang dipilih tidak ada pada inventory!\n");
        }
    }
}
