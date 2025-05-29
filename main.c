#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BERAS,
    SAYUR,
    BUAH,
    ROTI,
    LAINNYA
} JenisMakanan;

char namaJenisMakanan[5][20] = {"Beras", "Sayur", "Buah", "Roti", "Lainnya"};

typedef struct {
    char namaDonatur[50];
    char jenisMakanan[30];
    int jumlah;
    char lokasi;
} Donatur;

typedef struct {
    char namaPenerima[50];
    char kebutuhan[30];
    char lokasi[30];
} Penerima;

int main() {
    int opsi = 0;
    printf("Selamat Datang dalam Program Foodlink!\n");
    printf("Menu Utama\n");
    
    do {
        printf("1. Tambah Donatur\n2. Tambah Penerima\n3. Lihat Semua Data\n4. Cocokkan Donasi\n5. Tampilkan Laporan Donasi\n6. Keluar\n");
        printf("Pilihlah Opsi yang Anda ingin Lakukan (1-5) : ");
        scanf("%d", &opsi);
        printf("\n");
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
<<<<<<< HEAD
                // Untuk Menampilkan Donasi
                break;
            case 6:
                // Keluar
=======
                // Untuk Menampilkan Laporan Donasi
                break;
            case 6:
>>>>>>> main
                return 0;
            default:
                printf("Tolong Pilihlah Opsi yang sesuai!\n");
                break;
        }
    } while(opsi != 5);
    return 0;
}
<<<<<<< HEAD

void pilihJenisMakanan() {
    int pilihan;
    printf("Pilih Jenis Makanan:\n");
    for (int i = 1; i < 5; i++) {
        printf("%d. %s\n", i, namaJenisMakanan[i]);
    }
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    if (pilihan >= 1 && pilihan <= 5) {
        return (JenisMakanan)pilihan;
    } else {
        printf("Pilihan tidak valid, diatur ke 'Lainnya',\n");
        return LAINNYA;
    }
}

void TambahDonatur(Donatur **donaturList, int *jumlahDonatur) {
    *donaturList = realloc(*donaturList, (*jumlahDonatur + 1) * sizeof(Donatur));
    Donatur *donatur = &(*donaturList)[*jumlahDonatur];
    
    printf("Nama Donatur : ");
    scanf(" %[^\n]", donatur->namaDonatur);
    printf("Jenis Makanan : ");
    scanf(" %[^\n]", donatur->jenisMakanan);
    *donatur->jenisMakanan = pilihJenisMakanan();
}
=======
>>>>>>> main
