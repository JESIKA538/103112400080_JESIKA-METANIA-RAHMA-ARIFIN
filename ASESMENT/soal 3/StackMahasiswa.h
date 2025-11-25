#define STACKMAHASISWA_H
#include <iostream>
#include <string>

using namespace std;
const int MAX = 6; 
struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir; 
};
struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX]; 
    int Top;                
};
void createStack(StackMahasiswa &S);
bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void push(StackMahasiswa &S, Mahasiswa inputData);
void pop(StackMahasiswa &S);
void updateData(StackMahasiswa &S, int posisi, Mahasiswa newData);
void viewStack(StackMahasiswa S);
void searchNilaiAkhir(StackMahasiswa S, float NilaiAkhirMin, float NilaiAkhirMax);
float hitungNilaiAkhir(float tugas, float uts, float uas);