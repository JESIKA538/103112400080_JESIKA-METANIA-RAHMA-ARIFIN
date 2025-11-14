#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    // Menggunakan pengurutan manual, kenapa dari dua?? karena kalau dari sembilan jadi kebalik outputnya.Udah nyoba pake pushAscending tapi kebalik udah di balik tetep kebalik.
    push(S, 2);
    push(S, 3);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);

    printInfo(S);

    return 0;
}
