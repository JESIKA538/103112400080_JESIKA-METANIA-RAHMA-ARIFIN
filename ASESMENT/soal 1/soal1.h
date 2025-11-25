#ifndef SOAL1_H
#define SOAL1_H

#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

extern Node* head;

void insertAkhir(string nama);
void deleteNama(string nama);
void view();
void hitungGenap();

#endif
