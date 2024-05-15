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

struct stringDataLaptop
{
    string nama;
    string harga;
    string stok;
    string deskripsi;
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
    stringDataLaptop slap[jumlahDataLaptop];

    file.open("Database\\laptop.csv", ios::in);

    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        getline(file, slap[i].nama, ',');
        getline(file, slap[i].harga, ',');
        getline(file, slap[i].stok, ',');
        getline(file, slap[i].deskripsi, '\n');
    }

    file.close();
    bacaDataLaptop();

    cout << "Masukkan pilihan untuk data yang ingin di ubah: ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    cout << "1. Nama: " << slap[pilihan - 1].nama << endl;
    cout << "2. Harga: " << slap[pilihan - 1].harga << endl;
    cout << "3. Stok: " << slap[pilihan - 1].stok << endl;
    cout << "4. Desc: " << slap[pilihan - 1].deskripsi << endl;
    cout << "0. Semua" << endl;
    cout << "Bagian mana yang ingin diubah: ";

    cin >> pilihanData;
    cin.clear();
    cin.ignore();

    switch (pilihanData)
    {
    case 1:
        cout << "Masukkan nama baru: ";
        getline(cin, slap[pilihan - 1].nama);
        break;
    case 2:
        cout << "Masukkan harga baru: ";
        cin >> slap[pilihan - 1].harga;
        cin.clear();
        cin.ignore();
        break;
    case 3:
        cout << "Masukkan stok baru: ";
        cin >> slap[pilihan - 1].stok;
        cin.clear();
        cin.ignore();
        break;
    case 4:
        cout << "Masukkan deskripsi baru: ";
        getline(cin, slap[pilihan - 1].deskripsi);
        break;
    case 0:
        cout << "Masukkan nama baru: ";
        getline(cin, slap[pilihan - 1].nama);
        cout << "Masukkan harga baru: ";
        cin >> slap[pilihan - 1].harga;
        cin.clear();
        cin.ignore();
        cout << "Masukkan stok baru: ";
        cin >> slap[pilihan - 1].stok;
        cin.clear();
        cin.ignore();
        cout << "Masukkan deskripsi baru: ";
        getline(cin, slap[pilihan - 1].deskripsi);
    }

    file.open("Database\\laptop.csv", ios::out | ios::trunc);

    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        file << slap[i].nama << ",";
        file << slap[i].harga << ",";
        file << slap[i].stok << ",";
        file << slap[i].deskripsi << "\n";
    }
    file.close();
}

void hapusDataLaptop(int& jumlahDataLaptop)
{
    string placeholder;
    int pilihan, pilihanData;
    fstream file;

    stringDataLaptop slap[jumlahDataLaptop];

    file.open("Database\\laptop.csv", ios::in);
    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        getline(file, slap[i].nama, ',');
        getline(file, slap[i].harga, ',');
        getline(file, slap[i].stok, ',');
        getline(file, slap[i].deskripsi, '\n');
    }
    file.close();

    bacaDataLaptop();

    cout << "Masukkan nomor urut data yang ingin dihapus >> ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    slap[pilihan - 1].nama = "";

    file.open("Database\\laptop.csv", ios::out | ios::trunc);
    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        if (slap[i].nama != "")
        {
            file << slap[i].nama << ",";
            file << slap[i].harga << ",";
            file << slap[i].stok << ",";
            file << slap[i].deskripsi << "\n";
        }
    }
    file.close();
}

int menuAdmin(int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    int pilihan;
    while (true)
    {
        cout << "Menu Admin" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
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
            ubahDataLaptop(jumlahDataLaptop);
            break;
        case 4:
            hapusDataLaptop(jumlahDataLaptop);
            break;
        case 0:
            return 0;
        }
    }
}
