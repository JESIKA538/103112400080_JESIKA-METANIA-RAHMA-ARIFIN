#include<iostream>
#include<cstring>
#include"pelajaran.h"
using namespace std;

pelajaran create_pelajaran(char namaPelajaran[], char kodePelajaran[]) {
    pelajaran pel;
    strcpy(pel.namaPelajaran, namaPelajaran);
    strcpy(pel.kodePelajaran, kodePelajaran);
    return pel;
}
    void tampil_pelajaran(pelajaran pel) {
        cout << "Nama Pelajaran: " << pel.namaPelajaran << endl;
        cout << "Nilai: " << pel.kodePelajaran << endl;
    }


