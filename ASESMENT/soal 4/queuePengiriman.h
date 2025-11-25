#define QUEUEPENGIRIMAN_H
#include <iostream>
#include <string>

using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};
const int MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[MAX]; 
    int Head;            
    int Tail;             
};
void createQueue(QueueEkspedisi &Q);
bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void enQueue(QueueEkspedisi &Q, Paket inputData);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);