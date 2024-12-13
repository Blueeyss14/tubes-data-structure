#include "rental_kendaraan.h"
void dataDummy(ListRelation &LRelasi, ListRental &LR, ListKendaraan &LKendaraan) {
    const int jumlahData = 10;
    infotypeRental rentals[jumlahData] = {
        {"Ayase", 7},
        {"Kiara", 5},
        {"Yui", 4},
        {"Ren", 6},
        {"Aoi", 3},
        {"Takumi", 8},
        {"Hikari", 5},
        {"Riku", 7},
        {"Mio", 6},
        {"Kaito", 4}
    };

    infotypeKendaraan kendaraans[jumlahData] = {
        {"Nissan_GT-R", "Sport", 1200000},
        {"Toyota_Supra", "Racing", 1100000},
        {"Mazda_RX-7", "Sport", 1150000},
        {"Honda_NSX", "Racing", 1300000},
        {"Mitsubishi_Lancer_Evo", "Sport", 1250000},
        {"Subaru_WRX_STI", "Racing", 1400000},
        {"Toyota_86", "Sport", 1100000},
        {"Nissan_370Z", "Racing", 1200000},
        {"Honda_Civic_Type_R", "Sport", 1050000},
        {"Mazda_MX-5", "Racing", 950000}
    };

    for (int i = 0; i < jumlahData; i++) {
        adrRental newRental = new elmRental;
        newRental->info = rentals[i];
        newRental->Next = NULL;
        newRental->Prev = NULL;

        adrKendaraan newKendaraan = new elmKendaraan;
        newKendaraan->info = kendaraans[i];
        newKendaraan->Next = NULL;

        if (FirstParent(LR) == NULL) {
            FirstParent(LR) = newRental;
            LastParent(LR) = newRental;
        } else {
            LastParent(LR)->Next = newRental;
            newRental->Prev = LastParent(LR);
            LastParent(LR) = newRental;
        }

        if (FirstChild(LKendaraan) == NULL) {
            FirstChild(LKendaraan) = newKendaraan;
        } else {
            adrKendaraan temp = FirstChild(LKendaraan);
            while (temp->Next != NULL) {
                temp = temp->Next;
            }
            temp->Next = newKendaraan;
        }

        adrRelation newRelation = new elmRelation;
        newRelation->Rental = newRental;
        newRelation->Kendaraan = newKendaraan;
        newRelation->Next = NULL;
        newRelation->Prev = NULL;

        if (FirstRelation(LRelasi) == NULL) {
            FirstRelation(LRelasi) = newRelation;
            LastRelation(LRelasi) = newRelation;
        } else {
            LastRelation(LRelasi)->Next = newRelation;
            newRelation->Prev = LastRelation(LRelasi);
            LastRelation(LRelasi) = newRelation;
        }
    }

    adrRelation P = FirstRelation(LRelasi);
    while (P != nullptr) {
        cout << "==========================================================" << endl;
        cout << "Peminjam: " << InfoParent(P->Rental).namaPemilk << endl;
        cout << "Lama Peminjaman: " << InfoParent(P->Rental).lamaPeminjaman << endl;
        cout << "Merk: " << InfoChild(P->Kendaraan).merk << endl;
        cout << "Type: " << InfoChild(P->Kendaraan).type << endl;
        cout << "Harga: Rp" << InfoChild(P->Kendaraan).harga << endl;
        cout << "==========================================================\n" << endl;
        P = NextRelation(P);
    }
}
