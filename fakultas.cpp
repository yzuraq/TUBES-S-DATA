#include "fakultas.h"

/* ====== Create List ====== */
void createListPT(listPT &L) {
    L.first = nullptr;
}

void createListFak(listFak &L) {
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

adr_fak createElmFak(infotypeFakultas x) {
    adr_fak f = new elmFak;
    f->info = x;
    f->next = nullptr;
    return f;
}

adr_rel createElmRelasi(adr_fak f) {
    adr_rel r = new elmRelasi;
    r->fak = f;
    r->next = nullptr;
    return r;
}

/* ====== Insert ====== */
void insertLastPT(listPT &L, adr_pt p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        adr_pt temp = L.first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = p;
    }
}

void insertLastFak(listFak &L, adr_fak f) {
    if (L.first == nullptr) {
        L.first = f;
    } else {
        adr_fak temp = L.first;
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

adr_fak searchFak(listFak L, string kodeFak) {
    adr_fak f = L.first;
    while (f != nullptr) {
        if (f->info.kodeFak == kodeFak)
            return f;
        f = f->next;
    }
    return nullptr;
}

/* ====== Relasi ====== */
void addRelasi(listPT &LPT, listFak LF, string kodePT, string kodeFak) {
    adr_pt pt = searchPT(LPT, kodePT);
    adr_fak fak = searchFak(LF, kodeFak);

    if (pt == nullptr || fak == nullptr) {
        cout << "PT atau Fakultas tidak ditemukan!\n";
        return;
    }

    adr_rel r = createElmRelasi(fak);
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

void deleteFak(listFak &L, string kodeFak) {
    adr_fak f = L.first, prev = nullptr;
    while (f != nullptr && f->info.kodeFak != kodeFak) {
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
        cout << "\nPT: " << p->info.namaPT << endl;
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            cout << " - " << r->fak->info.namaFak << endl;
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
            cout << "- " << r->fak->info.namaFak << endl;
            r = r->next;
        }
    }
}

void showPTbyFakultas(listPT L, string kodeFak) {
    adr_pt p = L.first;
    while (p != nullptr) {
        adr_rel r = p->firstRelasi;
        while (r != nullptr) {
            if (r->fak->info.kodeFak == kodeFak) {
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
