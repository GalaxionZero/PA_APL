#include <iostream>
#include <fstream>
using namespace std;


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


int menuUser()
{
    int pilihan;
    while (true)
    {
        cout << "Menu" << endl;
        cout << "1. Lihat List Laptop" << endl;
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
        case 0:
            return 0;
        }
    }
}
