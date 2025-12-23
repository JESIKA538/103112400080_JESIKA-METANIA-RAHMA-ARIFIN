#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

#endif
