#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 100;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
int pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
