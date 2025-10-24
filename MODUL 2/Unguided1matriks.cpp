#include <iostream>
using namespace std;

// Fungsi untuk penjumlahan matriks
void jumlahMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk pengurangan matriks
void kurangMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk perkalian matriks
void kaliMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Fungsi untuk menampilkan matriks
void tampilMatriks(int matriks[3][3]) {
    for(int i = 0; i < 3; i++) {
        cout << "[ ";
        for(int j = 0; j < 3; j++) {
            cout << matriks[i][j];
            if(j < 2) cout << "\t";
        }
        cout << " ]" << endl;
    }
}

int main() {
    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int hasil[3][3];
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cin >> pilihan;  // langsung input, tanpa teks "Pilih operasi (1-4)"

        switch(pilihan) {
            case 1:
                cout << "\n=== Penjumlahan Matriks ===" << endl;
                cout << "\nMatriks A:" << endl;
                tampilMatriks(matriksA);
                cout << "\nMatriks B:" << endl;
                tampilMatriks(matriksB);

                jumlahMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil A + B:" << endl;
                tampilMatriks(hasil);
                break;

            case 2:
                cout << "\n=== Pengurangan Matriks ===" << endl;
                cout << "\nMatriks A:" << endl;
                tampilMatriks(matriksA);
                cout << "\nMatriks B:" << endl;
                tampilMatriks(matriksB);

                kurangMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil A - B:" << endl;
                tampilMatriks(hasil);
                break;

            case 3:
                cout << "\n=== Perkalian Matriks ===" << endl;
                cout << "\nMatriks A:" << endl;
                tampilMatriks(matriksA);
                cout << "\nMatriks B:" << endl;
                tampilMatriks(matriksB);

                kaliMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil A x B:" << endl;
                tampilMatriks(hasil);
                break;

            default:
                if(pilihan != 4)
                    cout << "\nPilihan tidak valid! Silakan pilih 1-4." << endl;
        }

    } while(pilihan != 4);

    return 0;
}
