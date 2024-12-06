#ifndef RENTAL_KENDARAAN_H_INCLUDED
#define RENTAL_KENDARAAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define First(p) p.First
#define Info(p) (p)->info
#define Next(p) (p)->Next
#define Prev(p) p->Prev


#define Peminjaman(p) (p)->peminjaman

#define FirstParent(p) p.First
#define InfoParent(p) p->info
#define NextParent(p) p->Next

#define FirstChild(L) L.First
#define InfoChild(p) p->info
#define LastChild(L) L.Last
#define NextChild(p) p->Next
#define PrevChild(p) p->Prev

#define FirstRelation(L) L.First
#define InfoRelation(p) p->info
#define LastRelation(L) L.Last
#define NextRelation(p) p->Next
#define PrevRelation(p) p->Prev


struct rental {
    string namaPeminjam;
    int lamaPeminjaman;
    bool isTersedia;
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
    adrRelation peminjaman;
};

struct elmKendaraan {
    infotypeKendaraan info;
    adrKendaraan Prev;
    adrKendaraan Next;
};

struct elmRelation {
    adrRelation Next;
    adrKendaraan kendaraan;
};

struct ListRental {
    adrRental First;
};

struct ListKendaraan {
    adrKendaraan First;
};

struct ListRelation {
    adrRelation First;
};

void createListRental(ListRental &LR);
void createListKendaraan(ListKendaraan &LK);
void createRelationList(ListRelation &LR);
adrRental createElmnRental(infotypeRental R);

void insertElementParent_Rental(ListRental &LR, adrRental P);
void insertElementChild_Kendaraan(ListKendaraan &LK, adrKendaraan P, infotypeKendaraan newKendaraan);
void insertElementRelation_Relation(ListRelation &LR, adrRelation P);
#endif
