# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINGKED LIST </h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

### 1. Pengertian MULTI LINGKED LIST

Multi-linked list adalah variasi dari linked list di mana setiap node dapat memiliki lebih dari satu pointer sehingga node tersebut dapat terhubung secara simultan dalam lebih dari satu urutan atau daftar. Dengan kata lain:

Node memiliki multiple pointers yang menunjuk ke node lain pada struktur berbeda.

Struktur ini dapat merepresentasikan beberapa urutan atau hubungan langsung dalam satu struktur data (contoh: urutan berdasarkan nama, umur, atau relasi lain) tanpa harus menggandakan data.

### 2. Komponen Struktur
Sebuah multi-linked list secara umum terdiri dari:

- Data field
Data yang disimpan di node.

- Multiple link fields / pointers
Lebih dari satu pointer dalam satu node, yang menunjuk ke node lain berdasarkan relasi tertentu (mis. next1, next2, … nextN).

### 3. Karakteristik
Dinamis,	Ukuran dapat berubah tanpa memori kontigu.

Multi urutan,	Setiap node bisa berada dalam lebih dari satu urutan relasi. 

Fleksibel,	Dapat digunakan untuk mewakili struktur kompleks, seperti sparse matrix, list of list, atau multiple sort orders. 

Operasi kompleks	Penambahan atau penghapusan node harus memperbarui beberapa pointer. (implisit dari struktur linked list)

### 4. Contoh aplikasi
Beberapa aplikasi umum dari multi-linked list antara lain:

-Representasi list of lists atau struktur dua dimensi — misal daftar daftar, di mana suatu node bisa terhubung ke daftar lain secara vertikal dan horizontal. 

- Representasi sparse matrix — setiap node bisa dikaitkan berdasarkan baris dan kolom secara bersamaan. 

- Multi urutan berdasarkan kriteria berbeda — misal daftar pelanggan berdasarkan nama dan umur dalam satu struktur tanpa replikasi data.

### 5. Operasi pada Multi-Linked List
Create / Inisialisasi
Membuat struktur list awal dan mengatur pointer ke NULL.

Insert
Menambahkan node baru dan menghubungkannya ke beberapa list atau relasi sekaligus.

Delete
Menghapus node dengan memperhatikan seluruh pointer yang terhubung agar tidak terjadi dangling pointer.

Traversal
Menelusuri data berdasarkan pointer tertentu (misalnya traversal induk saja, atau traversal anak).

Searching
Mencari node berdasarkan kriteria tertentu melalui jalur pointer yang sesuai.

## Guided 

### 1.Multilist.h
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

// ==== TYPEDEF POINTER ====
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

// ==== STRUCT CHILD ====
struct nodeChild {
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

// ==== STRUCT PARENT ====
struct nodeParent {
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

// ==== CREATE LIST ====
void createListInduk(listInduk &Induk);
void createListAnak(listAnak &Anak);

// ==== ALOKASI & DEALOKASI PARENT ====
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

// ==== ALOKASI & DEALOKASI CHILD ====
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

// ==== OPERASI PADA PARENT ====
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void hapusListAnak(listAnak &Anak);

// ==== OPERASI PADA CHILD ====
void insertLastChild(listAnak &Anak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &Anak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);


// ==== OPERASI PRINT ====
void printStrukturMLL(listInduk &LInduk);

#endif


### Multilistcpp
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

### Main.cpp
#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    //Inisialisasi list
    listInduk LInduk;
    createListInduk(LInduk);

    //Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);

    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);

    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //Memasukan Data Child (Menu Makanan) ke kategori tertentu

    //-> Isi Kategori Makanan Berat
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);

    // -> Isi Kategori Minuman
    NodeChild D02 = alokasiNodeChild("N02", "Just Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01); 

    cout << endl;

    // -> Print MLL setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    // -> Searching node child
    findChildByID(LInduk, "D01");
    cout << endl;

    // -> Delete node child
    deleteAfterChild(K01 -> L_Anak, M01);
    cout << endl;

    // -> Delete node parent
    deleteAfterParent(LInduk, K02);
    cout << endl;

    // -> print mll setelah delete-delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}

penjelasan singkat guided 1
Program ini adalah program yang mengimplementasikan struktur Multi Lingked

## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”. Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”. Kemudian pada file “main.cpp”  lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya seperti ini : 


```C++
source code unguided 1
```

## MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;       
    float bobot;     
};
struct nodeParent;
struct nodeChild;

typedef nodeParent* NodeParent;
typedef nodeChild* NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent {
    NodeParent first;
    NodeParent last;
};

// Mengecek list kosong 
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

// Create List 
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

// Alokasi Node 
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

// Dealokasi 
void deallocNodeParent(NodeParent NParent);
void deallocNodeChild(NodeChild NChild);

// Insert Parent 
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void deleteLastParent(listParent &LParent);

// Insert Child 
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteLastChild(listChild &LChild);

// Print Struktur Multi Linked List 
void printMLLStructure(listParent LParent);

// Delete List Child (kosongkan semua child) 
void deleteListChild(listChild &LChild);

#endif

## MultiLL.cpp
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
        }
        delete P;
    }
}

void deleteLastParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.last;
        if (LParent.first == LParent.last) {
            deleteFirstParent(LParent);
        } else {
            LParent.last = P->prev;
            LParent.last->next = NULL;
            delete P;
        }
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;

        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;

        delete P;
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild P = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = P->next;
            LChild.first->prev = NULL;
        }
        delete P;
    }
}

void deleteLastChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild P = LChild.last;
        if (LChild.first == LChild.last) {
            deleteFirstChild(LChild);
        } else {
            LChild.last = P->prev;
            LChild.last->next = NULL;
            delete P;
        }
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild P = NPrev->next;
        NPrev->next = P->next;

        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LChild.last = NPrev;

        delete P;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent kosong.\n";
        return;
    }

    NodeParent P = LParent.first;
    int parentNum = 1;

    while (P != NULL) {
        cout << "=== Parent " << parentNum << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int childNum = 1;
            while (C != NULL) {
                cout << "  - Child " << childNum << " :\n";
                cout << "     ID Hewan : " << C->isidata.idHewan << endl;
                cout << "     Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "     Habitat : " << C->isidata.habitat << endl;
                cout << "     Ekor : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "     Bobot : " << C->isidata.bobot << endl;

                C = C->next;
                childNum++;
            }
        }

        cout << "  " << endl;

        P = P->next;
        parentNum++;
    }
}



## main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    NodeChild C001_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C001_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);

    insertLastChild(P1->L_Child, C001_1);
    insertLastChild(P1->L_Child, C001_2);

    NodeChild C002_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    NodeChild C002_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    NodeChild C002_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);

    insertLastChild(P2->L_Child, C002_1);
    insertLastChild(P2->L_Child, C002_2);
    insertLastChild(P2->L_Child, C002_3);

    NodeChild C004_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C004_1);

    printMLLStructure(LP);

    return 0;
}


### Output Unguided 1 :

##### Output 1
Output 1
![Output Unguided 1 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%201/output%20unguided1%20MODUL%2013.png)

##### Output 2
Output 2
![Output Unguided 1.1 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%201/output%20unguided1.1%20MODUL%2013.png)

penjelasan unguided 1 
Program ini mengimplementasikan struktur data multi-linked list bertipe induk–anak, di mana parent merepresentasikan golongan hewan dan child merepresentasikan data hewan yang termasuk dalam golongan tersebut. Setiap node parent disusun dalam doubly linked list dan memiliki satu linked list child sendiri, sehingga satu golongan dapat menampung banyak hewan tanpa duplikasi data. File MultiLL.h berisi definisi struktur dan deklarasi fungsi, MultiLL.cpp mengimplementasikan operasi dasar seperti inisialisasi, alokasi, penyisipan, penghapusan, dan penelusuran data, sedangkan main.cpp digunakan untuk menguji program dengan menambahkan beberapa golongan dan hewan, lalu menampilkan hubungan parent–child menggunakan fungsi printMLLStructure.

### 2.  Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. 

```C++
source code unguided 2
```
## MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;       
    float bobot;     
};
struct nodeParent;
struct nodeChild;

typedef nodeParent* NodeParent;
typedef nodeChild* NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent {
    NodeParent first;
    NodeParent last;
};

// Mengecek list kosong 
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

// Create List 
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

// Alokasi Node 
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

// Dealokasi 
void deallocNodeParent(NodeParent NParent);
void deallocNodeChild(NodeChild NChild);

// Insert Parent 
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void deleteLastParent(listParent &LParent);

// Insert Child 
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteLastChild(listChild &LChild);

// Print Struktur Multi Linked List 
void printMLLStructure(listParent LParent);

// Delete List Child (kosongkan semua child) 
void deleteListChild(listChild &LChild);

void searchHewanByEkor(listParent LParent, bool tail);
#endif


## MultiLL.cpp
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
        }
        delete P;
    }
}

void deleteLastParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.last;
        if (LParent.first == LParent.last) {
            deleteFirstParent(LParent);
        } else {
            LParent.last = P->prev;
            LParent.last->next = NULL;
            delete P;
        }
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;

        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;

        delete P;
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild P = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = P->next;
            LChild.first->prev = NULL;
        }
        delete P;
    }
}

void deleteLastChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild P = LChild.last;
        if (LChild.first == LChild.last) {
            deleteFirstChild(LChild);
        } else {
            LChild.last = P->prev;
            LChild.last->next = NULL;
            delete P;
        }
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild P = NPrev->next;
        NPrev->next = P->next;

        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LChild.last = NPrev;

        delete P;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent kosong.\n";
        return;
    }

    NodeParent P = LParent.first;
    int parentNum = 1;

    while (P != NULL) {
        cout << "=== Parent " << parentNum << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int childNum = 1;
            while (C != NULL) {
                cout << "  - Child " << childNum << " :\n";
                cout << "     ID Hewan : " << C->isidata.idHewan << endl;
                cout << "     Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "     Habitat : " << C->isidata.habitat << endl;
                cout << "     Ekor : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "     Bobot : " << C->isidata.bobot << endl;

                C = C->next;
                childNum++;
            }
        }

        cout << "------------------------------\n";

        P = P->next;
        parentNum++;
    }
}
// search hewan by ekor
void searchHewanByEkor(listParent LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong.\n";
        return;
    }

    NodeParent P = LParent.first;
    int parentPos = 1;
    bool found = false;

    // Telusuri tiap parent
    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int childPos = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                found = true;

                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << childPos << "!\n";

                // --- Data Child ---
                cout << "--- Data Child ---\n";
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "------------------------------\n";

                // --- Data Parent ---
                cout << "--- Data Parent ---\n";
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "------------------------------\n";
            }

            C = C->next;
            childPos++;
        }

        P = P->next;
        parentPos++;
    }

    if (!found) {
        cout << "Tidak ditemukan hewan dengan ekor = "
             << (tail ? "TRUE" : "FALSE") << endl;
    }
}



## main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));


    cout << "===== STRUKTUR MULTI LINKED LIST =====\n";
    printMLLStructure(LP);

    cout << "\n===== SEARCH HEWAN DENGAN EKOR FALSE =====\n";
    searchHewanByEkor(LP, false);

    return 0;
}


### Output Unguided 2 :

##### Output 

![Output Unguided 2 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%202/output%20unguided2%20MODUL%2013.png)

penjelasan unguided 2
Program ini merupakan implementasi multi-linked list induk–anak menggunakan doubly linked list, di mana node parent menyimpan data golongan hewan dan setiap parent memiliki list child yang berisi data hewan dalam golongan tersebut. Program menyediakan operasi lengkap seperti pembuatan list, alokasi dan dealokasi node, penambahan dan penghapusan node parent maupun child, serta penelusuran struktur data. Selain menampilkan seluruh isi multi-linked list melalui fungsi printMLLStructure, kode ini juga menambahkan fitur pencarian searchHewanByEkor yang menelusuri seluruh node child pada setiap parent untuk menemukan hewan berdasarkan atribut ekor (true/false) dan menampilkan informasi lengkap baik dari sisi child maupun parent, sehingga memperlihatkan relasi hierarkis antar data secara jelas.

### 3.Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini : 

```C++
source code unguided 3
```
## MultiLL.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct Hewan {
    string idHewan;
    string namaHewan;
    string habitat;
    int ekor;
    double bobot;
    Hewan* next; 
};

struct Golongan {
    string idGolongan;
    string namaGolongan;
    Golongan* prev; 
    Golongan* next;
    Hewan* firstChild; 
};

struct MultiLL {
    Golongan* firstParent;
    Golongan* lastParent;
};

// Inisialisasi
void createList(MultiLL &L);

// Tambah Parent
void createParent(string id, string nama, Golongan* &newParent);
void insertParentLast(MultiLL &L, Golongan* newParent);

// Tambah Child
void createChild(string id, string nama, string habitat, int ekor, double bobot, Hewan* &newChild);
bool insertChildFirst(MultiLL &L, string parentId, Hewan* newChild);

// Cari Node
Golongan* findParent(MultiLL L, string id);
Hewan* findChild(Golongan* P, string id);

// Hapus Node
void deleteChild(Golongan* &P, string childId);
bool deleteParent(MultiLL &L, string parentId);

void printMLLStructure(MultiLL L);

#endif 

## MultiLL.cpp
#include "MultiLL.h"

void createList(MultiLL &L) {
    L.firstParent = nullptr;
    L.lastParent = nullptr;
}

void createParent(string id, string nama, Golongan* &newParent) {
    newParent = new Golongan;
    newParent->idGolongan = id;
    newParent->namaGolongan = nama;
    newParent->prev = nullptr;
    newParent->next = nullptr;
    newParent->firstChild = nullptr;
}

void insertParentLast(MultiLL &L, Golongan* newParent) {
    if (L.firstParent == nullptr) {
        L.firstParent = newParent;
        L.lastParent = newParent;
    } else {
        L.lastParent->next = newParent;
        newParent->prev = L.lastParent;
        L.lastParent = newParent;
    }
}

Golongan* findParent(MultiLL L, string id) {
    Golongan* P = L.firstParent;
    while (P != nullptr) {
        if (P->idGolongan == id) {
            return P;
        }
        P = P->next;
    }
    return nullptr; 
}

// Implementasi Penghapusan Parent
bool deleteParent(MultiLL &L, string parentId) {
    Golongan* P = findParent(L, parentId);
    if (P == nullptr) {
        cout << "Gagal: Parent dengan ID " << parentId << " tidak ditemukan." << endl;
        return false;
    }

    // Hapus semua child dari parent ini
    cout << "Menghapus semua child dari Parent " << parentId << "..." << endl;
    Hewan* currentChild = P->firstChild;
    while (currentChild != nullptr) {
        Hewan* temp = currentChild;
        currentChild = currentChild->next;
        delete temp;
    }
    P->firstChild = nullptr; 

    // Hapus Parent dari list utama 
    if (P == L.firstParent && P == L.lastParent) {
        // Kasus 1: Hanya ada 1 node
        L.firstParent = nullptr;
        L.lastParent = nullptr;
    } else if (P == L.firstParent) {
        // Kasus 2: Node pertama
        L.firstParent = P->next;
        if (L.firstParent != nullptr) {
            L.firstParent->prev = nullptr;
        }
    } else if (P == L.lastParent) {
        // Kasus 3: Node terakhir
        L.lastParent = P->prev;
        if (L.lastParent != nullptr) {
            L.lastParent->next = nullptr;
        }
    } else {
        // Kasus 4: Node di tengah
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
    cout << "Sukses: Parent " << parentId << " dan semua child-nya telah dihapus." << endl;
    return true;
}

// Operasi Child (Hewan) 

void createChild(string id, string nama, string habitat, int ekor, double bobot, Hewan* &newChild) {
    newChild = new Hewan;
    newChild->idHewan = id;
    newChild->namaHewan = nama;
    newChild->habitat = habitat;
    newChild->ekor = ekor;
    newChild->bobot = bobot;
    newChild->next = nullptr;
}

bool insertChildFirst(MultiLL &L, string parentId, Hewan* newChild) {
    Golongan* P = findParent(L, parentId);
    if (P == nullptr) {
        cout << "Gagal: Parent dengan ID " << parentId << " tidak ditemukan." << endl;
        return false;
    }
    
    newChild->next = P->firstChild;
    P->firstChild = newChild;
    return true;
}

Hewan* findChild(Golongan* P, string id) {
    if (P == nullptr) return nullptr;
    
    Hewan* C = P->firstChild;
    while (C != nullptr) {
        if (C->idHewan == id) {
            return C;
        }
        C = C->next;
    }
    return nullptr; 
}

// Implementasi Penghapusan Child 
void deleteChild(Golongan* &P, string childId) {
    if (P == nullptr || P->firstChild == nullptr) {
        cout << "Tidak ada child untuk dihapus atau Parent tidak ditemukan." << endl;
        return;
    }
    
    Hewan* current = P->firstChild;
    Hewan* prev = nullptr;
    
    while (current != nullptr && current->idHewan != childId) {
        prev = current;
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "Child dengan ID " << childId << " tidak ditemukan." << endl;
        return;
    }
    
    // Hapus node current
    if (prev == nullptr) {
        // Kasus 1: Node pertama
        P->firstChild = current->next;
    } else {
        // Kasus 2: Node di tengah/akhir
        prev->next = current->next;
    }
    
    delete current;
    cout << "Child " << childId << " berhasil dihapus." << endl;
}

void printMLLStructure(MultiLL L) {
    cout << "\n=== Print MLL Structure ===" << endl;
    Golongan* P = L.firstParent;
    int parentCount = 1;
    
    if (P == nullptr) {
        cout << "(List Parent Kosong)" << endl;
    }

    while (P != nullptr) {
        cout << "\n--- Parent " << parentCount++ << " ---" << endl;
        cout << "ID Golongan : " << P->idGolongan << endl;
        cout << "Nama Golongan : " << P->namaGolongan << endl;
        
        Hewan* C = P->firstChild;
        int childCount = 1;
        
        if (C == nullptr) {
            cout << "(tidak ada child)" << endl;
        } else {
            while (C != nullptr) {
                cout << "- Child " << childCount++ << " -" << endl;
                cout << "  ID Hewan  : " << C->idHewan << endl;
                cout << "  Nama Hewan: " << C->namaHewan << endl;
                cout << "  Habitat   : " << C->habitat << endl;
                cout << "  Ekor      : " << C->ekor << endl;
                cout << "  Bobot     : " << C->bobot << endl;
                C = C->next;
            }
        }
        P = P->next;
    }
    cout << "  " << endl;
}
## main.cpp
#include "MultiLL.h"
#include <iomanip>

int main() {
    cout << fixed << setprecision(1);

    MultiLL L;
    createList(L);
    cout << "Multi Linked List berhasil diinisialisasi." << endl;

    cout << "\n--- Setup Data Awal ---" << endl;

    Golongan* P1;
    createParent("G001", "Aves", P1);
    insertParentLast(L, P1);
    Hewan *C1_1, *C1_2;
    createChild("AV001", "Cenderawasih", "Hutan", 1, 0.3, C1_1);
    insertChildFirst(L, "G001", C1_1);
    createChild("AV002", "Bebek", "Air", 1, 2.0, C1_2);

    insertChildFirst(L, "G001", C1_2); 

    Golongan* P2;
    createParent("G002", "Mamalia", P2);
    insertParentLast(L, P2);
    Hewan *C2_1, *C2_2, *C2_3;
    createChild("M001", "Harimau", "Hutan", 1, 200.0, C2_1);
    insertChildFirst(L, "G002", C2_1);
    createChild("M003", "Gorilla", "Hutan", 1, 160.0, C2_2);
    insertChildFirst(L, "G002", C2_2); 
    createChild("M002", "Kucing", "Darat", 1, 5.0, C2_3);
    insertChildFirst(L, "G002", C2_3); 

    Golongan* P3;
    createParent("G003", "Pisces", P3);
    insertParentLast(L, P3);

    Golongan* P4;
    createParent("G004", "Amfibi", P4);
    insertParentLast(L, P4);
    Hewan *C4_1;
    createChild("A001", "Katak", "Air", 4, 0.1, C4_1);
    insertChildFirst(L, "G004", C4_1);

    Golongan* P5;
    createParent("G005", "Reptil", P5);
    insertParentLast(L, P5);

    cout << "Data awal berhasil dibuat." << endl;
    
    cout << " === " << endl;
    cout << ">>> OPERASI DELETE: Menghapus Parent G004 <<<" << endl;
    cout << "===" << endl;
    deleteParent(L, "G004");

    cout << " ==== " << endl;
    cout << ">>> HASIL PRINT SETELAH PENGHAPUSAN G004 <<<" << endl;
    cout << "  " << endl;
    printMLLStructure(L);

    return 0;
}

### Output Unguided 3 :

##### Output 
Output 3
![Output Unguided 3 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%203/output%20unguided3%20MODUL%2013.png)




penjelasan unguided 3
Program ini merupakan implementasi multi-linked list induk–anak yang memodelkan hubungan antara golongan hewan (parent) dan hewan (child), di mana parent disusun dalam doubly linked list dan setiap parent memiliki singly linked list child. Struktur MultiLL menyimpan pointer ke parent pertama dan terakhir, sedangkan setiap Golongan menyimpan data golongan serta pointer ke daftar hewan (firstChild). Program menyediakan operasi inisialisasi, penambahan parent dan child, pencarian node, penghapusan child, serta penghapusan parent beserta seluruh child-nya secara aman untuk mencegah kebocoran memori. Fungsi printMLLStructure digunakan untuk menampilkan seluruh struktur hierarkis, sementara main.cpp berfungsi sebagai pengujian dengan membuat data awal, melakukan operasi delete pada salah satu parent, dan menampilkan hasil akhir struktur multi-linked list.

## Kesimpulan
Multi-linked list adalah struktur data dinamis yang memungkinkan satu node memiliki lebih dari satu pointer untuk merepresentasikan banyak relasi. Struktur ini sangat cocok untuk data kompleks yang memiliki hubungan induk-anak, banyak urutan, atau representasi dua dimensi. Meskipun memiliki tingkat kompleksitas implementasi yang lebih tinggi, multi-linked list memberikan fleksibilitas dan efisiensi yang tidak dimiliki oleh linked list konvensional.

## Referensi
[1] S. Kumar et al., Word Search Puzzle using Multi-Linked Lists,
International Journal of Engineering and Advanced Technology (IJEAT), Vol. 8, Issue 4S2, 2019.
[2] R. D. Kalyani, Multi Linked Lists: An Object Oriented Approach,
International Journal of Computer Science and Engineering, 2018.
[3] Sahni, S. – Data Structures, Algorithms, and Applications in C++, McGraw-Hill.
[4] IEEE Xplore Digital Library – Topik: Multi-linked data structures


