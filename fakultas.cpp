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

adr_fk createElmFk(infotypeFakultas x) {
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
        cout << "PT atau Fakultas tidak ditemukan!\n";
        return;
    }

    adr_rel r = createElmRelasi(fk);
    r->next = pt->firstRelasi;
    pt->firstRelasi = r;
}

/* ====== Delete ====== */
void deletePT(listPT &L, string kodePT) {
    adr_pt p = L.first, prev = nullptr;
    while (p != nullptr && p->info.kodePT != kodePT) {
        prev = p;
        p = p->next;
    }
    if (p != nullptr) {
        if (prev == nullptr)
            L.first = p->next;
        else
            prev->next = p->next;
        delete p;
    }
}

void deleteFk(listFk &L, string kodeFk) {
    adr_fk f = L.first, prev = nullptr;
    while (f != nullptr && f->info.kodeFk != kodeFk) {
        prev = f;
        f = f->next;
    }
    if (f != nullptr) {
        if (prev == nullptr)
            L.first = f->next;
        else
            prev->next = f->next;
        delete f;
    }
}

/* ====== Show ====== */
void showAllPT(listPT L) {
    adr_pt p = L.first;
    while (p != nullptr) {
        cout << "\nPT: " << p->info.namaPT << " (" << p->info.kodePT << ")\n";
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            cout << " - " << r->fk->info.namaFk << " (" << r->fk->info.kodeFk << ")\n";
            r = r->next;
        }
        p = p->next;
    }
}

void showPTwithFakultas(listPT L, string kodePT) {
    adr_pt p = searchPT(L, kodePT);
    if (p != nullptr) {
        adr_rel r = p->firstRelasi;
        cout << "Fakultas di " << p->info.namaPT << ":\n";
        while (r != nullptr) {
            cout << "- " << r->fk->info.namaFk << endl;
            r = r->next;
        }
    }
}

void showPTbyFakultas(listPT L, string kodeFk) {
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
    adr_pt maxPT = nullptr, minPT = nullptr;

    while (p != nullptr) {
        int count = 0;
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            count++;
            r = r->next;
        }
        if (count > max) {
            max = count;
            maxPT = p;
        }
        if (count < min) {
            min = count;
            minPT = p;
        }
        p = p->next;
    }

    if (maxPT && minPT) {
        cout << "PT Fakultas Terbanyak: " << maxPT->info.namaPT << endl;
        cout << "PT Fakultas Tersedikit: " << minPT->info.namaPT << endl;
    }
}

// void showFK(listFk f){
//     adr_fk fk = f.first;
//     while (fk != nullptr)
//     {
//         cout << "Kode Fakultas: " << fk->info.kodeFk << ", Nama Fakultas: " << fk->info.namaFk << endl;
//         fk = fk->next;
//     }
    
// }