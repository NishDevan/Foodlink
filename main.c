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
    printf("✅ Donatur berhasil ditambahkan.\n");
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
                // Untuk Menampilkan Donasi
                break;
            case 6:
                return 0;
            default:
                printf("Tolong Pilihlah Opsi yang sesuai!\n");
                break;
        }
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
