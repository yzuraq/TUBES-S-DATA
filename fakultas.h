#ifndef FAKULTAS_H
#define FAKULTAS_H

#include <iostream>
#include <string>
using namespace std;

/* ====== Struct Info ====== */
struct infotypePT {
    string kodePT;
    string namaPT;
};

struct infotypeFk {
    string kodeFk;
    string namaFk;
};

/* ====== Forward Declaration ====== */
typedef struct elmPT *adr_pt;
typedef struct elmFk *adr_fk;
typedef struct elmRelasi *adr_rel;

/* ====== Elemen ====== */
struct elmPT {
    infotypePT info;
    adr_pt next;
    adr_rel firstRelasi;
};

struct elmFk {
    infotypeFk info;
    adr_fk next;
};

struct elmRelasi {
    adr_fk fk;
    adr_rel next;
};

/* ====== List ====== */
struct listPT {
    adr_pt first;
};

struct listFk {
    adr_fk first;
};

/* ====== Function & Procedure ====== */
/* ====== Create List ====== */
void createListPT(listPT &L);
void createListFak(listFk &L);

/* ====== Create Element ====== */
adr_pt createElmPT(infotypePT x);
adr_fk createElmFk(infotypeFk x);
adr_rel createElmRelasi(adr_fk f);

/* ====== Cek Kesamaan Input ====== */
bool cekKesamaanInputPT(listPT l, string kodePT, string namaPT);
bool cekKesamaanInputFk(listFk f, string kodeFk, string namaFk);

/* ====== Insert ====== */
void insertLastPT(listPT &L, adr_pt p);
void insertLastFk(listFk &L, adr_fk f);

/* ====== Search ====== */
adr_pt searchPT(listPT L, string kodePT);
adr_fk searchFk(listFk L, string kodeFk);

/* ====== Relasi ====== */
void addRelasi(listPT &LPT, listFk LF, string kodePT, string kodeFk);

/* ====== Delete ====== */
void deletePT(listPT &L, string kodePT);
void deleteFk(listFk &L, string kodeFk);

/* ====== Show ====== */
void showAllPT(listPT L);
void showPTwithFakultas(listPT L, string kodePT);
void showPTbyFakultas(listPT L, string kodeFk);
void showPTMaxMinFakultas(listPT L);

#endif
