#ifndef MAHASISWA_H
#define MAHASISWA_H

//Definisi Tipe(struct)
struct mahasiswa {
    char nim[10];
    int nilai1,nilai2;
};

//Deklarasi Primitif(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);


