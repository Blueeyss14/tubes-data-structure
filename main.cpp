#include <iostream>
#include "rental_kendaraan.h"
using namespace std;

void menuUtama()
{
    cout << "=== APLIKASI RENTAL KENDARAAN ===" << endl;
    cout << "1. Tambah Data Rental" << endl;
    /*Point a, b, c
        > Saat program dijalankan maka akan diminta inputan dari parent, child & relasi
            pada aplikasi ini menggunakan:
            - insertFirstParent_Rental()
            - insertFirstChild_Kendaraan()
            - inserFirstRelation_Relation()
        > Ketiga fungsi ini bisa dilihat di "rental_kendaraan.cpp"
        > Lebih spesifik bisa dilihat di "main.cpp" pada pilihan == 1
    */
    cout << "2. Tampilkan Semua Data (Relasi)" << endl;
    /*
        > Menampilkan seluruh data termasuk dataDummy menggunakan relasi, parent dan child
            kasus mencakup tiga fungsi utama:
            - ShowAllParent()
            - ShowAllList()
            - ShowRelation()
        > Fungsi ini saling terhubung yang bisa dilihat di "rental_kendaraan.cpp"
        > Fungsi dataDummy bisa dilihat di "data_dummy.cpp"
        > Lebih spesifik bisa dilihat di "main.cpp" pada pilihan == 2
    */
    cout << "3. Cari Kendaraan" << endl;
    /*Point g, h, i
        > Program mencari data yang dimana ketika program meminta inputan dari find Parent, Child dan Relation
            - findParent_Rental()
            - findChild_Kendaraan()
            - findRelation_Relation()
        >Lebih spesifik bisa dilihat di "main.cpp" pada pilihan == 3
    */
    cout << "4. Urutkan Data Berdasarkan Harga" << endl;
    /*
        > Fungsi ini bisa dilihat di rentalFn.cpp
    */
    cout << "5. Rental Kendaraan" << endl;
    cout << "6. Daftar Kendaraan Terpinjam" << endl;
    cout << "7. Total Pendapatan Rental" << endl;
    /*
        > Fungsi ini bisa dilihat di rentalFn.cpp
    */
    cout << "8. Hapus Data Rental" << endl;
    /*Point d, e, f:
        deleteRentalData {
            berisi:
            - deleteParent
            - deleteRelasi
            - deleteChild
        }
        ketiga fungsi itu dipanggil ke deleteRentalData() yang bisa dilihat di "rentalFn.cpp"
        dan ketiga fungsi itu berada di "rental_kendaraan.cpp"
    */
   
   //Point j, k, l, m, n, o, p, q, r, s
    cout << "9. Show all data List Parent" << endl;
    cout << "10. Show all data List Child" << endl;
    cout << "11. Show data parent tertentu" << endl;
    cout << "12. Show data child tertentu" << endl;
    cout << "13. Show setiap data parent beserta data child yang bereleasi" << endl;
    cout << "14. Show data child beserta data parent yang masing masing child miliki" << endl;
    cout << "15. Count relation dari setiap element parent" << endl;
    cout << "16. Count relation yang dimiliki oleh child tertentu" << endl;
    cout << "17. Count element child yang tidak memiliki relasi" << endl;
    cout << "18. Edit relasi/mengganti child dari parent tertentu" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

int main()
{
    int index = 0;
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
            cout << "Nama Pemilik Kendaraan: ";
            cin >> rental.namaPemilk;
            cout << "Lama Pinjam (Jam): ";
            cin >> rental.lamaPeminjaman;

            infotypeKendaraan kendaraan;
            cout << "Merk Kendaraan: ";
            cin >> kendaraan.merk;
            cout << "Type Kendaraan: ";
            cin >> kendaraan.type;
            cout << "Harga Rental: ";
            cin >> kendaraan.harga;

            adrRental newRental = createElmnRental(rental);
            adrKendaraan newKendaraan = createElmnKendaraan(kendaraan);
            insertFirstParent_Rental(LR, newRental);
            insertFirstChild_Kendaraan(LK, newKendaraan);
            insertFirstRelation_Relation(LRelasi, newRental, newKendaraan);

            cout << "\n==========================================================" << endl;
            cout << "Data Rental Berhasil Ditambahkan!" << endl;
            cout << "==========================================================" << endl;
        }
        else if (pilihan == 2)
        {
            dataDummy(LRelasi, LR, LK);
            showAllDataRelation_Relation(LRelasi);
        }
        else if (pilihan == 3)
        {
            string namaPemilik;
            string merkKendaraan;

            cout << "Masukkan Nama Pemilik: ";
            cin >> namaPemilik;
            cout << "Masukkan Merk Kendaraan: ";
            cin >> merkKendaraan;

            adrRental rental = findParent_Rental(LR, namaPemilik);
            adrKendaraan kendaraan = findChild_Kendaraan(LK, merkKendaraan);

            adrRelation relasi = findRelation_Relation(LRelasi, rental, kendaraan);

            if (relasi != NULL)
            {
                cout << "\n==========================================================" << endl;
                cout << "Kendaraan Ditemukan" << endl;
                cout << "==========================================================" << endl;
                cout << "Pemilik: " << InfoParent(RentalRelation(relasi)).namaPemilk << endl;
                cout << "Lama Peminjaman: " << InfoParent(RentalRelation(relasi)).lamaPeminjaman << " jam" << endl;
                cout << "Nama Kendaraan: " << InfoChild(KendaraanRelation(relasi)).merk << endl;
                cout << "Type: " << InfoChild(KendaraanRelation(relasi)).type << endl;
                cout << "Harga Rental: " << InfoChild(KendaraanRelation(relasi)).harga << endl;
                cout << "==========================================================" << endl;
            }
            else
            {
                cout << "\n==========================================================" << endl;
                cout << "Data tidak ditemukan." << endl;
                cout << "==========================================================" << endl;
            }
        }
        else if (pilihan == 4)
        {
            urutkanDataBerdasarkanHarga(LK, LR, LRelasi);
            adrRental dataRental = FirstParent(LR);
            adrKendaraan dataKendaraan = FirstChild(LK);
            if (dataRental == NULL && dataKendaraan == NULL)
            {
                cout << "\n==========================================================" << endl;
                cout << "Tidak ada data kendaraan yang tersedia." << endl;
                cout << "==========================================================" << endl;
            }
            else
            {
                cout << "\n==========================================================" << endl;
                cout << "Data Berhasil diurutkan" << endl;
                cout << "==========================================================" << endl;
                while (dataRental != NULL && dataKendaraan != NULL)
                {
                    // cout << index++ << endl;
                    cout << "==========================================================" << endl;
                    cout << "Pemilik Kendaraan: " << InfoParent(dataRental).namaPemilk << endl;
                    cout << "Lama Peminjam: " << InfoParent(dataRental).lamaPeminjaman << endl;
                    cout << "Merk: " << InfoChild(dataKendaraan).merk << endl;
                    cout << "Tipe: " << InfoChild(dataKendaraan).type << endl;
                    cout << "Harga: " << InfoChild(dataKendaraan).harga << endl;
                    dataRental = NextParent(dataRental);
                    dataKendaraan = NextChild(dataKendaraan);
                    cout << "==========================================================\n"
                         << endl;
                }
            }
        }
        else if (pilihan == 5)
        {
            string namaPemilik, merkKendaraan, namaPeminjam;

            cout << "Masukkan Nama Peminjam: ";
            cin >> namaPeminjam;
            cout << "Masukkan Nama Pemilik: ";
            cin >> namaPemilik;
            cout << "Masukkan Merk Kendaraan: ";
            cin >> merkKendaraan;

            adrRental rental = findParent_Rental(LR, namaPemilik);
            adrKendaraan kendaraan = findChild_Kendaraan(LK, merkKendaraan);
            adrRelation relasi = findRelation_Relation(LRelasi, rental, kendaraan);

            if (rental == NULL || kendaraan == NULL || relasi == NULL)
            {
                cout << "\n==========================================================" << endl;
                cout << "Data tidak ditemukan atau kendaraan tidak tersedia." << endl;
                cout << "==========================================================" << endl;
            }
            else
            {
                if (InfoParent(rental).namaPeminjam != "")
                {
                    cout << "\n==========================================================" << endl;
                    cout << "Kendaraan sudah dipinjam oleh: " << InfoParent(rental).namaPeminjam << endl;
                    cout << "==========================================================" << endl;
                }
                else
                {
                    InfoParent(rental).namaPeminjam = namaPeminjam;
                    cout << "\n==========================================================" << endl;
                    cout << "Kendaraan berhasil dipinjam oleh: " << namaPeminjam << endl;
                    cout << "==========================================================" << endl;
                }
            }
        }
        else if (pilihan == 6)
        {
            cout << "\n==========================================================" << endl;
            cout << "            Daftar Kendaraan yang Sedang Dipinjam         " << endl;
            cout << "==========================================================" << endl;

            adrRental rental = FirstParent(LR);
            bool adaPeminjaman = false;

            while (rental != NULL)
            {
                if (InfoParent(rental).namaPeminjam != "")
                {
                    adaPeminjaman = true;
                    cout << "Nama Peminjam: " << InfoParent(rental).namaPeminjam << endl;
                    cout << "Nama Pemilik Kendaraan: " << InfoParent(rental).namaPemilk << endl;
                    cout << "Lama Peminjaman: " << InfoParent(rental).lamaPeminjaman << " jam" << endl;

                    adrRelation relasi = FirstRelation(LRelasi);
                    while (relasi != NULL)
                    {
                        if (RentalRelation(relasi) == rental)
                        {
                            cout << "Merk Kendaraan: " << InfoChild(KendaraanRelation(relasi)).merk << endl;
                            cout << "Type Kendaraan: " << InfoChild(KendaraanRelation(relasi)).type << endl;
                            cout << "Harga Rental: " << InfoChild(KendaraanRelation(relasi)).harga << endl;
                        }
                        relasi = NextRelation(relasi);
                    }

                    cout << "==========================================================" << endl;
                }
                rental = NextParent(rental);
            }

            if (!adaPeminjaman)
            {
            cout << "\n==========================================================" << endl;
                cout << "Tidak ada kendaraan yang sedang dipinjam." << endl;
                cout << "==========================================================" << endl;
            }
        }
        else if (pilihan == 7)
        {
            cout << "\n==========================================================" << endl;
            cout << "            Total Pendapatan Rental Kendaraan            " << endl;
            cout << "==========================================================" << endl;

            int totalPendapatan = hitungTotalPendapatanRental(LRelasi);

            cout << "Total Pendapatan Rental: " << totalPendapatan << " IDR" << endl;
            cout << "==========================================================" << endl;
        }
        else if (pilihan == 8)
        {
            string namaPeminjam, namaPemilik, merkKendaraan;

            cout << "Masukkan Nama Peminjam: ";
            cin >> namaPeminjam;
            cout << "Masukkan Nama Pemilik: ";
            cin >> namaPemilik;
            cout << "Masukkan Merk Kendaraan: ";
            cin >> merkKendaraan;

            deleteRentalData(LRelasi, LR, LK, namaPemilik, merkKendaraan, namaPeminjam);
        }

        else if (pilihan == 9) {
            showAllDataParent_Rental(LR);
        }
        else if (pilihan == 10) {
            showAllDataKendaraan_Kendaraan(LK);
        }
        else if (pilihan == 11)
        {
            string namaKendaraan;
            cout << "Masukkan Nama Kendaraan (Parent): ";
            cin >> namaKendaraan;

            showDataParentFromChild(LRelasi, LK, namaKendaraan);
        }

        else if (pilihan == 12)
        {
            string namaChild;
            cout << "Masukkan Nama Pemilik (Child): ";
            cin >> namaChild;

            showDataChildFromParent(LR, LRelasi, namaChild);
        }
        else if (pilihan == 13)
        {
            showDataParentChildRelation(LRelasi);
        }

        else if (pilihan == 14)
        {
            showDataChildParentRelation(LRelasi);
        }
        else if (pilihan == 15)
        {
            countRelationFromEveryParent(LR, LRelasi);
        }
        else if (pilihan == 16)
        {
            string merkKendaraan;
            cout << "Masukkan Merk Kendaraan: ";
            cin >> merkKendaraan;

            adrKendaraan child = findChild_Kendaraan(LK, merkKendaraan);
            if (child != NULL)
            {
                int jumlahRelasi = countRelationChild(LRelasi, child);
                cout << "\n==========================================================" << endl;
                cout << "Kendaraan " << merkKendaraan << " memiliki " << jumlahRelasi << " relasi" << endl;
                cout << "==========================================================" << endl;
            }
            else
            {
                cout << "\n==========================================================" << endl;
                cout << "Kendaraan dengan merk " << merkKendaraan << " tidak ditemukan" << endl;
                cout << "==========================================================" << endl;
            }
        }
        else if (pilihan == 17)
        {
            int jumlahChildTanpaRelasi = countElmnChildNoRelation(LK, LRelasi);
            cout << "\n==========================================================" << endl;
            cout << "Jumlah kendaraan yang tidak memiliki relasi: " << jumlahChildTanpaRelasi << endl;
            cout << "==========================================================" << endl;
        }
        else if (pilihan == 18)
        {
            string namaPemilik, merkKendaraanBaru;
            cout << "Masukkan Nama Pemilik: ";
            cin >> namaPemilik;
            cout << "Masukkan Merk Kendaraan Baru: ";
            cin >> merkKendaraanBaru;

            adrRental parent = findParent_Rental(LR, namaPemilik);
            if (parent != NULL)
            {
                editRelation(LRelasi, LK, parent, merkKendaraanBaru);
            }
            else
            {
                cout << "\n==========================================================" << endl;
                cout << "Pemilik dengan nama " << namaPemilik << " tidak ditemukan" << endl;
                cout << "==========================================================" << endl;
            }
        }
        else if (pilihan == 0)
        {
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
