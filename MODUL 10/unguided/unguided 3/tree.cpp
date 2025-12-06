#include "tree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address& root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else {
            insertNode(root->right, x); 
        }
    }
}

address findNode(address root, infotype x) {
    if (root == Nil || root->info == x) {
        return root;
    } else {
        if (x < root->info) {
            return findNode(root->left, x);
        } else {
            return findNode(root->right, x);
        }
    }
}
// Traversal In-Order (Kiri - Root - Kanan)
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        std::cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Traversal Pre-Order (Root - Kiri - Kanan)
void printPreorder(address root) {
    if (root != Nil) {
        std::cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Traversal Post-Order (Kiri - Kanan - Root)
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << root->info << " - ";
    }
}

// 1. Fungsi hitungJumlahNode
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

// 2. Fungsi hitungTotalInfo
int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return 0; 
    } else {
        return root->info + hitungTotalInfo(root->left, 0) + hitungTotalInfo(root->right, 0);
    }
}

// 3. Fungsi hitungKedalaman (Tinggi Pohon)
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return 0; 
    } else {
        int kedalamanKiri = hitungKedalaman(root->left, 0);
        int kedalamanKanan = hitungKedalaman(root->right, 0);
        
        return 1 + std::max(kedalamanKiri, kedalamanKanan);
    }
}