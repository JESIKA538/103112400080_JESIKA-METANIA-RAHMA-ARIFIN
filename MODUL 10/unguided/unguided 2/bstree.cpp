#include "bstree.h"
#include <algorithm>

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
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    } 
    else if (x > root->info) {
        insertNode(root->right, x);
    }
    
}

address findNode(address root, infotype x) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) return findNode(root->left, x);
    return findNode(root->right, x);
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        std::cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left, 0) + hitungTotalInfo(root->right, 0);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return 0; 
    }
    int kiri = hitungKedalaman(root->left, 0);
    int kanan = hitungKedalaman(root->right, 0);
    return 1 + std::max(kiri, kanan); 
}
