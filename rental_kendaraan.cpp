#include "rental_kendaraan.h"

void createList(list &L) {
    list_first(L) = NULL;
    list_last(L) = NULL;
}

address createElement(infotype data) {
    address P = new elmlist;
    list_info(P) = data;
    list_next(P) = NULL;
    list_prev(P) = NULL;
    return P;
}

void insertFirst(list &L, address P) {
    if (list_first(L) == NULL) {
        list_first(L) = P;
        list_last(L) = P;
    } else {
        list_next(P) = list_first(L);
        list_prev(list_first(L)) = P;
        list_first(L) = P;
    }
}

void insertLast(list &L, address P) {
    if (list_first(L) == NULL) {
        list_first(L) = P;
        list_last(L) = P;
    } else {
        list_next(list_last(L)) = P;
        list_prev(P) = list_last(L);
        list_last(L) = P;
    }
}

void insertAfter(list &L, address Q, address P) {
    if (Q != NULL) {
        list_next(P) = list_next(Q);
        list_prev(P) = Q;
        
        if (list_next(Q) != NULL) {
            list_prev(list_next(Q)) = P;
        } else {
            list_last(L) = P;
        }
        list_next(Q) = P;
    }
}

void deleteFirst(list &L) {
    if (list_first(L) != NULL) {
        address P = list_first(L);
        if (list_first(L) == list_last(L)) {
            list_first(L) = NULL;
            list_last(L) = NULL;
        } else {
            list_first(L) = list_next(P);
            list_prev(list_first(L)) = NULL;
            list_next(P) = NULL;
        }
        delete P;
    }
}

void deleteLast(list &L) {
    if (list_first(L) != NULL) {
        address P = list_last(L);
        if (list_first(L) == list_last(L)) {
            list_first(L) = NULL;
            list_last(L) = NULL;
        } else {
            list_last(L) = list_prev(P);
            list_next(list_last(L)) = NULL;
            list_prev(P) = NULL;
        }
        delete P;
    }
}

void deleteAfter(list &L, address Q) {
    if (Q != NULL && list_next(Q) != NULL) {
        address P = list_next(Q);
        
        if (list_next(P) != NULL) {
            list_next(Q) = list_next(P);
            list_prev(list_next(P)) = Q;
        } else {
            list_next(Q) = NULL;
            list_last(L) = Q;
        }
        
        list_next(P) = NULL;
        list_prev(P) = NULL;
        delete P;
    }
}

address findData(list &L, string merkKendaraan) {
    address P = list_first(L);
    while (P != NULL) {
        if (list_info(P).merk == merkKendaraan) {
            return P;
        }
        P = list_next(P);
    }
    return NULL;
}

void deleteData(list &L, string data) {
    address P = findData(L, data);
    if (P != NULL) {
        if (P == list_first(L) && list_first(L) == list_last(L)) {
            list_first(L) = NULL;
            list_last(L) = NULL;
            delete P;
        } else if (P == list_first(L)) {
            deleteFirst(L);
        } else if (P == list_last(L)) {
            deleteLast(L);
        } else {
            deleteAfter(L, list_prev(P));
        }
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

void sortKendaraan(list &L, string kriteria) {
    address P, Q;
    infotype temp;
    
    P = list_first(L);
    while (P != NULL) {
        Q = list_next(P);
        while (Q != NULL) {
            if (kriteria == "nama") {
                if (list_info(P).nama > list_info(Q).nama) {
                    temp = list_info(P);
                    list_info(P) = list_info(Q);
                    list_info(Q) = temp;
                }
            } else if (kriteria == "harga") {
                if (list_info(P).harga > list_info(Q).harga) {
                    temp = list_info(P);
                    list_info(P) = list_info(Q);
                    list_info(Q) = temp;
                }
            }
            Q = list_next(Q);
        }
        P = list_next(P);
    }
}

int hitungTotalPendapatan(list L) {
    int total = 0;
    address P = list_first(L);
    while (P != NULL) {
        total += list_info(P).harga;
        P = list_next(P);
    }
    return total;
}

void showKendaraanTerental(list L) {
    address P = list_first(L);
    int i = 1;
    while (P != NULL) {
        cout << i << ". Nama Penyewa: " << list_info(P).nama << endl;
        cout << "   Merk Kendaraan: " << list_info(P).merk << endl;
        cout << "   Waktu Pinjam: " << list_info(P).waktu_pinjam << endl;
        cout << "   Waktu Pengembalian: " << list_info(P).waktu_pengembalian << endl;
        cout << "   Harga: Rp" << list_info(P).harga << endl;
        cout << "------------------------" << endl;
        P = list_next(P);
        i++;
    }
}

void cariKendaraanByHarga(list L, int min_harga, int max_harga) {
    address P = list_first(L);
    bool found = false;
    while (P != NULL) {
        if (list_info(P).harga >= min_harga && list_info(P).harga <= max_harga) {
            cout << "Merk: " << list_info(P).merk << endl;
            cout << "Harga: Rp" << list_info(P).harga << endl;
            cout << "------------------------" << endl;
            found = true;
        }
        P = list_next(P);
    }
    if (!found) {
        cout << "Tidak ada kendaraan dalam range harga tersebut" << endl;
    }
}

bool kendaraanTersedia(list L, string merk) {
    address P = list_first(L);
    while (P != NULL) {
        if (list_info(P).merk == merk) {
            return true;
        }
        P = list_next(P);
    }
    return false;
}

