#include <iostream>
#include "tree.h" 

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    
    // Urutan insertNode: 1, 2, 6, 4, 5, 3, 6, 7
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << " Hasil Traversal " << endl;
    
    // Traversal In-Order
    cout << "In-Order  : ";
    printInorder(root);
    cout << endl;
    
    // Traversal Pre-Order
    cout << "Pre-Order : ";
    printPreorder(root);
    cout << endl;
    
    // Traversal Post-Order
    cout << "Post-Order: ";
    printPostorder(root);
    cout << endl;

    cout << "--- Hasil Perhitungan ---" << endl;
    
    // Hitung Kedalaman/Tinggi Pohon
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl; 
    
    // Hitung Jumlah Node
    cout << "jumlah node : " << hitungJumlahNode(root) << endl; 
    
    // Hitung Total Info
    cout << "total : " << hitungTotalInfo(root, 0) << endl; 
    
    return 0;
}