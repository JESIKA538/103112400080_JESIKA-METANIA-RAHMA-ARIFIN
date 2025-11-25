#ifndef SOAL2_H
#define SOAL2_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

extern Node* head;
extern Node* tail;

void insertAkhir(int nilai);
void deleteTerakhir();
void viewDepan();
void reverseList();

#endif
