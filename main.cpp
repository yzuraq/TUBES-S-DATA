#include "fakultas.h"

int main() {
    listPT LPT;
    listFk LFk;
    createListPT(LPT);
    createListFak(LFk);

    string kode_pt[2] = {"PT001", "PT002"};
    string nama_pt[2] = {"Telkom University", "ITS"};
    string kode_fk[4] = {"Fk001", "Fk002", "Fk003", "Fk004"};
    string nama_fk[4] = {"Informatika", "Elektro", "Teknik Mesin", "Sipil"};
    
    for (int i = 0; i < 2; i++) {
        infotypePT p;
        p.kodePT = kode_pt[i];
        p.namaPT = nama_pt[i];
        insertLastPT(LPT, createElmPT(p));
    }
    
    for (int i = 0; i < 4; i++) {
        infotypeFk f;
        f.kodeFk = kode_fk[i];
        f.namaFk = nama_fk[i];
        insertLastFk(LFk, createElmFk(f));
    }
 
    addRelasi(LPT, LFk, "PT001", "Fk001");
    addRelasi(LPT, LFk, "PT001", "Fk002");
    addRelasi(LPT, LFk, "PT002", "Fk003");
    addRelasi(LPT, LFk, "PT002", "Fk001");
    addRelasi(LPT, LFk, "PT002", "Fk004");

    int pilih;
    do {
       cout << "========MENU DATA PERGURUAN TINGGI========\n";
        cout << "1. Tambah data Perguruan Tinggi\n";
        cout << "2. Tambah data Fakultas\n";
        cout << "3. Hubungkan data Perguruan Tinggi dengan Fakultas\n";
        cout << "4. Hapus data Perguruan Tinggi tertentu\n";
        cout << "5. Hapus data Fakultas tertentu\n";
        cout << "6. Tampilkan semua data Perguruan Tinggi beserta Fakultasnya\n";
        cout << "7. Tampilkan data Perguruan Tinggi yang memiliki Fakultas tertentu\n";
        cout << "8. Tampilkan data Fakultas yang memiliki Perguruan Tinggi tertentu\n";
        cout << "9. Tampilkan data Perguruan Tinggi dengan jumlah Fakultas terbanyak dan tersedikit\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;
        cout << endl;

        if (pilih < 0 || pilih > 9) {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n\n";
        }
        else if (pilih == 1) 
        {
            infotypePT p;
            cout << "Masukkan kode Perguruan Tinggi: ";
            cin >> p.kodePT;
            cout << "Masukkan nama Perguruan Tinggi: ";
            getline(cin >> ws, p.namaPT);
            adr_pt newPT = createElmPT(p);
            insertLastPT(LPT, newPT);
            cout << endl;
        }
        else if (pilih == 2) 
        {
            infotypeFk f;
            cout << "Masukkan kode Fakultas: ";
            cin >> f.kodeFk;
            cout << "Masukkan nama Fakultas: ";
            getline(cin >> ws, f.namaFk);
            adr_fk newFk = createElmFk(f);
            insertLastFk(LFk, newFk);
            cout << endl;
        }
        else if (pilih == 3) 
        {
            string kodePT, kodeFk;
            cout << "Masukkan kode Perguruan Tinggi: ";
            cin >> kodePT;
            cout << "Masukkan kode Fakultas: ";
            cin >> kodeFk;
            addRelasi(LPT, LFk, kodePT, kodeFk);
            cout << endl;
        }
        else if (pilih == 4) 
        {
            string kodePTDel;
            cout << "Masukkan kode Perguruan Tinggi yang akan dihapus: ";
            cin >> kodePTDel;
            deletePT(LPT, kodePTDel);
            cout << endl;
        }
        else if (pilih == 5) 
        {
            string kodeFkDel;
            cout << "Masukkan kode Fakultas yang akan dihapus: ";
            cin >> kodeFkDel;
            deleteFk(LFk, LPT, kodeFkDel);
            cout << endl;
        }
        else if (pilih == 6) 
        {
            showAllPT(LPT);
        }
        else if (pilih == 7) 
        {
            string kodePTSearch;
            cout << "Masukkan kode Perguruan Tinggi: ";
            cin >> kodePTSearch;
            showPTwithFakultas(LPT, kodePTSearch);
            cout << endl;
        }
        else if (pilih == 8) 
        {
            string kodeFkSearch;
            cout << "Masukkan kode Fakultas: ";
            cin >> kodeFkSearch;
            showPTbyFakultas(LPT, LFk, kodeFkSearch);
            cout << endl;
        }
        else if (pilih == 9) 
        {
            showPTMaxMinFakultas(LPT);
        }
    } while (pilih != 0);
    
    cout << "Program Selesai.\n";
    cout << "Terima kasih telah menggunakan program ini!\n\n";

    return 0;
}
