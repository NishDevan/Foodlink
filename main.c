#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DONATUR 100
#define MAX_PENERIMA 100

typedef enum { SUKMAJAYA, BEJI, CIMANGGIS, TUGU, LOKASI_INVALID } Lokasi;
typedef enum { NASI, SAYUR, BUAH, DAGING, IKAN, JENIS_INVALID } JenisMakanan;

const char* lokasiStr[] = {"Sukmajaya", "Beji", "Cimanggis", "Tugu"};
const char* jenisStr[] = {"nasi", "sayur", "buah", "daging", "ikan"};

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

typedef struct {
    Donatur daftarDonatur[MAX_DONATUR];
    int jumlahDonatur;
    Penerima daftarPenerima[MAX_PENERIMA];
    int jumlahPenerima;
} Database;

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

int hitungSkorKecocokan(Penerima *p, Donatur *d) {
    int skor = 0;
    if (p->kebutuhan == d->jenisMakanan) skor++;
    if (p->jumlah <= d->jumlah) skor++;
    if (p->lokasi == d->lokasi) skor++;
    return skor;
}

void inputDonatur(Database* db) {
    if (db->jumlahDonatur >= MAX_DONATUR) {
        printf("Kapasitas maksimum donatur telah tercapai.\n");
        return;
    }

    Donatur *d = &db->daftarDonatur[db->jumlahDonatur];

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
    getchar();

    char lokasi[50];
    printf("Lokasi (Sukmajaya, Beji, Cimanggis, Tugu): ");
    scanf(" %[^\n]", lokasi);
    d->lokasi = parseLokasi(lokasi);
    if (d->lokasi == LOKASI_INVALID) {
        printf("Lokasi tidak valid.\n");
        return;
    }

    d->sudahDipakai = false;
    db->jumlahDonatur++;
    printf("Donatur berhasil ditambahkan.\n");
}

void inputPenerima(Database* db) {
    if (db->jumlahPenerima >= MAX_PENERIMA) {
        printf("Kapasitas maksimum penerima telah tercapai.\n");
        return;
    }

    Penerima *p = &db->daftarPenerima[db->jumlahPenerima];

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
    getchar();

    char lokasi[50];
    printf("Lokasi Penerima (Sukmajaya, Beji, Cimanggis, Tugu): ");
    scanf(" %[^\n]", lokasi);
    p->lokasi = parseLokasi(lokasi);
    if (p->lokasi == LOKASI_INVALID) {
        printf("Lokasi tidak valid.\n");
        return;
    }

    db->jumlahPenerima++;
    printf("Penerima berhasil ditambahkan.\n");
}

void tampilkanSemuaData(Database* db) {
    printf("\n=== Daftar Donatur ===\n");
    for (int i = 0; i < db->jumlahDonatur; i++) {
        Donatur *d = &db->daftarDonatur[i];
        printf("%d. %s - %s - %d - %s\n", i + 1,
               d->nama, jenisStr[d->jenisMakanan], d->jumlah, lokasiStr[d->lokasi]);
    }

    printf("\n=== Daftar Penerima ===\n");
    for (int i = 0; i < db->jumlahPenerima; i++) {
        Penerima *p = &db->daftarPenerima[i];
        printf("%d. %s - %s - %d - %s\n", i + 1,
               p->nama, jenisStr[p->kebutuhan], p->jumlah, lokasiStr[p->lokasi]);
    }
}

void cocokkanDonasi(Database* db) {
    printf("\n=== Pencocokan Donasi ===\n");
    for (int i = 0; i < db->jumlahPenerima; i++) {
        Penerima *p = &db->daftarPenerima[i];
        printf("\nPermintaan dari %s:\n", p->nama);
        int cocok = 0;
        for (int j = 0; j < db->jumlahDonatur; j++) {
            Donatur *d = &db->daftarDonatur[j];
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

void tampilkanLaporan(Database* db) {
    int total = db->jumlahDonatur;
    int terpakai = 0;
    for (int i = 0; i < db->jumlahDonatur; i++) {
        if (db->daftarDonatur[i].sudahDipakai) terpakai++;
    }
    printf("\n=== Laporan Donasi ===\n");
    printf("Total Donasi        : %d\n", total);
    printf("Donasi Terpakai     : %d\n", terpakai);
    printf("Donasi Belum Terpakai: %d\n", total - terpakai);
}

int main() {
    Database db = {0};
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
        getchar();

        switch (opsi) {
            case 1: inputDonatur(&db); break;
            case 2: inputPenerima(&db); break;
            case 3: tampilkanSemuaData(&db); break;
            case 4: cocokkanDonasi(&db); break;
            case 5: tampilkanLaporan(&db); break;
            case 0: printf("Terima kasih telah menggunakan Foodlink!\n"); break;
            default: printf("Opsi tidak valid!\n");
        }
    }

    return 0;
}
