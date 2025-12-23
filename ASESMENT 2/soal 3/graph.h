#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

struct Node;
struct Edge;

struct Edge {
    Node* tujuan;
    Edge* next;
};

struct Node {
    char nama;          
    bool visited;
    bool ignore;
    Edge* edge;
    Node* next;
};

class Graph {
public:
    Node* head;

    Graph();

    Node* tambahNode(char nama);
    void tambahEdge(Node* a, Node* b);

    void tampilkanJaringan();

    void resetVisited();
    void DFS(Node* n, int& jumlah);
    int totalNode();

    void analisisKotaKritis();
};

#endif
