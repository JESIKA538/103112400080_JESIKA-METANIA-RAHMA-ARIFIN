# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH </h1>
<p align="center">JESIKA METANIA RAHMA ARIFIN - 103112400080</p>

### 1. Pengertian GRAPH

Graph adalah struktur matematika yang terdiri dari himpunan simpul (vertex/node) dan himpunan sisi (edge) yang menghubungkan pasangan simpul. Secara formal, graph G didefinisikan sebagai pasangan terurut G = (V, E), dimana V adalah himpunan tidak kosong dari simpul dan E adalah himpunan sisi yang menghubungkan simpul-simpul tersebut.

### 2. Jenis-Jenis GRAPH
-Graph Berarah (Directed Graph/Digraph): Sisi memiliki arah tertentu dari satu simpul ke simpul lainnya
-Graph Tak Berarah (Undirected Graph): Sisi tidak memiliki arah
-Graph Berbobot (Weighted Graph): Setiap sisi memiliki nilai atau bobot tertentu
-Graph Sederhana: Tidak memiliki loop atau sisi ganda

### 3. Representasi GRAPH
Graph dapat direpresentasikan dengan:

-Matriks Adjacency (Adjacency Matrix): Matriks berukuran n×n untuk graph dengan n simpul.

-List Adjacency (Adjacency List): Setiap simpul memiliki daftar simpul yang bertetangga

### 4. Contoh aplikasi GRAPH
Aplikasi Graph

1. Jaringan sosial dan analisis hubungan
2. Sistem transportasi dan routing
3. Jaringan komputer
4. Analisis algoritma pencarian
5. Optimasi jalur terpendek


## Guided 

### 1.graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmEdge;
struct ElmNode;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);

#endif

### graph_init.cpp
#include "graph.h"
#include <iostream>

using namespace std;

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

### graph_edge.cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}

### Main.cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}

penjelasan singkat guided 1
Program ini adalah program yang mengimplementasikan struktur graph.

## Unguided 

### 1.  Buatlah ADT Graph tidak berarah file “graph.h”:
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
info : infoGraph
visited : integer
firstEdge : adrEdge
Next : adrNode
>
Type ElmEdge <
Node : adrNode
Next : adrEdge
>
Type Graph <
first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)

### Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

```C++
source code unguided 1
```

## graph.h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
typedef char infoGraph;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif

## graph.cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

## main.cpp
#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, D);

    cout << "Isi Graph:" << endl;
    PrintInfoGraph(G);

    return 0;
}


### Output Unguided 1 :

##### Output 1
Output 1
![Output Unguided 1 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%201/output%20unguided1%20MODUL%2013.png)


penjelasan unguided 1 
Program ini mengimplementasikan ADT Graph tidak berarah menggunakan representasi adjacency list. Setiap node menyimpan informasi berupa karakter, penanda kunjungan (visited), daftar edge yang terhubung, serta pointer ke node berikutnya. Edge digunakan untuk merepresentasikan hubungan antar node dan disimpan dalam bentuk linked list pada masing-masing node.

File graph.h berisi definisi struktur data dan deklarasi fungsi dasar graph. File graph.cpp mengimplementasikan fungsi-fungsi tersebut, yaitu membuat graph kosong, menambahkan node, menghubungkan dua node secara dua arah, serta menampilkan hubungan antar node. Pada main.cpp, graph diuji dengan menambahkan beberapa node, menghubungkannya, dan menampilkan isi graph, sehingga memperlihatkan cara kerja graph tidak berarah secara sederhana.

### 2.   Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintDFS (Graph G, adrNode N);

```C++
source code unguided 2
```
### graph.h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
typedef char infoGraph;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);

#endif

## graph.cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) {
        return;
    }

    // Kunjungi node
    cout << N->info << " ";
    N->visited = 1;

    // Menelusuri semua tetangga
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->node->visited == 0) {
            PrintDFS(G, E->node);
        }
        E = E->next;
    }
}


## main.cpp
#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "DFS : ";
    PrintDFS(G, A);
    cout << endl;

    // reset visited (digunakan untuk menandai node yang sudah di kunjungi)
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

### Output Unguided 2 :

##### Output 

![Output Unguided 2 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%202/output%20unguided2%20MODUL%2013.png)

penjelasan unguided 2
Program ini mengimplementasikan ADT Graph tidak berarah menggunakan adjacency list dan dilengkapi dengan algoritma Depth First Search (DFS). Setiap node memiliki penanda visited untuk menandai node yang sudah dikunjungi agar tidak terjadi pengulangan. DFS bekerja dengan mengunjungi node awal, kemudian menelusuri node-node tetangga secara rekursif hingga tidak ada lagi node yang bisa dikunjungi. Setelah proses DFS selesai, nilai visited di-reset agar graph dapat digunakan kembali untuk penelusuran selanjutnya.

### 3.Buatlah prosedur untuk menampilkanhasil penelusuran DFS.prosedur PrintBFS (Graph G, adrNode N)

```C++
source code unguided 3
```
## graph.h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
typedef char infoGraph;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif

## graph.cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    // Queue sederhana
    adrNode Q[100];
    int front = 0, rear = 0;

    // Mulai dari node awal
    Q[rear++] = N;
    N->visited = 1;

    while (front < rear) {
        adrNode P = Q[front++];

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q[rear++] = E->node;
            }
            E = E->next;
        }
    }
}

## main.cpp
#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    // reset visited (digunakan untuk menandai node yang sudah di kunjungi)
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    cout << "BFS : ";
    PrintBFS(G, A);
    cout << endl;

    return 0;
}

### Output Unguided 3 :

##### Output 
Output 3
![Output Unguided 3 Modul 13](https://raw.githubusercontent.com/JESIKA538/103112400080_JESIKA-METANIA-RAHMA-ARIFIN/main/MODUL%2013/unguided/unguided%203/output%20unguided3%20MODUL%2013.png)

penjelasan unguided 3
Program ini merupakan implementasi multi-linked list induk–anak yang memodelkan hubungan antara golongan hewan (parent) dan hewan (child), di mana parent disusun dalam doubly linked list dan setiap parent memiliki singly linked list child. Struktur MultiLL menyimpan pointer ke parent pertama dan terakhir, sedangkan setiap Golongan menyimpan data golongan serta pointer ke daftar hewan (firstChild). Program menyediakan operasi inisialisasi, penambahan parent dan child, pencarian node, penghapusan child, serta penghapusan parent beserta seluruh child-nya secara aman untuk mencegah kebocoran memori. Fungsi printMLLStructure digunakan untuk menampilkan seluruh struktur hierarkis, sementara main.cpp berfungsi sebagai pengujian dengan membuat data awal, melakukan operasi delete pada salah satu parent, dan menampilkan hasil akhir struktur multi-linked list.

## Kesimpulan
Graph merupakan struktur matematika fundamental yang terdiri dari simpul (vertex) dan sisi (edge) yang menghubungkan simpul-simpul tersebut, secara formal dinyatakan sebagai G = (V, E). Teori graph memiliki berbagai klasifikasi berdasarkan karakteristiknya, seperti graph berarah, tak berarah, berbobot, dan sederhana, yang masing-masing memiliki aplikasi dan kegunaan spesifik.
Representasi graph dapat dilakukan melalui matriks adjacency maupun list adjacency, dimana pemilihan metode representasi bergantung pada kebutuhan efisiensi ruang dan waktu dalam implementasi. Teori graph memiliki aplikasi yang sangat luas dalam berbagai bidang, mulai dari analisis jaringan sosial, sistem transportasi, jaringan komputer, hingga optimasi algoritma pencarian dan penentuan jalur terpendek.

## Referensi
[1] 1. Bondy, J. A., & Murty, U. S. R. (2008). Graph Theory. Springer. Graduate Texts in Mathematics, Vol. 244.
[2] Diestel, R. (2017). Graph Theory (5th ed.). Springer-Verlag, Berlin.
[3] Wilson, R. J. (1996). Introduction to Graph Theory (4th ed.). Prentice Hall
[4] Chartrand, G., & Zhang, P. (2012). A First Course in Graph Theory. Dover Publications.
[5] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press. (Bab Graph Algorithms)
[6]West, D. B. (2001). Introduction to Graph Theory (2nd ed.). Prentice Hall.
[7]Harary, F. (1969). "Graph Theory". Addison-Wesley Publishing Company.



