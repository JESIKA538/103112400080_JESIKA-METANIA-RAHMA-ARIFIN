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
