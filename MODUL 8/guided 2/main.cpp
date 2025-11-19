#include <iostream>
#include "queue.h"
using namespace std;

// Fungsi utama proggram
int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);
    cout << "\n Enqueue 3 Elemen" << endl;
    enQueue(Q, 5);
    printInfo(Q);
    enQueue(Q, 2);
    printInfo(Q);
    enQueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    enQueue(Q,4);
    printInfo(Q);

    
    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    printInfo(Q);

    return 0;
}