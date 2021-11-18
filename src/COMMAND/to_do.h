#ifndef TODO_H
#define TODO_H

#include "../boolean.h"
#include "../ADT Queue/requestList.h"
#include "../ADT Linked List/todoList.h"
#include "../ADT Lain/UangWaktu.h"

// Fungsi untuk memindahkan isi dari daftar pesanan ke dalam to do list sesuai waktu sekarang
void fromRLtoTDL(PrioQueue *q, to_do_List *tdl, int time);

// Fungsi untuk display to do list ketika diminta
void to_do(to_do_List *tdl);

#endif