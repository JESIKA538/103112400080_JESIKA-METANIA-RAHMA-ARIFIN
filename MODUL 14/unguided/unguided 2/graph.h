#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
typedef char infoGraph;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);

#endif