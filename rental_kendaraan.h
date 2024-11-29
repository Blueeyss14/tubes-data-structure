#ifndef RENTAL_KENDARAAN_H_INCLUDED
#define RENTAL_KENDARAAN_H_INCLUDED

#define FIRST(L) L.first
#define LAST(L) L.last
#define NEXT(P) P->next
#define PREV(P) P->prev
#define INFO(P) P->info

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

struct List {
    address first;
    address last;
};



void createList(List &L);
address createElement(infotype data);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Q, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Q);
address findData(List &L, string merkKendaraan);
void deleteData(List &L, string data);
void sortKendaraan(List &L, string kriteria);
int hitungTotalPendapatan(List L);
void showKendaraanTerental(List L);
void cariKendaraanByHarga(List L, int min_harga, int max_harga);
bool kendaraanTersedia(List L, string merk);
void urutHargaTerendah(List &L, address P);
void urutHargaTertinggi(List &L, address P);

#endif 