# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE </h1>
<p align="center"> JESIKA METANIA RAHMA ARIFIN_103112400080 </p>

## Dasar Teori
ABSTRACT DATA TYPE
Tipe data abstrak bertujuan untuk menspesifikasi perangkat lunak dengan mengenkapsulasi data yang didefinisikan secara abstrak melalui konstruktor dan operasi yang dispesifikasikan oleh sekumpulan persamaan terarah (orde pertama) yang beroperasi pada ekspresi konstruktor. Dalam pengaturan ini, komputasi dilakukan melalui penulisan ulang (rewriting), yaitu dengan berulang kali mengganti sisi kiri persamaan dengan sisi kanannya. Pencarian sisi kiri melibatkan algoritma pencocokan pola, oleh karena itu gaya definisi ini sering disebut sebagai definisi pencocokan pola.
Contoh tipikal dari pendekatan sederhana ini adalah tipe data abstrak Nat yang diberikan di bawah ini dalam sintaks seperti OBJ, yang menspesifikasikan bilangan asli dengan penambahan yang direpresentasikan dalam notasi Peano:
OBJ Nat
constructors
  0 : Nat
  succ : Nat → Nat
operators
  + : Nat × Nat → Nat
variables
  x, y : Nat
equations
  0 + x = x
  succ(x) + y = succ(x + y)
end OBJ
Salah satu tujuan ADT adalah menyembunyikan detail representasi sehingga pengguna hanya melihat antarmuka (operasi) yang diperbolehkan.
ADT sering dijelaskan menggunakan spesifikasi aljabar (operasi + hukum / persamaan) atau logika, yang menyatakan sifat-sifat yang harus dipenuhi operasi-operasi ADT.
ADT berkaitan erat dengan teori tipe, khususnya pada aspek type abstraction dan existential types.
Teori ADT juga membahas bagaimana membentuk ADT baru dari ADT yang sudah ada (misalnya melalui operasi gabungan, produk, sum types, rekursi).
ADT adalah spesifikasi abstrak; struktur data adalah implementasi konkret yang memenuhi ADT tersebut. Sebuah ADT bisa diimplementasikan dengan berbagai struktur data.
Karena ADT memiliki spesifikasi formal, implementasi dapat diverifikasi (misalnya melalui pembuktian bahwa implementasi memenuhi sifat spesifikasi).
Beberapa isu yang dibahas dalam teori ADT: konflik antara penyembunyian data dan optimisasi memori, atau efisiensi implementasi vs kemurnian spesifikasi.

## Guided 

### 1.ADT

```C++
#include<iostream>
#include"mahasiswa.h"

using namespace std;

// Realisasi dari fungsi inputMhs
void inputMhs(mahasiswa &m) {
    cout << "Input NIM:";
    cin >> m.nim;
    cout << "Input Nilai 1:";
    cin >> m.nilai1;
    cout << "Input Nilai 2:";
    cin >> m.nilai2;
}

// Realisasi dari fungsi rata2
float rata2(mahasiswa m) {
    return(float)(m.nilai1 + m.nilai2) / 2;
}

penjelasan singkat guided 1
Kode ini merupakan implementasi (realisasi) dari dua fungsi yang berhubungan dengan tipe data abstrak (ADT) bernama mahasiswa.

### 2. ADT

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//Definisi Tipe(struct)
struct mahasiswa {
    char nim[10];
    int nilai1,nilai2;
};

//Deklarasi Primitif(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif

penjelasan singkat guided 2
File ini menyimpan deklarasi (interface) — bukan implementasi. Implementasinya ada di file .cpp

### 3. ADT

```C++
#include<iostream>
#include"mahasiswa.h"
#include<cstdlib>

using namespace std;
int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai adalah :" << rata2(mhs);
    //system("pause");
    return 0;
}

penjelasan singkat guided 3
Ini adalah contoh penerapan Abstract Data Type (ADT), karena data (struct mahasiswa) dan operasi terhadap data (inputMhs, rata2) dibuat terpisah dan terstruktur.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nim,nama;
    float uts, uas,tugas,nilaiAkhir;
};
float nilaiAkhir(float uts, float uas, float tugas){
    return 0.3*uts + 0.4*uas + 0.3*tugas;
};
int main() {
    mahasiswa mhs[10];
    int n;
    cout << "Jumlah mahasiwa (max 10): ";
    cin >> n;
    cin.ignore(); // tujuan nya biar ga error

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;

       mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cin.ignore();
    }
     cout << "\n=== DAFTAR NILAI MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " (" << mhs[i].nim << ") = "
             << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/Unguided/Unguided1.png)

penjelasan unguided 1 
Program ini digunakan untuk:
Mencatat dan menampilkan daftar nilai mahasiswa (UTS, UAS, dan Tugas) serta menghitung nilai akhirnya.

### 2.Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
Type pelajaran <
namamapel: string
kodemapel: string
> function create_pelajaran( namapel: string,
kodepel
: string) →
pelajaran
pelajaran )
informatids lab
procedure tampil_pelajaran (input pel :
Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

```C++
source code unguided 2
//  main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    char namaMapel[] = "Struktur Data";
    char kodeMapel[] = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodeMapel);
    tampil_pelajaran(pel);

    return 0;
}

// pelajaran.cpp
#include<iostream>
#include<cstring>
#include"pelajaran.h"
using namespace std;

pelajaran create_pelajaran(char namaMapel[], char kodeMapel[]) {
    pelajaran pel;
    strcpy(pel.namaMapel, namaMapel);
    strcpy(pel.kodeMapel, kodeMapel);
    return pel;
}
    void tampil_pelajaran(pelajaran pel) {
        cout << "Nama Mapel: " << pel.namaMapel << endl;
        cout << "Kode Mapel: " << pel.kodeMapel << endl;
    }


// pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

struct pelajaran {
    char namaMapel[50];
    char kodeMapel[10];
};
pelajaran create_pelajaran(char namaMapel[], char kodeMapel[]);
void tampil_pelajaran(pelajaran pel);

#endif

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/Unguided/Unguided2.png)

penjelasan unguided 2
File Header – pelajaran.h

File ini berfungsi sebagai deklarasi struktur dan fungsi yang akan digunakan dalam program.
Isinya biasanya hanya berupa definisi tipe data (struct) dan prototipe fungsi, tanpa implementasi logika.

File Implementasi – pelajaran.cpp

File ini berisi definisi (implementasi) dari fungsi yang sudah dideklarasikan di header.

File Utama – main.cpp

File ini berisi program utama yang menjalankan logika menggunakan ADT tersebut.
Bagian ini biasanya hanya “memanggil” fungsi-fungsi dari file sebelumnya.

### 3. menggunakan namespace std;

ke dalam utama() {
string namapel "Struktur Data";
string kodepel "STD"
pelajaran pel create pelajaran (namapel, kodepel);
tampil pelajaran (pel):
kembali 0;
Gambar 3-1 main.cpp pelajaran
Contoh output hasil:
nama pelajaran Struktur Data
nilai : STD
Gambar 3-2 output pelajaran

3. Buatlah program dengan ketentuan:
2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
fungsi/prosedur yang menampilkan isi sebuah array integer 2D
fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/Unguided/Unguided3.png)

penjelasan unguided 3
Program ini intinya menampilkan dua array 2D (matriks) dan menunjukkan dua jenis penukaran nilai:
Tukar elemen tertentu antar dua array (menggunakan indeks baris dan kolom)
Tukar nilai menggunakan pointer.

## Kesimpulan
Program ADT yang telah dikembangkan menerapkan prinsip Abstract Data Type (ADT) dalam bahasa C++ dengan cara mendefinisikan tipe data baru berupa struktur mataPelajaran yang memiliki dua atribut, yaitu namaPelajaran dan kodePelajaran. Dengan membagi kode menjadi tiga komponen utama, yaitu file header (pelajaran.h) untuk deklarasi struktur dan fungsi, file implementasi (pelajaran.cpp) untuk definisi fungsi create_pelajaran dan tampil_pelajaran, serta file utama (main.cpp) yang menggunakan fungsi-fungsi tersebut, program ini menunjukkan penerapan prinsip abstraksi, modularitas, dan enkapsulasi. Proses pembuatan objek pelajaran dilakukan melalui panggilan fungsi create_pelajaran, sedangkan penujukan data ke layar dilakukan dengan fungsi tampil_pelajaran. Program ini menunjukkan bagaimana tipe data abstrak dapat digunakan untuk merepresentasikan entitas nyata, dalam hal ini mata pelajaran, dengan memisahkan definisi data, implementasi logika, dan penggunaannya. Di samping itu, dengan adanya struktur yang teratur dan pengelolaan file yang transparan, program ini mendukung proses pemeliharaan, pengembangan, serta pemahaman kode secara keseluruhan, sesuai dengan prinsip dasar dari Tipe Data Abstrak (ADT)


## Referensi
[1] Jean-Pierre Jouannaud, Mitsuhiro Okada,
Abstract data type systems,
Theoretical Computer Science,
Volume 173, Issue 2,
1997,
Pages 349-391,
ISSN 0304-3975,
https://doi.org/10.1016/S0304-3975(96)00161-2.
 
<br>[2] LRI, Bat. 490, CNRS/Université de Paris Sud, 91405 Orsay, France
Department of Philosophy, Keio University, 108 Minatoku, Tokyo, Japan.

<br>[3] Thomas, J.C., and Gould, J.D. A psychological study of queryby-example. Proc. AFIPS 1975 NCC, Vol. 44, AFIPS Press, Montvale, N.J., pp. 439-445. (IBM Res. Rep. RC-5124, Nov. 1974). 

<br>[4] Zloof, M.M. Query-by-example. Proc. AFIPS 1975 NCC, Vol.
44, AFIPS Press, Montvale, N.J., pp. 431-438 (IBM Res. Rep. RC4917, July 1974). 

<br>[5] Zloof, M.M. Query-by-example: A data base management language. IBM Res. Rep., Dec. 1976; available upon request from
Mosh6 Zloof, T.J. Watson Res. Ctr., Yorktown Heights, N.Y. 

