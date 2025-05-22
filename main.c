#include <stdio.h>

int main() {
    int opsi = 0;
    printf("Selamat Datang dalam Program Foodlink!\n");
    printf("Menu Utama\n");
    
    do {
        printf("1. Tambah Donatur\n2. Tambah Penerima\n3. Lihat Semua Data\n4. Cocokkan Donasi\n5. Tampilkan Laporan Donasi\n");
        printf("Pilihlah Opsi yang Anda ingin Lakukan (1-5) : ");
        scanf("%d", &opsi);
        switch (opsi) {
            case 1:
                // Untuk Tambah Donatur
                break;
            case 2:
                // Untuk Tambah Penerima
                break;
            case 3:
                // Untuk Melihat Semua Data
                break;
            case 4:
                // Untuk Mencocokkan Donasi
                break;
            case 5:
                // Untuk Menampilkan Laporan Donasi
                break;
            case 6:
                return 0;
            default:
                printf("Tolong Pilihlah Opsi yang sesuai!\n");
                break;
        }
    } while(opsi != 5);
    return 0;
}
