#include<iostream>
using namespace std;

int cariMaksimum(int arr[], int ukuran) {
    int maksimum =arr[0];
    for (int i = 0; i < ukuran; i++) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
        }
        return maksimum;
    }
    void operasiAritmetika(int arr[], int ukuran) {
        int totaljumlah = 0;
        for (int i = 0; i < ukuran; i++) {
            totaljumlah += arr[i];
        }
        cout  << "total penjumlahan:" << totaljumlah << endl;
        int totalKali = 1;
        for (int i = 0; i < ukuran; i++) {
            totalKali *= arr[i];
        }
        cout << "total perkalian: " << totalKali << endl;
     }
        int main() {
            const int ukuran = 5;
            int arr[ukuran];
            for (int i = 0; i < ukuran; i++) {
                cout << "masukkan nilai array ke-" << i << " : ";
                cin >> arr[i];
            }
            cout << endl;
            cout << "nilai terbesar dalam array: " << cariMaksimum(arr, ukuran) << endl;

            operasiAritmetika(arr, ukuran);
            return 0;
}