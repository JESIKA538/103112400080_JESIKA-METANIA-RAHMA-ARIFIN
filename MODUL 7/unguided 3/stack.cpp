#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0 && S.info[S.top] < x) {
        push(temp, pop(S));
    }
    push(S, x); // untuk memasukan nilai x ke stack S

    // Untuk mengembalikan elemen dari temp
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    string input = "4729601";  

    for (char c : input) {
        if (isdigit(c)) {
            push(S, c - '0');
        }
    }
}
