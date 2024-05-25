#include <iostream>
#include <fstream>
using namespace std;

void setColorAdmin(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);}

struct deskripsiLaptop
{
    string deskripsi;
};

struct adminDataLaptop
{
    string nama;
    int harga;
    int stok;
    struct deskripsiLaptop desc;
};

struct adminSejarahPembelian
{
    time_t waktuPembelian;
    string namaUser;
    string namaLaptop;
    int nominal;
    string pembayaran;
};


// Selection sort nama laptop
void shellSort(adminDataLaptop alap[], int& jumlahDataLaptop)
{
    for (int gap = jumlahDataLaptop / 2; gap > 0; gap /= 2)
            {
                for (int i = gap; i < jumlahDataLaptop; i++)
                {
                    adminDataLaptop temp = alap[i];
                    int j;
                    for (j = i; j >= gap && alap[j-gap].harga > temp.harga; j -= gap)
                    {
                        alap[j] = alap[j - gap];
                    }
                    alap[j] = temp;
                }
            }
}

// Shell sort harga laptop
void selectionSort(adminDataLaptop alap[], int& jumlahDataLaptop)
{
    int i, j, minimum;
        for (i = 0; i < jumlahDataLaptop - 1; i++)
        {
            minimum = i;
            for (j = i+1; j < jumlahDataLaptop; j++)
            {
                if (alap[j].nama < alap[minimum].nama)
                {
                    minimum = j;
                }
            }

            if (minimum != i)
            {
            adminDataLaptop temp = alap[minimum];
            alap[minimum] = alap[i];
            alap[i] = temp;
            }
        }
}


void tambahkanDataLaptop(int& jumlahDataLaptop)
{
    string nama, deskripsi;
    int harga, stok;

    system("cls");
    setColorAdmin(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColorAdmin(10);
    cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
    cout << "\t\t\t\t\t\t                     (MERK)                     " << endl;
    setColorAdmin(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColorAdmin(10);

    cout << "\t\t\t\t\t\tMasukkan Nama Laptop >> ";
    setColorAdmin(6);
    getline(cin, nama);

    if(nama.empty())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
        system("cls");
        setColorAdmin(4);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        sleep_for(seconds(2));
        system("cls");
        tambahkanDataLaptop(jumlahDataLaptop);
    }

    while (true)
    {
    system("cls");
    setColorAdmin(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColorAdmin(10);
    cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
    cout << "\t\t\t\t\t\t                    (HARGA)                     " << endl;
    setColorAdmin(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColorAdmin(10);
    cout << "\t\t\t\t\t\tMasukkan harga laptop (dalam rupiah) >> ";
    setColorAdmin(6);
        if (cin >> noskipws >> harga)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColorAdmin(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
            }
    }

    while (true)
    {
        system("cls");
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
        cout << "\t\t\t\t\t\t                    (STOK)                      " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\tMasukkan stok laptop >> ";
        setColorAdmin(6);

        if (cin >> noskipws >> stok)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColorAdmin(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
            }
    }

    while (true)
    {
        system("cls");
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
        cout << "\t\t\t\t\t\t                  (DESKRIPSI)                   " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t\tMasukkan spesifikasi laptop >> ";
        setColorAdmin(6);
        getline(cin, deskripsi);

        if (deskripsi.empty())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
            system("cls");
            setColorAdmin(4);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            sleep_for(seconds(2));
            system("cls");
        }
            else
            {
                break;
            }
    }

    fstream file;
    file.open("Database\\laptop.csv", ios::out | ios::app);

    file << nama << ",";
    file << harga << ",";
    file << stok << ",";
    file << deskripsi << "\n";
    file.close();

    jumlahDataLaptop += 1;
}

void bacaDataLaptop(int& jumlahDataLaptop, bool sortByName)
{
    string placeholder;
    int i = 1;
    fstream file;
    adminDataLaptop alap[jumlahDataLaptop];

    file.open("Database\\laptop.csv", ios::in);

    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        getline(file, alap[i].nama, ',');
        getline(file, placeholder, ',');
        alap[i].harga = stoi(placeholder);
        getline(file, placeholder, ',');
        alap[i].stok = stoi(placeholder);
        getline(file, alap[i].desc.deskripsi, '\n');
    }

    file.close();

    if (sortByName)
        selectionSort(alap, jumlahDataLaptop);
    else
        shellSort(alap, jumlahDataLaptop);


    // Header tabel
    setColorAdmin(3);
    cout << string(139, '=') << endl;
    cout << left << setw(5); setColorAdmin(10); cout << "No."; setColorAdmin(3); cout << " | ";
    cout << left << setw(20); setColorAdmin(10); cout << "Nama"; setColorAdmin(3); cout << " | ";
    cout << left << setw(40); setColorAdmin(10); cout << "Harga"; setColorAdmin(3); cout << " | ";
    cout << left << setw(10); setColorAdmin(10); cout << "Stok"; setColorAdmin(3); cout << " | ";
    cout << left << setw(50); setColorAdmin(10); cout << "Deskripsi"; setColorAdmin(3); cout << " | " << endl;
    cout << string(139, '=') << endl;

    for (int i = 0; i < jumlahDataLaptop; ++i)
    {
        if (alap[i].nama != "")
        {
            cout << left << setw(5); setColorAdmin(10); cout << i + 1; setColorAdmin(3); cout << " | ";
            cout << left << setw(20); setColorAdmin(10); cout << alap[i].nama; setColorAdmin(3); cout << " | ";
            cout << left << setw(40); setColorAdmin(10); cout << alap[i].harga; setColorAdmin(3); cout << " | ";
            cout << left << setw(10); setColorAdmin(10); cout << alap[i].stok; setColorAdmin(3); cout << " | ";
            cout << left << setw(50); setColorAdmin(10); cout << alap[i].desc.deskripsi; setColorAdmin(3); cout << " | " << endl;
        }
    }
    setColorAdmin(3);
    cout << string(139, '=') << endl;
}

void ubahDataLaptop(int& jumlahDataLaptop)
{
    string placeholder;
    int pilihan, pilihanData;
    fstream file;
    adminDataLaptop alap[jumlahDataLaptop];

    file.open("Database\\laptop.csv", ios::in);
    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        getline(file, alap[i].nama, ',');
        getline(file, placeholder, ',');
        alap[i].harga = stoi(placeholder);
        getline(file, placeholder, ',');
        alap[i].stok = stoi(placeholder);
        getline(file, alap[i].desc.deskripsi, '\n');
    }
    file.close();

    selectionSort(alap, jumlahDataLaptop);
    bacaDataLaptop(jumlahDataLaptop, true);

    cout << "\nMasukkan nomor urut data yang ingin di ubah >> ";
    while (!(cin >> noskipws >> pilihan) && pilihan > 0 && pilihan <= jumlahDataLaptop)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ubahDataLaptop(jumlahDataLaptop);
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");

    while (true)
    {
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10); cout << "\t\t\t\t\t\t  1. Nama: "; setColorAdmin(6); cout << alap[pilihan - 1].nama << endl;
        setColorAdmin(10); cout << "\t\t\t\t\t\t  2. Harga: "; setColorAdmin(6); cout << alap[pilihan - 1].harga << endl;
        setColorAdmin(10); cout << "\t\t\t\t\t\t  3. Stok: "; setColorAdmin(6); cout << alap[pilihan - 1].stok << endl;
        setColorAdmin(10); cout << "\t\t\t\t\t\t  4. Deskripsi: "; setColorAdmin(6); cout << alap[pilihan - 1].desc.deskripsi << endl;
        setColorAdmin(10); cout << "\t\t\t\t\t\t  0. Ubah keseluruhan" << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        cout << "\n\t\t\t\t\t\t  Bagian yang ingin diubah >> ";

        if (cin >> noskipws >> pilihanData && pilihanData >= 0 && pilihanData <= 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColorAdmin(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t           PILIHAN TIDAK VALID          " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
            }
    }

    switch (pilihanData)
    {
    case 1:
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t                UBAH NAMA LAPTOP                " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t    Masukkan nama baru >> ";
        setColorAdmin(6);
        getline(cin, alap[pilihan - 1].nama);
        break;

    case 2:
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t               UBAH HARGA LAPTOP                " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t    Masukkan harga baru >> ";
        setColorAdmin(6);
        cin >> alap[pilihan - 1].harga;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;

    case 3:
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t                UBAH STOK LAPTOP                " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t    Masukkan stok baru >> ";
        setColorAdmin(6);
        cin >> alap[pilihan - 1].stok;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;

    case 4:
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t             UBAH DESKRIPSI LAPTOP              " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\tMasukkan deskripsi baru >> ";
        setColorAdmin(6);
        getline(cin, alap[pilihan - 1].desc.deskripsi);
        break;

    case 0:
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t================================================" << endl;

        setColorAdmin(10);
        cout << "\t\t\t\t\t\t  Masukkan nama baru >> ";
        setColorAdmin(6);
        getline(cin, alap[pilihan - 1].nama);

        setColorAdmin(10);
        cout << "\t\t\t\t\t\t  Masukkan harga baru >> ";
        setColorAdmin(6);
        cin >> alap[pilihan - 1].harga;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        setColorAdmin(10);
        cout << "\t\t\t\t\t\t  Masukkan stok baru >> ";
        setColorAdmin(6);
        cin >> alap[pilihan - 1].stok;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        setColorAdmin(10);
        cout << "\t\t\t\t\t\t  Masukkan deskripsi baru >> ";
        setColorAdmin(6);
        getline(cin, alap[pilihan - 1].desc.deskripsi);
    }

    file.open("Database\\laptop.csv", ios::out | ios::trunc);
    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        file << alap[i].nama << ",";
        file << alap[i].harga << ",";
        file << alap[i].stok << ",";
        file << alap[i].desc.deskripsi << "\n";
    }
    file.close();
}

int hapusDataLaptop(int& jumlahDataLaptop)
{
    string placeholder, key;
    fstream file;

    adminDataLaptop alap[jumlahDataLaptop];

    file.open("Database\\laptop.csv", ios::in);
    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        getline(file, alap[i].nama, ',');
        getline(file, placeholder, ',');
        alap[i].harga = stoi(placeholder);
        getline(file, placeholder, ',');
        alap[i].stok = stoi(placeholder);
        getline(file, alap[i].desc.deskripsi, '\n');
    }
    file.close();

    selectionSort(alap, jumlahDataLaptop);
    bacaDataLaptop(jumlahDataLaptop, true);

    setColorAdmin(10);
    cout << "\nMasukkan nama laptop yang ingin dihapus >> ";
    setColorAdmin(6);
    getline(cin, key);

    if (key.empty())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
        system("cls");
        setColorAdmin(4);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        sleep_for(seconds(2));
        system("cls");
        hapusDataLaptop(jumlahDataLaptop);
    }

    // Binary Search
    int low = 0;
    int high = jumlahDataLaptop - 1;

    while (low <= high)
    {
        int mid = (low + high)/2;
        if (key == alap[mid].nama)
        {
            alap[mid].nama = "";

            file.open("Database\\laptop.csv", ios::out | ios::trunc);
            for (int i = 0; i < jumlahDataLaptop; i++)
            {
                if (alap[i].nama != "")
                {
                    file << alap[i].nama << ",";
                    file << alap[i].harga << ",";
                    file << alap[i].stok << ",";
                    file << alap[i].desc.deskripsi << "\n";
                }
            }
            file.close();

            jumlahDataLaptop -= 1;
            return 0;
        }
            else if (key < alap[mid].nama)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
    system("cls");
    setColorAdmin(4);
    cout << "\t\t\t\t\t\t\t========================================" << endl;
    cout << "\t\t\t\t\t\t\t      NAMA LAPTOP TIDAK DITEMUKAN       " << endl;
    cout << "\t\t\t\t\t\t\t========================================" << endl;
    sleep_for(seconds(2));
    system("cls");
    return 0;
}

// Prosedur data riwayat
void listRiwayatAdmin(int &jumlahDataRiwayat)
{
    fstream file;
    string placeholder;
    adminSejarahPembelian asp[jumlahDataRiwayat];

    // Mengambil data riwayat dari csv
    file.open("Database\\transaction_history.csv", ios::in);
    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        getline(file, placeholder, ',');
        asp[i].waktuPembelian = stoi(placeholder);
        getline(file, asp[i].namaUser, ',');
        getline(file, asp[i].namaLaptop, ',');
        getline(file, placeholder, ',');
        asp[i].nominal = stoi(placeholder);
        getline(file, asp[i].pembayaran, '\n');
    }
    file.close();

    // Mencari nama di dalam riwayat dan membandingkan dengan namaUser
    // untuk menunjukkan hanya yang di beli oleh user
    // Header
    setColorAdmin(3);
    cout << string(137, '=') << endl;
    setColorAdmin(10); cout << left << setw(15) << "Nama"; setColorAdmin(3); cout << " | ";
    setColorAdmin(10); cout << left << setw(25) << "Tanggal Pembelian"; setColorAdmin(3); cout << " | ";
    setColorAdmin(10); cout << left << setw(25) << "Waktu Pembelian"; setColorAdmin(3); cout << " | ";
    setColorAdmin(10); cout << left << setw(15) << "Laptop"; setColorAdmin(3); cout << " | ";
    setColorAdmin(10); cout << left << setw(25) << "Nominal"; setColorAdmin(3); cout << " | ";
    setColorAdmin(10); cout << left << setw(15) << "Pembayaran"; setColorAdmin(3); cout << " | " << endl;
    cout << string(137, '=') << endl;

    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        tm *ltm = localtime(&asp[i].waktuPembelian);
        setColorAdmin(10);
        cout << left << setw(15) << asp[i].namaUser;
        setColorAdmin(3); cout << " | ";
        setColorAdmin(10);
        cout << left << setw(25) << (to_string(ltm->tm_mday) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(1900 + ltm->tm_year));
        setColorAdmin(3); cout << " | ";
        setColorAdmin(10);
        cout << left << setw(25) << (to_string(ltm->tm_hour) + "." + to_string(ltm->tm_min) + "." + to_string(ltm->tm_sec));
        setColorAdmin(3); cout << " | ";
        setColorAdmin(10);
        cout << left << setw(15) << asp[i].namaLaptop;
        setColorAdmin(3); cout << " | ";
        setColorAdmin(10);
        cout << left << setw(25) << fixed << setprecision(0) << asp[i].nominal;
        setColorAdmin(3); cout << " | ";
        setColorAdmin(10);
        cout << left << setw(15) << asp[i].pembayaran;
        setColorAdmin(3); cout << " | " << endl;
    }
    setColorAdmin(3);
    cout << string(137, '=') << endl;
}

int menuAdmin(int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    int pilihan, pilihanSorting;
    while (true)
    {
        system("cls");
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t\t               MENU ADMIN                " << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t\t    [1] Lihat data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [2] Lihat riwayat pembelian" << endl;
        cout << "\t\t\t\t\t\t\t    [3] Tambahkan data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [4] Ubah data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [5] Hapus data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [0] Keluar dari akun" << endl;
        setColorAdmin(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColorAdmin(10);
        cout << "\t\t\t\t\t\t\t  Masukkan pilihan >> ";
        setColorAdmin(6);

        cin >> pilihan;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan)
        {
        case 1:
            system("cls");
            setColorAdmin(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColorAdmin(10);
            cout << "\t\t\t\t\t\t\t           LIHAT DAFTAR LAPTOP            " << endl;
            setColorAdmin(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColorAdmin(10);
            cout << "\t\t\t\t\t\t\t    [1] Urutkan berdasarkan nama" << endl;
            cout << "\t\t\t\t\t\t\t    [2] Urutkan berdasarkan harga" << endl;
            setColorAdmin(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColorAdmin(10);
            cout << "\t\t\t\t\t\t\t  Masukkan pilihan >> ";
            setColorAdmin(6);

            cin >> pilihanSorting;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (pilihanSorting)
            {
            case 1:
                system("cls");
                bacaDataLaptop(jumlahDataLaptop, true);
                setColorAdmin(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            case 2:
                system("cls");
                bacaDataLaptop(jumlahDataLaptop, false);
                setColorAdmin(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            }
            break;
        case 2:
            system("cls");
            listRiwayatAdmin(jumlahDataRiwayat);
            setColorAdmin(10);
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
            cin.clear();
            break;
        case 3:
            system("cls");
            tambahkanDataLaptop(jumlahDataLaptop);
            break;
        case 4:
            system("cls");
            ubahDataLaptop(jumlahDataLaptop);
            break;
        case 5:
            system("cls");
            hapusDataLaptop(jumlahDataLaptop);
            break;
        case 0:
            return 0;
        }
    }
}
