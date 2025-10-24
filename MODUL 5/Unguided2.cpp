#include<iostream>
using namespace std;

//Definisi node
struct Node{ //Memiliki 2 bagian yaitu data dan pointer
    int data; 
    Node *next; //Pointer ke node berikutnya
};

//Fungsi untuk pencarian
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;

        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }

        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

//Prosedur untuk menambah node
void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr};

    if(!head) head = newNode;
    
    else{
        Node* temp = head; //mulai dari head
        while (temp -> next) temp = temp -> next;
        temp -> next = newNode;
    }
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n";

    // ==========================
    // Pencarian pertama
    // ==========================
    int key = 40;
    cout << "Mencari nilai: " << key << "\n";

    Node* result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    }

    // ==========================
    // Pencarian kedua
    // ==========================
    key = 35;
    cout << "\nMencari nilai: " << key << "\n";

    result = linearSearch(head, key);

    if (!result) {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
