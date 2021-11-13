#include "bfs.h"
#include <stdio.h>


void CreateBFSQueue(bfsQueue *Q)
{
    BFS_IDX_HEAD(*Q) = -1;
    BFS_IDX_TAIL(*Q) = -1;
}
void bfsEnqueue(bfsQueue *Q, int i)
{
    if((BFS_IDX_TAIL(*Q) == (QueueCapacity - 1)) && (BFS_IDX_HEAD(*Q) != 0))
    {
        int idx_geser = BFS_IDX_HEAD(*Q);
        int len = bfsLength(*Q);
        int i = 0;
        int temp;

        for(i; i < len; i++)
        {
            temp = BFS_HEAD(*Q);
            BFS_IDX_HEAD(*Q) -= idx_geser;
            BFS_HEAD(*Q) = temp;
            BFS_IDX_HEAD(*Q) += (1 + idx_geser);
        }
        BFS_IDX_HEAD(*Q) = 0;
        BFS_IDX_TAIL(*Q) -= (idx_geser - 1);
        BFS_TAIL(*Q) = i;
    }
    else if (isBFSQueueEmpty(*Q))
    {
        BFS_IDX_HEAD(*Q) = 0;
        BFS_IDX_TAIL(*Q) = 0;
        BFS_TAIL(*Q) = i;
    }
    else
    {
        BFS_IDX_TAIL(*Q) += 1;
        BFS_TAIL(*Q) = i;    
    }
}
void bfsDequeue(bfsQueue *Q, int *i)
{
    *i = BFS_HEAD(*Q);
    if (bfsLength(*Q) == 1)
    {
        BFS_IDX_HEAD(*Q) = -1;
        BFS_IDX_TAIL(*Q) = -1;
    }
    else
    {
        BFS_IDX_HEAD(*Q) += 1;
    }
}
boolean isBFSQueueEmpty(bfsQueue Q)
{
    return ((BFS_IDX_HEAD(Q) == -1) && (BFS_IDX_TAIL(Q) == -1));
}
int bfsLength(bfsQueue Q)
{
    if(isBFSQueueEmpty(Q))
    {
        return 0;
    }
    else
        return (BFS_IDX_TAIL(Q)-BFS_IDX_HEAD(Q) + 1);
}
void displayBFSQueue(bfsQueue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    if(isBFSQueueEmpty(q))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        int i = 0;
        int save_idx = BFS_IDX_HEAD(q);
        int len = bfsLength(q);

        for(i; i < len; i++)
        {

            if(i == (len - 1))
            {
                printf("%d", BFS_TAIL(q));
                printf("]");
            }
            else
            {
                printf("%d", BFS_HEAD(q));
                printf(",");
                BFS_IDX_HEAD(q) += 1;
            }
        }
        BFS_IDX_HEAD(q) = save_idx;
    }
}


void bfs(map *m, bfsQueue *Q, int *waktu, adjMatrix A, Coordinate src, Coordinate check)
{
    visited v;
    distance d;
    int temp, checkName;
    for(int i = 0; i < adjLength(A); i++)
    {
        isVisited(v, i) = false;
        Distance(d, i) = 0;
    }
    if(nama(src) == '8')
    {
        bfsEnqueue(Q, 0);
        isVisited(v, 0) = true;
        Distance(d, 0) = 0;
    }
    else
    {
        int index = nama(src)-'A' + 1;
        bfsEnqueue(Q, index);
        isVisited(v, index) = true;
        Distance(d, index) = 0;
    }

    while(!isBFSQueueEmpty(*Q))
    {
        int u = (BFS_HEAD(*Q));
        bfsDequeue(Q, &temp);
        for(int V = 0; V < adjLength(A); V++)
        {
            if(!isVisited(v, V) && adjacent(A, u, V) == 1)
                {
                    
                    bfsEnqueue(Q, V);
                    isVisited(v, V) = true;
                    Distance(d, V) = Distance(d, u) + 1;
                }
        }
    }

    if(nama(check) == '8')
    {
        checkName = 0;
    }
    else
    {
        checkName = nama(check)-'A' + 1;
    }
    *waktu = Distance(d, checkName);
}