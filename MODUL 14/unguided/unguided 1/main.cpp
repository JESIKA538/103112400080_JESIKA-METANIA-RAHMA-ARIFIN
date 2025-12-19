#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, D);

    cout << "Isi Graph:" << endl;
    PrintInfoGraph(G);

    return 0;
}