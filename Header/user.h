#include <iostream>
#include <fstream>
using namespace std;

struct DataLaptop
{
    string nama;
    string harga;
    string stok;
    string deskripsi;
};

string metodePembayaran[] = {"bri", "bni", "mandiri", "dana"};

void listLaptop()
{
    string namaLaptop, hargaLaptop, stokLaptop, descLaptop;
    int i = 1;
    ifstream filein;

    filein.open("Database\\DataLaptop.csv", ios::in);

    while (!filein.eof())
    {
        getline(filein, namaLaptop, ',');
        getline(filein, hargaLaptop, ',');
        getline(filein, stokLaptop, ',');
        getline(filein, descLaptop, '\n');

        if (namaLaptop != "")
        {
            cout << "No. " << i << endl
                 << "Nama: " << namaLaptop << endl;
            cout << "Harga: " << hargaLaptop << endl;
            cout << "Stok: " << stokLaptop << endl;
            cout << descLaptop << endl
                 << "|||" << endl;
        }
        i++;
    }

    // Beli laptop disini?
    // Atau di fungsi lain buat itu di panggil disini

    filein.close();
}

void beliLaptop(string namaUser)
{
    int pilihan, metodePembayaran, jumlahData;
    string placeholder;
    fstream file;

    file.open("Database\\DataLaptop.csv", ios::in);
    while (!file.eof())
    {
        getline(file, placeholder, 'n');
        jumlahData++;
    }
    file.close();

    struct DataLaptop slap[jumlahData];

    file.open("Database\\DataLaptop.csv", ios::in);
    for (int i = 0; i < jumlahData; i++)
    {
        getline(file, slap[i].nama, ',');
        getline(file, slap[i].harga, ',');
        getline(file, slap[i].stok, ',');
        getline(file, slap[i].deskripsi, '\n');
    }
    file.close();
    listLaptop();

    cout << "Pilih laptop yang ingin dibeli: ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    cout << "Memakai apa anda ingin membayar?" << endl;
    cout << "[1] Bank Transfer" << endl;
    cout << "[2] E-Wallet" << endl;
    cout << "Pilih >> ";
    cin >> metodePembayaran;

    cin.clear();
    cin.ignore();

    switch (metodePembayaran)
    {
    case 1:
    {
        int statusPembayaran;
        cout << "Silakan transfer ke rekening: 000000116413" << endl;
        cout << "Senilai: Rp" << slap[pilihan - 1].harga << endl;
        cout << "[1] SUDAH TRANSFER" << endl;
        cout << "[2] BATALKAN TRANSAKSI" << endl;
        cout << "Pilih >> ";
        cin >> statusPembayaran;
        switch (statusPembayaran)
        {
        case 1:
            file.open("Database\\DataRiwayat.csv", ios::out | ios::app);

            file << namaUser << ',';
            file << slap[pilihan - 1].nama << ',';
            file << "bank" << '\n';
            file.close();

            cout << "Pembayaran berhasil" << endl;
            break;
        default:
            cout << "Pembayaran dibatalkan" << endl;
            break;
        }
        cin.clear();
        cin.ignore();
        break;
    }
    case 2:
    {
        int statusPembayaran;
        cout << "Silakan transfer ke: DANA 08123123123" << endl;
        cout << "Senilai: Rp" << slap[pilihan - 1].harga << endl;
        cout << "[1] SUDAH TRANSFER" << endl;
        cout << "[2] BATALKAN TRANSAKSI" << endl;
        cout << "Pilih >> ";
        cin >> statusPembayaran;
        switch (statusPembayaran)
        {
        case 1:
            file.open("Database\\DataRiwayat.csv", ios::out | ios::app);

            file << namaUser << ',';
            file << slap[pilihan - 1].nama << ',';
            file << "wallet" << '\n';
            file.close();

            cout << "Pembayaran berhasil" << endl;
            break;
        default:
            cout << "Pembayaran dibatalkan" << endl;
            break;
        }
        cin.clear();
        cin.ignore();
        break;
    }
    default:
        break;
    }
}

int menuUser(string namaUser)
{
    int pilihan;
    while (true)
    {
        cout << "Menu" << endl;
        cout << "1. Lihat List Laptop" << endl;
        cout << "2. Beli" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter: ";

        cin >> pilihan;
        cin.clear();
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            listLaptop();
            break;
        case 2:
            beliLaptop(namaUser);
            break;
        case 0:
            return 0;
        }
    }
}
