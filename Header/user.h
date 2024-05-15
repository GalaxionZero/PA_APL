#include <iostream>
#include <fstream>
using namespace std;


struct userDataLaptop
{
    string nama;
    string harga;
    string stok;
    string deskripsi;
};

string metodePembayaran[] = {"bri", "bni", "mandiri", "dana"};


void listLaptop(int& jumlahData)
{
    string namaLaptop, hargaLaptop, stokLaptop, descLaptop;
    int i = 1;
    fstream file;

    file.open("Database\\DataLaptop.csv", ios::in);

    while (!file.eof())
    {
        getline(file, namaLaptop, ',');
        getline(file, hargaLaptop, ',');
        getline(file, stokLaptop, ',');
        getline(file, descLaptop, '\n');

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

    file.close();
}


void beliLaptop(string namaUser, int& jumlahData)
{
    int pilihan;
    string placeholder, modePembayaran;
    fstream file;

    struct userDataLaptop ulap[jumlahData];

    file.open("Database\\DataLaptop.csv", ios::in);
    for (int i = 0; i < jumlahData; i++)
    {
        getline(file, ulap[i].nama, ',');
        getline(file, ulap[i].harga, ',');
        getline(file, ulap[i].stok, ',');
        getline(file, ulap[i].deskripsi, '\n');
    }
    file.close();
    listLaptop(jumlahData);

    cout << "Pilih laptop yang ingin dibeli: ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    cout << "Memakai apa anda ingin membayar? (bank dll)";
    cin >> modePembayaran;
    cin.clear();
    cin.ignore();

    file.open("Database\\DataRiwayat.csv", ios::out | ios::app);

    file << namaUser << ',';
    file << ulap[pilihan-1].nama << ',';
    file << modePembayaran << '\n';
    file.close();
}

int menuUser(string namaUser, int& jumlahData)
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
            listLaptop(jumlahData);
            break;
        case 2:
            beliLaptop(namaUser, jumlahData);
            break;
        case 0:
            return 0;
        }
    }
}
