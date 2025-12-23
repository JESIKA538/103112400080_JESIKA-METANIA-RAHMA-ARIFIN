#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

// Struktur untuk List Child (Film)
struct NodeChild {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild* next;
    NodeChild* prev;
};

struct ListChild {
    NodeChild* first;
    NodeChild* last;
};

// Struktur untuk List Parent (Genre)
struct NodeParent {
    string idGenre;
    string namaGenre;
    ListChild childs;
    NodeParent* next;
    NodeParent* prev;
};

struct ListParent {
    NodeParent* first;
    NodeParent* last;
};

// Prototipe 
void createListParent(ListParent &L);
void createListChild(ListChild &L);
NodeParent* alokasiNodeParent(string id, string nama);
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(NodeParent* &P);
void dealokasiNodeChild(NodeChild* &P);

void insertFirstParent(ListParent &L, NodeParent* P);
void insertLastChild(ListChild &L, NodeChild* P);
void deleteAfterParent(ListParent &L, NodeParent* prevNode);
void hapusListChild(ListChild &L);

void searchFilmByRatingRange(ListParent L, float minR, float maxR);
void printStrukturMLL(ListParent L);

#endif