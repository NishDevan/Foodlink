#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DONATUR 100   // Maksimum jumlah donatur yang bisa disimpan
#define MAX_PENERIMA 100  // Maksimum jumlah penerima yang bisa disimpan


typedef enum { SUKMAJAYA, BEJI, CIMANGGIS, TUGU, LOKASI_INVALID } Lokasi; // Enum buat nyimpen lokasi yang valid
typedef enum { NASI, SAYUR, BUAH, DAGING, IKAN, JENIS_INVALID } JenisMakanan; // Enum buat jenis makanan yang valid

// Struktur data buat nyimpen info donatur:
typedef struct {
    char nama[50];           // Nama donatur
    JenisMakanan jenisMakanan; // Jenis makanan yang didonorkan
    int jumlah;              // Jumlah makanan
    Lokasi lokasi;           // Lokasi donatur
    bool sudahDipakai;       // Flag, udah dipakai atau belum untuk pencocokan
} Donatur;

// Struktur data buat nyimpen info penerima:
typedef struct {
    char nama[50];           // Nama penerima
    JenisMakanan kebutuhan; // Jenis makanan yang dibutuhkan
    int jumlah;              // Jumlah yang dibutuhkan
    Lokasi lokasi;           // Lokasi penerima
} Penerima;

// Struktur database yang nyimpen array donatur dan penerima, plus jumlahnya:
typedef struct {
    Donatur daftarDonatur[MAX_DONATUR];
    int jumlahDonatur;
    Penerima daftarPenerima[MAX_PENERIMA];
    int jumlahPenerima;
} Database;

// Fungsi buat ubah string lokasi jadi enum Lokasi:
Lokasi parseLokasi(const char* str, const char* lokasiStr[]) {
    for (int i = 0; i < 4; i++) {
        // Bandingin input sama daftar lokasi pakai case-insensitive
        if (strcasecmp(str, lokasiStr[i]) == 0) return i;
    }
    return LOKASI_INVALID; // Kalau gak ketemu, return invalid
}

// Fungsi buat ubah string jenis makanan jadi enum JenisMakanan:
JenisMakanan parseJenis(const char* str, const char* jenisStr[]) {
    for (int i = 0; i < 5; i++) {
        // Bandingin input sama daftar jenis makanan pakai case-insensitive
        if (strcasecmp(str, jenisStr[i]) == 0) return i;
    }
    return JENIS_INVALID; // Kalau gak ketemu, return invalid
}

// Fungsi hitung skor kecocokan antara penerima dan donatur:
// Skor 1 poin tiap kriteria yang cocok: jenis makanan, jumlah cukup, lokasi sama
int hitungSkorKecocokan(Penerima *p, Donatur *d) {
    int skor = 0;
    if (p->kebutuhan == d->jenisMakanan) skor++;       // Cocok jenis makanan
    if (p->jumlah <= d->jumlah) skor++;                 // Donatur punya cukup jumlah
    if (p->lokasi == d->lokasi) skor++;                 // Lokasi sama
    return skor;
}

// Fungsi input data donatur baru ke database:
void inputDonatur(Database* db, const char* lokasiStr[], const char* jenisStr[]) {
    if (db->jumlahDonatur >= MAX_DONATUR) {
        printf("Kapasitas maksimum donatur telah tercapai.\n");
        return;
    }

    Donatur *d = &db->daftarDonatur[db->jumlahDonatur]; // Pointer ke donatur baru

    printf("\n=== Input Data Donatur ===\n");
    printf("Nama Donatur       : ");
    scanf(" %[^\n]", d->nama);  // Input nama (boleh ada spasi)

    char jenis[50];
    printf("Jenis Makanan (nasi, sayur, buah, daging, ikan): ");
    scanf(" %[^\n]", jenis);
    d->jenisMakanan = parseJenis(jenis, jenisStr);  // Ubah input ke enum
    if (d->jenisMakanan == JENIS_INVALID) {
        printf("Jenis makanan tidak valid.\n");
        return;
    }

    printf("Jumlah             : ");
    scanf("%d", &d->jumlah);
    getchar(); // Buang newline yang tersisa di buffer

    char lokasi[50];
    printf("Lokasi (Sukmajaya, Beji, Cimanggis, Tugu): ");
    scanf(" %[^\n]", lokasi);
    d->lokasi = parseLokasi(lokasi, lokasiStr);   // Ubah input ke enum
    if (d->lokasi == LOKASI_INVALID) {
        printf("Lokasi tidak valid.\n");
        return;
    }

    d->sudahDipakai = false;   // Donasi baru, belum dipakai buat pencocokan
    db->jumlahDonatur++;       // Tambah jumlah donatur
    printf("Donatur berhasil ditambahkan.\n");
}

// Fungsi input data penerima baru ke database:
void inputPenerima(Database* db, const char* lokasiStr[], const char* jenisStr[]) {
    if (db->jumlahPenerima >= MAX_PENERIMA) {
        printf("Kapasitas maksimum penerima telah tercapai.\n");
        return;
    }

    Penerima *p = &db->daftarPenerima[db->jumlahPenerima]; // Pointer penerima baru

    printf("\n=== Input Data Penerima ===\n");
    printf("Nama Penerima        : ");
    scanf(" %[^\n]", p->nama);

    char jenis[50];
    printf("Jenis Makanan Dibutuhkan (nasi, sayur, buah, daging, ikan): ");
    scanf(" %[^\n]", jenis);
    p->kebutuhan = parseJenis(jenis, jenisStr);
    if (p->kebutuhan == JENIS_INVALID) {
        printf("Jenis makanan tidak valid.\n");
        return;
    }

    printf("Jumlah Dibutuhkan    : ");
    scanf("%d", &p->jumlah);
    getchar(); // Bersihin newline di buffer

    char lokasi[50];
    printf("Lokasi Penerima (Sukmajaya, Beji, Cimanggis, Tugu): ");
    scanf(" %[^\n]", lokasi);
    p->lokasi = parseLokasi(lokasi, lokasiStr);
    if (p->lokasi == LOKASI_INVALID) {
        printf("Lokasi tidak valid.\n");
        return;
    }

    db->jumlahPenerima++; // Tambah jumlah penerima
    printf("Penerima berhasil ditambahkan.\n");
}

// Fungsi buat nampilin semua data donatur dan penerima yang ada di database:
void tampilkanSemuaData(Database* db, const char* lokasiStr[], const char* jenisStr[]) {
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

// Fungsi buat nyocokin donasi antara donatur dan penerima:
// Donatur yang cocok dengan skor minimal 2 akan ditandai sudah dipakai
void cocokkanDonasi(Database* db, const char* lokasiStr[], const char* jenisStr[]) {
    printf("\n=== Pencocokan Donasi ===\n");
    for (int i = 0; i < db->jumlahPenerima; i++) {
        Penerima *p = &db->daftarPenerima[i];
        printf("\nPermintaan dari %s:\n", p->nama);
        int cocok = 0;
        for (int j = 0; j < db->jumlahDonatur; j++) {
            Donatur *d = &db->daftarDonatur[j];
            if (d->sudahDipakai) continue; // Lewat kalau donasi sudah dipakai
            int skor = hitungSkorKecocokan(p, d);
            if (skor >= 2) { // Minimal 2 kriteria cocok baru diterima
                printf("-> Cocok dengan %s (%s - %d - %s) | Skor: %d/3\n",
                       d->nama, jenisStr[d->jenisMakanan], d->jumlah, lokasiStr[d->lokasi], skor);
                d->sudahDipakai = true; // Tandai donasi sudah dipakai
                cocok++;
            }
        }
        if (cocok == 0) printf("-> Tidak ada donatur yang cocok.\n");
    }
}

// Fungsi buat nampilin laporan donasi: total, terpakai, belum terpakai:
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
    Database db = {0};  // Inisialisasi database kosong

    // Array string buat konversi enum ke string
    const char* lokasiStr[] = {"Sukmajaya", "Beji", "Cimanggis", "Tugu"};
    const char* jenisStr[] = {"nasi", "sayur", "buah", "daging", "ikan"};

    int opsi = -1;
    printf("Selamat Datang di Program Foodlink!\n");

    // Loop menu sampai user pilih keluar (0)
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
        getchar(); // Bersihin newline

        // Switch case buat jalankan pilihan menu
        switch (opsi) {
            case 1: inputDonatur(&db, lokasiStr, jenisStr); break;
            case 2: inputPenerima(&db, lokasiStr, jenisStr); break;
            case 3: tampilkanSemuaData(&db, lokasiStr, jenisStr); break;
            case 4: cocokkanDonasi(&db, lokasiStr, jenisStr); break;
            case 5: tampilkanLaporan(&db); break;
            case 0: printf("Terima kasih telah menggunakan Foodlink!\n"); break;
            default: printf("Opsi tidak valid!\n");
        }
    }
}