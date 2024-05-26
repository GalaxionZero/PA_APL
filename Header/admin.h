#include <iostream>
#include <fstream>

#include "util.h"

using namespace std;

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
    setColor(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
    cout << "\t\t\t\t\t\t                     (MERK)                     " << endl;
    setColor(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColor(10);

    cout << "\t\t\t\t\t\tMasukkan Nama Laptop >> ";
    setColor(6);
    getline(cin, nama);

    if(nama.empty())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
        system("cls");
        setColor(4);
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
    setColor(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
    cout << "\t\t\t\t\t\t                    (HARGA)                     " << endl;
    setColor(3);
    cout << "\t\t\t\t\t\t================================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\tMasukkan harga laptop (dalam rupiah) >> ";
    setColor(6);
        if (cin >> noskipws >> harga && harga > 0)
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
                setColor(4);
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
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
        cout << "\t\t\t\t\t\t                    (STOK)                      " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\tMasukkan stok laptop >> ";
        setColor(6);

        if (cin >> noskipws >> stok && stok > 0)
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
                setColor(4);
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
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t                 TAMBAH LAPTOP                  " << endl;
        cout << "\t\t\t\t\t\t                  (DESKRIPSI)                   " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\tMasukkan spesifikasi laptop >> ";
        setColor(6);
        getline(cin, deskripsi);

        if (deskripsi.empty())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
            system("cls");
            setColor(4);
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
    setColor(3);
    cout << string(139, '=') << endl;
    cout << left << setw(5); setColor(10); cout << "No."; setColor(3); cout << " | ";
    cout << left << setw(20); setColor(10); cout << "Nama"; setColor(3); cout << " | ";
    cout << left << setw(40); setColor(10); cout << "Harga"; setColor(3); cout << " | ";
    cout << left << setw(10); setColor(10); cout << "Stok"; setColor(3); cout << " | ";
    cout << left << setw(50); setColor(10); cout << "Deskripsi"; setColor(3); cout << " | " << endl;
    cout << string(139, '=') << endl;

    for (int i = 0; i < jumlahDataLaptop; ++i)
    {
        if (alap[i].nama != "")
        {
            cout << left << setw(5); setColor(10); cout << i + 1; setColor(3); cout << " | ";
            cout << left << setw(20); setColor(10); cout << alap[i].nama; setColor(3); cout << " | ";
            cout << left << setw(40); setColor(10); cout << alap[i].harga; setColor(3); cout << " | ";
            cout << left << setw(10); setColor(10); cout << alap[i].stok; setColor(3); cout << " | ";
            cout << left << setw(50); setColor(10); cout << alap[i].desc.deskripsi; setColor(3); cout << " | " << endl;
        }
    }
    setColor(3);
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
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10); cout << "\t\t\t\t\t\t  1. Nama: "; setColor(6); cout << alap[pilihan - 1].nama << endl;
        setColor(10); cout << "\t\t\t\t\t\t  2. Harga: "; setColor(6); cout << alap[pilihan - 1].harga << endl;
        setColor(10); cout << "\t\t\t\t\t\t  3. Stok: "; setColor(6); cout << alap[pilihan - 1].stok << endl;
        setColor(10); cout << "\t\t\t\t\t\t  4. Deskripsi: "; setColor(6); cout << alap[pilihan - 1].desc.deskripsi << endl;
        setColor(10); cout << "\t\t\t\t\t\t  0. Ubah keseluruhan" << endl;
        setColor(3);
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
                setColor(4);
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

        while (true)
        {
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t                UBAH NAMA LAPTOP                " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t    Masukkan nama baru >> ";
            setColor(6);
            getline(cin, alap[pilihan - 1].nama);

            if ((alap[pilihan - 1].nama).empty())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                setColor(4);
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
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
        break;

    case 2:
        while (true)
        {
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t               UBAH HARGA LAPTOP                " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t    Masukkan harga baru >> ";
            setColor(6);
            if (cin >> noskipws >> alap[pilihan - 1].harga && alap[pilihan - 1].harga > 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");
                }

        }
        break;

    case 3:
        while (true)
        {
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t                UBAH STOK LAPTOP                " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t    Masukkan stok baru >> ";
            setColor(6);
            if (cin >> noskipws >> alap[pilihan - 1].stok && alap[pilihan - 1].stok >= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");
                }

        }
        break;

    case 4:
        while(true)
        {
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t             UBAH DESKRIPSI LAPTOP              " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t================================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\tMasukkan deskripsi baru >> ";
            setColor(6);
            getline(cin, alap[pilihan - 1].desc.deskripsi);

            if (alap[pilihan - 1].desc.deskripsi.empty())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                setColor(4);
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
        break;

    case 0:
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t================================================" << endl;

        while (true)
        {
            setColor(10);
            cout << "\t\t\t\t\t\t  Masukkan nama baru >> ";
            setColor(6);
            getline(cin, alap[pilihan - 1].nama);

            if ((alap[pilihan - 1].nama).empty())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                setColor(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");

                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
            }
                else
                {
                    break;
                }
        }

        while(true)
        {
            setColor(10);
            cout << "\t\t\t\t\t\t  Masukkan harga baru >> ";
            setColor(6);

            if (cin >> noskipws >> alap[pilihan - 1].harga && alap[pilihan - 1].harga > 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");

                    setColor(3);
                    cout << "\t\t\t\t\t\t================================================" << endl;
                    setColor(10);
                    cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
                    setColor(3);
                    cout << "\t\t\t\t\t\t================================================" << endl;
                }
        }

        while(true)
        {
            setColor(10);
            cout << "\t\t\t\t\t\t  Masukkan stok baru >> ";
            setColor(6);
            cin >> alap[pilihan - 1].stok;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (cin >> noskipws >> alap[pilihan - 1].stok && alap[pilihan - 1].stok >= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");

                    setColor(3);
                    cout << "\t\t\t\t\t\t================================================" << endl;
                    setColor(10);
                    cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
                    setColor(3);
                    cout << "\t\t\t\t\t\t================================================" << endl;
                }
        }

        while (true)
        {
            setColor(10);
            cout << "\t\t\t\t\t\t  Masukkan deskripsi baru >> ";
            setColor(6);
            getline(cin, alap[pilihan - 1].desc.deskripsi);

            if (alap[pilihan - 1].desc.deskripsi.empty())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                setColor(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t         DATA TIDAK BISA KOSONG         " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");

                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t                UBAH DATA LAPTOP                " << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
            }
                else
                {
                    break;
                }
        }
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

    setColor(10);
    cout << "\nMasukkan nama laptop yang ingin dihapus >> ";
    setColor(6);
    getline(cin, key);

    if (key.empty())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
        system("cls");
        setColor(4);
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
    setColor(4);
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
    setColor(3);
    cout << string(137, '=') << endl;
    setColor(10); cout << left << setw(15) << "Nama"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(25) << "Tanggal Pembelian"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(25) << "Waktu Pembelian"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(15) << "Laptop"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(25) << "Nominal"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(15) << "Pembayaran"; setColor(3); cout << " | " << endl;
    cout << string(137, '=') << endl;

    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        tm *ltm = localtime(&asp[i].waktuPembelian);
        setColor(10);
        cout << left << setw(15) << asp[i].namaUser;
        setColor(3); cout << " | ";
        setColor(10);
        cout << left << setw(25) << (to_string(ltm->tm_mday) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(1900 + ltm->tm_year));
        setColor(3); cout << " | ";
        setColor(10);
        cout << left << setw(25) << (to_string(ltm->tm_hour) + "." + to_string(ltm->tm_min) + "." + to_string(ltm->tm_sec));
        setColor(3); cout << " | ";
        setColor(10);
        cout << left << setw(15) << asp[i].namaLaptop;
        setColor(3); cout << " | ";
        setColor(10);
        cout << left << setw(25) << fixed << setprecision(0) << asp[i].nominal;
        setColor(3); cout << " | ";
        setColor(10);
        cout << left << setw(15) << asp[i].pembayaran;
        setColor(3); cout << " | " << endl;
    }
    setColor(3);
    cout << string(137, '=') << endl;
}

int menuAdmin(int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    int pilihan, pilihanSorting;
    while (true)
    {
        system("cls");
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t               MENU ADMIN                " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t    [1] Lihat data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [2] Lihat riwayat pembelian" << endl;
        cout << "\t\t\t\t\t\t\t    [3] Tambahkan data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [4] Ubah data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [5] Hapus data laptop" << endl;
        cout << "\t\t\t\t\t\t\t    [0] Keluar dari akun" << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t  Masukkan pilihan >> ";
        setColor(6);

        while (!(cin >> noskipws >> pilihan) && pilihan >= 0 && pilihan <= 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
            system("cls");
            setColor(4);
            cout << "========================================" << endl;
            cout << "           PILIHAN TIDAK VALID          " << endl;
            cout << "========================================" << endl;
            sleep_for(seconds(2));
            system("cls");
            menuAdmin(jumlahDataLaptop, jumlahDataRiwayat);
        }

        switch (pilihan)
        {
        case 1:
            system("cls");
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t           LIHAT DAFTAR LAPTOP            " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t    [1] Urutkan berdasarkan nama" << endl;
            cout << "\t\t\t\t\t\t\t    [2] Urutkan berdasarkan harga" << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t  Masukkan pilihan >> ";
            setColor(6);

            while (true)
            {
                if (cin >> noskipws >> pilihanSorting && pilihanSorting > 0 && pilihanSorting <= 2)
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
                        setColor(4);
                        cout << "========================================" << endl;
                        cout << "           PILIHAN TIDAK VALID          " << endl;
                        cout << "========================================" << endl;
                        sleep_for(seconds(2));
                        system("cls");
                    }
            }

            switch (pilihanSorting)
            {
            case 1:
                system("cls");
                bacaDataLaptop(jumlahDataLaptop, true);
                setColor(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            case 2:
                system("cls");
                bacaDataLaptop(jumlahDataLaptop, false);
                setColor(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            }
            break;
        case 2:
            system("cls");
            listRiwayatAdmin(jumlahDataRiwayat);
            setColor(10);
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
