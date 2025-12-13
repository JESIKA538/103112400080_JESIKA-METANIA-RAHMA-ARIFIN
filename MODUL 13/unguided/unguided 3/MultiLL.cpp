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