#ifndef RENTAL_KENDARAAN_H_INCLUDED
#define RENTAL_KENDARAAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct rentalKendaraan {
    string nama;
    string merk, waktu_pinjam, waktu_pengembalian;
    int harga;
};

typedef rentalKendaraan infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

#define list_first(L) L.first
#define list_last(L) L.last
#define list_next(P) P->next
#define list_prev(P) P->prev
#define list_info(P) P->info

void createList(list &L);
address createElement(infotype data);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address Q, address P);
void deleteFirst(list &L);
void deleteLast(list &L);
void deleteAfter(list &L, address Q);
address findData(list &L, string merkKendaraan);
void deleteData(list &L, string data);
void sortKendaraan(list &L, string kriteria);
int hitungTotalPendapatan(list L);
void showKendaraanTerental(list L);
void cariKendaraanByHarga(list L, int min_harga, int max_harga);
bool kendaraanTersedia(list L, string merk);

#endif 
