#include "fakultas.h"

int main() {
    listPT LPT;
    listFk LF;
    createListPT(LPT);
    createListFak(LF);

    string kode_pt[2] = {"PT001", "PT002"};
    string nama_pt[2] = {"Telkom University", "ITS"};
    string kode_fk[4] = {"FK001", "FK002", "FK003", "FK004"};
    string nama_fk[4] = {"Informatika", "Elektro", "Teknik Mesin", "Sipil"};
    
    for (int i = 0; i < 2; i++) {
        infotypePT x;
        x.kodePT = kode_pt[i];
        x.namaPT = nama_pt[i];
        insertLastPT(LPT, createElmPT(x));
    }
    
    for (int i = 0; i < 4; i++) {
        infotypeFakultas f;
        f.kodeFk = kode_fk[i];
        f.namaFk = nama_fk[i];
        insertLastFk(LF, createElmFk(f));
    }
 
    addRelasi(LPT, LF, "PT001", "FK001");
    addRelasi(LPT, LF, "PT001", "FK002");
    addRelasi(LPT, LF, "PT002", "FK003");
    addRelasi(LPT, LF, "PT002", "FK001");
    addRelasi(LPT, LF, "PT002", "FK004");

    int pilih;
    do {
       cout << "========MENU DATA PERGURUAN TINGGI========\n";
        cout << "1. Tambahkan data perguruan tinggi\n";
        cout << "2. Tambahkan data fakultas\n";
        cout << "3. Menghubungkan data perguruan tinggi dengan fakultas\n";
        cout << "4. Menghapus data perguruan tinggi tertentu\n";
        cout << "5. Menghapus data fakultas tertentu\n";
        cout << "6. Tampilkan semua data perguruan tinggi beserta fakultasnya\n";
        cout << "7. Tampilkan data perguruan tinggi yang memiliki fakultas tertentu\n";
        cout << "8. Tampilkan data fakultas dari perguruan tinggi tertentu\n";
        cout << "9. Tampilkan data perguruan tinggi dengan jumlah fakultas terbanyak dan tersedikit\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;
        cout << endl;

        switch(pilih) {
            case 1: {
                infotypePT p;
                cout << "Masukkan kode PT: ";
                cin >> p.kodePT;
                cout << "Masukkan nama PT: ";
                getline(cin >> ws, p.namaPT);
                adr_pt newPT = createElmPT(p);
                insertLastPT(LPT, newPT);
                cout << endl;
                break;
            }
            case 2: {
                infotypeFakultas f;
                cout << "Masukkan kode Fakultas: ";
                cin >> f.kodeFk;
                cout << "Masukkan nama Fakultas: ";
                getline(cin >> ws, f.namaFk);
                adr_fk newFk = createElmFk(f);
                insertLastFk(LF, newFk);
                cout << endl;
                break;
            }
            case 3: {
                string kodePT, kodeFk;
                cout << "Masukkan kode PT: ";
                cin >> kodePT;
                cout << "Masukkan kode Fakultas: ";
                cin >> kodeFk;
                addRelasi(LPT, LF, kodePT, kodeFk);
                cout << endl;
                break;
            }
            case 4: {
                string kodePTDel;
                cout << "Masukkan kode PT yang akan dihapus: ";
                cin >> kodePTDel;
                deletePT(LPT, kodePTDel);
                cout << endl;
                break;
            }
            case 5: {
                string kodeFkDel;
                cout << "Masukkan kode Fakultas yang akan dihapus: ";
                cin >> kodeFkDel;
                deleteFk(LF, kodeFkDel);
                cout << endl;
                break;
            }
            case 6: {
                showAllPT(LPT);
                break;
            }
            case 7: {
                string kodePTSearch;
                cout << "Masukkan kode PT: ";
                cin >> kodePTSearch;
                showPTwithFakultas(LPT, kodePTSearch);
                cout << endl;
                break;
            }
            case 8: {
                string kodeFkSearch;
                cout << "Masukkan kode Fakultas: ";
                cin >> kodeFkSearch;
                showPTbyFakultas(LPT, kodeFkSearch);
                cout << endl;
                break;
            }
            case 9: {
                showPTMaxMinFakultas(LPT);
                cout << endl;
                break;
            }
        }
    } while (pilih != 0);
    cout << "\nProgram Selesai." << endl;
    cout << "Terima kasih telah menggunakan program ini!" << endl;

    return 0;
}
