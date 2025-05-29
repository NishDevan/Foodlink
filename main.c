#include <stdio.h>
#include <string.h>

#define MAX_DONATUR 100
#define MAX_PENERIMA 100

typedef struct {
    char nama[50];
    char jenisMakanan[50];
    int jumlah;
    char lokasi[50];
} Donatur;

typedef struct {
    char nama[50];
    char kebutuhan[50];
    int jumlah;
    char lokasi[50];
} Penerima;

Donatur daftarDonatur[MAX_DONATUR];
int jumlahDonatur = 0;

Penerima daftarPenerima[MAX_PENERIMA];
int jumlahPenerima = 0;

int hitungSkorKecocokan(Penerima *p, Donatur *d) {
    return 0;
}

void cocokkanDonasi() {
    printf("\n=== Proses Pencocokan Massal ===\n");
    for (int i = 0; i < jumlahPenerima; i++) {
        printf("\nPenerima %s:\n", daftarPenerima[i].nama);
        
    }
}

void tampilkanLaporan() {
    printf("\n=== Laporan Ringkas ===\n");
    printf("Jumlah Donatur  : %d\n", jumlahDonatur);
    printf("Jumlah Penerima : %d\n", jumlahPenerima);
}

int main() {
    int opsi = -1;

    printf("Selamat Datang di Program Foodlink!\n");

    while (opsi != 0) {
        printf("\nMenu Utama:\n");
        printf("1. Tambah Donatur\n");
        printf("2. Tambah Penerima\n");
        printf("3. Lihat Semua Data\n");
        printf("4. Cocokkan Donasi (Massal)\n");
        printf("5. Tampilkan Laporan Donasi\n");
        printf("0. Keluar\n");
        printf("Pilih opsi (0-5): ");
        scanf("%d", &opsi);

        switch (opsi) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                cocokkanDonasi();
                break;
            case 5:
                tampilkanLaporan();
                break;
            case 0:
                printf("Terima kasih telah menggunakan Foodlink!\n");
                break;
            default:
                printf("Tolong Pilihlah Opsi yang sesuai!\n");
        }
    }

    return 0;
}
