#include "rental_kendaraan.h"
void createListRental(ListRental &LR) {
    FirstParent(LR) = NULL;
}

void createListKendaraan(ListKendaraan &LK) {
    FirstChild(LK) = NULL;
}

void createRelationList(ListRelation &LR) {
    FirstRelation(LR) = NULL;
}
//parent -> DLL
adrRental createElmnRental(infotypeRental R) {
    adrRental P = new elmRental;
    InfoParent(P) = R;
    NextParent(P) = NULL;
    PrevParent(P) = NULL;
    return P;
}
//child -> SLL
adrKendaraan createElmnKendaraan(infotypeKendaraan K) {
    adrKendaraan P = new elmKendaraan;
    InfoChild(P) = K;
    NextChild(P) = NULL;
    return P;
}
//relation -> MLL
adrRelation createElmnRelation(adrRental R, adrKendaraan K) {
    adrRelation P = new elmRelation;
    NextRelation(P) = NULL;
    RentalRelation(P) = R;
    KendaraanRelation(P) = K;
    return P;
}


void insertFirstParent_Rental(ListRental &LR, adrRental P) {
    if (FirstParent(LR) == NULL) {
        FirstParent(LR) = P;
        LastParent(LR) = P;
        NextParent(P) = NULL;
        PrevParent(P) = NULL;
    } else {
        NextParent(P) = FirstParent(LR);
        PrevParent(FirstParent(LR)) = P;
        FirstParent(LR) = P; 
    }
}

void insertFirstChild_Kendaraan(ListKendaraan &LK, adrKendaraan P) {
    if (FirstChild(LK) == NULL) {
        FirstChild(LK) = P;
    } else {
        NextChild(P) = FirstChild(LK);
        FirstChild(LK) = P;
    }
}

void insertFirstRelation_Relation(ListRelation &LR, adrRental P, adrKendaraan K) {
    adrRelation R = createElmnRelation(P, K);
    if (FirstRelation(LR) == NULL) {
        FirstRelation(LR) = R;
        LastRelation(LR) = R;
    } else {
        NextRelation(R) = FirstRelation(LR);
        FirstRelation(LR) = R;
    }
}