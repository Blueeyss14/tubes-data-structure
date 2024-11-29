//Sementara dalam pengerjaan Tugas Besar
//Sementara dalam pengerjaan Tugas Besar
//Sementara dalam pengerjaan Tugas Besar

#include <iostream>
#include "rental_kendaraan.h"
using namespace std;

void menuUtama() {
    cout << "=== APLIKASI RENTAL KENDARAAN ===" << endl;
    cout << "1. Tambah Data Rental" << endl;
    cout << "2. Tampilkan Semua Data" << endl;
    cout << "3. Cari Kendaraan" << endl;
    cout << "4. Hapus Data Rental" << endl;
    cout << "5. Urutkan Data" << endl;
    cout << "6. Cari Berdasarkan Range Harga" << endl;
    cout << "7. Hitung Total Pendapatan" << endl;
    cout << "8. Urutkan Data Harga" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}


void urutDataHarga(List &L) {
    string kriteria;
    int pilihan;
    address P;
    cout << "1. Urutkan dari harga Terendah" << endl;
    cout << "2. Urutkan dari harga Tertinggi" << endl;
    cout << "3. Urutkan dari Nama/Harga" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        urutHargaTerendah(L, P);
    }
    else if (pilihan == 2) {
        urutHargaTertinggi(L, P);
    }
    else if (pilihan == 3) {
        cout << "Urutkan berdasarkan (nama/harga): ";
        cin >> kriteria;
        sortKendaraan(L, kriteria);
        cout << "Data berhasil diurutkan!" << endl;
    }
}


int main() {
    List L;
    createList(L);
    int pilihan = -1;
    
    while (pilihan != 0) {
        menuUtama();
        cin >> pilihan;
        
        if (pilihan == 1) {
            infotype data;
            cout << "Nama Penyewa: ";
            cin >> data.nama;
            cout << "Merk Kendaraan: ";
            cin >> data.merk;
            cout << "Waktu Pinjam: ";
            cin >> data.waktu_pinjam;
            cout << "Waktu Pengembalian: ";
            cin >> data.waktu_pengembalian;
            cout << "Harga Sewa: ";
            cin >> data.harga;
            
            address P = createElement(data);
            insertLast(L, P);
            cout << "Data berhasil ditambahkan!" << endl;
        } 
        else if (pilihan == 2) {
            if (FIRST(L) == NULL) {
                cout << "Data kosong!" << endl;
            } else {
                cout << "\nData Kendaraan Terental:" << endl;
                showKendaraanTerental(L);
            }
        }
        else if (pilihan == 3) {
            string merk;
            cout << "Masukkan Merk Kendaraan: ";
            cin >> merk;
            
            address P = findData(L, merk);
            if (P != NULL) {
                cout << "Kendaraan ditemukan!" << endl;
                cout << "Nama Penyewa: " << INFO(P).nama << endl;
                cout << "Merk: " << INFO(P).merk << endl;
                cout << "Waktu Pinjam: " << INFO(P).waktu_pinjam << endl;
                cout << "Waktu Pengembalian: " << INFO(P).waktu_pengembalian << endl;
                cout << "Harga: Rp" << INFO(P).harga << endl;
            } else {
                cout << "Kendaraan tidak ditemukan!" << endl;
            }
        }
        else if (pilihan == 4) {
            string merk;
            cout << "Masukkan Merk Kendaraan yang akan dihapus: ";
            cin >> merk;
            deleteData(L, merk);
        }
        else if (pilihan == 5) {
            urutDataHarga(L);
        }
        else if (pilihan == 6) {
            int min_harga, max_harga;
            cout << "Masukkan range harga:" << endl;
            cout << "Minimal: ";
            cin >> min_harga;
            cout << "Maksimal: ";
            cin >> max_harga;
            cariKendaraanByHarga(L, min_harga, max_harga);
        }
        else if (pilihan == 7) {
            int total = hitungTotalPendapatan(L);
            cout << "Total Pendapatan: Rp" << total << endl;
        }
        else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
        
        cout << endl;
    }
    return 0;
}