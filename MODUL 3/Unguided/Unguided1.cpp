#include<iostream>
using namespace std;

struct mahasiswa{
    string nim,nama;
    float uts, uas,tugas,nilaiAkhir;
};
float nilaiAkhir(float uts, float uas, float tugas){
    return 0.3*uts + 0.4*uas + 0.3*tugas;
};
int main() {
    mahasiswa mhs[10];
    int n;
    cout << "Jumlah mahasiwa (max 10): ";
    cin >> n;
    cin.ignore(); // tujuan nya biar ga error

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;

       mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cin.ignore();
    }
     cout << "\n=== DAFTAR NILAI MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " (" << mhs[i].nim << ") = "
             << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}
