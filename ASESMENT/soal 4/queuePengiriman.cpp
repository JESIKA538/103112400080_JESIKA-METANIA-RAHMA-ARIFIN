#include "QueuePengiriman.h"

void createQueue(QueueEkspedisi &Q) {
    Q.Head = 0; 
    Q.Tail = -1; 
    cout << "Queue kosong berhasil dibuat." << endl;
}
bool isEmpty(QueueEkspedisi Q) {
    return Q.Tail == -1; 
}
bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1; 
}
void enQueue(QueueEkspedisi &Q, Paket inputData) {
    if (isFull(Q)) {
        cout << "ANTRIAN PENUH! Tidak dapat menambahkan paket." << endl;
    } else {
        Q.Tail++;
        Q.dataPaket[Q.Tail] = inputData;
        cout << "Paket dengan Resi " << inputData.KodeResi << " berhasil di-enqueue." << endl;
    }
}
void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "ANTRIAN KOSONG! Tidak ada paket yang bisa di-dequeue." << endl;
    } else {
        Paket paketDihapus = Q.dataPaket[Q.Head]; 
        cout << "Paket dengan Resi " << paketDihapus.KodeResi << " berhasil di-dequeue (dihapus)." << endl;

        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
        if (Q.Tail == -1) {
            Q.Head = 0; 
        }
    }
}
void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Antrian paket kosong." << endl;
    } else {
        cout << "\n--- Tampilan Queue Paket (Head -> Tail) ---" << endl;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << i + 1 << ". ";
            cout << "Resi: " << Q.dataPaket[i].KodeResi 
                 << ", Pengirim: " << Q.dataPaket[i].NamaPengirim
                 << ", Berat: " << Q.dataPaket[i].BeratBarang << "kg"
                 << ", Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        }
        cout << " " << endl;
    }
}