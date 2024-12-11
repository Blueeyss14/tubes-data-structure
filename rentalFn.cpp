#include "rental_kendaraan.h"

void urutkanDataBerdasarkanHarga(ListKendaraan &LK, ListRental &LR, ListRelation &LRelasi) {
    if (FirstChild(LK) == NULL) return;

    adrRelation currentRelasi = FirstRelation(LRelasi);
    while (currentRelasi != NULL) {
        adrRelation nextRelasi = NextRelation(currentRelasi);
        while (nextRelasi != NULL) {
            if (InfoChild(KendaraanRelation(currentRelasi)).harga > InfoChild(KendaraanRelation(nextRelasi)).harga) {
                kendaraan tempKendaraan = InfoChild(KendaraanRelation(currentRelasi));
                InfoChild(KendaraanRelation(currentRelasi)) = InfoChild(KendaraanRelation(nextRelasi));
                InfoChild(KendaraanRelation(nextRelasi)) = tempKendaraan;

                rental tempRental = InfoParent(RentalRelation(currentRelasi));
                InfoParent(RentalRelation(currentRelasi)) = InfoParent(RentalRelation(nextRelasi));
                InfoParent(RentalRelation(nextRelasi)) = tempRental;
            }
            nextRelasi = NextRelation(nextRelasi);
        }
        currentRelasi = NextRelation(currentRelasi);
    }
}


adrKendaraan cariKendaraanBerdasarkanHarga(ListKendaraan &LK, int harga) {
    adrKendaraan current = FirstChild(LK);
    while (current != NULL) {
        if (InfoChild(current).harga == harga) {
            return current;
        }
        current = NextChild(current);
    }
    return NULL;
}