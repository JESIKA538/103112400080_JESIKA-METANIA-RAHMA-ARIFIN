#include "StackMahasiswa.h"

int main() {
    StackMahasiswa S;
    createStack(S);

    int pilihan, pos;
    Mahasiswa m;

    do {
        cout << "\n=== MENU STACK MAHASISWA ===\n";
        cout << "1. Push data\n";
        cout << "2. Pop data\n";
        cout << "3. Update data berdasarkan posisi\n";
        cout << "4. View stack\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> m.Nama;
                cout << "Masukkan NIM: ";
                cin >> m.NIM;
                cout << "Nilai Tugas: ";
                cin >> m.NilaiTugas;
                cout << "Nilai UTS: ";
                cin >> m.NilaiUTS;
                cout << "Nilai UAS: ";
                cin >> m.NilaiUAS;

                push(S, m);
                break;

            case 2:
                pop(S);
                break;

            case 3:
                cout << "Masukkan posisi: ";
                cin >> pos;

                cout << "Masukkan data baru\n";
                cout << "Nama: "; cin >> m.Nama;
                cout << "NIM: "; cin >> m.NIM;
                cout << "Nilai Tugas: "; cin >> m.NilaiTugas;
                cout << "Nilai UTS: "; cin >> m.NilaiUTS;
                cout << "Nilai UAS: "; cin >> m.NilaiUAS;

                updateData(S, pos, m);
                break;

            case 4:
                viewStack(S);
                break;

            case 0:
                cout << "Keluar..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
