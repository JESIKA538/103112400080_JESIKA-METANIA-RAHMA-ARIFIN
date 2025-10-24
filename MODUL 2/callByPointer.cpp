#include<iostream>
using namespace std;

void ubahNilai(int *ptr) {
    *ptr = 20; // mengubah nilai variabel yang di tunjuk oleh pointer
}
int main() {
    int x=10;
    cout << "nilai sebeleum diubah:" << x << endl;
    ubahNilai(&x); // mengirimkan alamat memeori x ke fungsi
    cout << "nilai setelah diubah:" << x << endl;

    return 0;
}