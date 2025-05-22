#include <stdio.h>
#include <string.h>

// Constants
#define MAX_DONATUR 100
#define MAX_PENERIMA 100

// Struktur data
struct donatur {
    char nama[50];
    char jenisMakanan[50];
    int jumlah;
    char lokasi[50];
};

struct penerima {
    char nama[50];
    char kebutuhan[50];
    int jumlah;
    char lokasi[50];
};

// Array dan jumlah data
struct donatur daftarDonatur[MAX_DONATUR];
int jumlahDonatur = 0;

struct penerima daftarPenerima[MAX_PENERIMA];
int jumlahPenerima = 0;

// Fungsi untuk menghitung skor kecocokan
int hitungSkorKecocokan(struct penerima p, struct donatur d) {
    int skor = 0;
    if (strcmp(p.kebutuhan, d.jenisMakanan) == 0) skor++;
    if (p.jumlah <= d.jumlah) skor++;
    if (strcmp(p.lokasi, d.lokasi) == 0) skor++;
    return skor;
}

// Fungsi menambahkan donatur
void inputDonatur() {
    if (jumlahDonatur >= MAX_DONATUR) {
        printf("Kapasitas maksimum donatur telah tercapai.\n");
        return;
    }

    struct donatur d;
    printf("\n=== Input Data Donatur ===\n");
    printf("Nama Donatur       : ");
    scanf(" %[^\n]", d.nama);
    printf("Jenis Makanan      : ");
    scanf(" %[^\n]", d.jenisMakanan);
    printf("Jumlah             : ");
    scanf("%d", &d.jumlah);
    printf("Lokasi             : ");
    scanf(" %[^\n]", d.lokasi);

    daftarDonatur[jumlahDonatur] = d;  // Simpan ke array
    jumlahDonatur++;                   // Tambah jumlah
    printf("Donatur berhasil ditambahkan.\n");
}

// Fungsi menambahkan penerima dan cari donatur paling cocok
void inputPenerima() {
    if (jumlahPenerima >= MAX_PENERIMA) {
        printf("Kapasitas maksimum penerima telah tercapai.\n");
        return;
    }

    struct penerima p;
    printf("\n=== Input Data Penerima ===\n");
    printf("Nama Penerima        : ");
    scanf(" %[^\n]", p.nama);
    printf("Jenis Makanan Dibutuhkan : ");
    scanf(" %[^\n]", p.kebutuhan);
    printf("Jumlah Dibutuhkan    : ");
    scanf("%d", &p.jumlah);
    printf("Lokasi Penerima      : ");
    scanf(" %[^\n]", p.lokasi);

    daftarPenerima[jumlahPenerima] = p;  // Simpan ke array
    jumlahPenerima++;                    // Tambah jumlah

    // Cari donatur paling cocok
    int maxSkor = -1;
    int indeksTerbaik = -1;

    for (int i = 0; i < jumlahDonatur; i++) {
        int skor = hitungSkorKecocokan(p, daftarDonatur[i]);
        if (skor > maxSkor) {
            maxSkor = skor;
            indeksTerbaik = i;
        }
    }

    // Tampilkan hasil pencocokan
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

// Fungsi menampilkan semua data
void tampilkanSemuaData() {
    printf("\n=== Daftar Donatur ===\n");
    for (int i = 0; i < jumlahDonatur; i++) {
        printf("%d. %s - %s - %d - %s\n", i + 1,
               daftarDonatur[i].nama,
               daftarDonatur[i].jenisMakanan,
               daftarDonatur[i].jumlah,
               daftarDonatur[i].lokasi);
    }

    printf("\n=== Daftar Penerima ===\n");
    for (int i = 0; i < jumlahPenerima; i++) {
        printf("%d. %s - %s - %d - %s\n", i + 1,
               daftarPenerima[i].nama,
               daftarPenerima[i].kebutuhan,
               daftarPenerima[i].jumlah,
               daftarPenerima[i].lokasi);
    }
}

// Fungsi lain (placeholder)
void cocokkanDonasi() {
    printf("Fungsi pencocokan donasi banyak belum diimplementasi.\n");
}

void tampilkanLaporan() {
    printf("Fungsi laporan donasi belum diimplementasi.\n");
}

// Fungsi utama
int main() {
    int opsi = -1;

    printf("Selamat Datang di Program Foodlink!\n");

    while (opsi != 0) {
        printf("\nMenu Utama:\n");
        printf("1. Tambah Donatur\n");
        printf("2. Tambah Penerima\n");
        printf("3. Lihat Semua Data\n");
        printf("4. Cocokkan Donasi\n");
        printf("5. Tampilkan Laporan Donasi\n");
        printf("0. Keluar\n");
        printf("Pilih opsi (0-5): ");
        scanf("%d", &opsi);

        switch (opsi) {
            case 1: inputDonatur(); break;
            case 2: inputPenerima(); break;
            case 3: tampilkanSemuaData(); break;
            case 4: cocokkanDonasi(); break;
            case 5: tampilkanLaporan(); break;
            case 0: printf("Terima kasih telah menggunakan Foodlink!\n"); break;
            default: printf("Opsi tidak valid. Coba lagi.\n");
        }
    }

    return 0;
}
