#ifndef STACK_H
#include<iostream>
#define MaxEl 20
#define Nil-1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; // array untuk menyimpan elemen stcak
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // menambahkan elemen ke dalam stack
infotype pop(Stack &S); // MENGAMBIL ELEMEN TERATAS DARI STACK
void printInfo(Stack S);
void balikStack(Stack &S); // membalik urutan elemen dalam stack

#endif

