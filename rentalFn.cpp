#include "rental_kendaraan.h"

void urutkanDataBerdasarkanHarga(ListKendaraan &LK, ListRental &LR, ListRelation &LRelasi)
{
    if (FirstChild(LK) == NULL)
        return;

    adrRelation currentRelasi = FirstRelation(LRelasi);
    while (currentRelasi != NULL)
    {
        adrRelation nextRelasi = NextRelation(currentRelasi);
        while (nextRelasi != NULL)
        {
            if (InfoChild(KendaraanRelation(currentRelasi)).harga > InfoChild(KendaraanRelation(nextRelasi)).harga)
            {
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

adrKendaraan cariKendaraanBerdasarkanHarga(ListKendaraan &LK, int harga)
{
    adrKendaraan current = FirstChild(LK);
    while (current != NULL)
    {
        if (InfoChild(current).harga == harga)
        {
            return current;
        }
        current = NextChild(current);
    }
    return NULL;
}

int hitungTotalPendapatanRental(ListRelation LRelasi)
{
    int totalPendapatan = 0;
    adrRelation relasi = FirstRelation(LRelasi);

    while (relasi != NULL)
    {
        adrRental rental = RentalRelation(relasi);
        if (InfoParent(rental).namaPeminjam != "")
        {
            totalPendapatan += InfoChild(KendaraanRelation(relasi)).harga;
        }
        relasi = NextRelation(relasi);
    }

    return totalPendapatan;
}

void deleteRentalData(ListRelation &LRelasi, ListRental &LR, ListKendaraan &LKendaraan, string namaPemilik, string merkKendaraan, string namaPeminjam) {
    adrRental rental = findParent_Rental(LR, namaPemilik);
    adrKendaraan kendaraan = findChild_Kendaraan(LKendaraan, merkKendaraan);
    
    if (rental != NULL && kendaraan != NULL) {
        adrRelation relasi = findRelation_Relation(LRelasi, rental, kendaraan);
        
        if (relasi != NULL && InfoParent(rental).namaPeminjam == namaPeminjam) {
            deleteFirstRelation_Relation(LRelasi, relasi);
            deleteFirstParent_Rental(LR, rental);
            deleteFirstChild_Kendaraan(LKendaraan, kendaraan);

            cout << "\n==========================================================" << endl;
            cout << "Data Rental Berhasil Dihapus!" << endl;
            cout << "==========================================================" << endl;
        } else {
            cout << "\n==========================================================" << endl;
            cout << "Data tidak ditemukan." << endl;
            cout << "==========================================================" << endl;
        }
    } else {
        cout << "\n==========================================================" << endl;
        cout << "Data Rental atau Kendaraan tidak ditemukan." << endl;
        cout << "==========================================================" << endl;
    }
}