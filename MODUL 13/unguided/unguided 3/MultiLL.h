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