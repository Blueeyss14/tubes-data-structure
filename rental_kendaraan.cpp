#include "rental_kendaraan.h"

void createList(List &L) {
    FIRST(L) = NULL;
    LAST(L) = NULL;
}

address createElement(infotype data) {
    address P = new elmlist;
    INFO(P) = data;
    NEXT(P) = NULL;
    PREV(P) = NULL;
    return P;
}

void insertFirst(List &L, address P) {
    if (FIRST(L) == NULL) {
        FIRST(L) = P;
        LAST(L) = P;
    } else {
        NEXT(P) = FIRST(L);
        PREV(FIRST(L)) = P;
        FIRST(L) = P;
    }
}

void insertLast(List &L, address P) {
    if (FIRST(L) == NULL) {
        FIRST(L) = P;
        LAST(L) = P;
    } else {
        NEXT(LAST(L)) = P;
        PREV(P) = LAST(L);
        LAST(L) = P;
    }
}

void insertAfter(List &L, address Q, address P) {
    if (Q != NULL) {
        NEXT(P) = NEXT(Q);
        PREV(P) = Q;
        
        if (NEXT(Q) != NULL) {
            PREV(NEXT(Q)) = P;
        } else {
            LAST(L) = P;
        }
        NEXT(Q) = P;
    }
}

void deleteFirst(List &L) {
    if (FIRST(L) != NULL) {
        address P = FIRST(L);
        if (FIRST(L) == LAST(L)) {
            FIRST(L) = NULL;
            LAST(L) = NULL;
        } else {
            FIRST(L) = NEXT(P);
            PREV(NEXT(P)) = NULL;
            NEXT(P) = NULL;
        }
    }
}

void deleteLast(List &L) {
    if (FIRST(L) != NULL) {
        address P = LAST(L);
        if (FIRST(L) == LAST(L)) {
            FIRST(L) = NULL;
            LAST(L) = NULL;
        } else {
            LAST(L) = PREV(P);
            NEXT(LAST(L)) = NULL;
            PREV(P) = NULL;
        }
    }
}

void deleteAfter(List &L, address Q) {
    if (Q != NULL && NEXT(Q) != NULL) {
        address P = NEXT(Q);
        
        if (NEXT(P) != NULL) {
            NEXT(Q) = NEXT(P);
            PREV(NEXT(P)) = Q;
        } else {
            NEXT(Q) = NULL;
            LAST(L) = Q;
        }
        
        NEXT(P) = NULL;
        PREV(P) = NULL;
    }
}

address findData(List &L, string merkKendaraan) {
    address P = FIRST(L);
    while (P != NULL) {
        if (INFO(P).merk == merkKendaraan) {
            return P;
        }
        P = NEXT(P);
    }
    return NULL;
}

void deleteData(List &L, string data) {
    address P = findData(L, data);
    if (P != NULL) {
        if (P == FIRST(L) && FIRST(L) == LAST(L)) {
            FIRST(L) = NULL;
            LAST(L) = NULL;
            delete P;
        } else if (P == FIRST(L)) {
            deleteFirst(L);
        } else if (P == LAST(L)) {
            deleteLast(L);
        } else {
            deleteAfter(L, PREV(P));
        }
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

void sortKendaraan(List &L, string kriteria) {
    address P, Q;
    infotype temp;
    
    P = FIRST(L);
    while (P != NULL) {
        Q = NEXT(P);
        while (Q != NULL) {
            if (kriteria == "nama") {
                if (INFO(P).nama > INFO(Q).nama) {
                    temp = INFO(P);
                    INFO(P) = INFO(Q);
                    INFO(Q) = temp;
                }
            } else if (kriteria == "harga") {
                if (INFO(P).harga > INFO(Q).harga) {
                    temp = INFO(P);
                    INFO(P) = INFO(Q);
                    INFO(Q) = temp;
                }
            }
            Q = NEXT(Q);
        }
        P = NEXT(P);
    }
}

int hitungTotalPendapatan(List L) {
    int total = 0;
    address P = FIRST(L);
    while (P != NULL) {
        total += INFO(P).harga;
        P = NEXT(P);
    }
    return total;
}

void showKendaraanTerental(List L) {
    address P = FIRST(L);
    int i = 1;
    while (P != NULL) {
        cout << i << ". Nama Penyewa: " << INFO(P).nama << endl;
        cout << "   Merk Kendaraan: " << INFO(P).merk << endl;
        cout << "   Waktu Pinjam: " << INFO(P).waktu_pinjam << endl;
        cout << "   Waktu Pengembalian: " << INFO(P).waktu_pengembalian << endl;
        cout << "   Harga: Rp" << INFO(P).harga << endl;
        cout << "------------------------" << endl;
        P = NEXT(P);
        i++;
    }
}

void cariKendaraanByHarga(List L, int min_harga, int max_harga) {
    address P = FIRST(L);
    bool found = false;
    while (P != NULL) {
        if (INFO(P).harga >= min_harga && INFO(P).harga <= max_harga) {
            cout << "Merk: " << INFO(P).merk << endl;
            cout << "Harga: Rp" << INFO(P).harga << endl;
            cout << "------------------------" << endl;
            found = true;
        }
        P = NEXT(P);
    }
    if (!found) {
        cout << "Tidak ada kendaraan dalam range harga tersebut" << endl;
    }
}

bool kendaraanTersedia(List L, string merk) {
    address P = FIRST(L);
    while (P != NULL) {
        if (INFO(P).merk == merk) {
            return true;
        }
        P = NEXT(P);
    }
    return false;
}

void urutHargaTerendah(List &L, address P) {
    address Q;
    infotype temp;

    if (FIRST(L) == NULL) {
        cout << "Data kosong!" << endl;
        return;
    }
    
    P = FIRST(L);

    
    while (P != NULL) {
        Q = NEXT(P);
        while (Q != NULL) {
            if (INFO(P).harga > INFO(Q).harga) {
                temp = INFO(P);
                INFO(P) = INFO(Q);
                INFO(Q) = temp;
            }
            Q = NEXT(Q);
        }
        P = NEXT(P);
    }
    cout << "Data berhasil diurutkan dari harga terendah!" << endl;
    showKendaraanTerental(L);
}

void urutHargaTertinggi(List &L, address P) {
    address Q;
    infotype temp;
    if (FIRST(L) == NULL) {
        cout << "Data kosong!" << endl;
        return;
    }
    
    P = FIRST(L);
    while (P != NULL) {
        Q = NEXT(P);
        while (Q != NULL) {
            if (INFO(P).harga < INFO(Q).harga) {
                temp = INFO(P);
                INFO(P) = INFO(Q);
                INFO(Q) = temp;
            }
            Q = NEXT(Q);
        }
        P = NEXT(P);
    }
    cout << "Data berhasil diurutkan dari harga tertinggi!" << endl;
    showKendaraanTerental(L);
}