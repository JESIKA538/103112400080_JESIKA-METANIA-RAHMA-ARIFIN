#include "QueuePengiriman.h"
#include <limits> 


void tampilkanMenu() {
    cout << "\n--- Komaniya Ekspres ---" << endl;
    cout << "1. Input Data Paket" << endl;
    cout << "2. Hapus Data Paket" << endl;
    cout << "3. Tampilkan queue paket" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihan anda: ";
}
void inputSemuaData(QueueEkspedisi &Q) {
    Paket p1 = {"123456", "Hutao", 14, "Sumeru"};
    enQueue(Q, p1);

    Paket p2 = {"234567", "Ayaka", 10, "Fontaine"};
    enQueue(Q, p2);

    Paket p3 = {"345678", "Bennet", 7, "Natlan"};
    enQueue(Q, p3);

    Paket p4 = {"456789", "Furina", 16, "Liyue"};
    enQueue(Q, p4);

    Paket p5 = {"567890", "Nefer", 6, "Inazuma"};
    enQueue(Q, p5);

    cout << "\n[Semua 5 paket data awal telah selesai di-enqueue secara otomatis.]" << endl;
}

int main() {
    QueueEkspedisi Q;
    int pilihan;

    createQueue(Q);
    inputSemuaData(Q);

    do {
        tampilkanMenu();
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = 0;
            cout << "Input tidak valid. Silakan masukkan angka pilihan." << endl;
            continue;
        }

        switch (pilihan) {
            case 1: {
                Paket newPaket;
                cout << "\n--- Tambah Paket Baru ---" << endl;
                cout << "Kode Resi: "; cin >> newPaket.KodeResi;
                cout << "Nama Pengirim: "; cin >> newPaket.NamaPengirim;
                cout << "Berat Barang (kg): "; 
                while (!(cin >> newPaket.BeratBarang) || newPaket.BeratBarang <= 0) {
                    cout << "Input berat tidak valid. Masukkan angka positif: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Tujuan: "; cin >> newPaket.Tujuan;
                enQueue(Q, newPaket);
                break;
            }
            case 2:
                deQueue(Q); 
                cout << "\n[Tampilan queue setelah 1x DeQueue]:" << endl;
                viewQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}