#include "Soal2.h"

int main() {
    int pilihan, nilai;

    do {
        cout << "\nMenu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertAkhir(nilai);
            break;

        case 2:
            deleteTerakhir();
            break;

        case 3:
            viewDepan();
            break;

        case 4:
            reverseList();
            cout << "List setelah di-reverse: ";
            viewDepan();
            break;

        case 0:
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
