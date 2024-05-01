#include <iostream>
#include <fstream>
using namespace std;


struct deskripsiLaptop
{
    string deskripsi;
};

struct dataLaptop
{
    string nama;
    double harga;
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

void tambahkanDataLaptop()
{
    string nama, harga, stok, deskripsi;
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
    fileout.open("Database\\DataLaptop.csv", ios::out | ios::app);

    fileout << nama << ",";
    fileout << harga << ",";
    fileout << stok << ",";
    fileout << deskripsi << "\n";
    fileout.close();
}


void bacaDataLaptop()
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
            cout << "No. " << i << endl << "Nama: " << namaLaptop << endl;
            cout << "Harga: " << hargaLaptop << endl;
            cout << "Stok: " << stokLaptop << endl;
            cout << descLaptop << endl << "|||" << endl;
        }
        i++;
    }

    // Beli laptop disini?
    // Atau di fungsi lain buat itu di panggil disini

    filein.close();
}


void ubahDataLaptop()
{
    string placeholder;
    int jumlahData = 0, pilihan, pilihanData;
    fstream filein;
    filein.open("Database\\DataLaptop.csv", ios::in);

    while (!filein.eof())
    {
        getline(filein, placeholder, 'n');
        jumlahData++;
    }

    filein.close();

    stringDataLaptop slap[jumlahData];

    filein.open("Database\\DataLaptop.csv", ios::in);

    for (int i = 0; i < jumlahData; i++)
    {
        getline(filein, slap[i].nama, ',');
        getline(filein, slap[i].harga, ',');
        getline(filein, slap[i].stok, ',');
        getline(filein, slap[i].deskripsi, '\n');
    }

    filein.close();

    bacaDataLaptop();

    cout << "Masukkan pilihan untuk data yang ingin di ubah: ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    cout << "1. Nama: " << slap[pilihan-1].nama << endl;
    cout << "2. Harga: " << slap[pilihan-1].harga << endl;
    cout << "3. Stok: " << slap[pilihan-1].stok << endl;
    cout << "4. Desc: " << slap[pilihan-1].deskripsi << endl;
    cout << "0. Semua" << endl;
    cout << "Bagian mana yang ingin diubah: ";

    cin >> pilihanData;
    cin.clear();
    cin.ignore();

    switch (pilihanData)
    {
    case 1:
        cout << "Masukkan nama baru: ";
        getline(cin, slap[pilihan-1].nama);
        break;
    case 2:
        cout << "Masukkan harga baru: ";
        cin >> slap[pilihan-1].harga;
        cin.clear();
        cin.ignore();
        break;
    case 3:
        cout << "Masukkan stok baru: ";
        cin >> slap[pilihan-1].stok;
        cin.clear();
        cin.ignore();
        break;
    case 4:
        cout << "Masukkan deskripsi baru: ";
        getline(cin, slap[pilihan-1].deskripsi);
        break;
    case 0:
        cout << "Masukkan nama baru: ";
        getline(cin, slap[pilihan-1].nama);
        cout << "Masukkan harga baru: ";
        cin >> slap[pilihan-1].harga;
        cin.clear();
        cin.ignore();
        cout << "Masukkan stok baru: ";
        cin >> slap[pilihan-1].stok;
        cin.clear();
        cin.ignore();
        cout << "Masukkan deskripsi baru: ";
        getline(cin, slap[pilihan-1].deskripsi);
    }

    filein.open("Database\\DataLaptop.csv", ios::out | ios::trunc);

    for (int i = 0; i < jumlahData; i++)
    {
        filein << slap[i].nama << ",";
        filein << slap[i].harga << ",";
        filein << slap[i].stok << ",";
        filein << slap[i].deskripsi << "\n";
    }

    filein.close();
}


//void hapusDataLaptop();
//{
//    string placeholder;
//    int jumlahData = 0, pilihan, pilihanData;
//    fstream filein;
//    filein.open("Database\\DataLaptop.csv", ios::in);
//
//    while (!filein.eof())
//    {
//        getline(filein, placeholder, 'n');
//        jumlahData++;
//    }
//
//    filein.close();
//
//    stringDataLaptop slap[jumlahData];
//
//    filein.open("Database\\DataLaptop.csv", ios::in);
//
//    for (int i = 0; i < jumlahData; i++)
//    {
//        getline(filein, slap[i].nama, ',');
//        getline(filein, slap[i].harga, ',');
//        getline(filein, slap[i].stok, ',');
//        getline(filein, slap[i].deskripsi, '\n');
//    }
//
//    bacaDataLaptop();
//
//    cin >> pilihan;
//    cin.clear();
//    cin.ignore();
//
//    slap[pilihan-1].nama
//}


int menuAdmin()
{
    int pilihan;
    while (true)
    {
        cout << "Menu Admin" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete"<< endl;
        cout << "0. Logout" << endl;
        cout << "Enter: ";

        cin >> pilihan;
        cin.clear();
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            tambahkanDataLaptop();
            break;
        case 2:
            bacaDataLaptop();
            break;
        case 3:
            ubahDataLaptop();
            break;
//        case 4:
//            hapusDataLaptop();
//            break;
        case 0:
            return 0;
        }
    }
}
