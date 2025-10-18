#include "singlyst.h"

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            dealokasi(L.first);
            L.first = nullptr;
        } else {
            address prev = nullptr;
            address curr = L.first;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            dealokasi(curr);
        }
    }
}

void deleteAfter(List &L, infotype x) {
    address prec = L.first;
    while (prec != nullptr && prec->info != x) {
        prec = prec->next;
    }
    if (prec != nullptr && prec->next != nullptr) {
        address P = prec->next;
        prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}
