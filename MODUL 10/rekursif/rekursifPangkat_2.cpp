#include<iostream>
using namespace std;

int pangkat_2(int  x) {
    if(x == 0){ // basis
        return 1;
    } else if (x>0) { // rekurens
        return 2 * pangkat_2(x-1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;
    int x;
    cout << "Masukkan nilai x : ";
    cin >> x;
    cout << "2 pangkat " << x << " adalah : " << pangkat_2(x) << endl;
    return 0;

}

// Misal x = 3
//pangkat_(3)
// 2* pangkat_2(2);
// 2* (2* pangkat_2(1))
// 2* (2* (2* pangkat_2(0)))
// = 2* (2* (2*1))
// = 8
