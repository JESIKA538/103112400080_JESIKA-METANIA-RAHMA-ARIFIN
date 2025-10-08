#include <iostream>
#include <string>
using namespace std;

int main() {
    int bilanganbulat;
    cout << "Masukkan bilanganbulat : ";
    cin >> bilanganbulat;

    if (bilanganbulat < 0 || bilanganbulat > 100) {
        cout << "Angka di luar bilangan bulat (0-100)." << endl;
        return 0;
    }
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                        "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", 
                        "empat belas", "lima belas", "enam belas", 
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", 
                        "delapan puluh", "sembilan puluh"};

     if (bilanganbulat == 0) {
        cout << "nol" << endl;
    } else if (bilanganbulat < 10) {
        cout << satuan[bilanganbulat] << endl;
    } else if (bilanganbulat < 20) {
        cout << belasan[bilanganbulat- 10] << endl;
    } else if (bilanganbulat < 100) {
        int puluh = bilanganbulat/ 10;
        int sisa = bilanganbulat % 10;
        if (sisa == 0) {
            cout << puluhan[puluh] << endl;
        } else {
            cout << puluhan[puluh] << " " << satuan[sisa] << endl;
        }
    } else if (bilanganbulat == 100) {
        cout << "seratus" << endl;
    }

    return 0;
}