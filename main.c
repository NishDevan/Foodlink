#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DONATUR 100
#define MAX_PENERIMA 100

// Enum untuk lokasi dan jenis makanan
typedef enum { SUKMAJAYA, BEJI, CIMANGGIS, TUGU, LOKASI_INVALID } Lokasi;
typedef enum { NASI, SAYUR, BUAH, DAGING, IKAN, JENIS_INVALID } JenisMakanan;

const char* lokasiStr[] = {"Sukmajaya", "Beji", "Cimanggis", "Tugu"};
const char* jenisStr[] = {"nasi", "sayur", "buah", "daging", "ikan"};

Lokasi parseLokasi(const char* str) {
    for (int i = 0; i < 4; i++) {
        if (strcasecmp(str, lokasiStr[i]) == 0) return i;
    }
    return LOKASI_INVALID;
}

JenisMakanan parseJenis(const char* str) {
    for (int i = 0; i < 5; i++) {
        if (strcasecmp(str, jenisStr[i]) == 0) return i;
    }
    return JENIS_INVALID;
}

typedef struct {
    char nama[50];
    JenisMakanan jenisMakanan;
    int jumlah;
    Lokasi lokasi;
    bool sudahDipakai;
} Donatur;

typedef struct {
    char nama[50];
    JenisMakanan kebutuhan;
    int jumlah;
    Lokasi lokasi;
} Penerima;

Donatur daftarDonatur[MAX_DONATUR];
int jumlahDonatur = 0;

Penerima daftarPenerima[MAX_PENERIMA];
int jumlahPenerima = 0;

int hitungSkorKecocokan(Penerima *p, Donatur *d) {
    int skor = 0;
    if (p->kebutuhan == d->jenisMakanan) skor++;
    if (p->jumlah <= d->jumlah) skor++;
    if (p->lokasi == d->lokasi) skor++;
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

    char jenis[50];
    printf("Jenis Makanan (nasi, sayur, buah, daging, ikan): ");
    scanf(" %[^\n]", jenis);
    d->jenisMakanan = parseJenis(jenis);
    if (d->jenisMakanan == JENIS_INVALID) {
        printf("Jenis makanan tidak valid.\n");
        return;
    }

    printf("Jumlah             : ");
    scanf("%d", &d->jumlah);
    getchar(); // consume leftover newline

    char lokasi[50];
    printf("Lokasi (Sukmajaya, Beji, Cimanggis, Tugu): ");
    scanf(" %[^\n]", lokasi);
    d->lokasi = parseLokasi(lokasi);
    if (d->lokasi == LOKASI_INVALID) {
        printf("Lokasi tidak valid.\n");
        return;
    }

    d->sudahDipakai = false;
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

    char jenis[50];
    printf("Jenis Makanan Dibutuhkan (nasi, sayur, buah, daging, ikan): ");
    scanf(" %[^\n]", jenis);
    p->kebutuhan = parseJenis(jenis);
    if (p->kebutuhan == JENIS_INVALID) {
        printf("Jenis makanan tidak valid.\n");
        return;
    }

    printf("Jumlah Dibutuhkan    : ");
    scanf("%d", &p->jumlah);
    getchar(); // consume leftover newline

    char lokasi[50];
    printf("Lokasi Penerima (Sukmajaya, Beji, Cimanggis, Tugu): ");
    scanf(" %[^\n]", lokasi);
    p->lokasi = parseLokasi(lokasi);
    if (p->lokasi == LOKASI_INVALID) {
        printf("Lokasi tidak valid.\n");
        return;
    }

    jumlahPenerima++;
    printf("Penerima berhasil ditambahkan.\n");
}

void tampilkanSemuaData() {
    printf("\n=== Daftar Donatur ===\n");
    for (int i = 0; i < jumlahDonatur; i++) {
        Donatur *d = &daftarDonatur[i];
        printf("%d. %s - %s - %d - %s\n", i + 1,
               d->nama, jenisStr[d->jenisMakanan], d->jumlah, lokasiStr[d->lokasi]);
    }

    printf("\n=== Daftar Penerima ===\n");
    for (int i = 0; i < jumlahPenerima; i++) {
        Penerima *p = &daftarPenerima[i];
        printf("%d. %s - %s - %d - %s\n", i + 1,
               p->nama, jenisStr[p->kebutuhan], p->jumlah, lokasiStr[p->lokasi]);
    }
}

void cocokkanDonasi() {
    printf("\n=== Pencocokan Donasi ===\n");
    for (int i = 0; i < jumlahPenerima; i++) {
        Penerima *p = &daftarPenerima[i];
        printf("\nPermintaan dari %s:\n", p->nama);
        int cocok = 0;
        for (int j = 0; j < jumlahDonatur; j++) {
            Donatur *d = &daftarDonatur[j];
            if (d->sudahDipakai) continue;
            int skor = hitungSkorKecocokan(p, d);
            if (skor >= 2) {
                printf("-> Cocok dengan %s (%s - %d - %s) | Skor: %d/3\n",
                       d->nama, jenisStr[d->jenisMakanan], d->jumlah, lokasiStr[d->lokasi], skor);
                d->sudahDipakai = true;
                cocok++;
            }
        }
        if (cocok == 0) printf("-> Tidak ada donatur yang cocok.\n");
    }
}

void tampilkanLaporan() {
    int total = jumlahDonatur;
    int terpakai = 0;
    for (int i = 0; i < jumlahDonatur; i++) {
        if (daftarDonatur[i].sudahDipakai) terpakai++;
    }
    printf("\n=== Laporan Donasi ===\n");
    printf("Total Donasi        : %d\n", total);
    printf("Donasi Terpakai     : %d\n", terpakai);
    printf("Donasi Belum Terpakai: %d\n", total - terpakai);
}

int main() {
    int opsi = -1;
    printf("Selamat Datang di Program Foodlink!\n");
    while (opsi != 0) {
        printf("\nMenu:\n");
        printf("1. Tambah Donatur\n");
        printf("2. Tambah Penerima\n");
        printf("3. Lihat Semua Data\n");
        printf("4. Cocokkan Donasi\n");
        printf("5. Tampilkan Laporan\n");
        printf("0. Keluar\n");
        printf("Pilih opsi (0-5): ");
        scanf("%d", &opsi);
        getchar(); // consume newline after number input

        switch (opsi) {
            case 1: inputDonatur(); break;
            case 2: inputPenerima(); break;
            case 3: tampilkanSemuaData(); break;
            case 4: cocokkanDonasi(); break;
            case 5: tampilkanLaporan(); break;
            case 0: printf("Terima kasih telah menggunakan Foodlink!\n"); break;
            default: printf("Opsi tidak valid!\n");
        }
    }
}
