#include "rental_kendaraan.h"

address createElement(infotype data) {
    address P;
    P = new elmlist;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirst(list &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(list &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertAfter(list &L, address Q, address P) {
    if (Q != NULL) {
        next(P) = next(Q);
        prev(P) = Q;
        
        if (next(Q) != NULL) {
            prev(next(Q)) = P;
        } else {
            last(L) = P;
        }
        next(Q) = P;
    }
}

void deleteFirst(list &L) {
    if (first(L) != NULL) {
        address P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        delete P;
    }
}

void deleteLast(list &L) {
    if (first(L) != NULL) {
        address P = last(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        delete P;
    }
}

void deleteAfter(list &L, address Q) {
    if (Q != NULL && next(Q) != NULL) {
        address P = next(Q);
        
        if (next(P) != NULL) {
            next(Q) = next(P);
            prev(next(P)) = Q;
        } else {
            next(Q) = NULL;
            last(L) = Q;
        }
        
        next(P) = NULL;
        prev(P) = NULL;
        delete P;
    }
} 

address findData(list &L, string merkKendaraan) {
    address P = first(L);
    while (P != NULL) {
        if (info(P).merk == merkKendaraan) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteData(list &L, string data1) {
    address P = findData(L, data1);
    if (P != NULL) {
        if (P == first(L) && first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
            delete P;
        } else if (P == first(L)) {
            deleteFirst(L);
        } else if (P == last(L)) {
            deleteLast(L);
        } else {
            deleteAfter(L, prev(P));
        }
    } else {
        cout << "Tidak Ada Kendaraan" << endl;
    }
}

void sortKendaraan(list &L, string kriteria) {
    address P, Q;
    infotype temp;
    
    P = first(L);
    while (P != NULL) {
        Q = P->next;
        while (Q != NULL) {
            if (kriteria == "merk") {
                if (info(P).merk > info(Q).merk) {
                    temp = info(P);
                    info(P) = info(Q);
                    info(Q) = temp;
                }
            } else if (kriteria == "harga") {
                if (info(P).harga > info(Q).harga) {
                    temp = info(P);
                    info(P) = info(Q);
                    info(Q) = temp;
                }
            }
            Q = Q->next;
        }
        P = P->next;
    }
}

int hitungTotalPendapatan(list L) {
    int total = 0;
    address P = first(L);
    while (P != NULL) {
        total += info(P).harga;
        P = next(P);
    }
    return total;
}

void showKendaraanTerental(list L) {
    address P = first(L);
    int i = 1;
    while (P != NULL) {
        cout << i << ". Nama Penyewa: " << info(P).nama << endl;
        cout << "   Merk Kendaraan: " << info(P).merk << endl;
        cout << "   Waktu Pinjam: " << info(P).waktu_pinjam << endl;
        cout << "   Waktu Pengembalian: " << info(P).waktu_pengembalian << endl;
        cout << "   Harga: Rp" << info(P).harga << endl;
        cout << "------------------------" << endl;
        P = next(P);
        i++;
    }
}

void cariKendaraanByHarga(list L, int min_harga, int max_harga) {
    address P = first(L);
    bool found = false;
    while (P != NULL) {
        if (info(P).harga >= min_harga && info(P).harga <= max_harga) {
            cout << "Merk: " << info(P).merk << endl;
            cout << "Harga: Rp" << info(P).harga << endl;
            cout << "------------------------" << endl;
            found = true;
        }
        P = next(P);
    }
    if (!found) {
        cout << "Tidak ada kendaraan" << endl;
    }
}

bool kendaraanTersedia(list L, string merk) {
    address P = first(L);
    while (P != NULL) {
        if (info(P).merk == merk) {
            return true;
        }
        P = next(P);
    }
    return false;
}

