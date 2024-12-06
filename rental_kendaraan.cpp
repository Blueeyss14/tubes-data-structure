#include "rental_kendaraan.h"

void createListRental(ListRental &LR) {
    First(LR) = NULL;
}

void createListKendaraan(ListKendaraan &LK) {
    First(LK) = NULL;
}

void createRelationList(ListRelation &LR) {
    First(LR) = NULL;
}

adrRental createElmnRental(infotypeRental R) {
    adrRental P = new elmRental;
    Info(P) = R;
    Next(P) = NULL;
    Peminjaman(P) = NULL;
    return P;
}

adrKendaraan createElmnKendaraan(infotypeKendaraan K) {
    adrKendaraan P = new elmKendaraan;
    Info(P) = K;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}
adrRelation createElmnRelation(adrKendaraan K) {
    adrRelation P = new elmRelation;
    P->kendaraan = K;
    Next(P) = NULL;
    return P;
}

void insertElementParent_Rental(ListRental &LR, adrRental P) {
    if (FirstParent(LR) == NULL) {
        FirstParent(LR) = P;
    } else {
        adrRental Q = FirstParent(LR);
        while (NextParent(Q) != NULL) {
            Q = NextParent(Q);
        }
        NextParent(Q) = P;
    }
}

void insertElementChild_Kendaraan(ListKendaraan &LK, adrKendaraan P, infotypeKendaraan newKendaraan) {
    if (FirstChild(LK) == NULL) {
        createListKendaraan(LK);
        FirstChild(LK) = P;
        InfoChild(P) = newKendaraan;
    } else {
        adrKendaraan x = FirstChild(LK);
        while (NextChild(x) != NULL) {
            x = NextChild(x);
        }
        adrKendaraan newElm = createElmnKendaraan(newKendaraan);
        NextChild(x) = newElm;
        PrevChild(newElm) = x;
        cout << "Elemen baru berhasil ditambahkan ke List Kendaraan" << endl;
    }
}


void insertElementRelation_Relation(ListRelation &LR, adrRelation P) {
    if (FirstRelation(LR) == NULL) {
        FirstRelation(LR) = P;
        NextRelation(P) = NULL;
    } else {
        adrRelation currentRelation = FirstRelation(LR);
        while (NextRelation(currentRelation) != NULL) {
            currentRelation = NextRelation(currentRelation);
        }
        NextRelation(currentRelation) = P;
        NextRelation(P) = NULL;
    }
    cout << "Relation berhasil ditambahkan ke List Relation" << endl;
}
