#include "../boolean.h"
#include "../ADT Point/point.h"
#include "../ADT Matriks/adjMatriks.h"
#include "../ADT Matriks/map.h"



#define QueueCapacity 27
#define INFTY 999

typedef struct {
	int buffer[QueueCapacity]; 
	int idxBFSHead;
	int idxBFSTail;
} bfsQueue;

#define BFS_IDX_HEAD(q) (q).idxBFSHead
#define BFS_IDX_TAIL(q) (q).idxBFSTail
#define     BFS_HEAD(q) (q).buffer[(q).idxBFSHead]
#define     BFS_TAIL(q) (q).buffer[(q).idxBFSTail]
#define Distance(D, i) (D).distance[(i)]

typedef struct {
    boolean isVisited[27];
} visited;

#define isVisited(V, i) (V).isVisited[(i)]

typedef struct {
    int distance[27];
} distance;


void CreateBFSQueue(bfsQueue *Q);
void bfsEnqueue(bfsQueue *Q, int i);
void bfsDequeue(bfsQueue *Q, int *i);
boolean isBFSQueueEmpty(bfsQueue Q);
int bfsLength(bfsQueue Q);
void displayBFSQueue(bfsQueue q);
void bfs(map *m, bfsQueue *Q, int *waktu, adjMatrix A, Coordinate src, Coordinate check);
