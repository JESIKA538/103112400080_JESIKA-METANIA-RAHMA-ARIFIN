#include<iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "[";
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j];
            if (j < 2) cout << "\t";
            }
            cout << "]" << endl;        
        
    
    }
    
}
// Penukaran elemen
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
int temp = arr1[baris][kolom];
arr1[baris][kolom] = arr2[baris][kolom];
arr2[baris][kolom] = temp;
}

//Tukar isi variabel
void tukarIsi(int* ptr1, int*ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int B[3][3] = {{11,12,13}, {14,15,16}, {17,18,19}};
    int *p1, *p2;

    cout << "Array A: " << endl;
    tampilkanArray(A);
    cout << "Array B: " << endl;
    tampilkanArray(B);

    //Tukar elemen Array
    tukarElemen(A, B, 1, 2);
    cout << "\nSetelah tukar elemen[1][2] antara A dan B:" << endl;
    cout << "Array A: " << endl; tampilkanArray(A);
    cout << "Array B: " << endl; tampilkanArray(B);

    p1 = &A[0][0];
    p2 = &B[2][2];
    cout << "\nIsi sebelum ditukar:  *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    tukarIsi(p1, p2);
    cout << "Isi setelah ditukar (pointer): *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    cout << "Array A setelah tukar pointer:" << endl; tampilkanArray(A);
    cout << "Array B setelah tukar pointer:" << endl; tampilkanArray(B);

    return 0;
}