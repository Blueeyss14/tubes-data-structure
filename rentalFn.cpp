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

void deleteRentalData(ListRental &LR, ListKendaraan &LK, ListRelation &LRelasi, string namaPeminjam, string namaPemilik, string merkKendaraan)
{
    adrRental rental = FirstParent(LR);
    adrKendaraan kendaraan = FirstChild(LK);
    adrRelation relasi = FirstRelation(LRelasi);

    while (relasi != NULL)
    {
        if (InfoParent(relasi->Rental).namaPemilk == namaPemilik &&
            InfoParent(relasi->Rental).namaPeminjam == namaPeminjam &&
            InfoChild(relasi->Kendaraan).merk == merkKendaraan)
        {

            deleteLastRelation_Relation(LRelasi, rental, kendaraan);
            cout << "Data relasi berhasil dihapus!" << endl;

            deleteLastParent_Rental(LR, rental);
            cout << "Data rental berhasil dihapus!" << endl;

            deleteLastChild_Kendaraan(LK, kendaraan);
            cout << "Data kendaraan berhasil dihapus!" << endl;

            return;
        }
        relasi = NextRelation(relasi);

        cout << "Data tidak ditemukan!" << endl;
    }
}