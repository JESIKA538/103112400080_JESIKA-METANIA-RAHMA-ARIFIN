#include <iostream>
using namespace std;

int main() {
    int Panjang = 20;
    int Lebar = 10;

    int *ptrPanjang = &Panjang;
    int *ptrLebar = &Lebar;

    cout << "=== Nilai awal ===" << endl;
    cout << "Panjang: " << Panjang << endl;
    cout << "Lebar: " << Lebar << endl;
    cout << endl;

    // Menghitung luas
    int luas = (*ptrPanjang) * (*ptrLebar);
    // Menghitung keliling
    int keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    // Menampilkan hasil perhitungan
    cout << "=== Hasil perhitungan ===" << endl;
    cout << "Luas persegi panjang: " << luas << endl;
    cout << "Keliling persegi panjang: " << keliling << endl;
    cout << endl;

    // Ubah nilai panjang dan lebar lewat pointer
    *ptrPanjang = 45;
    *ptrLebar = 70;

    // Menghitung ulang nilai luas dan keliling 
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    // Menampilkan nilai baru
    cout << "=== Nilai baru ===" << endl;
    cout << "Panjang: " << *ptrPanjang << endl;
    cout << "Lebar: " << *ptrLebar << endl;
    cout << "Luas baru: " << luas << endl;
    cout << "Keliling baru: " << keliling << endl;

    return 0;
}
