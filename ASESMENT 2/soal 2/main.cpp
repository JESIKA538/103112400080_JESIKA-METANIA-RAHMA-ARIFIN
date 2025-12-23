#include "mll.h"

int main() {
    ListParent bioskop;
    
    createListParent(bioskop);

    insertFirstParent(bioskop, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(bioskop, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(bioskop, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(bioskop, alokasiNodeParent("G001", "Action"));

    NodeParent* P1 = bioskop.first;            
    NodeParent* P2 = bioskop.first->next;       
    NodeParent* P3 = bioskop.first->next->next;
    NodeParent* P4 = bioskop.last;              

    insertLastChild(P1->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    insertLastChild(P2->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P2->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(P3->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(P4->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P4->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    cout << "[Output Soal 3]" << endl;
    printStrukturMLL(bioskop);
    cout << endl;

    cout << "[Output Soal 4: Search Rating 8.0 - 8.5]" << endl;
    searchFilmByRatingRange(bioskop, 8.0, 8.5);
    cout << endl;

    cout << "[Proses: Menghapus Genre Comedy setelah Action...]" << endl;
    deleteAfterParent(bioskop, P1);
    cout << endl;

    cout << "[Output Soal 6: Struktur Setelah Penghapusan]" << endl;
    printStrukturMLL(bioskop);

    return 0;
}