#include <iostream>
#include "bstree.h"
#include <iomanip> // Opsional

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    // Menampilkan isi pohon secara InOrder
    printInorder(root);
    cout << "\n" << endl; 
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl; 
    cout << "jumlah node : " << hitungJumlahNode(root) << endl; 
    cout << "total : " << hitungTotalInfo(root, 0) << endl; 
    
    return 0;
}