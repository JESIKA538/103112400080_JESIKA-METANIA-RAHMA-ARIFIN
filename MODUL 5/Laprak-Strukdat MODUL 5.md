# <h1 align="center">Laporan Praktikum Modul 5 -SINGLY LINGKED  (Bagian Kedua)</h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

## Dasar Teori
Pengertian Linked list
Linked list sekumpulan elemen bertipe sama, yang mempunyai keterurutan tertentu, yang setiap elemennya terdiri dari dua bagian. Struktur berupa rangkaian elemen saling berkait dimana setiap elemen dihubungkan elemen lain melalui pointer. Pointer adalah alamat elemen. Penggunaan pointer untuk mengacu elemen berakibat elemen-elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori.
Bentuk Umum: Infotype sebuah tipe terdefinisi yang menyimpan informasi sebuah elemen list. Next address dari elemen berikutnya (suksesor) Jika L adalah list, dan P adalah address, maka alamat elemen pertama list L dapat diacu dengan notasi. Sebelum digunakan harus dideklarasikan terlebih dahulu. Elemen yang diacu oleh P dapat dikonsultasi informasinya dengan notasi.
Struktur node (konseptual).

Node {
  data;
  next; // pointer ke node berikutnya atau null
}
head -> Node1 -> Node2 -> ... -> NodeN -> null

### Pengertian Searching (Pencarian)

Searching atau pencarian adalah proses untuk menemukan lokasi atau data tertentu di dalam suatu kumpulan elemen data. Tujuan utama dari pencarian adalah menemukan apakah suatu elemen terdapat dalam kumpulan data dan, jika ada, di mana posisinya berada.
Menurut GeeksforGeeks (2024), algoritma pencarian dibagi menjadi dua jenis utama, yaitu pencarian berurutan (linear search) dan pencarian biner (binary search), tergantung pada cara data tersebut diakses dan diurutkan.

### A. Pencarian Linear (Linear Search) pada Singly Linked List
Definisi
Linear Search atau Sequential Search adalah metode pencarian paling sederhana, di mana elemen dicari dengan memeriksa satu per satu dari awal hingga akhir daftar.
Metode ini tidak membutuhkan data yang terurut dan dapat digunakan pada struktur data seperti array, linked list, atau list dinamis.
Algoritma:
function linearSearch(head, key):
    current = head
    while current != null:
        if current.data == key: return true
        current = current.next
    return false

Pada singly linked list, linear search biasanya merupakan pilihan standar untuk pencarian karena struktur list tidak mendukung akses acak yang diperlukan algoritma pembagian (divide-and-conquer).

### B. Binary Search
Binary Search adalah metode pencarian yang lebih efisien dengan kompleksitas waktu O(log n), namun hanya dapat diterapkan pada data yang sudah terurut.
Pada array, binary search dilakukan dengan membagi dua data secara berulang hingga nilai yang dicari ditemukan.
Namun, pada singly linked list, algoritma binary search tidak dapat berjalan secara langsung karena linked list tidak mendukung akses acak (random access) seperti array.
Beberapa studi/paper mengusulkan metode khusus untuk “melakukan” binary search pada linked list (mis. menggunakan array indeks tambahan, dual pointers, atau struktur bantu lain) sehingga menemukan atau memperkirakan posisi tengah menjadi lebih cepat. Contohnya:
Menyimpan penunjuk/indeks ke node agar memungkinkan bentuk akses acak (tabel indeks / array penunjuk).

Metode dual-pointer yang berusaha mencari titik tengah dengan dua pointer untuk setiap pemisahan sublist.

Namun, metode tersebut meningkatkan overhead (memori tambahan atau perjalanan ekstra) dan dalam banyak situasi mengurangi atau menghapus keuntungan teoretis binary search—sehingga seringkali tidak lebih baik dibandingkan linear search pada linked list standar. Karena itu, literatur menyimpulkan bahwa untuk singly linked list sederhana, pencarian linier tetap lebih praktis/efisien kecuali terdapat struktur tambahan atau perubahan pada metode penyimpanan


## Guided 

### 1. ListBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

### main.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;  
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;  
    createList(List);

    dataBuah dtBuah;  
    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "=== ISI LIST SETELAH DILAKUKAN INSERT ===" << endl;
    printList(List);  
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "=== ISI LIST SETELAH DILAKUKAN UPDATE ===" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    return 0;
}

## listBuah.h
#ifndef LIST_BUAH
#define LIST_BUAH
#define Nil NULL 

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah
typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct

struct node{ //node untuk isi dari linked listnya. isi setiap node adalah data & pointer
    dataBuah isidata;
    address next; 
};

struct linkedlist{
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &list);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif

penjelasan singkat guided 1
Program ini mendemonstrasikan ide manajemen memori dinamis dalam singly linked list, meliputi operasi penyisipan, penghapusan, dan pembaruan.
Keuntungannya adalah ukuran daftar dapat tumbuh atau mengecil secara fleksibel sesuai kebutuhan.
Program ini juga berfungsi sebagai landasan sebelum memasukkan operasi pencarian (linear/biner) pada bagian kedua modul berikutnya.


### 2.Binary
```C++
source code guided 2
#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node *next;
};

// Fungsi untuk menambah node di akhir
void append(Node* &head, int value) {
    Node* newNode = new Node;   // buat node baru
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) head = newNode;  // jika list kosong
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk menghitung panjang linked list
int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Fungsi untuk mengambil node ke-n
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next;
    return head;
}

// Binary Search pada Linked List (dengan akses sequential)
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getSize(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        if (!midNode) return nullptr;
        if (midNode->data == key) return midNode;
        else if (midNode->data < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}

penjelasan singkat guided 2
Program ini menunjukkan pencarian data dalam Singly Linked List dengan metode Binary Search, walaupun sebenarnya Binary Search tidak efisien untuk linked list karena tidak mendukung akses acak.
Akan tetapi, program ini tetap menggunakan prinsip binary search dengan menghitung lokasi node dan menelusurinya secara berurutan


### 3. Linear

```C++
source code guided 3
#include<iostream>
using namespace std;

//Definisi node
struct Node{ //Memiliki 2 bagian yaitu data dan pointer
    int data; 
    Node *next; //Pointer ke node berikutnya
};

//FUngsi untuk pencarian
Node *linearSearch(Node *head, int key){
    Node *current = head;
    while (current != nullptr){
        if (current -> data == key) return current;
        current = current -> next; //Pindah ke node berikutnya
    }

    return nullptr; //Tidak ditemukan
}

//Prosedur untuk menambah node
void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr};

    if(!head) head = newNode;
    
    else{
        Node* temp = head; //mulai dari head
        while (temp -> next) temp = temp -> next;
        temp -> next = newNode;
    }
}

int main(){
    Node * head = nullptr; //inisialisasi head
    append(head, 10); append(head, 20); append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result ? "Found" : "Not Found") << endl; //condition? value_if_true : value_if_false;
    return 0;
}

penjelasan singkat guided 3
Program ini mengilustrasikan metode pencarian data (searching) dalam Singly Linked List dengan menggunakan Linear Search.
Dengan kata lain, pencarian dilakukan secara beruntun mulai dari node pertama (head) sampai data yang dicari ditemukan atau daftar selesai.

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 1:
-Gunakan struktur Node dengan data integer dan pointer next
-Implementasikan fungsi append() untuk menambah node
-Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan
-Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
-Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi
-Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian

```C++
source code unguided 1
```C++
source code unguided 2
#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node *next;
};

// Fungsi untuk menambah node di akhir
void append(Node* &head, int value) {
    Node* newNode = new Node;   // buat node baru
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) head = newNode;  // jika list kosong
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Fungsi untuk mengambil node ke-n
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next;
    return head;
}

// Binary Search pada Linked List 
Node* binarySearch(Node* head, int key) {
    int right = 0;
    Node* temp = head;
    while (temp) {
        right++;
        temp = temp->next;
    }
    right--;

    int left = 0;
    int iterasi = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);
        if (!midNode) break;

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
             << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            return midNode;
        }
        else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

int main() {
    cout << "BINARY SEARCH PADA LINGKED LIST" << endl;
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Isi Lingked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Mencari data yang ada dalam list

    // Pencarian pertama (40)
    // ============================
    int key = 60;
    cout << "Mencari nilai: " << key << endl;

    Node* result = binarySearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    }

    // ============================
    // Pencarian kedua (25)
    // ============================
    key = 45;
    cout << "\nMencari nilai: " << key << endl;

    result = binarySearch(head, key);

    if (!result) {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 5/Unguided1-MODUL 5.png)

![Screenshot Output Unguided 1.1](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 5/Unguided1.1-MODUL 5.png)

penjelasan unguided 1 
Program ini digunakan untuk mencari nilai tertentu (key) di dalam Linked List yang sudah terurut menggunakan algoritma Binary Search.

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 2:
Gunakan struktur Node dengan data integer dan pointer next
Implementasikan fungsi append() untuk menambah node
Implementasikan fungsi linearSearch () yang mengembalikan pointer ke node yang ditemukan
Data dalam linked list tidak perlu terurut untuk linear search
Tampilkan setiap langkah pencarian dan node yang sedang diperiksa
Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

```C++
source code unguided 3
#include<iostream>
using namespace std;

//Definisi node
struct Node{ //Memiliki 2 bagian yaitu data dan pointer
    int data; 
    Node *next; //Pointer ke node berikutnya
};

//Fungsi untuk pencarian
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;

        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }

        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

//Prosedur untuk menambah node
void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr};

    if(!head) head = newNode;
    
    else{
        Node* temp = head; //mulai dari head
        while (temp -> next) temp = temp -> next;
        temp -> next = newNode;
    }
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n";

    // ==========================
    // Pencarian pertama
    // ==========================
    int key = 40;
    cout << "Mencari nilai: " << key << "\n";

    Node* result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    }

    // ==========================
    // Pencarian kedua
    // ==========================
    key = 35;
    cout << "\nMencari nilai: " << key << "\n";

    result = linearSearch(head, key);

    if (!result) {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 5/Unguided2-MODUL 5.png)

![Screenshot Output Unguided 2.2](https://github.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 5/Unguided2.2-MODUL 5.png)

penjelasan unguided 2
Program ini digunakan untuk mencari sebuah nilai (key) di dalam struktur data linked list menggunakan metode pencarian linear (linear search).

## Kesimpulan
Hasil analisis dan pelaksanaan program pencarian data pada linked list dengan metode Linear Search dan Binary Search menunjukkan bahwa kedua algoritma berjalan dengan baik serta menunjukkan proses pencarian secara rinci. Dalam Linear Search, pencarian dilakukan dengan mengecek setiap node satu per satu dari awal sampai akhir hingga data ditemukan atau dianggap tidak ada. Metode ini mudah dan efisien untuk daftar terkait yang tidak terurut.

Pada Binary Search, pencarian dilakukan dengan cara membagi linked list menjadi dua bagian secara berulang berdasarkan nilai tengahnya. Algoritma ini hanya dapat digunakan pada linked list yang urut, dan meskipun lebih efisien dalam teori untuk struktur array, pada linked list efisiensinya hampir sama dengan Linear Search karena tidak bisa langsung mengakses elemen tengah


## Referensi
[1] GeeksforGeeks. (2025, July 23). Linked List Data Structure. Retrieved October 24, 2025, from https://www.geeksforgeeks.org/linked-list-data-structure

[2]GeeksforGeeks. (2024, September 4). Binary Search on Singly Linked List. Retrieved October 24, 2025, from https://www.geeksforgeeks.org/binary-search-on-singly-linked-list

[3]Kumar, S. (2019). Binary Search in Linked List. International Journal of Recent Technology and Engineering (IJRTE), 8(4), 324–327.

[4]Datta, S., & Bhattacharjee, P. (2014). Implementation of Binary Search on a Singly Linked List Using Dual Pointers. International Journal of Computer Science and Information Technologies (IJCSIT), 5(2), 2783–2786.

[5]Steve, J. (n.d.). Chapter: Linked Lists. Lecture Notes on Data Structures.
