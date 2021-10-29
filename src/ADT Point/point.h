/*File: coordinate.h*/
/* ADT POINT*/

#ifndef coordinate_H
#define coordinate_H


#include "../boolean.h"
//#include "../ADT Mesin Kata/tokenmachine.h"


#define ROW_MAX 20
#define COL_MAX 30

typedef struct {
    char nama;
    int row;
    int col;
}  Coordinate;

//SELEKTOR

#define row(C) (C).row
#define col(C) (C).col
#define nama(C) (C).nama

/*PRIMITIF*/
/*KONSTRUKTOR*/
Coordinate* CreateCoord (char nama, int row, int col);
/*I.S. Koordinat sembarang*/
/*F.S. Koordinat diisi dengan valuenya masing-masing*/

/*I/O*/
void DisplayCoord(Coordinate C);
/*I.S. Koordinat terdefinisi*/
/*F.S. Ditampilkan koordinat dalam bentuk "nama (row,col)"*/

/*Cek indeks*/
boolean IsIdxCoordValid(Coordinate C);
/*I.S. Koordinat sembarang*/
/*F.S. Bernilai true untuk indeks koordinat yang berada dalam rentang  1 <= row <= 20 dan 1 <= col <= 30*/
boolean IsCoordEff(Coordinate C, int rowEff, int colEff);
/*I.S. Koordinat sembarang, rowEff dan colEff terdefinisi*/
/*F.S. bernilai true untuk indeks koordinat yang berada dalam rentang  1 <= row <= rowEff dan 1 <= col <= colEff*/


#endif