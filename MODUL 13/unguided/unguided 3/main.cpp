#include "MultiLL.h"
#include <iomanip>

int main() {
    cout << fixed << setprecision(1);

    MultiLL L;
    createList(L);
    cout << "Multi Linked List berhasil diinisialisasi." << endl;

    cout << "\n--- Setup Data Awal ---" << endl;

    Golongan* P1;
    createParent("G001", "Aves", P1);
    insertParentLast(L, P1);
    Hewan *C1_1, *C1_2;
    createChild("AV001", "Cenderawasih", "Hutan", 1, 0.3, C1_1);
    insertChildFirst(L, "G001", C1_1);
    createChild("AV002", "Bebek", "Air", 1, 2.0, C1_2);

    insertChildFirst(L, "G001", C1_2); 

    Golongan* P2;
    createParent("G002", "Mamalia", P2);
    insertParentLast(L, P2);
    Hewan *C2_1, *C2_2, *C2_3;
    createChild("M001", "Harimau", "Hutan", 1, 200.0, C2_1);
    insertChildFirst(L, "G002", C2_1);
    createChild("M003", "Gorilla", "Hutan", 1, 160.0, C2_2);
    insertChildFirst(L, "G002", C2_2); 
    createChild("M002", "Kucing", "Darat", 1, 5.0, C2_3);
    insertChildFirst(L, "G002", C2_3); 

    Golongan* P3;
    createParent("G003", "Pisces", P3);
    insertParentLast(L, P3);

    Golongan* P4;
    createParent("G004", "Amfibi", P4);
    insertParentLast(L, P4);
    Hewan *C4_1;
    createChild("A001", "Katak", "Air", 4, 0.1, C4_1);
    insertChildFirst(L, "G004", C4_1);

    Golongan* P5;
    createParent("G005", "Reptil", P5);
    insertParentLast(L, P5);

    cout << "Data awal berhasil dibuat." << endl;
    
    cout << " === " << endl;
    cout << ">>> OPERASI DELETE: Menghapus Parent G004 <<<" << endl;
    cout << "===" << endl;
    deleteParent(L, "G004");

    cout << " ==== " << endl;
    cout << ">>> HASIL PRINT SETELAH PENGHAPUSAN G004 <<<" << endl;
    cout << "  " << endl;
    printMLLStructure(L);

    return 0;
}