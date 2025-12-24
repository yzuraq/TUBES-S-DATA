#include "fakultas.h"

int main() {
    listPT LPT;
    listFak LF;
    createListPT(LPT);
    createListFak(LF);

    int pilih;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Perguruan Tinggi\n";
        cout << "2. Tambah Fakultas\n";
        cout << "3. Tambah Relasi PT - Fakultas\n";
        cout << "4. Tampilkan Semua PT\n";
        cout << "5. Tampilkan Fakultas PT\n";
        cout << "6. PT dengan Fakultas Terbanyak & Tersedikit\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            infotypePT x;
            cout << "Kode PT: "; cin >> x.kodePT;
            cout << "Nama PT: "; cin.ignore(); getline(cin, x.namaPT);
            insertLastPT(LPT, createElmPT(x));
        } 
        else if (pilih == 2) {
            infotypeFakultas f;
            cout << "Kode Fakultas: "; cin >> f.kodeFak;
            cout << "Nama Fakultas: "; cin.ignore(); getline(cin, f.namaFak);
            insertLastFak(LF, createElmFak(f));
        }
        else if (pilih == 3) {
            string kPT, kF;
            cout << "Kode PT: "; cin >> kPT;
            cout << "Kode Fakultas: "; cin >> kF;
            addRelasi(LPT, LF, kPT, kF);
        }
        else if (pilih == 4) {
            showAllPT(LPT);
        }
        else if (pilih == 5) {
            string kPT;
            cout << "Kode PT: "; cin >> kPT;
            showPTwithFakultas(LPT, kPT);
        }
        else if (pilih == 6) {
            showPTMaxMinFakultas(LPT);
        }

    } while (pilih != 0);

    return 0;
}
