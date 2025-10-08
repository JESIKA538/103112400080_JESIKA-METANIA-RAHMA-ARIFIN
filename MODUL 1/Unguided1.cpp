#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;

    std::cout << "Masukkan angka pertama: ";
    std::cin >> angka1;

    std::cout << "Masukkan angka kedua: ";
    std::cin >> angka2;

    std::cout << "Hasil Penjumlahan: " << angka1 + angka2 << std::endl;
    std::cout << "Hasil Pengurangan: " << angka1 - angka2 << std::endl;
    std::cout << "Hasil Perkalian: " << angka1 * angka2 << std::endl;

    if (angka1 != 0) {
        std::cout << "Hasil Pembagian: " << angka1 / angka2 << std::endl;
    } else {
        std::cout << "Pembagian tidak dapat dilakukan" << std::endl;
    }

    return 0;
}