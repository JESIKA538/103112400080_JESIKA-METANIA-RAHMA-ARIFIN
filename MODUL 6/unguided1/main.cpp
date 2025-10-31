#include "DoublyList.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong." << endl;
    } else {
        cout << "Isi List Kendaraan:" << endl;
        while (P != Nil) {
            cout << "Nopol   : " << P->info.nopol << endl;
            cout << "Warna   : " << P->info.warna << endl;
            cout << "Tahun   : " << P->info.thnBuat << endl;
            cout << "----------------------" << endl;
            P = P->next;
        }
    }
}
