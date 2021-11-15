#include <stdio.h>
#include "inventory.h"
// #include "../ADT Lain/UangWaktu.c"
// #include "../ADT Linked List/inprogressList.c"
// #include "../ADT Linked List/inprogressNode.c"
// #include "../ADT Linked List/todoNode.c"
// #include "../ADT List/adjList.c" 
// #include "../ADT List/Gadget.c"
// #include "../ADT List/InventoryGadget.c"
// #include "../ADT Matriks/adjMatriks.c"
// #include "../ADT Matriks/map.c"
// #include "../ADT Mesin Kata/charmachine.c"
// #include "../ADT Mesin Kata/tokenmachine.c"
// #include "../ADT Point/point.c"
// #include "../ADT Stack/stack.c"
// #include "../ADT Queue/requestList.c"
// #include "../pcolor/pcolor.c"
// #include "../boolean.h"

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
        printf("%s tidak jadi digunakan\n", NAME(G));
    } else if (num < 0 || num > lengthAdjList(l)) {
        printf("Input tidak valid!\n");
    } else {
        *src = *ElmtPointer(l, num-1);
        printf("Mobita sekarang berada di titik ");
        DisplayCoord(*src);
        printf("!\n%s berhasil digunakan", NAME(G));
        deleteGadget(IG, G);
    }
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
        if (ELMT(*IG, x).ID == ID(G)) { // Kondisi ketika Gadget tersebut ada
            if (ID(G) == 1) {
                // kain pembungkus waktu
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
                        printf("%s berhasil digunakan\n", NAME(G));
                        deleteGadget(IG, G);
                    } else {
                        printf("%s tidak berhasil digunakan\n", NAME(G));
                    }
                }
                else {
                    printf("%s tidak berhasil digunakan karena item teratas bukan perisable item\n", NAME(G));
                }
            }
            
            else if (ID(G) == 2) {
                // senter pembesar
                if(MAKSIMUM(*s) * 2 > CAPACITYSTACK){
                    printf("%s tidak dapat digunakan karena melebihi kapasitas maksimum\n", NAME(G));
                }else{
                    MAKSIMUM(*s) *= 2;
                    printf("%s berhasil digunakan\n", NAME(G));
                    deleteGadget(IG, G);
                }
            }
            
            else if (ID(G) == 3) {
                // pintu kemana saja
                movePintuKemanaSaja(src, m, A, IG, G);
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

            } else if (ID(G) == 5) {
                // senter pengecil, menghilangkan efek heavy item
                if (TOP(*s).type == "H") {
                    copyString(TOP(*s).type, "N");
                    printf("%s berhasil digunakan\n", NAME(G));
                    deleteGadget(IG, G);
                }
                else {
                    printf("%s gagal digunakan karena item teratas bukan Heavy Item!\n", NAME(G));
                }
            }
        } else {
            // Kondisi ketika Gadget tersebut tidak ada
            printf("Gadget yang dipilih tidak ada pada inventory!\n");
        }
    }
}

int main() {
    printf("a");
}