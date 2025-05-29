#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
=======

//constants
#define MAX_DONATUR 100
#define MAX_PENERIMA 100

//simple data structure
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

//array dan jumlah data
struct donatur daftarDonatur[MAX_DONATUR];
int jumlahDonatur = 0;

struct penerima daftarPenerima[MAX_PENERIMA];
int jumlahPenerima = 0;

//fungsi untuk menghitung skor kecocokan
int hitungSkorKecocokan(struct penerima p, struct donatur d) {
    int skor = 0;
    if (strcmp(p.kebutuhan, d.jenisMakanan) == 0) skor++;
    if (p.jumlah <= d.jumlah) skor++;
    if (strcmp(p.lokasi, d.lokasi) == 0) skor++;
    return skor;
}

//fungsi menambahkan donatur
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

    daftarDonatur[jumlahDonatur] = d;  //simpan ke array
    jumlahDonatur++;                  
    printf("Donatur berhasil ditambahkan.\n");
}

//fungsi menambahkan penerima dan cari donatur paling cocok
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

    daftarPenerima[jumlahPenerima] = p;  //disimpan ke array
    jumlahPenerima++;                    //tambah jumlah

    //cari donatur paling cocok
    int maxSkor = -1;
    int indeksTerbaik = -1;

    for (int i = 0; i < jumlahDonatur; i++) {
        int skor = hitungSkorKecocokan(p, daftarDonatur[i]);
        if (skor > maxSkor) {
            maxSkor = skor;
            indeksTerbaik = i;
        }
    }

    //tampilkan hasil pencocokan
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

//fungsi lain (placeholder doang)
void cocokkanDonasi() {
    printf("Fungsi pencocokan donasi banyak belum diimplementasi.\n");
}

void tampilkanLaporan() {
    printf("Fungsi laporan donasi belum diimplementasi.\n");
}
>>>>>>> main

//constants
#define MAX_DONATUR 100
#define MAX_PENERIMA 100
//kalau mau ada maksimum donatur, nanti tinggal if jumlahDonatur >= MAX_DONATUR, printf "maaf jumlah kapasitas donatur udah tercapai"

//enum jenis makanan (opsional untuk dikembangin kedepan)
enum jenisMakanan {KARBOHIDRAT, PROTEIN, SAYURAN, LAINNYA};

//structure data
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

//array donatur (data dummy)
struct donatur daftarDonatur[MAX_DONATUR];
int jumlahDonatur = 4;

struct penerima daftarPenerima[MAX_PENERIMA];
int jumlahPenerima = 0;

//Functions =============================================================================

// Placeholder functions
void inputDonatur() {
}

void cocokkanDonasi() {
}

void tampilkanLaporan() {
}

void tampilkanData() {
    printf("\n=== Data Donatur ===\n");
    if (jumlahDonatur == 0) {
        printf("Belum ada data donatur.\n");
    } else {
        for (int i = 0; i < jumlahDonatur; i++) {
            printf("Donatur %d:\n", i + 1);
            printf("Nama     : %s\n", daftarDonatur[i].nama);
            printf("Makanan  : %s\n", daftarDonatur[i].jenisMakanan);
            printf("Jumlah   : %d\n", daftarDonatur[i].jumlah);
            printf("Lokasi   : %s\n", daftarDonatur[i].lokasi);
            printf("-----------------------------\n");
        }
    }

    printf("\n=== Data Penerima ===\n");
    if (jumlahPenerima == 0) {
        printf("Belum ada data penerima.\n");
    } else {
        for (int i = 0; i < jumlahPenerima; i++) {
            printf("Penerima %d:\n", i + 1);
            printf("Nama     : %s\n", daftarPenerima[i].nama);
            printf("Kebutuhan: %s\n", daftarPenerima[i].kebutuhan);
            printf("Jumlah   : %d\n", daftarPenerima[i].jumlah);
            printf("Lokasi   : %s\n", daftarPenerima[i].lokasi);
            printf("-----------------------------\n");
        }
    }
}

// Fungsi utama
int main() {
<<<<<<< HEAD
    int opsi = 0;
    printf("Selamat Datang dalam Program Foodlink!\n");

    do {
        printf("\nMenu Utama\n");
=======
    int opsi = -1;

    printf("Selamat Datang di Program Foodlink!\n");

    while (opsi != 0) {
        printf("\nMenu Utama:\n");
>>>>>>> main
        printf("1. Tambah Donatur\n");
        printf("2. Tambah Penerima\n");
        printf("3. Lihat Semua Data\n");
        printf("4. Cocokkan Donasi\n");
        printf("5. Tampilkan Laporan Donasi\n");
<<<<<<< HEAD
        printf("Pilihlah Opsi yang Anda ingin Lakukan (1-5) : ");
        scanf("%d", &opsi);

=======
        printf("0. Keluar\n");
        printf("Pilih opsi (0-5): ");
        scanf("%d", &opsi);
        printf("\n");
>>>>>>> main
        switch (opsi) {
            case 1:
                inputDonatur();
                break;
            case 2:
                inputPenerima();
                break;
            case 3:
                tampilkanData();
                break;
            case 4:
                cocokkanDonasi();
                break;
<<<<<<< HEAD
            case 5:
                tampilkanLaporan();
                break;
=======
          case 5:
                // Untuk Menampilkan Donasi
                break;
            case 6:
                return 0;
>>>>>>> main
            default:
                printf("Tolong Pilihlah Opsi yang sesuai!\n");
                break;
        }
<<<<<<< HEAD
    } while(opsi != 5);

    printf("Terima kasih telah menggunakan Foodlink!\n");
    return 0;
}

=======
    }

    return 0;
}
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
>>>>>>> main
