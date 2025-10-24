#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node *next;
};

// Fungsi untuk menambah node di akhir
void append(Node* &head, int value) {
    Node* newNode = new Node;   // buat node baru
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) head = newNode;  // jika list kosong
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Fungsi untuk mengambil node ke-n
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next;
    return head;
}

// Binary Search pada Linked List 
Node* binarySearch(Node* head, int key) {
    int right = 0;
    Node* temp = head;
    while (temp) {
        right++;
        temp = temp->next;
    }
    right--;

    int left = 0;
    int iterasi = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);
        if (!midNode) break;

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
             << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            return midNode;
        }
        else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

int main() {
    cout << "BINARY SEARCH PADA LINGKED LIST" << endl;
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Isi Lingked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Mencari data yang ada dalam list

    // Pencarian pertama (40)
    // ============================
    int key = 60;
    cout << "Mencari nilai: " << key << endl;

    Node* result = binarySearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    }

    // ============================
    // Pencarian kedua (25)
    // ============================
    key = 45;
    cout << "\nMencari nilai: " << key << endl;

    result = binarySearch(head, key);

    if (!result) {
        cout << "Hasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}