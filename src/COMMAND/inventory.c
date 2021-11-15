#include "inventory.h"
#include <stdio.h>

void movePintuKemanaSaja(Coordinate *src, map m, adjMatrix A, InventoryGadget *IG, Gadget G) {
    char c;
    adjList l;
    CreateAdjList(&l);
    int num;

    c = nama(*src);
    printf("Posisi yang dapat dicapai: \n");
    AdjList(m, &l, A, c);
    for(int i = 0; i < lengthAdjList(l); i++)
    {
        printf("%d. ", i+1);
        DisplayCoord(*ElmtPointer(l, i));
        printf("\n");
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    scanf("%d", &num);
    if (num == 0) {
        printf("Pintu kemana saja tidak jadi digunakan\n");
    } else if (num < 0 || num > lengthAdjList(l)) {
        printf("Input tidak valid!\n");
    } else {
        *src = *ElmtPointer(l, num-1);
        printf("Mobita sekarang berada di titik ");
        DisplayCoord(*src);
        printf("!\nPintu kemana saja berhasil digunakan");
        deleteGadget(IG, G);
    }
}

int lengthIPL(in_progress_list ipl) {
    ipAddress p;
    p = FIRST(ipl);
    int i = 0;
    while (p != NULL) {
        i++;
    }
    return i;
}

void inventory(InventoryGadget *IG, in_progress_list *ipl, Stack *s, UangWaktu *c, Coordinate *src, map m, adjMatrix A){
    int x;
    displayInventory(*IG);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    scanf("%d", &x);
    if(x == 0) {
        printf("Tidak ada gadget yang jadi digunakan\n");
    } else if(x < 0 || x > 5) {
        printf("Nomor yang anda masukkan tidak tepat!\n");
    } else {
        Gadget G;
        G = ELMT(*IG, x);
        if (ELMT(*IG, x).ID == ID(G)) {
            // Kondisi ketika Gadget tersebut ada
            if (ID(G) == 1) {
                struct items perishItem;
                if (TOP(*s).type == "P") {
                    // Mencari item tersebut pada progress list
                    int i = lengthIPL(*ipl) - 1;
                    boolean flag = false;
                    while (i>=0 && !flag) {
                        if (getElmtIP(*ipl,i).type == 'P') {
                            inProgressList newIPL = getElmtIP(*ipl,i);
                            newIPL.startTime = WAKTU(*c);
                            setElmtIP(ipl, i, newIPL);
                            flag = true;
                        } else {
                            i--;
                        }
                    }
                    
                    if (flag) {
                        printf("Kain pembungkus waktu berhasil digunakan\n");
                        deleteGadget(IG, G);
                    } else {
                        printf("Kain pembungkus waktu tidak berhasil digunakan\n");
                    }
                }
                else {
                    printf("Kain pembungkus waktu tidak berhasil digunakan\n");
                }
            }
            
            else if (ID(G) == 2) {
                if(MAKSIMUM(*s) * 2 > CAPACITYSTACK){
                    printf("Senter Pembesar tidak dapat digunakan karena melebihi kapasitas maksimum\n");
                }else{
                    MAKSIMUM(*s) *= 2;
                    printf("Senter Pembesar berhasil digunakan\n");
                    deleteGadget(IG, G);
                }
            }
            
            else if (ID(G) == 3) {
                movePintuKemanaSaja(src, m, A, IG, G);
            }
            
            else if (ID(G) == 4) {
                if(WAKTU(*c) < 50){
                    WAKTU(*c) = 0;
                }else{
                    WAKTU(*c) = WAKTU(*c) - 50;
                }
                deleteGadget(IG, G);

            } else if (ID(G) == 5) {
                // menghilangkan efek heavy item
                if (TOP(*s).type == 'H') {
                    TOP(*s).type = 'N';
                    deleteGadget(IG, G);
                    printf("Senter pengecil berhasil digunakan!\n");
                }
                else {
                    printf("Senter pengecil gagal digunakan karena item teratas bukan Heavy Item!\n");
                }
            }
        } else {
            // Kondisi ketika Gadget tersebut tidak ada
            printf("Gadget yang dipilih tidak ada pada inventory!\n");
        }
    }
}