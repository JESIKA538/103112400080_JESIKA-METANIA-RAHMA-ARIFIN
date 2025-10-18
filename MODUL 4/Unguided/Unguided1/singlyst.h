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
