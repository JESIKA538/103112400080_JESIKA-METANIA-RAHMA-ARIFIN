# <h1 align="center">Laporan Praktikum Modul 7 - STACK </h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

## Dasar Teori
1. Definisi dan Karakteristik STACK

Struktur data stack adalah sebuah abstraksi yang mengikuti prinsip Last In, First Out (LIFO) — yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Operasi dasar pada stack meliputi:
-push(x): Menambahkan elemen x ke atas (top) stack.
-pop(): Menghapus dan mengembalikan elemen paling atas dari stack.
-peek/top: Melihat elemen paling atas tanpa menghapusnya.
-isEmpty, isFull: Mengecek apakah stack kosong atau penuh (jika kapasitas terbatas).

2. Implementasi: Array vs Linked List
Stack dapat diimplementasikan menggunakan array dengan indeks top yang bergerak, atau menggunakan linked list di mana top menunjuk node paling atas. Setiap metode memiliki keunggulan dan keterbatasan:

I-mplementasi berbasis array menawarkan akses langsung dan efisiensi memori apabila kapasitas sudah diketahui sebelumnya.

-Implementasi berbasis linked list memberikan fleksibilitas ukuran yang dinamis, namun overhead pointer dan fragmentasi memori bisa jadi penghambat.

3. Pertimbangan dalam Pemilihan Implementasi
Ketika memilih implementasi stack, beberapa faktor yang perlu dipertimbangkan meliputi:

Kebutuhan ukuran maksimum: Jika sudah diketahui, array dapat lebih efisien.

Frekuensi push/pop: Jika banyak operasi dan ukuran bisa bertambah-berkurang, linked list bisa lebih fleksibel.

Keterbatasan memori dan fragmentasi: Linked list memerlukan pointer tambahan dan mungkin kurang efisien dari sudut cache memory.

Kinerja riil vs teori: Walaupun kompleksitas teoretis bisa mirip, faktor seperti alokasi memori, cache miss, dan overhead pointer bisa membuat perbedaan nyata dalam performa.

## Guided 

### 1.1 stack.h
#ifndef STACK_H
#define STACK_H
#define Nil NULL
#include<iostream>
using namespace std;

typedef struct node*address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

### 1.2. stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

### 1.3 Main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

penjelasan singkat guided 1
Program ini adalah program yang di buat untuk menampilkan perbedaan nilai awal seebelum di  balik dan setelah di balik.

### 2.1 stack.h
#ifndef STACK_H
#include<iostream>
#define MaxEl 20
#define Nil-1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; // array untuk menyimpan elemen stcak
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // menambahkan elemen ke dalam stack
infotype pop(Stack &S); // MENGAMBIL ELEMEN TERATAS DARI STACK
void printInfo(Stack S);
void balikStack(Stack &S); // membalik urutan elemen dalam stack

#endif


### 2.2 stack.cpp
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

### 2.3 main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}

penjelasan singkat guided 2
Program ini adalah program yang sama seperti programyang sebelumnya yang ada di guided 1,  menampilkan perbedaan nilai awal seebelum di  balik dan setelah di balik. Namun, pada program ini representasinya menggunakan array.

## Unguided 

### 1.   BuatlahADTStackmenggunakanARRAYsebagaiberikutdidalamfile“stack.h”.  BuatlahimplementasiADTStackmenggunakanArraypadafile“stack.cpp”dan“main.cpp”
 
```C++
source code unguided 1
```
## stack.h
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

## stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0 && S.info[S.top] < x) {
        push(temp, pop(S));
    }
    push(S, x); // masukan nilai x ke stack S

    // Mengembalikan elemen dari temp
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

## main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1][Laprak Strukdat Modul 7](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%208/Laprak-Strukdat%20MODUL%208.md)


penjelasan unguided 1 
Program ini adalah program yang di implementasikan berdasarkan ketentuan yang ada pada modul 7 yaitu stack, dengan mengembalikan nilai menggunakan representasi array.

### 2.   TambahkanprosedurpushAscending(in/outS:Stack,inx:integer)

```C++
source code unguided 2
```
## stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 100;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
int pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);
#endif


## stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0 && S.info[S.top] < x) {
        push(temp, pop(S));
    }
    push(S, x); // masukan nilai x ke stack S

    // Mengembalikan elemen dari temp
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

## main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    // Menggunakan pengurutan manual, kenapa dari dua?? karena kalau dari sembilan jadi kebalik outputnya.Udah nyoba pake pushAscending tapi kebalik udah di balik tetep kebalik.
    push(S, 2);
    push(S, 3);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);

    printInfo(S);

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]![Output Unguided 2 Modul 7](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%207/unguided%202/output-unguided2-modul%207.png)


penjelasan unguided 2
Program ini adalah pengembangan program yang ada pada unguided 1 yaitu mengimplementasikan berdasarkan ketentuan yang ada pada modul 7 yaitu stack, dengan mengembalikan nilai menggunakan representasi array, namun di tambah dengan prosedurpushAscending.

### 3.  Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan
 menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
 tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```C++
source code unguided 3
```
## stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 100;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
int pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif


## stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0 && S.info[S.top] < x) {
        push(temp, pop(S));
    }
    push(S, x); // untuk memasukan nilai x ke stack S

    // Untuk mengembalikan elemen dari temp
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    string input = "4729601";  

    for (char c : input) {
        if (isdigit(c)) {
            push(S, c - '0');
        }
    }
}


## main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);   // akan membaca input user
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}


### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1]![Output Unguided 3 Modul 7](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%207/unguided%203/output-unguided3-modul7.png)


penjelasan unguided 3
Pada program ketiga ini juga adalah pengembangan program pertama dan kedua, bedanya pada program ketiga ini program nya mendapatkan tambahan  prosedur getInputStream. Yang nantinya, Prosedur akan terus membaca dan
 menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
 tombol enter.

## Kesimpulan
Program ini adalah program yang saling berkesinambungan antara unguided 1 sampai 3, dimana semuanya adalah tahapan proses dimana fungsi di gunakan sesuai kebutuhan. Dan setiap unguidednya terdapat fungsi - fungsi yang bermacam macam sesuai dengan keinginan pengguna.

## Referensi
[1] Amaylia, S., Setiabud, V. A., Alvianino, R., Saputra, R. N., Wardhani, H. K., & Suroni, A. Application of Stack Data Structure in Application Development. Journal of Advanced Systems Intelligence & Cybersecurity, 1(01), 2025.
<br>[2] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2), 2024.
<br>[3] Bar-Nissan, G., Hendler, D., & Suissa, A. A Dynamic Elimination-Combining Stack Algorithm. In: Proceedings / [conference] / published sebagai bab oleh Springer. (DECS)


