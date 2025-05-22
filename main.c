#include <stdio.h>
#include <string.h>

//constants
#define MAX_DONATUR 100
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
struct donatur daftarDonatur[MAX_DONATUR] = {
    {"Donatur A", "Nasi", 10, "Jakarta"},
    {"Donatur B", "Roti", 5, "Bandung"},
    {"Donatur C", "Nasi", 8, "Jakarta"},
    {"Donatur D", "Nasi", 3, "Depok"}
};
int jumlahDonatur = 4;

//Functions =============================================================================

//Fungsi untuk menghitung skor kecocokan
int hitungSkorKecocokan(struct penerima p, struct donatur d) {
    int skor = 0;
    if (strcmp(p.kebutuhan, d.jenisMakanan) == 0) skor++;
    if (p.jumlah <= d.jumlah) skor++;
    if (strcmp(p.lokasi, d.lokasi) == 0) skor++;
    return skor;
}

//Fungsi input penerima (request) dan cari donatur paling cocok
void inputPenerima() {
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

    // Pencarian donatur paling cocok
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
        printf("Penerima \"%s\" paling cocok dengan donatur:\n", p.nama);
        printf("Nama Donatur : %s\n", d.nama);
        printf("Jenis        : %s\n", d.jenisMakanan);
        printf("Jumlah       : %d\n", d.jumlah);
        printf("Lokasi       : %s\n", d.lokasi);
        printf("Skor Kecocokan: %d dari 3\n", maxSkor);
    } else {
        printf("Tidak ditemukan donatur yang cocok untuk \"%s\".\n", p.nama);
    }
}

// Placeholder functions
void inputDonatur() {
}

void cocokkanDonasi() {
}

void tampilkanLaporan() {
}

//================================================================================================

// Fungsi utama
int main() {
    int opsi = 0;
    printf("Selamat Datang dalam Program Foodlink!\n");

    do {
        printf("\nMenu Utama\n");
        printf("1. Tambah Donatur\n");
        printf("2. Tambah Penerima\n");
        printf("3. Lihat Semua Data\n");
        printf("4. Cocokkan Donasi\n");
        printf("5. Tampilkan Laporan Donasi\n");
        printf("Pilihlah Opsi yang Anda ingin Lakukan (1-5) : ");
        scanf("%d", &opsi);

        switch (opsi) {
            case 1:
                inputDonatur();
                break;
            case 2:
                inputPenerima();
                break;
            case 3:
                printf("Fungsi belum diimplementasikan.\n");
                break;
            case 4:
                cocokkanDonasi();
                break;
            case 5:
                tampilkanLaporan();
                break;
            default:
                printf("Tolong Pilihlah Opsi yang sesuai!\n");
                break;
        }
    } while(opsi != 5);

    printf("Terima kasih telah menggunakan Foodlink!\n");
    return 0;
}

