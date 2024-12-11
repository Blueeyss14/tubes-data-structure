#include <iostream>
#include "rental_kendaraan.h"
using namespace std;

void menuUtama()
{
    cout << "=== APLIKASI RENTAL KENDARAAN ===" << endl;
    cout << "1. Tambah Data Rental" << endl;
    cout << "2. Tampilkan Semua Data" << endl;
    cout << "3. Cari Kendaraan" << endl;
    cout << "4. Delete Data Rental Kendaraan" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

int main()
{
    int pilihan = -1;
    ListRental LR;
    ListKendaraan LK;
    ListRelation LRelasi;

    createListRental(LR);
    createListKendaraan(LK);
    createRelationList(LRelasi);

    int indexKendaraan = 1;

    while (pilihan != 0)
    {
        menuUtama();
        cin >> pilihan;

        if (pilihan == 1)
        {
            infotypeRental rental;
            cout << "Nama Peminjam: ";
            cin >> rental.namaPeminjam;
            cout << "Lama Pinjam (Jam): ";
            cin >> rental.lamaPeminjaman;

            infotypeKendaraan kendaraan;
            cout << "Merk Kendaraan: ";
            cin >> kendaraan.merk;
            cout << "Type Kendaraan: ";
            cin >> kendaraan.type;
            cout << "Harga Kendaraan: ";
            cin >> kendaraan.harga;

            adrRental newRental = createElmnRental(rental);
            adrKendaraan newKendaraan = createElmnKendaraan(kendaraan);
            insertFirstParent_Rental(LR, newRental);
            insertFirstChild_Kendaraan(LK, newKendaraan);
            insertFirstRelation_Relation(LRelasi, newRental, newKendaraan);

            cout << "Data Rental Berhasil Ditambahkan!" << endl;
        }
        else if (pilihan == 2)
        {
            showAllDataRelation_Relation(LRelasi);
        }
        else if (pilihan == 3)
        {
            string namaPeminjam;
            string merkKendaraan;

            cout << "Masukkan Nama Peminjam: ";
            cin >> namaPeminjam;
            cout << "Masukkan Merk Kendaraan: ";
            cin >> merkKendaraan;

            adrRental rental = findParent_Rental(LR, namaPeminjam);
            adrKendaraan kendaraan = findChild_Kendaraan(LK, merkKendaraan);

            adrRelation relasi = findRelation_Relation(LRelasi, rental, kendaraan);

            if (relasi != NULL)
            {
                cout << "\n==========================================================" << endl;
                cout << "Kendaraan Ditemukan" << endl;
                cout << "==========================================================" << endl;
                cout << "Peminjam: " << InfoParent(RentalRelation(relasi)).namaPeminjam << endl;
                cout << "Lama Peminjaman: " << InfoParent(RentalRelation(relasi)).lamaPeminjaman << " jam" << endl;
                cout << "Nama Kendaraan: " << InfoChild(KendaraanRelation(relasi)).merk << endl;
                cout << "Type: " << InfoChild(KendaraanRelation(relasi)).type << endl;
                cout << "Harga: " << InfoChild(KendaraanRelation(relasi)).harga << endl;
                cout << "==========================================================" << endl;

            }
            else
            {
                cout << "\n==========================================================" << endl;
                cout << "Data tidak ditemukan." << endl;
                cout << "==========================================================" << endl;
            }
        } else if (pilihan == 4) {
            
            
        } else if (pilihan == 0) {
            cout << "\n==========================================================" << endl;
            cout << "Terimakasih Telah Mengunjungi Aplikasi Rental Kendaraan ini" << endl;
            cout << "==========================================================" << endl;
        }
        else
        {
            cout << "\n==========================================================" << endl;
            cout << "Pilihan tidak valid, silakan masukkan ulang" << endl;
            cout << "==========================================================" << endl;

        }
    }
    return 0;
}
