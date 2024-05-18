#include <iostream>
#include <fstream>
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
void selectionSort(adminDataLaptop alap[], int& jumlahDataLaptop)
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
void shellSort(adminDataLaptop alap[], int& jumlahDataLaptop)
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
    cout << "Masukkan nama laptop: ";
    getline(cin, nama);
    cout << "Masukkan harga laptop: ";
    cin >> harga;
    cout << "Masukkan stok laptop yang dimiliki: ";
    cin >> stok;
    cin.clear();
    cin.ignore();
    cout << "Masukkan deskripsi spek laptop: ";
    getline(cin, deskripsi);

    ofstream fileout;
    fileout.open("Database\\laptop.csv", ios::out | ios::app);

    fileout << nama << ",";
    fileout << harga << ",";
    fileout << stok << ",";
    fileout << deskripsi << "\n";
    fileout.close();

    jumlahDataLaptop += 1;
    cout << jumlahDataLaptop;
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


    for (int i = 0; i < jumlahDataLaptop; ++i)
    {
        if (alap[i].nama != "")
        {
            cout << "No. " << i+1 << endl;
            cout << "Nama: " << alap[i].nama << endl;
            cout << "Harga: " << alap[i].harga << endl;
            cout << "Stok: " << alap[i].stok << endl;
            cout << alap[i].desc.deskripsi << endl;
            cout << "|||" << endl;
        }
    }
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

    bacaDataLaptop(jumlahDataLaptop, false);

    cout << "Masukkan pilihan untuk data yang ingin di ubah: ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    cout << "1. Nama: " << alap[pilihan - 1].nama << endl;
    cout << "2. Harga: " << alap[pilihan - 1].harga << endl;
    cout << "3. Stok: " << alap[pilihan - 1].stok << endl;
    cout << "4. Desc: " << alap[pilihan - 1].desc.deskripsi << endl;
    cout << "0. Semua" << endl;
    cout << "Bagian mana yang ingin diubah: ";

    cin >> pilihanData;
    cin.clear();
    cin.ignore();

    switch (pilihanData)
    {
    case 1:
        cout << "Masukkan nama baru: ";
        getline(cin, alap[pilihan - 1].nama);
        break;
    case 2:
        cout << "Masukkan harga baru: ";
        cin >> alap[pilihan - 1].harga;
        cin.clear();
        cin.ignore();
        break;
    case 3:
        cout << "Masukkan stok baru: ";
        cin >> alap[pilihan - 1].stok;
        cin.clear();
        cin.ignore();
        break;
    case 4:
        cout << "Masukkan deskripsi baru: ";
        getline(cin, alap[pilihan - 1].desc.deskripsi);
        break;
    case 0:
        cout << "Masukkan nama baru: ";
        getline(cin, alap[pilihan - 1].nama);
        cout << "Masukkan harga baru: ";
        cin >> alap[pilihan - 1].harga;
        cin.clear();
        cin.ignore();
        cout << "Masukkan stok baru: ";
        cin >> alap[pilihan - 1].stok;
        cin.clear();
        cin.ignore();
        cout << "Masukkan deskripsi baru: ";
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

void hapusDataLaptop(int& jumlahDataLaptop)
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
    bacaDataLaptop(jumlahDataLaptop, false);

    cout << "Masukkan nama laptop yang ingin dihapus: ";
    getline(cin, key);

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
    cout << "Nama laptop tidak ditemukan";
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

    // Mencari nama didalam riwayat dan membandingkan dengan namaUser
    // untuk menunjukkan hanya yang di beli oleh user
    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        tm *ltm = localtime(&asp[i].waktuPembelian);
        cout << asp[i].namaUser << endl;
        cout << "Waktu Pembelian: " << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << " pukul " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
        cout << asp[i].namaLaptop << endl;
        cout << asp[i].nominal << endl;
        cout << asp[i].pembayaran << endl;
    }
}

int menuAdmin(int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    int pilihan, pilihanSorting;
    while (true)
    {
        cout << "Menu Admin" << endl;
        cout << "1. Tambahkan Data Laptop" << endl;
        cout << "2. Lihat Data Laptop" << endl;
        cout << "3. Lihat Riwayat Pembelian" << endl;
        cout << "4. Ubah Data Laptop" << endl;
        cout << "5. Hapus Data Laptop" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter: ";

        cin >> pilihan;
        cin.clear();
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            tambahkanDataLaptop(jumlahDataLaptop);
            break;
        case 2:
            cout << "1. Urutkan secara nama" << endl;
            cout << "2. Urutkan secara harga" << endl;
            cout << "Enter: ";
            cin >> pilihanSorting;
            cin.clear();
            cin.ignore();

            switch (pilihanSorting)
            {
            case 1:
                bacaDataLaptop(jumlahDataLaptop, true);
                break;
            case 2:
                bacaDataLaptop(jumlahDataLaptop, false);
                break;
            }
            break;
        case 3:
            listRiwayatAdmin(jumlahDataRiwayat);
            break;
        case 4:
            ubahDataLaptop(jumlahDataLaptop);
            break;
        case 5:
            hapusDataLaptop(jumlahDataLaptop);
            break;
        case 0:
            return 0;
        }
    }
}
