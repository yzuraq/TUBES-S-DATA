#include "fakultas.h"

/* ====== Create List ====== */
void createListPT(listPT &L) {
    L.first = nullptr;
}

void createListFak(listFk &L) {
    L.first = nullptr;
}

/* ====== Create Element ====== */
adr_pt createElmPT(infotypePT x) {
    adr_pt p = new elmPT;
    p->info = x;
    p->next = nullptr;
    p->firstRelasi = nullptr;
    return p;
}

adr_fk createElmFk(infotypeFk x) {
    adr_fk f = new elmFk;
    f->info = x;
    f->next = nullptr;
    return f;
}

adr_rel createElmRelasi(adr_fk f) {
    adr_rel r = new elmRelasi;
    r->fk = f;
    r->next = nullptr;
    return r;
}

/* ====== Cek Kesamaan Input ====== */
bool cekKesamaanInputPT(listPT l, string kodePT, string namaPT){
    adr_pt p = l.first;
    while(p != nullptr){
        if(p->info.kodePT == kodePT || p->info.namaPT == namaPT){
            return true;
        }
        p = p->next;
    }

    return false;
}

bool cekKesamaanInputFk(listFk f, string kodeFk, string namaFk){
    adr_fk fk = f.first;
    while(fk != nullptr){
        if(fk->info.kodeFk == kodeFk || fk->info.namaFk == namaFk){
            return true;
        }
        fk = fk->next;
    }

    return false;
}


/* ====== Insert ====== */
void insertLastPT(listPT &L, adr_pt p) {
    if (cekKesamaanInputPT(L, p->info.kodePT, p->info.namaPT))
    {
        cout << "Data Perguruan Tinggi sudah ada!\n";
        return;
    }
    
    if (L.first == nullptr) {
        L.first = p;
    } else {
        adr_pt temp = L.first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = p;
    }
}

void insertLastFk(listFk &L, adr_fk f) {
    if (cekKesamaanInputFk(L, f->info.kodeFk, f->info.namaFk))
    {
        cout << "Data Fakultas sudah ada!\n";
        return;
    }
    
    if (L.first == nullptr) {
        L.first = f;
    } else {
        adr_fk temp = L.first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = f;
    }
}

/* ====== Search ====== */
adr_pt searchPT(listPT L, string kodePT) {
    adr_pt p = L.first;
    while (p != nullptr) {
        if (p->info.kodePT == kodePT)
            return p;
        p = p->next;
    }
    return nullptr;
}

adr_fk searchFk(listFk L, string kodeFk) {
    adr_fk f = L.first;
    while (f != nullptr) {
        if (f->info.kodeFk == kodeFk)
            return f;
        f = f->next;
    }
    return nullptr;
}

/* ====== Relasi ====== */
void addRelasi(listPT &LPT, listFk LF, string kodePT, string kodeFk) {
    adr_pt pt = searchPT(LPT, kodePT);
    adr_fk fk = searchFk(LF, kodeFk);

    if (pt == nullptr || fk == nullptr) {
        cout << "Perguruan Tinggi atau Fakultas tidak ditemukan.\n";
        return;
    }

    adr_rel r = createElmRelasi(fk);
    r->next = nullptr;
    
    if (pt->firstRelasi == nullptr) {
        pt->firstRelasi = r;
    } else {
        adr_rel temp = pt->firstRelasi;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = r;
    }
}

/* ====== Delete ====== */
void deletePT(listPT &LPT, string kodePT) {
    adr_pt p = LPT.first;
    adr_pt prev = nullptr;


    while (p != nullptr && p->info.kodePT != kodePT) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Data Perguruan Tinggi tidak ditemukan.\n";
        return;
    }

    adr_rel r = p->firstRelasi;
    while (r != nullptr) {
        adr_rel temp = r;
        r = r->next;
        delete temp;
    }
    p->firstRelasi = nullptr;

    if (prev == nullptr) {
        LPT.first = p->next;
    } else {
        prev->next = p->next;
    }

    cout << "Perguruan Tinggi dengan kode " 
         << p->info.kodePT 
         <<" berhasil dihapus!\n";
    delete p;
}

void deleteFk(listFk &LFk, listPT &LPT, string kodeFk) {
    adr_fk fk = LFk.first;
    adr_fk prevFk = nullptr;

    while (fk != nullptr && fk->info.kodeFk != kodeFk) {
        prevFk = fk;
        fk = fk->next;
    }

    if (fk == nullptr) {
        cout << "Data Fakultas tidak ditemukan.\n";
        return;
    }

    adr_pt p = LPT.first;
    while (p != nullptr) {
        adr_rel r = p->firstRelasi;
        adr_rel prev = nullptr;

        while (r != nullptr) {
            if (r->fk == fk) {
                if (prev == nullptr) {
                    p->firstRelasi = r->next;
                } else {
                    prev->next = r->next;
                }
                adr_rel del = r;
                r = r->next;
                delete del;
            } else {
                prev = r;
                r = r->next;
            }
        }
        p = p->next;
    }

    if (prevFk == nullptr) {
        LFk.first = fk->next;
    } else {
        prevFk->next = fk->next;
    }

     cout << "Fakultas dengan kode " 
          << fk->info.kodeFk 
          << " berhasil dihapus!\n";
    delete fk;
}

/* ====== Show ====== */
void showAllPT(listPT L) {
    adr_pt p = L.first;
    if (p == nullptr) {
        cout << "Tidak ada data Perguruan Tinggi.\n";
        return;
    }
    while (p != nullptr) {
        cout << "Perguruan Tinggi: " << p->info.namaPT 
             << " (" << p->info.kodePT << ")\n";
        adr_rel r = p->firstRelasi;
        if (r == nullptr) {
            cout << "  - Tidak ada fakultas.\n";
        } else {
            while (r != nullptr) {
                cout << "\t\t  - " << r->fk->info.namaFk << " (" 
                     << r->fk->info.kodeFk << ")\n";
                r = r->next;
            }
        }
        cout << endl;
        p = p->next;
    }
}

void showPTwithFakultas(listPT L, string kodePT) {
    adr_pt p = searchPT(L, kodePT);
    if (p != nullptr) {
        adr_rel r = p->firstRelasi;
        cout << "Fakultas yang ada di Perguruan Tinggi " 
             << p->info.namaPT << ":\n";
        while (r != nullptr) {
            cout << "- " << r->fk->info.namaFk << endl;
            r = r->next;
        }
    }
}

void showPTbyFakultas(listPT L, listFk LFk, string kodeFk) {
    adr_fk fk = searchFk(LFk, kodeFk);
    if (fk == nullptr) {
        cout << "Data Fakultas tidak ditemukan.\n";
        return;
    }
    cout << "Perguruan Tinggi yang memiliki Fakultas " 
         << fk->info.namaFk << ":\n";
    adr_pt p = L.first;
    while (p != nullptr) {
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            if (r->fk->info.kodeFk == kodeFk) {
                cout << p->info.namaPT << endl;
            }
            r = r->next;
        }
        p = p->next;
    }
}

void showPTMaxMinFakultas(listPT L) {
    adr_pt p = L.first;
    int max = -1, min = 999;

    while (p != nullptr) {
        int count = 0;
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            count++;
            r = r->next;
        }
        if (count > max) max = count;
        if (count < min) min = count;
        p = p->next;
    }

    cout << "Perguruan Tinggi dengan Fakultas Terbanyak (" 
         << max << "):\n";
    p = L.first;
    while (p != nullptr) {
        int count = 0;
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            count++;
            r = r->next;
        }
        if (count == max)
            cout << "- " << p->info.namaPT << endl;
        p = p->next;
    }
    cout << endl;

    cout << "Perguruan Tinggi dengan Fakultas Tersedikit (" 
         << min << "):\n";
    p = L.first;
    while (p != nullptr) {
        int count = 0;
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            count++;
            r = r->next;
        }
        if (count == min)
            cout << "- " << p->info.namaPT 
                 << endl;
        p = p->next;
    }
    cout << endl;
}

