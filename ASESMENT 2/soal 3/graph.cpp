#include "Graph.h"

Graph::Graph() {
    head = NULL;
}

// tambah node
Node* Graph::tambahNode(char nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->visited = false;
    baru->ignore = false;
    baru->edge = NULL;
    baru->next = NULL;

    if (head == NULL)
        head = baru;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
    return baru;
}

// tambah edge dua arah
void Graph::tambahEdge(Node* a, Node* b) {
    Edge* e1 = new Edge;
    e1->tujuan = b;
    e1->next = a->edge;
    a->edge = e1;

    Edge* e2 = new Edge;
    e2->tujuan = a;
    e2->next = b->edge;
    b->edge = e2;
}

// tampilkan jaringan
void Graph::tampilkanJaringan() {
    Node* n = head;
    while (n != NULL) {
        cout << "Node " << n->nama << " terhubung ke: ";
        Edge* e = n->edge;
        while (e != NULL) {
            cout << e->tujuan->nama << " ";
            e = e->next;
        }
        cout << endl;
        n = n->next;
    }
}

// reset visited
void Graph::resetVisited() {
    Node* n = head;
    while (n != NULL) {
        n->visited = false;
        n = n->next;
    }
}

// DFS sederhana
void Graph::DFS(Node* n, int& jumlah) {
    if (n == NULL || n->visited || n->ignore)
        return;

    n->visited = true;
    jumlah++;

    Edge* e = n->edge;
    while (e != NULL) {
        DFS(e->tujuan, jumlah);
        e = e->next;
    }
}

// hitung total node
int Graph::totalNode() {
    int total = 0;
    Node* n = head;
    while (n != NULL) {
        total++;
        n = n->next;
    }
    return total;
}

// analisis kota kritis
void Graph::analisisKotaKritis() {
    int total = totalNode();
    Node* kota = head;

    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n\n";

    while (kota != NULL) {
        kota->ignore = true;
        resetVisited();

        Node* start = head;
        while (start != NULL && start->ignore)
            start = start->next;

        int terkunjungi = 0;
        if (start != NULL)
            DFS(start, terkunjungi);

        if (terkunjungi < total - 1) {
            cout << "[PERINGATAN] Kota " << kota->nama
                 << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << kota->nama
                 << " lockdown, distribusi terputus.\n\n";
        } else {
            cout << "Kota " << kota->nama
                 << " aman (redundansi oke).\n\n";
        }

        kota->ignore = false;
        kota = kota->next;
    }
}
