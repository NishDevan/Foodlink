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
    int skor = 0;
    if (strcmp(p->kebutuhan, d->jenisMakanan) == 0) skor++;
    if (p->jumlah <= d->jumlah) skor++;
    if (strcmp(p->lokasi, d->lokasi) == 0) skor++;
    return skor;
}

void inputDonatur() {
    if (jumlahDonatur >= MAX_DONATUR) {
        printf("Kapasitas maksimum donatur telah tercapai.\n");
        return;
    }

    Donatur *d = &daftarDonatur[jumlahDonatur];

    printf("\n=== Input Data Donatur ===\n");
    printf("Nama Donatur       : ");
    scanf(" %[^\n]", d->nama);
    printf("Jenis Makanan      : ");
    scanf(" %[^\n]", d->jenisMakanan);
    printf("Jumlah             : ");
    scanf("%d", &d->jumlah);
    printf("Lokasi             : ");
    scanf(" %[^\n]", d->lokasi);

    jumlahDonatur++;                  
    printf("Donatur berhasil ditambahkan.\n");
}

void inputPenerima() {
    if (jumlahPenerima >= MAX_PENERIMA) {
        printf("Kapasitas maksimum penerima telah tercapai.\n");
        return;
    }

    Penerima *p = &daftarPenerima[jumlahPenerima];

    printf("\n=== Input Data Penerima ===\n");
    printf("Nama Penerima        : ");
    scanf(" %[^\n]", p->nama);
    printf("Jenis Makanan Dibutuhkan : ");
    scanf(" %[^\n]", p->kebutuhan);
    printf("Jumlah Dibutuhkan    : ");
    scanf("%d", &p->jumlah);
    printf("Lokasi Penerima      : ");
    scanf(" %[^\n]", p->lokasi);

    jumlahPenerima++;

    int maxSkor = -1;
    Donatur *donaturTerbaik = NULL;

    for (int i = 0; i < jumlahDonatur; i++) {
        int skor = hitungSkorKecocokan(p, &daftarDonatur[i]);
        if (skor > maxSkor) {
            maxSkor = skor;
            donaturTerbaik = &daftarDonatur[i];
        }
    }

    printf("\n=== Hasil Pencocokan ===\n");
    if (indeksTerbaik != -1 && maxSkor > 0) {
        struct donatur d = daftarDonatur[indeksTerbaik];
        printf("Penerima \"%s\" cocok dengan donatur:\n", p.nama);
        printf("Nama Donatur : %s\n", d.nama);
        printf("Jenis        : %s\n", d.jenisMakanan);
        printf("Jumlah       : %d\n", d.jumlah);
        printf("Lokasi       : %s\n", d.lokasi);
        printf("Skor Kecocokan: %d dari 3\n", maxSkor);
    } else {
        printf("Tidak ditemukan donatur yang cocok untuk \"%s\".\n", p.nama);
    }
}

//fungsi menampilkan semua data
void tampilkanSemuaData() {
    printf("\n=== Daftar Donatur ===\n");
    for (int i = 0; i < jumlahDonatur; i++) {
        Donatur *d = &daftarDonatur[i];
        printf("%d. %s - %s - %d - %s\n", i + 1,
               d->nama, d->jenisMakanan, d->jumlah, d->lokasi);
    }

    printf("\n=== Daftar Penerima ===\n");
    for (int i = 0; i < jumlahPenerima; i++) {
        Penerima *p = &daftarPenerima[i];
        printf("%d. %s - %s - %d - %s\n", i + 1,
               p->nama, p->kebutuhan, p->jumlah, p->lokasi);
    }
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
                inputDonatur();
                break;
            case 2:
                inputPenerima();
                break;
            case 3:
                tampilkanSemuaData();
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

    return 0;
}