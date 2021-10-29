/*Coordinate.h*/ 
/*Tipe Data Point*/
#include <stdio.h>
#include <stdlib.h>
#include "point.h"


//KONSTRUKTOR
Coordinate* CreateCoord (char namaCoord, int row, int col)
{
    Coordinate *C = (Coordinate*) malloc(sizeof(Coordinate));
    row(*C) = row;
    col(*C) = col;
    nama(*C) = namaCoord;
    return C;
}

void DisplayCoord(Coordinate C)
{   
    //Contoh: A (1,3) dengan nama = A, row = 1, col = 3

    printf("%c", nama(C));
    printf(" (%d,%d)", row(C), col(C));   
}

boolean IsIdxCoordValid(Coordinate C)
{
    /*Dengan mengurangi row_max dan row_min (dan juga utk col) untuk penempatan '*', */
    /*Maka idx Coord yang valid adalah 1 <= row <= 20 dan 1 <= col <= 30 */
    
    return ((row(C) < ROW_MAX + 1 && row(C) >= 1) && (col(C) < COL_MAX + 1 && col(C) >= 1));
}

boolean IsCoordEff(Coordinate C, int rowEff, int colEff)
/*Cek apakah Coord masuk indeks efektif*/
/*PERHATIAN!! yng dicek adalah indeks map, sehingga dimulai dari nol*/
{
    return ((row(C) < rowEff + 1 && row(C) >= 1) && (col(C) < colEff + 1 && col(C) >= 1));
}
