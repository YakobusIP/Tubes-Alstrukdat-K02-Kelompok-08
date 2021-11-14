#include <stdio.h>
#include "help.h"

void Help(){
    printf("BERIKUT ADALAH COMMAND YANG BISA ANDA GUNAKAN DALAM GAME INI\n");
    printf("1. MOVE        - Berpindah ke lokasi selanjutnya\n");
    printf("2. PICK UP     - Mengambil item jika ada pesanan yang harus diambil pada lokasi\n");
    printf("3. DROP OFF    - Mengantarkan item di tumpukan teratas tas jika lokasi sesuai\n");
    printf("4. MAP         - Memunculkan peta\n");
    printf("5. TO DO       - Menampilkan pesanan yang masuk ke To Do List\n");
    printf("6. IN PROGRESS - Menampilkan pesanan yang sedang dikerjakan\n");
    printf("7. BUY         - Membeli gadget yang tersedia pada sistem\n");
    printf("8. INVENTORY   - Menampilkan isi inventory dan memilih gadget yang akan digunakan\n");
    printf("9. HELP        - Menampilkan seluruh command yang dapat dimasukkan beserta deskripsinya\n");
    printf("10. SAVE GAME  - Menyimpan state dari permainan yang sedang dijalankan\n");
    printf("11. RETURN     - Mengembalikan item di tumpukan teratas pada tas kembali ke lokasi pick up\n");
}