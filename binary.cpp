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

// Fungsi untuk menghitung panjang linked list
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

// Binary Search pada Linked List (dengan akses sequential)
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getSize(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        if (!midNode) return nullptr;
        if (midNode->data == key) return midNode;
        else if (midNode->data < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
