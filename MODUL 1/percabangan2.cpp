#include <iostream>
using namespace std;

int main() {
    int pilihan, angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;
    
    cout << "MENU" << endl;
    cout << "1.penjumlahan" << endl;
    cout << "2.pengurangan" << endl;
    cout << "masukkan pilihan : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan : " << angka1 + angka2 << endl;
            cout << endl;
        break;
        case 2:
            cout << "pengurangan : " << angka1 - angka2 << endl;
            cout << endl;
        break;
        default:
            cout << "pilihan salah" << endl;
    }
    return 0;
}