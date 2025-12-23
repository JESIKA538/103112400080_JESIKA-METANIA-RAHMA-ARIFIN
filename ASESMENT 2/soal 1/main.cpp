#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST tree;

    cout << "=== Membuat BST ===" << endl;

    tree.insertNode(tree.newNode("Rizkina Azizah", 60, "Basic"));
    tree.insertNode(tree.newNode("Hakan Ismail", 50, "Bronze"));
    tree.insertNode(tree.newNode("Olivia Saevali", 65, "Silver"));
    tree.insertNode(tree.newNode("Felix Pedrosa", 47, "Gold"));
    tree.insertNode(tree.newNode("Gamel Al Ghifari", 56, "Platinum"));
    tree.insertNode(tree.newNode("Mutiara Fauziah", 52, "Bronze"));
    tree.insertNode(tree.newNode("Hanif Al Faiz", 70, "Basic"));
    tree.insertNode(tree.newNode("Davi Ilyas", 68, "Silver"));
    tree.insertNode(tree.newNode("Abdad Mubarak", 81, "Gold"));

    cout << "\n=== Traversal InOrder ===" << endl;
    tree.inOrder();
    cout << endl;

    cout << "\nNode MostLeft : " << tree.mostLeft()->beratBadan << endl;
    cout << "Node MostRight : " << tree.mostRight()->beratBadan << endl;

    float cari = 70;
    Node* parent = NULL;
    Node* hasil = tree.searchByBeratBadan(cari, parent);

    if (hasil != NULL) {
        cout << "Data ditemukan didalam BST!\n" << endl;

        cout << "====Data Node Yang Dicari====\n" << endl;
        cout << "Nama Member : " << hasil->namaMember << endl;
        cout << "Berat Badan : " << hasil->beratBadan << endl;
        cout << "Tier Member : " << hasil->tierMember << endl;

        cout << "====Data Parent====\n" << endl;
        if (parent != NULL) {
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
        }

        cout << "====Tidak Memiliki Sibling====\n" << endl;
        
        cout << "====Data Child Kiri====\n" << endl;
        cout << "Nama Member : " << hasil->left->namaMember << endl;
        cout << "Berat Badan : " << hasil->left->beratBadan << endl;
        cout << "Tier Member : " << hasil->left->tierMember << endl;

        cout << "\n====Data Child Kanan====\n" << endl;
        cout << "Nama Member : " << hasil->right->namaMember << endl;
        cout << "Berat Badan : " << hasil->right->beratBadan << endl;
        cout << "Tier Member : " << hasil->right->tierMember << endl;

    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}
