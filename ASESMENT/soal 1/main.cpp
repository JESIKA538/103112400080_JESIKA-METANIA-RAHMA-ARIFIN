#include "Soal1.h"

int main() {
    int pilihan;
    string nama;

    do {
        cout << "\nMenu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nama: ";
            cin >> nama;
            insertAkhir(nama);
            break;

        case 2:
            cout << "Masukkan nama untuk delete: ";
            cin >> nama;
            deleteNama(nama);
            break;

        case 3:
            view();
            break;

        case 4:
            hitungGenap();
            break;

        case 0:
            cout << "Keluar" << endl;
            break;

        default:
            cout << "Pilihan tidak valid" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
