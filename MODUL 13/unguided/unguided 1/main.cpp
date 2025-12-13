#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    NodeChild C001_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    NodeChild C001_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);

    insertLastChild(P1->L_Child, C001_1);
    insertLastChild(P1->L_Child, C001_2);

    NodeChild C002_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    NodeChild C002_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    NodeChild C002_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);

    insertLastChild(P2->L_Child, C002_1);
    insertLastChild(P2->L_Child, C002_2);
    insertLastChild(P2->L_Child, C002_3);

    NodeChild C004_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C004_1);

    printMLLStructure(LP);

    return 0;
}
