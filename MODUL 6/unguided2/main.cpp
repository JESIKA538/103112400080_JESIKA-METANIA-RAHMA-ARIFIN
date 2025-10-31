#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype data;
    address P;

    while (true) {
        cout << "masukkan nomor polisi: ";
        getline(cin, data.nopol);

        // Jika kosong (user langsung Enter), hentikan input
        if (data.nopol.empty()) {
            cout << endl;
            break;
        }

        cout << "masukkan warna kendaraan: ";
        getline(cin, data.warna);
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;
        cin.ignore(); // untuk menghapus newline di buffer

        // Cek duplikat nomor polisi
        if (findElm(L, data.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            P = alokasi(data);
            insertLast(L, P);
            cout << endl;
        }
        cout << endl;
    }

   cout << "DATA LIST 1" << endl;
printInfo(L);

cout << "Masukkan Nomor Polisi yang dicari : ";
string cari;
cin >> cari;

address hasil = findElmByNopol(L, cari);
if (hasil != Nil) {
    cout << "Nomor Polisi : " << hasil->info.nopol << endl;
    cout << "Warna        : " << hasil->info.warna << endl;
    cout << "Tahun        : " << hasil->info.thnBuat << endl;
} else {
    cout << "Data dengan nomor polisi " << cari << " tidak ditemukan." << endl;
}

}
