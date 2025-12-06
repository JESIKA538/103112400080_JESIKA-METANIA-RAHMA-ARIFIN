#ifndef bstree_H
#define bstree_H

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct TNode* address;
typedef struct TNode {
    infotype info;
    address left;
    address right;
} Node;

address alokasi(infotype x);
void insertNode(address& root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root);

#endif
