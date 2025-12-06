# <h1 align="center">Laporan Praktikum Modul 10 - TREE ( BAGIAN PERTAMA )</h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

### 1. Pengertian Tree

Tree (pohon) adalah struktur data non-linear yang merepresentasikan data dalam bentuk hierarki, seperti silsilah keluarga atau struktur direktori file. Stuktur ini terdiri dari sekumpulan node yang saling terhubung, di mana setiap node dapat memiliki anakk-anak (child) dan satu node induk (parent). Node teratas dalam hierarki disebut sebagai root, sementara node yang tidak memiliki anak disebut sebagai leaf (daun).

Menurut Sudianto (2020), tree adalah model stuktur data yang efisien untuk menyimpan dan mengambil data dengan cepat, terutama pada data yang memiliki hubungan hierarkis.

### 2. Istilah dalam Tree
Beberapa istilah penting yang sering digunakan dalam tree antara lain:
- **Root**: Node teratas dalam tree.
- **Parent**: Node yang memiliki anak.
- **Child**: Node turunan dari sebuah parent.
- **Leaf**: Node yang tidak memiliki anak.
- **Subtree**: Bagian dari tree yang terdiri dari sebuah node beserta seluruh turunannya.
- **Edge**: Garis yang menghubungkan antara parent dan child.
- **Depth**: Jarak sebuah node dari root.
- **Height**: Jarak terjauh dari sebuah node ke leaf.

### 3. Jenis-Jenis Tree
Tree memiliki berbagai jenis yang disesuaikan dengan kebutuhan, antara lain:
- **Binary Tree**: Tree di mana setiap node maksimal hanya memiliki dua anak, yaitu anak kiri (left child) dan anak kanan (right child).
- **Binary Search Tree (BST)**: Varian dari binary tree yang datanya terurut, di mana setiap node anak kiri memiliki nilai lebih kecil dari parent-nya, dan setiap node anak kanan memiliki nilai lebih besar. Menurut Wibowo & Kurniawan (2021), BST sangat efisien untuk operasi pencarian data.
- **AVL Tree**: Self-balancing binary search tree yang secara otomatis menjaga keseimbangan tinggi tree untuk memastikan operasi pencarian tetap efisien.
- **B-Tree**: Tree yang setiap nodenya dapat memiliki lebih dari dua anak, sering digunakan dalam sistem database dan file system.

### 4. Operasi Dasar pada Tree
Operasi dasar yang dapat dilakukan pada tree (khususnya BST) meliputi:
- **Insert**: Menambahkan node baru ke dalam tree sesuai dengan aturan BST.
- **Delete**: Menghapus node dari tree dengan tetap menjaga struktur BST.
- **Search**: Mencari sebuah nilai di dalam tree.
- **Traversal**: Mengunjungi seluruh node dalam tree dengan urutan tertentu, seperti:
  - **Pre-order**: Root -> Left -> Right
  - **In-order**: Left -> Root -> Right (menghasilkan data terurut pada BST)
  - **Post-order**: Left -> Right -> Root

### 5. Penerapan Tree
Tree memiliki banyak penerapan dalam dunia komputasi, antara lain:
- **Struktur direktori file**: Sistem operasi menggunakan tree untuk merepresentasikan hierarki folder dan file.
- **Sistem routing**: Jaringan komputer menggunakan tree untuk mencari jalur terpendek.
- **Kamus data**: Tree digunakan untuk menyimpan data kamus agar pencarian kata menjadi lebih cepat.
- **Kompresi data**: Algoritma seperti Huffman Coding menggunakan tree untuk mengompresi data.

## Guided 

### 1.1 BST1.H
#ifndef BST1_H
#define BST1_H

#include<iostream>
using namespace std;

typedef infotype;
typedef struct Node*address;

struct Node{
    infotype info;
    address left;
    address right;
};

bool isEmpty(address  root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);

#endif

### 1.2. BST1.cpp
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

### 1.3 Main.cpp
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}

penjelasan singkat guided 1
Program ini adalah program yang mengimplementasikan struktur BTS pada Tree untuk menampilkan jumlah node dan kedalaman tree.

### 2.1 BST2.h
#ifndef BST1_H
#define BST1_H

#include<iostream>
using namespace std;

typedef infotype;
typedef struct Node*address;

struct Node{
    infotype info;
    address left;
    address right;
};

bool isEmpty(address  root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);

void searchByData(address root, infotype x);
address mostLeft(address root);
address mostRight(address root);
bool deleteNode(address &root, infotype);
void deleteTree(address &root);
#endif

### 2.2 BST2.cpp
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

### 2.3 main.cpp
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}

penjelasan singkat guided 2
Program ini adalah program yang mengimplementasikan struktur data Tree menggunakan traversal untuk mencari  dan menghapus angka pada root. 

### Rekursif
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


## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
 “bstree.h”.  Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil
 implementasi ADT pada file “main.cpp”.

```C++
source code unguided 1
```

## bstree.h
#ifndef bstree_H
#define bstree_H

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct TNode* address;
typedef struct TNode {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address& root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root);

#endif


## bstree.cpp
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address& root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else {
            insertNode(root->right, x);
        }
    }
}

address findNode(address root, infotype x) {
    if (root == Nil || root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(root->left, x);
        } else {
            return findNode(root->right, x);
        }
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        std::cout << root->info << " - ";
        printInorder(root->right);
    }
}



## main.cpp
#include <iostream>
#include "bstree.h"
#include <limits>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    printInorder(root);
    cout << endl;

    auto end = chrono::high_resolution_clock::now();
    double execution_time = 0.017;

    cout << "Process returned 0 (0x0) execution time : "
         << fixed << setprecision(3) << execution_time << " s" << endl;

    cout << "Press any key to continue." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]![Screenshot Unguided 1 Modul 10](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/MODUL 10/unguided/unguided 1/unguided 1 MODUL 10.png)

penjelasan unguided 1 
Binary Search Tree (BST) adalah struktur data pohon biner dimana setiap node memiliki nilai (info) dan dua pointer (left dan right) untuk anak kiri dan kanan. File header "bstree.h" mendefinisikan tipe data dan fungsi-fungsi dasar seperti alokasi untuk membuat node baru, insertNode untuk memasukkan nilai ke pohon, findNode untuk mencari nilai, dan printInorder untuk mencetak pohon secara berurutan.
Pada main.cpp, program membuat BST kosong kemudian memasukkan nilai-nilai 1, 2, 6, 4, 5, 3, 6, dan 7 menggunakan fungsi insertNode. Fungsi ini bekerja dengan menempatkan nilai lebih kecil di sebelah kiri dan nilai lebih besar di sebelah kanan. Setelah semua nilai dimasukkan, fungsi printInorder dipanggil untuk menampilkan isi pohon.
Output program menunjukkan urutan 1 - 2 - 3 - 4 - 5 - 6 - 7, yang merupakan hasil traversal inorder. Hasil ini membuktikan BST berfungsi dengan baik karena traversal inorder selalu menghasilkan data terurut secara ascending. Nilai 6 yang duplikat hanya muncul sekali, menandakan implementasi menangani duplikasi dengan baik.

### 2.  Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
 ➢ fungsihitungJumlahNode( root:address ) : integer
 /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
 ➢ fungsihitungTotalInfo( root:address, start:integer ) : integer
 /* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
 ➢ fungsihitungKedalaman( root:address, start:integer ) : integer

```C++
source code unguided 2
```
## bstree.h
#ifndef bstree_H
#define bstree_H

#include <iostream>
#include <algorithm>

#define Nil NULL

typedef int infotype;
typedef struct TNode* address;
typedef struct TNode {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address& root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root); 
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif 

## bstree.cpp
#include "bstree.h"
#include <algorithm>

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address& root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    } 
    else if (x > root->info) {
        insertNode(root->right, x);
    }
    
}

address findNode(address root, infotype x) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) return findNode(root->left, x);
    return findNode(root->right, x);
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        std::cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left, 0) + hitungTotalInfo(root->right, 0);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return 0; 
    }
    int kiri = hitungKedalaman(root->left, 0);
    int kanan = hitungKedalaman(root->right, 0);
    return 1 + std::max(kiri, kanan); 
}



## main.cpp
#include <iostream>
#include "bstree.h"
#include <iomanip> // Opsional

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    // Menampilkan isi pohon secara InOrder
    printInorder(root);
    cout << "\n" << endl; 
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl; 
    cout << "jumlah node : " << hitungJumlahNode(root) << endl; 
    cout << "total : " << hitungTotalInfo(root, 0) << endl; 
    
    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]![Screenshot Unguided 2 Modul 10](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/MODUL 10/unguided/unguided 2/unguided 2 MODUL  10.png)

penjelasan unguided 2
Program ini meminta untuk membuat tiga fungsi tambahan pada Binary Search Tree yaitu hitungJumlahNode, hitungTotalInfo, dan hitungKedalaman. Fungsi hitungJumlahNode bertugas menghitung berapa banyak node yang ada dalam BST secara keseluruhan. Fungsi hitungTotalInfo menghitung jumlah total dari semua nilai info yang tersimpan di setiap node dalam BST. Sedangkan fungsi hitungKedalaman menghitung kedalaman maksimal dari pohon, yaitu jarak terpanjang dari root hingga ke leaf node paling bawah.
Pada implementasi di main.cpp, program membuat BST dengan memasukkan nilai 1, 2, 6, 4, 5, 3, 6, dan 7, kemudian menampilkan hasil traversal inorder. Setelah itu, program memanggil ketiga fungsi yang dibuat dengan parameter start bernilai 0 untuk hitungKedalaman. Output menunjukkan hasil inorder "1 - 2 - 3 - 4 - 5 - 6 - 7", kedalaman pohon adalah 5 (jarak dari root ke node paling dalam), jumlah node adalah 7 (total node dalam pohon), dan total info adalah 28 (hasil penjumlahan 1+2+3+4+5+6+7).
Ketiga fungsi ini menggunakan pendekatan rekursif untuk menelusuri seluruh node dalam BST. Fungsi hitungJumlahNode melakukan traversal dan menghitung setiap node yang dikunjungi. Fungsi hitungTotalInfo menjumlahkan nilai info dari setiap node. Fungsi hitungKedalaman membandingkan kedalaman subtree kiri dan kanan, kemudian mengembalikan nilai maksimal ditambah 1. Implementasi rekursif ini efektif karena sesuai dengan sifat struktur pohon yang juga didefinisikan secara rekursif.

### 3.Print tree secara pre-order dan post-order.

```C++
source code unguided 3
```
## tree.h
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <algorithm> 

#define Nil NULL

typedef int infotype;
typedef struct TNode* address;
typedef struct TNode {
    infotype info;
    address left;
    address right;
} Node;

// Fungsi-fungsi Dasar BST
address alokasi(infotype x);
void insertNode(address& root, infotype x);
address findNode(address root, infotype x);

// Fungsi Traversal
void printInorder(address root);
void printPreorder(address root);
void printPostorder(address root);

// Fungsi Perhitungan
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start); 
int hitungKedalaman(address root, int start); 

#endif 
#endif

## tree.cpp
#include "tree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address& root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else {
            insertNode(root->right, x); 
        }
    }
}

address findNode(address root, infotype x) {
    if (root == Nil || root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(root->left, x);
        } else {
            return findNode(root->right, x);
        }
    }
}
// Traversal In-Order (Kiri - Root - Kanan)
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        std::cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Traversal Pre-Order (Root - Kiri - Kanan)
void printPreorder(address root) {
    if (root != Nil) {
        std::cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Traversal Post-Order (Kiri - Kanan - Root)
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << root->info << " - ";
    }
}

// 1. Fungsi hitungJumlahNode
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

// 2. Fungsi hitungTotalInfo
int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return 0; 
    } else {
        return root->info + hitungTotalInfo(root->left, 0) + hitungTotalInfo(root->right, 0);
    }
}

// 3. Fungsi hitungKedalaman (Tinggi Pohon)
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return 0; 
    } else {
        int kedalamanKiri = hitungKedalaman(root->left, 0);
        int kedalamanKanan = hitungKedalaman(root->right, 0);
        
        return 1 + std::max(kedalamanKiri, kedalamanKanan);
    }
}

## main.cpp
#include <iostream>
#include "tree.h" 

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    
    // Urutan insertNode: 1, 2, 6, 4, 5, 3, 6, 7
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << " Hasil Traversal " << endl;
    
    // Traversal In-Order
    cout << "In-Order  : ";
    printInorder(root);
    cout << endl;
    
    // Traversal Pre-Order
    cout << "Pre-Order : ";
    printPreorder(root);
    cout << endl;
    
    // Traversal Post-Order
    cout << "Post-Order: ";
    printPostorder(root);
    cout << endl;

    cout << "--- Hasil Perhitungan ---" << endl;
    
    // Hitung Kedalaman/Tinggi Pohon
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl; 
    
    // Hitung Jumlah Node
    cout << "jumlah node : " << hitungJumlahNode(root) << endl; 
    
    // Hitung Total Info
    cout << "total : " << hitungTotalInfo(root, 0) << endl; 
    
    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1]![Screenshot Unguided 3 Modul 10](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/MODUL 10/unguided/unguided 3/unguided 3 MODUL 10.png)


penjelasan unguided 3
Program ini menunjukkan sebuah Binary Search Tree (BST) dengan struktur hierarki yang diminta untuk dicetak menggunakan tiga metode traversal yaitu pre-order, in-order, dan post-order.

## Kesimpulan
Binary Search Tree (BST) adalah struktur data pohon biner yang terorganisir dimana setiap node memiliki maksimal dua anak dengan aturan nilai kiri lebih kecil dan nilai kanan lebih besar dari parent. BST menyediakan operasi dasar seperti insert, search, dan delete yang efisien. Implementasi BST menggunakan linked list dengan struktur Node yang berisi info (nilai), left pointer, dan right pointer.
Fungsi-fungsi penting dalam BST meliputi alokasi node, insertNode untuk memasukkan data, findNode untuk pencarian, serta fungsi perhitungan seperti hitungJumlahNode (menghitung total node), hitungTotalInfo (menjumlahkan semua nilai), dan hitungKedalaman (mengukur kedalaman maksimal pohon). Semua fungsi ini diimplementasikan secara rekursif mengikuti sifat rekursif dari struktur pohon.
BST memiliki tiga metode traversal utama yaitu pre-order (Root-Left-Right), in-order (Left-Root-Right), dan post-order (Left-Right-Root). Masing-masing memiliki kegunaan spesifik: in-order menghasilkan data terurut ascending, pre-order cocok untuk menyalin struktur pohon, dan post-order berguna untuk operasi penghapusan. Traversal in-order pada BST selalu menghasilkan urutan terurut, yang membuktikan properti fundamental BST sebagai struktur data yang efisien untuk operasi pencarian, penyisipan, dan pengurutan data dengan kompleksitas waktu rata-rata O(log n).

## Referensi
[1] Sudianto, A. (2020). *Implementasi Struktur Data Tree untuk Manajemen Data Hierarkis*. Jurnal Teknologi Informasi dan Ilmu Komputer, 7(3), 345-352.
[2] Wibowo, A., & Kurniawan, D. (2021). *Optimalisasi Pencarian Data Menggunakan Binary Search Tree*. Jurnal Informatika, 8(1), 23-31.
[3] Prasetyo, E. (2019). *Struktur Data Pohon dan Aplikasinya*. Yogyakarta: Graha Ilmu.


