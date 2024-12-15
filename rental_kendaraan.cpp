#include "rental_kendaraan.h"
void createListRental(ListRental &LR) {
    FirstParent(LR) = NULL;
}

void createListKendaraan(ListKendaraan &LK) {
    FirstChild(LK) = NULL;
}

void createRelationList(ListRelation &LR) {
    FirstRelation(LR) = NULL;
    LastRelation(LR) = NULL;
}
//parent -> DLL
adrRental createElmnRental(infotypeRental R) {
    adrRental P = new elmRental;
    InfoParent(P) = R;
    NextParent(P) = NULL;
    PrevParent(P) = NULL;
    return P;
}
//child -> SLL
adrKendaraan createElmnKendaraan(infotypeKendaraan K) {
    adrKendaraan P = new elmKendaraan;
    InfoChild(P) = K;
    NextChild(P) = NULL;
    return P;
}
//relation -> MLL
adrRelation createElmnRelation(adrRental R, adrKendaraan K) {
    adrRelation P = new elmRelation;
    NextRelation(P) = NULL;
    RentalRelation(P) = R;
    KendaraanRelation(P) = K;
    return P;
}


void insertFirstParent_Rental(ListRental &LR, adrRental P) {
    if (FirstParent(LR) == NULL) {
        FirstParent(LR) = P;
        LastParent(LR) = P;
        NextParent(P) = NULL;
        PrevParent(P) = NULL;
    } else {
        NextParent(P) = FirstParent(LR);
        PrevParent(FirstParent(LR)) = P;
        FirstParent(LR) = P; 
    }
}

void insertFirstChild_Kendaraan(ListKendaraan &LK, adrKendaraan P) {
    if (FirstChild(LK) == NULL) {
        FirstChild(LK) = P;
    } else {
        NextChild(P) = FirstChild(LK);
        FirstChild(LK) = P;
    }
}

void insertFirstRelation_Relation(ListRelation &LR, adrRental P, adrKendaraan K) {
    adrRelation R = createElmnRelation(P, K);
    if (FirstRelation(LR) == NULL) {
        FirstRelation(LR) = R;
        LastRelation(LR) = R;
    } else {
        NextRelation(R) = FirstRelation(LR);
        FirstRelation(LR) = R;
    }
}

void insertLastParent_Rental(ListRental &LR, adrRental P) {
    if (FirstParent(LR) == NULL) {
        FirstParent(LR) = P;
        LastParent(LR) = P;
        NextParent(P) = NULL;
        PrevParent(P) = NULL;
    } else {
        NextParent(LastParent(LR)) = P;
        PrevParent(P) = LastParent(LR);
        LastParent(LR) = P;
        NextParent(P) = NULL;
    }
}
void insertLastChild_Kendaraan(ListKendaraan &LK, adrKendaraan P) {
    adrKendaraan x;

    if (FirstChild(LK) == NULL) {
        FirstChild(LK) = P;
    } else {
        x = FirstChild(LK);
        while (NextChild(x) != NULL) {
            x = NextChild(x);
        }
        NextChild(x) = P;
    }
}

void insertLastRelation_Relation(ListRelation &LR, adrRental P, adrKendaraan K) {
    adrRelation R = createElmnRelation(P, K);
    if (FirstRelation(LR) == NULL) {
        FirstRelation(LR) = R;
        LastRelation(LR) = R;
    } else {
        NextRelation(LastRelation(LR)) = R;
        LastRelation(LR) = R;
    }
}

void insertAfterParent_Rental(ListRental &LR, adrRental Prec, adrRental P) {
    if (NextParent(Prec) != NULL) {
        NextParent(P) = NextParent(Prec);
        PrevParent(NextParent(Prec)) = P;
        NextParent(Prec) = P;
        PrevParent(P) = Prec;
    } else {
        NextParent(Prec) = P;
        PrevParent(P) = Prec;
        LastParent(LR) = P;
    }
}

void insertAferChild_Kendaraan(ListKendaraan &LK, adrKendaraan Prec, adrKendaraan P) {
    if (NextChild(Prec) != NULL) {
        NextChild(P) = NextChild(Prec);
        NextChild(Prec) = P;
    } else {
        NextChild(Prec) = P;
    }
}

void insertAfterRelation_Relation(ListRelation &LR, adrRelation Prec, adrRental P, adrKendaraan K) {
    adrRelation R = createElmnRelation(P, K);
    if (NextRelation(Prec) != NULL) {
        NextRelation(R) = NextRelation(Prec);
        NextRelation(Prec) = R;
    } else {
        NextRelation(Prec) = R;
        LastRelation(LR) = R;
    }
}

void deleteFirstParent_Rental(ListRental &LR, adrRental rental) {
    if (rental == FirstParent(LR)) {
        FirstParent(LR) = NextParent(rental);
        if (FirstParent(LR) != NULL) {
            PrevParent(FirstParent(LR)) = NULL;
        }
    } else {
        if (NextParent(rental) != NULL) {
            PrevParent(NextParent(rental)) = PrevParent(rental);
        }
        if (PrevParent(rental) != NULL) {
            NextParent(PrevParent(rental)) = NextParent(rental);
        }
    }
}

void deleteFirstChild_Kendaraan(ListKendaraan &LK, adrKendaraan kendaraan) {
    if (kendaraan == FirstChild(LK)) {
        FirstChild(LK) = NextChild(kendaraan);
    } else {
        adrKendaraan prev = FirstChild(LK);
        while (prev != NULL && NextChild(prev) != kendaraan) {
            prev = NextChild(prev);
        }
        if (prev != NULL) {
            NextChild(prev) = NextChild(kendaraan);
        }
    }
}

void deleteFirstRelation_Relation(ListRelation &LRelasi, adrRelation relasi) {
    if (relasi == FirstRelation(LRelasi)) {
        FirstRelation(LRelasi) = NextRelation(relasi);
        if (FirstRelation(LRelasi) != NULL) {
            PrevRelation(FirstRelation(LRelasi)) = NULL;
        }
    } else {
        if (NextRelation(relasi) != NULL) {
            PrevRelation(NextRelation(relasi)) = PrevRelation(relasi);
        }
        if (PrevRelation(relasi) != NULL) {
            NextRelation(PrevRelation(relasi)) = NextRelation(relasi);
        }
    }
}



void deleteLastParent_Rental(ListRental &LR, adrRental P) {
    if (LastParent(LR) != NULL) {
        P = LastParent(LR);
        LastParent(LR) = PrevParent(P);
        if (LastParent(LR) != NULL) {
            NextParent(LastParent(LR)) = NULL;
        }
        PrevParent(P) = NULL;
        NextParent(P) = NULL;
    }
}


void deleteLastChild_Kendaraan(ListKendaraan &LR, adrKendaraan P) {
    adrKendaraan x;

    if (FirstChild(LR) != NULL) {
        if (NextChild(FirstChild(LR)) != NULL) {
            x = FirstChild(LR);

            while (NextChild(NextChild(x)) != NULL) {
                x = NextChild(x);
            }
            P = NextChild(x);
            NextChild(x) = NULL;
        } else {
            P = FirstChild(LR);
            FirstChild(LR) = NULL;
        }
    } else {
        P = NULL;
    }
}

void deleteLastRelation_Relation(ListRelation &LR, adrRental &P, adrKendaraan &K) {
    if (FirstRelation(LR) != NULL) {
        adrRelation R = FirstRelation(LR);
        adrRelation lastRel = NULL;

        while (NextRelation(R) != NULL) {
            lastRel = R;
            R = NextRelation(R);
        }

        P = RentalRelation(R);
        K = KendaraanRelation(R);

        if (lastRel == NULL) {
            FirstRelation(LR) = NULL;
            LastRelation(LR) = NULL;
        } else {
            NextRelation(lastRel) = NULL;
            LastRelation(LR) = lastRel;
        }
        NextRelation(R) = NULL;
        RentalRelation(R) = NULL;
        KendaraanRelation(R) = NULL;
    }
}


void deleteAfterParent_Rental(ListRental &LR, adrRental Prec) {
    if (NextParent(Prec) != NULL) {
        adrRental P = NextParent(Prec);
        NextParent(Prec) = NextParent(P);
        if (NextParent(P) != NULL) {
            PrevParent(NextParent(P)) = Prec;
        } else {
            LastParent(LR) = Prec;
        }
        NextParent(P) = NULL;
        PrevParent(P) = NULL;
    }
}

void deleteAfterChild_Kendaraan(ListKendaraan LK, adrKendaraan Prec, adrKendaraan P) {
    if (NextChild(Prec) != NULL) {
        adrKendaraan P = NextChild(Prec);
        NextChild(Prec) = NextChild(P);
        NextChild(P) = NULL;
    }
}

void deleteAfterRelation_Relation(ListRelation &LR, adrRelation Prec, adrRental P, adrKendaraan K) {
    if (NextRelation(Prec) != NULL) {
        adrRelation R = NextRelation(Prec);
        P = RentalRelation(R); 
        K = KendaraanRelation(R);
        NextRelation(Prec) = NextRelation(R);
        if (NextRelation(R) != NULL) {
            PrevRelation(NextRelation(R)) = Prec;
        } else {
            LastRelation(LR) = Prec;        
        }
        NextRelation(R) = NULL;
    }
}



adrRental findParent_Rental(ListRental &LR, string nama) {
    adrRental P;
    P = FirstParent(LR);
    while (P!=NULL) {
        if (InfoParent(P).namaPemilk == nama) {
            return P;
        }
        P = NextParent(P);
    }
    return P;
}

adrKendaraan findChild_Kendaraan(ListKendaraan &LK, string merkKendaraan) {
    adrKendaraan P;
    P = FirstChild(LK);
    while (P != NULL) {
        if (InfoChild(P).merk == merkKendaraan) {
            return P;
        }
        P = NextChild(P);
    }
    return P;
}


adrRelation findRelation_Relation(ListRelation &RL, adrRental R, adrKendaraan K) {
    adrRelation P = FirstRelation(RL);
    while (P != NULL) {
        if (RentalRelation(P) == R && KendaraanRelation(P) == K) {
            return P;
        }
        P = NextRelation(P);
    }
    return NULL;
}

void showAllDataParent_Rental(ListRental LR) {
    adrRental P;
    if (FirstParent(LR) != NULL) {
        P = FirstParent(LR);

        while (P != NULL) {
            cout << "\n==========================================================" << endl;
            cout <<"Pemilik: "<< InfoParent(P).namaPemilk << endl;
            cout << "Lama Peminjaman: " << InfoParent(P).lamaPeminjaman << endl;
            cout << "==========================================================" << endl;
            P = NextParent(P);
        }
    } else {
        cout << "List Kosong" << endl;
    }
}

void showAllDataKendaraan_Kendaraan(ListKendaraan LK) {
    adrKendaraan P;
    if (FirstChild(LK) != NULL) {
        P = FirstChild(LK);

        while (P != NULL) {
            cout << "\n==========================================================" << endl;
            cout << "Nama Kendaraan" << InfoChild(P).merk << endl;
            cout << "Type"<< InfoChild(P).type << endl;
            cout << InfoChild(P).harga << endl;
            cout << "==========================================================" << endl;
            P = NextChild(P);
        }
    } else {
        cout << "List Kosong" << endl;
    }
}

void showAllDataRelation_Relation(ListRelation LR) {
    adrRelation P;
    if (FirstRelation(LR) != NULL) {
        P = FirstRelation(LR);
        while (P != NULL) {
            cout << "\n==========================================================" << endl;
            cout << "Peminjam: " << InfoParent(RentalRelation(P)).namaPemilk << endl;
            cout << "Lama Peminjaman: " << InfoParent(RentalRelation(P)).lamaPeminjaman << endl;

            cout << "Merk: " << InfoChild(KendaraanRelation(P)).merk << endl;
            cout << "Type: " << InfoChild(KendaraanRelation(P)).type << endl;
            cout << "Harga: " << InfoChild(KendaraanRelation(P)).harga << endl;
            cout << "==========================================================\n" << endl;
            P = NextRelation(P);
        }
    } else {
        cout << "List Kosong" << endl;
    }
}


void showDataChildFromParent(ListRental LR, ListRelation LRel, string namaParent) {
    // show data child dari parent tertentu

    adrRental parent = findParent_Rental(LR, namaParent);
    if (parent != NULL) {
        adrRelation rel = FirstRelation(LRel);
        bool found = false;

        while (rel != NULL) {
            if (RentalRelation(rel) == parent) { 
                adrKendaraan child = KendaraanRelation(rel);
                cout << "\n==========================================================" << endl;
                cout << "Nama Kendaraan: " << InfoParent(child).merk << endl;
                cout << "Tipe: " << InfoParent(child).type << endl;
                cout << "Harga: " << InfoParent(child).harga << endl;
                cout << "==========================================================" << endl;
                found = true;
            }
            rel = NextRelation(rel);
        }

        if (!found) {
            cout << "\n==========================================================" << endl;
            cout << "Tidak ada kendaraan untuk peminjam ini." << endl;
            cout << "==========================================================" << endl;
        }
    } else {
        cout << "\n==========================================================" << endl;
        cout << "Peminjam tidak ditemukan." << endl;
        cout << "==========================================================" << endl;
    }
}

void showDataParentChildRelation(ListRelation LR) {
    if (FirstRelation(LR) == NULL) {
        cout << "\n==========================================================" << endl;
        cout << "Tidak ada data relasi" << endl;
        cout << "==========================================================" << endl;
        return;
    }

    adrRelation P = FirstRelation(LR);
    adrRental currentParent = NULL;
    int count = 1;

    cout << "\n==========================================================" << endl;
    cout << "        Data Parent dan Child yang Berelasi        " << endl;
    cout << "==========================================================" << endl;

    while (P != NULL) {
        if (currentParent != RentalRelation(P)) {
            currentParent = RentalRelation(P);
            cout << "\nData Parent ke-" << count << endl;
            cout << "Nama Pemilik: " << InfoParent(RentalRelation(P)).namaPemilk << endl;
            cout << "Lama Peminjaman: " << InfoParent(RentalRelation(P)).lamaPeminjaman << " jam" << endl;
            if (InfoParent(RentalRelation(P)).namaPeminjam != "") {
                cout << "Nama Peminjam: " << InfoParent(RentalRelation(P)).namaPeminjam << endl;
            }
            cout << "\nKendaraan yang dimiliki:" << endl;
            count++;
        }

        cout << "- Merk: " << InfoChild(KendaraanRelation(P)).merk << endl;
        cout << "  Type: " << InfoChild(KendaraanRelation(P)).type << endl;
        cout << "  Harga: Rp" << InfoChild(KendaraanRelation(P)).harga << endl;

        P = NextRelation(P);
    }
    cout << "==========================================================" << endl;
}

void showDataChildParentRelation(ListRelation LR) {
    if (FirstRelation(LR) == NULL) {
        cout << "\n==========================================================" << endl;
        cout << "Tidak ada data relasi" << endl;
        cout << "==========================================================" << endl;
        return;
    }

    adrRelation P = FirstRelation(LR);
    adrKendaraan currentChild = NULL;
    int count = 1;

    cout << "\n==========================================================" << endl;
    cout << "        Data Kendaraan dan Pemiliknya        " << endl;
    cout << "==========================================================" << endl;

    while (P != NULL) {
        if (currentChild != KendaraanRelation(P)) {
            currentChild = KendaraanRelation(P);
            cout << "\nData Kendaraan ke-" << count << endl;
            cout << "Merk: " << InfoChild(KendaraanRelation(P)).merk << endl;
            cout << "Type: " << InfoChild(KendaraanRelation(P)).type << endl;
            cout << "Harga: Rp" << InfoChild(KendaraanRelation(P)).harga << endl;
            cout << "\nDimiliki oleh:" << endl;
            count++;
        }

        cout << "- Nama Pemilik: " << InfoParent(RentalRelation(P)).namaPemilk << endl;
        cout << "  Lama Peminjaman: " << InfoParent(RentalRelation(P)).lamaPeminjaman << " jam" << endl;
        if (InfoParent(RentalRelation(P)).namaPeminjam != "") {
            cout << "  Dipinjam oleh: " << InfoParent(RentalRelation(P)).namaPeminjam << endl;
        }

        P = NextRelation(P);
    }
    cout << "==========================================================" << endl;
}

void showDataParentFromChild(ListRelation LR, ListKendaraan LK, string namaChild) {
    // Show data parent yang berelasi dengan child tertentu

    adrKendaraan child = findChild_Kendaraan(LK, namaChild);
    if (child != NULL) {
        adrRelation P = FirstRelation(LR);
        bool found = false;

        while (P != NULL) {
            if (KendaraanRelation(P) == child) {
                cout << "\n==========================================================" << endl;
                cout << "Pemilik: " << InfoParent(RentalRelation(P)).namaPemilk << endl;
                cout << "Lama Peminjaman: " << InfoParent(RentalRelation(P)).lamaPeminjaman << endl;
                cout << "==========================================================" << endl;
                found = true;
            }
            P = NextRelation(P);
        }
        if (!found) {
            cout << "\n==========================================================" << endl;
            cout << "Tidak ada peminjam untuk kendaraan ini." << endl;
            cout << "==========================================================" << endl;
        }
    } else {
        cout << "\n==========================================================" << endl;
        cout << "Kendaraan tidak ditemukan." << endl;
        cout << "==========================================================" << endl;
    }
}

void countRelationFromEveryParent(ListRental LR, ListRelation LRel) {
    if (FirstParent(LR) == NULL) {
        cout << "\n==========================================================" << endl;
        cout << "Tidak ada data parent" << endl;
        cout << "==========================================================" << endl;
        return;
    }

    cout << "\n==========================================================" << endl;
    cout << "    Jumlah Relasi dari Setiap Parent (Pemilik Kendaraan)    " << endl;
    cout << "==========================================================" << endl;

    adrRental P = FirstParent(LR);
    int totalParent = 0;
    int totalRelasi = 0;

    while (P != NULL) {
        int count = countRelationFromElmnParent(LRel, P);
        totalParent++;
        totalRelasi += count;

        cout << "Parent ke-" << totalParent << endl;
        cout << "Nama Pemilik: " << InfoParent(P).namaPemilk << endl;
        cout << "Lama Peminjaman: " << InfoParent(P).lamaPeminjaman << " jam" << endl;
        if (InfoParent(P).namaPeminjam != "") {
            cout << "Nama Peminjam: " << InfoParent(P).namaPeminjam << endl;
        }
        cout << "Jumlah Kendaraan: " << count << " kendaraan" << endl;

        if (count > 0) {
            cout << "\nDetail Kendaraan:" << endl;
            adrRelation rel = FirstRelation(LRel);
            int kendaraanKe = 1;
            while (rel != NULL) {
                if (RentalRelation(rel) == P) {
                    cout << kendaraanKe << ". Merk: " << InfoChild(KendaraanRelation(rel)).merk << endl;
                    cout << "   Type: " << InfoChild(KendaraanRelation(rel)).type << endl;
                    cout << "   Harga: Rp" << InfoChild(KendaraanRelation(rel)).harga << endl;
                    kendaraanKe++;
                }
                rel = NextRelation(rel);
            }
        }
        cout << "==========================================================" << endl;
        P = NextParent(P);
    }

    cout << "\nRingkasan:" << endl;
    cout << "Total Parent: " << totalParent << endl;
    cout << "Total Relasi: " << totalRelasi << endl;
    cout << "==========================================================" << endl;
}

int countRelationFromElmnParent(ListRelation LR, adrRental parent) {
    // count relation dari dari setiap elemen parent

    int count = 0;
    adrRelation rel = FirstRelation(LR);
    
    while (rel != NULL) {
        if (RentalRelation(rel) == parent) {
            count++;
        }
        rel = NextRelation(rel);
    }
    
    return count;
}

int countRelationChild(ListRelation LR, adrKendaraan child) {
    // count relation yang dimiliki oleh child tertentu

    int count = 0;
    adrRelation rel = FirstRelation(LR);
    
    while (rel != NULL) {
        if (KendaraanRelation(rel) == child) {
            count++;
        }
        rel = NextRelation(rel);
    }
    
    return count;
}

int countElmnChildNoRelation(ListKendaraan LK, ListRelation LR) {
    int count = 0;
    adrKendaraan child = FirstChild(LK);

    while (child != NULL) {
        bool adaRelation = false;
        adrRelation rel = FirstRelation(LR);
        
        while (rel != NULL) {
            if (KendaraanRelation(rel) == child) {
                adaRelation = true;
                break;
            }
            rel = NextRelation(rel);
        }
        
        if (!adaRelation) {
            count++;
        }
        
        child = NextChild(child);
    }
    
    return count;
}

void editRelation(ListRelation &LR, ListKendaraan LK, adrRental parent, string namaChildBaru) {
    if (parent == NULL) {
        cout << "\n==========================================================" << endl;
        cout << "Parent tidak ditemukan" << endl;
        cout << "==========================================================" << endl;
        return;
    }

    adrKendaraan childBaru = findChild_Kendaraan(LK, namaChildBaru);
    if (childBaru == NULL) {
        cout << "\n==========================================================" << endl;
        cout << "Kendaraan baru tidak ditemukan" << endl;
        cout << "==========================================================" << endl;
        return;
    }

    bool found = false;
    adrRelation rel = FirstRelation(LR);
    
    while (rel != NULL) {
        if (RentalRelation(rel) == parent) {
            KendaraanRelation(rel) = childBaru;
            found = true;
            break;
        }
        rel = NextRelation(rel);
    }

    if (found) {
        cout << "\n==========================================================" << endl;
        cout << "Relasi berhasil diupdate" << endl;
        cout << "==========================================================" << endl;
    } else {
        cout << "\n==========================================================" << endl;
        cout << "Parent tidak memiliki relasi yang bisa diupdate" << endl;
        cout << "==========================================================" << endl;
    }
}