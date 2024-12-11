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
    string merk, type;
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
    adrRelation Prev;
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
adrKendaraan createElmnKendaraan(infotypeKendaraan K);
adrRelation createElmnRelation(adrRental R, adrKendaraan K);
void insertFirstParent_Rental(ListRental &LR, adrRental P);
void insertFirstChild_Kendaraan(ListKendaraan &LK, adrKendaraan P);
void insertFirstRelation_Relation(ListRelation &LR, adrRental P, adrKendaraan K);
void insertLastParent_Rental(ListRental &LR, adrRental P);
void insertLastChild_Kendaraan(ListKendaraan &LK, adrKendaraan P);
void insertLastRelation_Relation(ListRelation &LR, adrRental P, adrKendaraan K);
void insertAfterParent_Rental(ListRental &LR, adrRental Prec, adrRental P);
void insertAferChild_Kendaraan(ListKendaraan &LK, adrKendaraan Prec, adrKendaraan P);
void insertAfterRelation_Relation(ListRelation &LR, adrRelation Prec, adrRental P, adrKendaraan K);
void deleteFirstParent_Rental(ListRental &LR, adrRental &P);
void deleteFirstChild_Kendaraan(ListKendaraan &LK, adrKendaraan P);
void deleteFirstRelation_Relation(ListRelation &LR, adrRental &P, adrKendaraan &K);
void deleteLastParent_Rental(ListRental &LR, adrRental P);
void deleteLastChild_Kendaraan(ListKendaraan &LR, adrKendaraan P);
void deleteLastRelation_Relation(ListRelation &LR, adrRental &P, adrKendaraan &K);
void deleteAfterParent_Rental(ListRental &LR, adrRental Prec);
void deleteAfterChild_Kendaraan(ListKendaraan LK, adrKendaraan Prec, adrKendaraan P);
void deleteAfterRelation_Relation(ListRelation &LR, adrRelation Prec, adrRental P, adrKendaraan K);
adrRental findParent_Rental(ListRental &LR, string nama);
adrKendaraan findChild_Kendaraan(ListKendaraan &LK, string nama);
adrRelation findRelation_Relation(ListRelation &RL, adrRental R, adrKendaraan K);
void showAllDataParent_Rental(ListRental LR);
void showAllDataKendaraan_Kendaraan(ListKendaraan LK);
void showAllDataRelation_Relation(ListRelation LR);
void showDataChildFromParent(ListRental LR, ListRelation LRel, string namaParent);
void showDataParentChildRelation(ListRelation LR);
void showDataChildFromParent(ListRental LR, ListRelation LRel, string namaParent);
void showDataParentFromChild(ListRelation LR, ListKendaraan LK, string namaChild);
int countRelationFromElmnParent(ListRelation LR, adrRental parent);
int countRelationChild(ListRelation LR, adrKendaraan child);
int countElmnChild(ListKendaraan LK, ListRelation LR);
void editRelation(ListRelation &LR, ListKendaraan LK, adrRental parent, string namaChildBaru);
void urutkanDataBerdasarkanHarga(ListKendaraan &LK, ListRental &LR, ListRelation &LRelasi);
#endif
