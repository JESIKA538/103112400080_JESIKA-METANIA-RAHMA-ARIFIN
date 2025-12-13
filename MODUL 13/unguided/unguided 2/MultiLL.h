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
