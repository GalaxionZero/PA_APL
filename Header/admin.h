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

void bacaDataLaptop()
{
    string namaLaptop, hargaLaptop, stokLaptop, descLaptop;
    int i = 1;
    ifstream filein;

    filein.open("Database\\laptop.csv", ios::in);

    while (!filein.eof())
    {
        getline(filein, namaLaptop, ',');
        getline(filein, hargaLaptop, ',');
        getline(filein, stokLaptop, ',');
        getline(filein, descLaptop, '\n');

        if (namaLaptop != "")
        {
            cout << "No. " << i << endl;
            cout << "Nama: " << namaLaptop << endl;
            cout << "Harga: " << hargaLaptop << endl;
            cout << "Stok: " << stokLaptop << endl;
            cout << descLaptop << endl;
            cout << "|||" << endl;
        }
        i++;
    }
    filein.close();
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
    bacaDataLaptop();

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

    bacaDataLaptop();

    cout << "Masukkan nomor urut data yang ingin dihapus >> ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    alap[pilihan - 1].nama = "";

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
    int pilihan;
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
            bacaDataLaptop();
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
