# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 1103112400080</p>

## Dasar Teori
2.1. Array
Array satu dimensi (1D) berfungsi untuk menyimpan rangkaian elemen 𝑛𝑛 yang sama dengan 𝑎𝑎𝑖𝑖,
di mana indeks bilangan bulat nonnegatif 𝑖𝑖 mencakup 𝑛𝑛 nilai-nilai yang berurutan.
Misalnya, dengan 𝑖𝑖 = 1, 2, … , 𝑛𝑛, elemen 𝑎𝑎𝑖𝑖 dapat diinterpretasikan sebagai komponen
vektor 𝒂𝒂 dalam ruang berdimensi 𝑛𝑛. Mengikuti notasi matematika ini,
sintaks standar untuk mengakses elemen larik dalam bahasa pemrograman tingkat tinggi
memerlukan penyebutan nama larik dan indeks elemen. Berdasarkan hal tersebut, penyusun
memastikan kalkulasi run-time alamat memori elemen array ke-𝑖𝑖 sebagai:
𝐴𝐴(𝑖𝑖) = 𝐴𝐴0 + 𝑙𝑙𝑇𝑇 × (𝑖𝑖 − 𝑖𝑖0), (1)
𝑖𝑖 = 𝑖𝑖0, 𝑖𝑖0 + 1, … , 𝑖𝑖0 + 𝑛𝑛 − 1 .
Di sini, 𝐴𝐴0 adalah alamat elemen awal, yang memiliki indeks 𝑖𝑖0, dan 𝑙𝑙𝑇𝑇 adalah
ukuran tipe data elemen (𝑇𝑇) dalam jumlah byte (B)—di sini, tentu saja, dalam
makna aslinya, yaitu (ukuran) lokasi memori dasar.
Nilai 𝑥𝑥(𝑖𝑖) dari elemen ke-𝑖𝑖 adalah konten memori 𝑀𝑀𝑇𝑇(𝐴𝐴(𝑖𝑖)) dari
alamat 𝐴𝐴(𝑖𝑖) yang ditafsirkan sebagai tipe data 𝑇𝑇,
𝑥𝑥(𝑖𝑖) = 𝑀𝑀𝑇𝑇(𝐴𝐴(𝑖𝑖)) .

2.2. C/C++ Arrays and Pointers
Bahasa C dan C++ menetapkan indeks awal ke 𝑖𝑖0 = 0, sehingga nilainya tidak perlu
dikurangi dari 𝑖𝑖. Hal ini menghasilkan rumus paling sederhana dan perhitungan alamat tercepat:
𝐴𝐴(𝑖𝑖) = 𝐴𝐴0 + 𝑙𝑙𝑇𝑇 × i, 𝑖𝑖 = 0, 1, … , 𝑛𝑛 − 1. (3)
Sebagaimana disinggung dalam pendahuluan (§1), alamat dan isi elemen juga dapat
dioperasikan oleh variabel bertipe data pointer khusus, yang biasanya disebut
pointer. Pointer menyimpan alamat dengan tipe data yang ditetapkan dan juga dapat dideskripsikan
sebagai alamat bertipe.
Secara keseluruhan, hal ini menghasilkan tiga kemungkinan cara untuk mengakses elemen array. Kami langsung menuliskannya dalam sintaksis bahasa C/C++ [1] (1988), [3], [4],
dengan cara yang sama seperti yang muncul dalam kode sumber benchmark pada Listing 1:
1. dengan menggunakan indeks elemen: iX[i];
2. dengan menggunakan aritmatika pointer dan kemudian dengan melakukan dereferensi pointer yang diperoleh:
*(pI0 + i);
3. dengan menaikkan pointer dan melakukan dereferensi: *(++pI).
Dua cara pertama merupakan jenis akses acak karena dapat mengakses elemen array
secara langsung melalui indeksnya, terlepas dari elemen yang diakses sebelumnya.
Akses ketiga hanya berlaku untuk lintasan melalui elemen array yang berurutan. Untuk memungkinkan
perbandingan efisiensi waktu antara ketiga jenis akses, di sini kami membatasi
pertimbangan hanya pada lintasan berurutan melalui elemen array untuk semua
jenis akses. Tentu saja, jenis lintasan ini juga yang paling umum dalam praktik. Pertimbangan umum di atas berlaku untuk susunan statis dan dinamis,
namun dalam teks selanjutnya, kami membatasi pertimbangan kami pada susunan statis.

2. Pointer
Pointer adalah tipe data khusus yang menyimpan alamat (addresses) dengan tipe data yang telah ditentukan. Pointer dapat juga digambarkan sebagai "typed addresses" (alamat bertipe).

Dalam bahasa C dan C++, pointer memungkinkan programmer untuk memanipulasi alamat memori dan isinya secara langsung, mirip dengan yang dimungkinkan dalam bahasa assembly, tetapi dengan menyerahkan detail organisasinya kepada compiler.

Deklarasi dan Inisialisasi Pointer

Operator & (address-of): digunakan untuk mendapatkan alamat dari sebuah variabel.
Operator * (dereference): digunakan untuk mengakses nilai dari alamat yang ditunjuk pointer.
cout << "Alamat x: " << &x << endl;
cout << "Nilai x melalui pointer: " << *ptr << endl;

Tipe-Tipe Pointer

1.Null Pointer: menunjuk ke alamat kosong (nullptr).

2.Void Pointer: pointer generik yang bisa menunjuk ke tipe apa pun, tapi perlu casting sebelum digunakan.

3.Pointer ke Pointer: digunakan untuk menyimpan alamat dari pointer lain.

4.Function Pointer: menunjuk ke alamat fungsi, berguna untuk callback.

5.Smart Pointer (C++11 ke atas): seperti unique_ptr, shared_ptr, dan weak_ptr, digunakan untuk manajemen memori otomatis.

Risiko Penggunaan Pointer

Dangling pointer: pointer menunjuk ke alamat yang sudah tidak valid (misalnya setelah delete).
Wild pointer: pointer yang belum diinisialisasi, berisi nilai acak.
Memory leak: terjadi jika alokasi memori dinamis (new) tidak dibebaskan (delete).
Oleh karena itu, penggunaan pointer harus hati-hati, atau gunakan smart pointer agar lebih aman.

## Guided 

### 1. ArrayNPointer
```C++
source code guided 1
#include<iostream>
using namespace std;

int main() {
    int arr[]= {10,20,30,40,50};
    int *ptr=arr; // pointer yang menunjuk ke elemen pertama array

    // mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++) {
        cout<< "elemen array ke-" << i+1 << "menggunakan pointer: " << *(ptr+i) << endl;
    }
    // mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++) {
        cout << "elemen array ke-" << i+1 << "menggunakan indeks: " << arr[i] << endl;

    }
    return 0;
}
penjelasan singkat guided 1
Program ini mendemonstrasikan dua cara mengakses elemen array: menggunakan pointer dan menggunakan indeks biasa.

### 2.CallByPointer
```C++
source code guided 2
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
penjelasan singkat guided 2
Program ini mendemonstrasikan pass by reference menggunakan pointer - cara mengubah nilai variabel asli melalui fungsi.

### 3.CallByReference
```C++
source code guided 3
#include<iostream>
using namespace std;

void ubahNilai(int&ref) {
    ref=20; // untuk mengubah nilai melalui referensi
}

int main() {
    int x=10;
    cout<< "nilai sebelum diubah:" << x << endl;
    ubahNilai(x); // mengirimkan referensi ke x
    cout << "nilai stelah diubah:" << x << endl;

    return 0;
}

penjelasan singkat guided 3
Program ini mendemonstrasikan pass by reference menggunakan reference (&) - cara lain mengubah nilai variabel asli melalui fungsi, tetapi lebih sederhana dari pointer.

### 4. FunctionProsedur
```C++
source code guided 4
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

penjelasan singkat guided
Program ini memiliki 3 fungsi utama: input array, mencari nilai maksimum, dan melakukan operasi aritmetika (penjumlahan & perkalian semua elemen).

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan,pengurangan,dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang di lakukan; jumlah matriks() untuk operasi penjumlahan, kurang matriks() untuk pengurangan, dan kali matriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case.

```C++
source code unguided 1
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

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 2/Unguided1.1_Matriks.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 2/Unguided1.2_Matriks.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 2/Unguided1.3_Matriks.png)

penjelasan unguided 1 
Program ini melakukan operasi matematika pada matriks 3×3: penjumlahan, pengurangan, dan perkalian dengan menu interaktif.


### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:

1. Buatlah 3 variabel integer di fungsi main: panjang beri nilai 10, lebar beri nilai 5, dan luas beri nilai 0.

2. Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar.

3. Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.

4. Cetak nilai luas ke layar.

5. Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar.

6. Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.

```C++
source code unguided 2

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


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 2/Unguided2_Keliling-Luas.png)


penjelasan unguided 2
Program ini menghitung luas dan keliling persegi panjang menggunakan pointer untuk memanipulasi nilai variabel, kemudian mendemonstrasikan bagaimana pointer dapat mengubah nilai variabel asli.

## Kesimpulan
Pointer dapat digunakan untuk mengakses dan memodifikasi nilai variabel secara langsung melalui alamat memori.

Program ini menunjukkan bahwa perubahan nilai melalui pointer (*ptrPanjang = 45; *ptrLebar = 70;) juga mengubah nilai asli variabel Panjang dan Lebar.

Pointer mempermudah manipulasi data, terutama ketika bekerja dengan variabel yang perlu diubah dari dalam fungsi atau saat menangani struktur data yang lebih kompleks (array, struct, class).

Dengan pointer, program bisa lebih fleksibel, namun juga perlu hati-hati karena kesalahan penggunaan bisa menyebabkan bug atau memory leak.

## Referensi
[1] Robert Logožar ; Dpt. of Electrical Engineering, University North, Varaždin, Croatia mail
Matija Mikac orcid id orcid.org/0000-0002-3449-8607 ; Dpt. of Electrical Engineering, University North, Varaždin, Croatia mail
Danijel Radošević ; Faculty of Organization and Informatics, University of Zagreb, Varaždin, Croatia mail

<br>[2] Anwar, Khoerul. "Multiple Inheritance Untuk C++." Jurnal Teknologi Informasi: Teori, Konsep, dan Implementasi, vol. 2, no. 1, 2011, pp. 25-39.

<br> [3] Association for Computing Machinery
New York, NY, United States


