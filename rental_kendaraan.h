#ifndef RENTAL_KENDARAAN_H_INCLUDED
#define RENTAL_KENDARAAN_H_INCLUDED

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

#include <iostream>
using namespace std;
#include <string>

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

#endif // RENTAL_KENDARAAN_H_INCLUDED
