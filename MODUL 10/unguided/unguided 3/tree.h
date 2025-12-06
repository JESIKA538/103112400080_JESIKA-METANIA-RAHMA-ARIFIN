#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <algorithm> 

#define Nil NULL

typedef int infotype;
typedef struct TNode* address;
typedef struct TNode {
    infotype info;
    address left;
    address right;
} Node;

// Fungsi-fungsi Dasar BST
address alokasi(infotype x);
void insertNode(address& root, infotype x);
address findNode(address root, infotype x);

// Fungsi Traversal
void printInorder(address root);
void printPreorder(address root);
void printPostorder(address root);

// Fungsi Perhitungan
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start); 
int hitungKedalaman(address root, int start); 

#endif 