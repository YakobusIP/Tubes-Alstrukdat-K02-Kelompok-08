/*File: map.h*/

#ifndef MAP_H
#define MAP_H

#include "adjMatriks.h"
#include "../ADT Point/point.h"
#include "../pcolor/pcolor.h"
#include "../ADT Linked List/inprogressList.h"
#include "../ADT Linked List/todoList.h"


#define ROW_MAX 20
#define COL_MAX 30
#define NONE '1'


typedef struct {
    Coordinate *coordinate[ROW_MAX+2][COL_MAX+2];
    int nRow;
    int nCol;
} map;


/*SELEKTOR*/
#define nRow(M) (M).nRow
#define nCol(M) (M).nCol
#define CoordPointer(M, i, j) (M).coordinate[(i)][(j)]
#define CoordNama(M, i, j) (M).coordinate[(i)][(j)]->nama


/*PRIMITIF*/

/*KONSTRUKTOR*/
void CreateMap(map *M, int nRow, int nCol);
/*I.S. M sembarang, nRow dan nCol berada dalam range*/
/*F.S. Terbentuk matriks map kosong dengan value pointer null*/

/*I/O*/
void ReadMap(map * M, Coordinate *C);
/*I.S. Map terdefinisi, Koordinat terdefinisi*/
/*F.S. Koordinat ditambahkan pada map*/
void DisplayMap(map M, adjMatrix A, Coordinate Mobita, in_progress_list ipl, to_do_List tdl);
/*I.S. Map terdefinisi*/
/*Menampilkan peta*/
void ListCoordinate(map M);
/*LAINNYA*/
Coordinate* CoordByName(map m, char nama);
/*I.S. Map terdefinisi, nama terdefinisi*/
/*F.S. Dikembalikan koordinat dengan nama 'nama' dari peta yang sudah ada*/
#endif
