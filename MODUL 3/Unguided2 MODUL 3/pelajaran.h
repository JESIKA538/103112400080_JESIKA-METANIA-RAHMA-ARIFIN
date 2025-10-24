#ifndef PELAJARAN_H
#define PELAJARAN_H


struct pelajaran {
    char namaPelajaran[50];
    char kodePelajaran[10];
};
pelajaran create_pelajaran(char namaPelajaran[], char kodePelajaran[]);
void tampil_pelajaran(pelajaran pel);

#endif
