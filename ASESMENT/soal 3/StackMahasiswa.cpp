#include "StackMahasiswa.h"

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S) {
    if (isFull(S)) {
        cout << "Stack penuh! Tidak bisa push.\n";
        return;
    }

    Mahasiswa m;
    cout << "Masukkan Nama   : ";
    cin >> m.Nama;
    cout << "Masukkan NIM    : ";
    cin >> m.NIM;
    cout << "Nilai Tugas     : ";
    cin >> m.NilaiTugas;
    cout << "Nilai UTS       : ";
    cin >> m.NilaiUTS;
    cout << "Nilai UAS       : ";
    cin >> m.NilaiUAS;

    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    cout << "Data berhasil di-push!\n";
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong! Tidak bisa pop.\n";
        return;
    }

    cout << "Data mahasiswa \"" << S.dataMahasiswa[S.Top].Nama 
         << "\" telah di-pop.\n";

    S.Top--;
}

void Update(StackMahasiswa &S, int posisi) {
    if (isEmpty(S)) {
        cout << "Stack kosong! Tidak ada data untuk update.\n";
        return;
    }

    if (posisi < 0 || posisi > S.Top) {
        cout << "Posisi tidak valid!\n";
        return;
    }

    Mahasiswa m;
    cout << "Update data pada posisi " << posisi << endl;
    cout << "Nama baru   : ";
    cin >> m.Nama;
    cout << "NIM baru    : ";
    cin >> m.NIM;
    cout << "Nilai Tugas : ";
    cin >> m.NilaiTugas;
    cout << "Nilai UTS   : ";
    cin >> m.NilaiUTS;
    cout << "Nilai UAS   : ";
    cin >> m.NilaiUAS;

    S.dataMahasiswa[posisi] = m;

    cout << "Data berhasil di-update!\n";
}

void View(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    cout << "\n=== Isi Stack (TOP ke BAWAH) ===\n";
    for (int i = S.Top; i >= 0; i--) {
        cout << "Posisi " << i 
             << " | Nama: " << S.dataMahasiswa[i].Nama
             << ", NIM: " << S.dataMahasiswa[i].NIM
             << ", Tugas: " << S.dataMahasiswa[i].NilaiTugas
             << ", UTS: " << S.dataMahasiswa[i].NilaiUTS
             << ", UAS: " << S.dataMahasiswa[i].NilaiUAS
             << endl;
    }
}
