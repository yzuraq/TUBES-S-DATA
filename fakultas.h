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

struct infotypeFakultas {
    string kodeFak;
    string namaFak;
};

/* ====== Forward Declaration ====== */
typedef struct elmPT *adr_pt;
typedef struct elmFak *adr_fak;
typedef struct elmRelasi *adr_rel;

/* ====== Elemen ====== */
struct elmPT {
    infotypePT info;
    adr_pt next;
    adr_rel firstRelasi;
};

struct elmFak {
    infotypeFakultas info;
    adr_fak next;
};

struct elmRelasi {
    adr_fak fak;
    adr_rel next;
};

/* ====== List ====== */
struct listPT {
    adr_pt first;
};

struct listFak {
    adr_fak first;
};

/* ====== Function & Procedure ====== */
void createListPT(listPT &L);
void createListFak(listFak &L);

adr_pt createElmPT(infotypePT x);
adr_fak createElmFak(infotypeFakultas x);
adr_rel createElmRelasi(adr_fak f);

void insertLastPT(listPT &L, adr_pt p);
void insertLastFak(listFak &L, adr_fak f);

adr_pt searchPT(listPT L, string kodePT);
adr_fak searchFak(listFak L, string kodeFak);

void addRelasi(listPT &LPT, listFak LF, string kodePT, string kodeFak);

void deletePT(listPT &L, string kodePT);
void deleteFak(listFak &L, string kodeFak);

void showAllPT(listPT L);
void showPTwithFakultas(listPT L, string kodePT);
void showPTbyFakultas(listPT L, string kodeFak);
void showPTMaxMinFakultas(listPT L);

#endif
