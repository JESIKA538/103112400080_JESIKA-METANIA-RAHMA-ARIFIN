#include "Soal1.h"

Node* head = NULL;


void insertAkhir(string nama) {
    Node* baru = new Node{nama, NULL};

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteNama(string nama) {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;


    if (temp != NULL && temp->nama == nama) {
        head = temp->next;
        delete temp;
        cout << "Nama \"" << nama << "\" berhasil dihapus.\n";
        return;
    }

    while (temp != NULL && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Nama tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Nama \"" << nama << "\" berhasil dihapus.\n";
}

void view() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}
void hitungGenap() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->nama.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }

    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}
