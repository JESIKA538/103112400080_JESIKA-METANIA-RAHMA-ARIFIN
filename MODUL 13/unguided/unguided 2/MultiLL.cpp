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
