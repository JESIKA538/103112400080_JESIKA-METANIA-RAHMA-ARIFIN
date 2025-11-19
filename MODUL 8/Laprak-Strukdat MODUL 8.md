# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE </h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

## Dasar Teori
1. Pengertian Queue

Queue (antrian) adalah struktur data linear yang mengikuti prinsip FIFO (First In, First Out), yaitu elemen yang pertama kali masuk akan menjadi elemen pertama yang keluar. Konsep ini menyerupai antrian pada kehidupan nyata, seperti antrian di loket atau kasir.

Menurut Ariyus (2019), queue adalah struktur data yang memproses data secara berurutan berdasarkan waktu kedatangan, sehingga elemen yang datang lebih awal harus diselesaikan terlebih dahulu sebelum elemen berikutnya.

Selain itu, Sari & Pratiwi (2021) menyatakan bahwa queue digunakan untuk memodelkan berbagai permasalahan komputasi yang membutuhkan pengelolaan proses secara teratur dan berurutan.

2. Operasi Dasar pada Queue

Beberapa operasi utama yang terdapat pada struktur data queue antara lain:

a. Enqueue

Operasi untuk menambahkan elemen baru ke bagian belakang (rear/tail) queue.

b. Dequeue

Operasi untuk menghapus elemen dari bagian depan (front/head) queue.

c. IsEmpty

Pengecekan apakah queue kosong.

d. IsFull

Pengecekan apakah queue sudah penuh (pada array-based queue).

e. Front dan Rear

Digunakan untuk mengetahui elemen paling depan dan paling belakang dari antrian.

Menurut Kurniawan et al. (2020), operasi enqueue dan dequeue pada queue merupakan mekanisme yang sangat penting dalam proses scheduling pada sistem komputer.

3. Jenis-Jenis Queue
a. Linear Queue

Queue paling dasar dengan head dan tail bergerak satu arah. Ketika penuh, meskipun ada ruang kosong di depan, tetap dianggap penuh.

b. Circular Queue

Variasi queue dengan indeks yang melingkar (circular). Ketika mencapai akhir array, indeks kembali ke posisi awal.

Sari (2020) menjelaskan bahwa circular queue lebih efisien karena memanfaatkan seluruh kapasitas memori dengan baik.

c. Priority Queue

Elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan dilayani lebih dahulu meskipun datang lebih lambat.

d. Double-Ended Queue (Deque)

Operasi penambahan dan penghapusan elemen dapat dilakukan dari kedua sisi, baik depan maupun belakang.

4. Penerapan Queue dalam Kehidupan dan Komputasi

Menurut Yuliana & Hakim (2022), queue digunakan dalam berbagai sistem komputasi modern seperti:

CPU scheduling (FCFS – First Come First Served)

Buffering data, seperti keyboard buffer atau printer queue

Manajemen pesan (message queue)

Simulasi antrian pada sistem pelayanan

Breadth-First Search (BFS) pada algoritma graf

Queue dipilih karena sifatnya yang memberikan keadilan dan keteraturan dalam pemrosesan data.

5.  Implementasi Queue

Queue dapat diimplementasikan menggunakan:

a. Array

Mudah diimplementasikan, tetapi memiliki keterbatasan kapasitas.

b. Linked List

Lebih fleksibel karena kapasitas bergantung pada memori yang tersedia.

c. Struktur data abstrak (ADT)

Sering digunakan pada pemrograman modular agar kode lebih terstruktur.

Menurut Santoso & Putra (2021), implementasi queue menggunakan linked list lebih efisien dalam hal penggunaan memori dibanding array yang statis.

## Guided 

### 1.1 stack.h
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
};

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q,int data);

#endif

### 1.2. stack.cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}

### 1.3 Main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB =alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q,  nodeE);

    cout << "--- Queue setelah enqueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}

penjelasan singkat guided 1
Program ini adalah program yang mengimplementasikan struktur data Queue (antrian) menggunakan linked list.
Queue bekerja dengan prinsip FIFO (First In First Out) — data yang masuk lebih dulu, akan keluar lebih dulu.

### 2.1 stack.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool ifFull(Queue Q);
void enQueue(Queue &Q, int x);
int deQueue(Queue &Q);
void printInfo(Queue Q);

#endif


### 2.2 stack.cpp
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}

### 2.3 main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

// Fungsi utama proggram
int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);
    cout << "\n Enqueue 3 Elemen" << endl;
    enQueue(Q, 5);
    printInfo(Q);
    enQueue(Q, 2);
    printInfo(Q);
    enQueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    enQueue(Q,4);
    printInfo(Q);

    
    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    printInfo(Q);

    return 0;
}

penjelasan singkat guided 2
Program ini adalah program yang mengimplementasikan struktur data Queue (antrian) menggunakan array.
Queue bekerja dengan prinsip FIFO (First In First Out) — data yang masuk lebih dulu, akan keluar lebih dulu.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”.  Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak)
```C++
source code unguided 1
```

## queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

typedef struct {
    infotype info[5];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

## queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
        return x;
    }

    // geser ke kiri
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "  | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}


## main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);                   // awal
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/JESIKA528/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 8/c:\Users\ASUS\OneDrive\Gambar\Screenshot\unguided 1 MODUL 8.png)

penjelasan unguided 1 
Program ini adalah program yang di implementasikan ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

```C++
source code unguided 2
```
## queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

typedef struct {
    infotype info[5];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif


## queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype val = Q.info[Q.head];

    // Jika elemen terakhir dihapus → queue kosong lagi
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } 
    else {
        Q.head++;   // head bergerak
    }

    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << "  " << Q.tail << "  : ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}


## main.cpp
##include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);                   // awal
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/JESIKA528/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 8/c:\Users\ASUS\OneDrive\Gambar\Screenshot\unguided 2 MODUL 8.png)

penjelasan unguided 2
Program ini adalah pengembangan program yang ada pada unguided 1 yaitu mengimplementasikan berdasarkan ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar)
```C++
source code unguided 3
```
## queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

typedef struct {
    infotype info[5];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

## queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    // Circular condition
    return ( (Q.tail + 1) % 5 == Q.head );
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail) {
        // Queue menjadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;
    }

    return val;
}

void printInfo(Queue Q) {
    cout << Q.head << "  " << Q.tail << "  : ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % 5;
        }
    }

    cout << endl;
}

## main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);               
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/JESIKA528/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/blob/main/MODUL 8/c:\Users\ASUS\OneDrive\Gambar\Screenshot\unguided 3 MODUL 8.png)

penjelasan unguided 3
Pada program ketiga ini juga adalah pengembangan program pertama dan kedua, bedanya pada program ketiga ini program nya  implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

## Kesimpulan
Seperti yang ditunjukkan oleh tiga perintah implementasi ADT Queue, setiap mekanisme queue alternatif mengelola posisi head dan tail secara berbeda, tetapi tetap mengikuti prinsip dasar FIFO (First In First Out).

 1. Alternatif 1: Head Diam, Tail Move

 Pada mekanisme ini, kepala tetap berada di posisi awal, sedangkan ekor terus bergerak maju.
 Keuntungan: akal sehat
 Kekurangan: Meskipun masih ada slot kosong, queue tetap penuh karena ruang yang kosong di depan tidak dapat digunakan kembali.

 2. Alternatif 2:Head Move, Tail Move
 
 Dalam mekanisme ini, kepala dan ekor bergerak maju setelah operasi enqueue dan dequeue.
 Keuntungan: dengan menggeser elemen (shifting), ruang depan dapat digunakan ulang.
 Kekurangan: Karena overhead pemindahan data, shifting memperlambat proses dequeue.
 
 3:  Alternatif 3:Pusat Berputar Head and Tail
 
 Dalam mekanisme queue berputar, ketika ujung dan ujung array mencapai batasnya, mereka akan kembali ke indeks 0.
 Keuntungan: Karena tidak ada ruang terbuang, penggunaan memori paling efisien.
 Kekurangan: implementasi lebih kompleks karena memerlukan perhitungan khusus (modular arithmetic).
 
## Referensi
[1]Ariyus, D. (2019). Struktur Data dan Algoritma untuk Pemrograman. Jurnal Rekayasa Teknologi Informasi, 7(2), 45–52.
<br>[2]Sari, N. L., & Pratiwi, D. (2021). Analisis Struktur Data Queue dalam Pengelolaan Data Berurutan. Jurnal Informatika dan Sistem Cerdas, 3(1), 12–20.
<br>[3] Kurniawan, A., Nugroho, P., & Widodo, S. (2020). Implementasi Struktur Data Queue pada Sistem Penjadwalan Komputer. Jurnal Teknologi dan Sistem Komputer, 8(3), 145–151.
<br>[4] Sari, A. P. (2020). Pemanfaatan Circular Queue pada Sistem Antrian Pelayanan. Jurnal Teknologi Informasi dan Ilmu Komputer, 7(4), 567–574.
<br>[5] Yuliana, R., & Hakim, A. (2022). Analisis Penggunaan Queue pada Sistem Komputasi Modern. Jurnal Ilmu Komputer dan Aplikasinya, 5(2), 89–98.
<br>[6] Santoso, H., & Putra, R. (2021). Implementasi Queue Menggunakan Linked List pada Aplikasi Pelayanan. Jurnal Sistem Informasi dan Teknologi, 4(1), 33–41.


