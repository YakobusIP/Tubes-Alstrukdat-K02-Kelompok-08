#include "inventory.h"
#include <stdio.h>

void inventory(InventoryGadget IG, AvailableGadget AG, inProgressList l, Stack *s, map m,  UangWaktu *c){
    int x;
    struct Gadget G;
    int ID;
    displayAvailableGadget(AG);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    adv();
    x = readNumberfromChar();
    if(x == 0){
        printf("Anda Tidak Jadi Menggunakan Gadget\n");
    }else if(x < 0 || x > 5){
        printf("Nomor yang anda masukkan tidak tepat!\n");
    }else{
        int i;
        for (i=1; i <= 5; i++ ) {
            if (x == i) {
                G = ELMT(IG, i);
                if (ELMT(IG, i).ID == G.ID) {
                    // Kondisi ketika Gadget tersebut ada
                    if (ID == 1) {
                        
                    } else if (ID == 2) {
                        if(MAKSIMUM(*s) * 2 > CAPACITYSTACK){
                            printf("Mohon maaf, Senter Pembesar tidak dapat digunakan\n");
                        }else{
                            MAKSIMUM(*s) = MAKSIMUM(*s) * 2;
                        }
                    } else if (ID == 3) {
                        
                    } else if (ID == 4) {
                        if(WAKTU(*c) < 50){
                            WAKTU(*c) = 0;
                        }else{
                            WAKTU(*c) = WAKTU(*c) - 50;
                        }
                        
                    } else if (ID == 5) {
                        
                    } 
                } else {
                    // Kondisi ketika Gadget tersebut tidak ada
                    printf("Gadget yang dipilih tidak ada!\n");
                }
                break;
            }
        }

        
    }
}