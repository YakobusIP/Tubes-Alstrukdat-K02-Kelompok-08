#include <stdio.h>
#include "move.h"


void move(Stack *s, in_progress_list *IPL, Coordinate *src, map m, adjMatrix A, UangWaktu *u, Ability *ability, int *waktu)
{
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
    num = readNumberfromSTDIN();

    if(num >= 1 && num < lengthAdjList(l) + 1)
    {
        *src = *ElmtPointer(l, num-1);
        printf("Mobita sekarang berada di titik ");
        DisplayCoord(*src);
        printf("!\n");

        /*stack *s, in_progress_list *ipl  */
        inProgressList temp_ipl, p;
        struct items temp_item;

        if(isHeavyinIPL(*IPL))
        {
            if(AbilityType(*ability, 0))
                {
                    AbilityType(*ability, 0) = false;
                }
            else ChangeWaktu(u, 1);
        }

        if(AbilityType(*ability, 0)) //khusus speed_boost
        {
            *waktu++;
        }
        else
        {
            ChangeWaktu(u, 1); //Tambah waktu sebanyak 1 satuan waktu
        } 

        int save_idx = IDX_TOP(*s);
        int i = save_idx;
        
        while(i >= 0)
        {
            p = getElmtIP(*IPL, i);
            //waktusekarang-starttime >= time limit
            if(p.type == 'P' && (WAKTU(*u) - p.startTime >= p.timeLimit))
            {
                deleteAtIP(IPL, i, &temp_ipl);
                popStack(s, &temp_item);
                save_idx--;
            }
            else
            {
                IDX_TOP(*s)--;
            }
            i--;
        }
        IDX_TOP(*s) = save_idx;
    }    
}

