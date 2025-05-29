#include <stdio.h>
#include <string.h>

//constants
#define MAX_DONATUR 100
#define MAX_PENERIMA 100

//simple data structtu
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
