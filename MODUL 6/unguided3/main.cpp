#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;

    // Input data kendaraan
    while (true) {
        cout << "masukkan nomor polisi: ";
        getline(cin, data.nopol);
        if (data.nopol.empty()) {
            cout << endl;
            break;
        }

        cout << "masukkan warna kendaraan: ";
        getline(cin, data.warna);
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;
        cin.ignore();

        if (findElm(L, data.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            P = alokasi(data);
            insertLast(L, P);
            cout << endl;
        }
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    // Bagian DELETE by nopol
    string hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus;

    address target = findElm(L, hapus);
    if (target != Nil) {
        if (target == L.first) {
            deleteFirst(L, P);
        } else if (target == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan." << endl << endl;
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);
}
