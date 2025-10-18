# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINGKED  (Bagian Pertama)</h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

## Dasar Teori
Pengertian Linked list
Linked list sekumpulan elemen bertipe sama, yang mempunyai keterurutan tertentu, yang setiap elemennya terdiri dari dua bagian. Struktur berupa rangkaian elemen saling berkait dimana setiap elemen dihubungkan elemen lain melalui pointer. Pointer adalah alamat elemen. Penggunaan pointer untuk mengacu elemen berakibat elemen-elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori.
Bentuk Umum: Infotype sebuah tipe terdefinisi yang menyimpan informasi sebuah elemen list. Next address dari elemen berikutnya (suksesor) Jika L adalah list, dan P adalah address, maka alamat elemen pertama list L dapat diacu dengan notasi. Sebelum digunakan harus dideklarasikan terlebih dahulu. Elemen yang diacu oleh P dapat dikonsultasi informasinya dengan notasi.
Beberapa Definisi:

1. List I adalah list kosong, jika First(L) = Nil
2. Elemen terakhir dikenali, dengan salah satu cara adalah karena Next(Last) = Nil
Nil adalah pengganti Null, perubahan ini dituliskan dengan #define Nil Null

a. Single Linked List

Linked List adalah salah satu bentuk struktur data, berisi kumpulan data (node) yang tersusun secara sekuensial, sambungmenyambung, dinamis dan terbatas.Linked List sering disebut juga Senarai Berantai.Linked List saling terhubung dengan bantuan pointer variabel. Masing-masing data dalam Linked List disebut dengan node (simpul) yang menempati alokasi memori secara dinamis dan biasanya berupa struct yang terdiri dari beberapa field.
Single Linked List adalah sebuah LINKED LIST yang menggunakan sebuah variabel pointer saja untuk menyimpan banyak data dengan metode LINKED LIST, suatu daftar isi yang saling berhubungan.

Karakteristik Singly Linked List (SLL)

Satu Arah Koneksi
Setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya.Karena itu, traversal hanya bisa dilakukan dari head ke tail.Tidak bisa langsung menuju node sebelumnya (berbeda dengan Doubly Linked List).
Dinamis
Ukuran SLL tidak tetap, node dapat ditambahkan atau dihapus kapan saja.
Memori dialokasikan secara dinamis saat node dibuat (malloc di C / new di C++/Java).
Operasi Dasar
Traversal: Menelusuri seluruh node untuk membaca data atau mencari node tertentu.
Insertion: Menambahkan node baru di awal, tengah, atau akhir list.
Deletion: Menghapus node tertentu tanpa harus memindahkan elemen lain (berbeda dengan array).
Head dan Tail
Head → Node pertama, titik awal untuk semua operasi.
Tail → Node terakhir, biasanya menunjuk ke NULL.
Head selalu dibutuhkan untuk menjaga akses ke list; jika hilang, seluruh list bisa “hilang” dari memori.

Efisiensi Penyimpanan:
Tidak seperti array statis, SLL tidak membuang memori yang tidak digunakan.Namun, setiap node membutuhkan memori tambahan untuk pointer (next).

Akses Elemen:
Untuk mengakses node ke-n, harus dilakukan traversal dari head sampai node ke-n.Tidak bisa langsung mengakses node tertentu (akses acak lebih lambat dibanding array).

Fleksibilitas:
Memudahkan penyisipan dan penghapusan node di posisi mana pun tanpa harus memindahkan elemen lain.Sangat berguna untuk implementasi struktur data lain, seperti stack dan queue.

Keterbatasan:
Traversal satu arah membuat beberapa operasi lebih lambat (misal pencarian node sebelumnya).Memerlukan pointer tambahan di setiap node, sehingga ada overhead memori.

Keunggulan
Memori dapat dialokasikan secara dinamis.
Tidak ada pemborosan memori seperti pada array statis.
Mempermudah operasi penyisipan dan penghapusan node dibanding array.

Kelemahan
Tidak bisa mengakses elemen secara langsung (harus traversal dari head).
Menggunakan pointer tambahan, sehingga ada overhead.
Akses random lebih lambat dibanding array.

## Guided 

### 1. Singly Lingked

```C++
list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. node terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, node sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

list.h

//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

penjelasan singkat guided 1
Program ini menerapkan Singly Linked List untuk menyimpan informasi mahasiswa, yaitu nama, NIM, dan usia. Linked list ini terdiri dari node, di mana setiap node menyimpan data mahasiswa dan sebuah pointer next yang mengarah ke node selanjutnya. Node pertama dalam daftar disebut head atau first, sedangkan node terakhir menunjuk ke NULL, menandakan akhir dari daftar.

Pertama, program menghasilkan linked list kosong dengan memanggil createList(), sehingga pointer first diatur ke NULL. Selanjutnya, memori dialokasikan untuk lima node mahasiswa dengan menggunakan fungsi alokasi(). Fungsi ini menghasilkan node baru, mengisi informasi mahasiswa sesuai parameter, dan menyetel pointer node berikutnya ke NULL


### 2. Singly lingked

```C++
list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}


list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
penjelasan singkat guided 2
Program ini adalah implementasi lengkap Singly Linked List (SLL) untuk menyimpan data mahasiswa (nama, NIM, umur). Program dibagi menjadi tiga bagian utama: header (list.h), implementasi fungsi (list.cpp), dan program utama (main.cpp).


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h” 
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file 
“Singlylist.cpp” 
Kemudian buat program utama didalam file “main.cpp”

```C++
source code unguided 1

singlyst.h
#ifndef SINGLYST_H
#define SINGLYST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif

singlyst.cpp
#include "singlyst.h"

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

main.cpp
#include "singlyst.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/Unguided-Delete/Unguided1-MODUL4.png)

penjelasan unguided 1 
Pada Unguided 1 kita diminta untuk membuat program main.cpp, singlyst.cpp, dan singlyst.h dari kode yang di sediakan untuk memunculkan output 9 12 8 0 2.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan 
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh 
node menggunakan deleteList(). 

```C++
source code unguided 2

singlyst.h
#ifndef SINGLYST_H
#define SINGLYST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, infotype x);
int nbList(List L);
void deleteList(List &L);

#endif

singlyst.cpp
#include "singlyst.h"

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            dealokasi(L.first);
            L.first = nullptr;
        } else {
            address prev = nullptr;
            address curr = L.first;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            dealokasi(curr);
        }
    }
}

void deleteAfter(List &L, infotype x) {
    address prec = L.first;
    while (prec != nullptr && prec->info != x) {
        prec = prec->next;
    }
    if (prec != nullptr && prec->next != nullptr) {
        address P = prec->next;
        prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}

main.cpp
#include "singlyst.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, 8);
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/Unguided-Delete/Unguided2-MODUL4.png)

penjelasan unguided 2
Program ini menerapkan Singly Linked List untuk menyimpan data bilangan bulat. Setiap node dalam daftar memiliki sebuah nilai (info) dan pointer (next) yang mengarah ke node selanjutnya, sementara first menunjuk ke node pertama dalam daftar. Program ini pertama-tama menciptakan list kosong, lalu membuat beberapa node dengan nilai spesifik dan menambahkannya di depan list memakai fungsi insertFirst.

Setelah semua node ditambahkan, program melakukan beberapa operasi penghapusan: deleteFirst menghapus node awal, deleteLast menghapus node akhir, dan deleteAfter menghapus node yang berada setelah node dengan nilai tertentu. Selanjutnya, program menunjukkan konten list yang tersisa serta menghitung jumlah node melalui printInfo dan nbList.


## Kesimpulan
program ini telah berhasil menerapkan Singly Linked List dengan operasi dasar seperti menambahkan node di awal (insertFirst), menghapus node pertama (deleteFirst), penghapusan node terakhir (deleteLast), dan penghapusan node setelah node tertentu (deleteAfter). Program ini juga dapat melakukan traversal untuk menampilkan konten list dan menghitung total node, serta menghapus semua list secara dinamis dengan menggunakan deleteList. Pemanfaatan manajemen memori dinamis (new dan delete) menjamin alokasi dan pembebasan setiap node dilakukan dengan tepat, sehingga mengurangi kemungkinan terjadinya memory leak. Dengan demikian, program ini mengilustrasikan konsep dasar linked list, mencakup pengelolaan pointer, urutan node, serta fleksibilitas dalam penambahan dan penghapusan node

## Referensi
[1] Eman Almadhoun, Jennifer Parham-Mocello,
Students’ difficulties with inserting and deleting nodes in a singly linked list in the C programming language,
Journal of Computer Languages.
[2] Sartika, I., & Rahman, A. (2020). Struktur Data dan Algoritma dengan C. Jakarta: Informatika.
[3] Modul ASD UM. (2016). Single & Double Linked List. Universitas Negeri Malang.


