#include "Soal2.h"

Node* head = NULL;
Node* tail = NULL;

void insertAkhir(int nilai) {
    Node* baru = new Node{nilai, NULL, NULL};

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void deleteTerakhir() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    if (head == tail) { // hanya 1 data
        delete head;
        head = tail = NULL;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete hapus;
}

// View dari depan
void viewDepan() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse TANPA node baru
void reverseList() {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        // tukar prev dan next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev; // maju ke node berikutnya (yang dulu next)
    }

    // swap head & tail
    if (temp != NULL) {
        head = temp->prev;
    }
}
