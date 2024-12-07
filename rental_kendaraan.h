#ifndef RENTAL_KENDARAAN_H_INCLUDED
#define RENTAL_KENDARAAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;


#define Peminjaman(p) (p)->peminjaman

//DLL
#define FirstParent(L) L.First
#define LastParent(L) L.Last
#define InfoParent(p) p->info
#define NextParent(p) p->Next
#define PrevParent(p) p->Prev

//SLL
#define FirstChild(L) L.First
#define InfoChild(p) p->info
#define NextChild(p) p->Next
#define PrevChild(p) p->Prev

//MLL
#define FirstRelation(L) L.First
#define InfoRelation(p) p->info
#define LastRelation(L) L.Last
#define NextRelation(p) p->Next
#define PrevRelation(p) p->Prev
#define RentalRelation(p) p->Rental
#define KendaraanRelation(p) p->Kendaraan



struct rental {
    string namaPeminjam;
    int lamaPeminjaman;
};

struct kendaraan {
    string nama, type;
    int harga;
};

typedef rental infotypeRental;
typedef kendaraan infotypeKendaraan;

typedef struct elmRental *adrRental;
typedef struct elmKendaraan *adrKendaraan;
typedef struct elmRelation *adrRelation;

struct elmRental {
    infotypeRental info;
    adrRental Next;
    adrRental Prev;
};

struct elmKendaraan {
    infotypeKendaraan info;
    adrKendaraan Next;
};

struct elmRelation {
    adrRelation Next;
    adrRental Rental;
    adrKendaraan Kendaraan;
};

struct ListRental {
    adrRental First;
    adrRental Last;
};

struct ListKendaraan {
    adrKendaraan First;
};

struct ListRelation {
    adrRelation First;
    adrRelation Last;
};

void createListRental(ListRental &LR);
void createListKendaraan(ListKendaraan &LK);
void createRelationList(ListRelation &LR);
adrRental createElmnRental(infotypeRental R);

void insertElementParent_Rental(ListRental &LR, adrRental P);
void insertElementChild_Kendaraan(ListKendaraan &LK, adrKendaraan P, infotypeKendaraan newKendaraan);
void insertElementRelation_Relation(ListRelation &LR, adrRelation P);
#endif
