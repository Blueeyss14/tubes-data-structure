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
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    list L;
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
            if (first(L) == NULL) {
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
                cout << "Nama Penyewa: " << info(P).nama << endl;
                cout << "Merk: " << info(P).merk << endl;
                cout << "Waktu Pinjam: " << info(P).waktu_pinjam << endl;
                cout << "Waktu Pengembalian: " << info(P).waktu_pengembalian << endl;
                cout << "Harga: Rp" << info(P).harga << endl;
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
            string kriteria;
            cout << "Urutkan berdasarkan (nama/harga): ";
            cin >> kriteria;
            sortKendaraan(L, kriteria);
            cout << "Data berhasil diurutkan!" << endl;
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
            cout << "Terima kasih telah menggunakan sistem ini!" << endl;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
        
    }
    
    return 0;
}
