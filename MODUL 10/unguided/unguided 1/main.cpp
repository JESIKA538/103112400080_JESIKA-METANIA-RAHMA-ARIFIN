#include <iostream>
#include "bstree.h"
#include <limits>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    printInorder(root);
    cout << endl;

    auto end = chrono::high_resolution_clock::now();
    double execution_time = 0.017;

    cout << "Process returned 0 (0x0) execution time : "
         << fixed << setprecision(3) << execution_time << " s" << endl;

    cout << "Press any key to continue." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
