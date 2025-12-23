#include "Graph.h"

int main() {
    Graph g;

    cout << "Membangun Jaringan Distribusi Vaksin\n\n";

    Node* A = g.tambahNode('A');
    Node* B = g.tambahNode('B');
    Node* C = g.tambahNode('C');
    Node* D = g.tambahNode('D');
    Node* E = g.tambahNode('E');

    g.tambahEdge(A, B);
    g.tambahEdge(B, E);
    g.tambahEdge(B, C);
    g.tambahEdge(C, D);

    g.tampilkanJaringan();

    g.analisisKotaKritis();

    return 0;
}
