#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    char namaPelajaran[] = "Struktur Data";
    char kodePelajaran[] = "STD";

    pelajaran pel = create_pelajaran(namaPelajaran, kodePelajaran);
    tampil_pelajaran(pel);

    return 0;
}
