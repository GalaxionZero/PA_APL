#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Mempermudah mengambil dan save data dari dan ke csv
struct userDataLaptop
{
    string nama;
    int harga;
    int stok;
    string deskripsi;
};

//Metode pembayaran yang diterima
string metodePembayaran[] = {"bri", "bni", "mandiri", "dana"};


//Prosedur read laptop
void listLaptop(int& jumlahDataLaptop)
{
    string namaLaptop, placeholder, descLaptop;
    int i = 1, stokLaptop, hargaLaptop;
    fstream file;

    file.open("Database\\DataLaptop.csv", ios::in);

    // ####Tambahkan pengkondisian kalo laptop habis, tidak di list lagi di listlaptop lain
    while (!file.eof())
    {
        getline(file, namaLaptop, ',');
        getline(file, placeholder, ',');
        hargaLaptop = stoi(placeholder);
        getline(file, placeholder, ',');
        stokLaptop = stoi(placeholder);
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
    file.close();
}


//Prosedur membeli laptop
void beliLaptop(string namaUser, int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    int pilihan;
    string modePembayaran, placeholder;
    fstream file;

    struct userDataLaptop ulap[jumlahDataLaptop];

    // Mengambil data dari csv dan menampung ke struct lokal
    file.open("Database\\DataLaptop.csv", ios::in);
    for (int i = 0; i < jumlahDataLaptop; i++)
    {
        getline(file, ulap[i].nama, ',');
        getline(file, placeholder, ',');
        ulap[i].harga = stoi(placeholder);
        getline(file, placeholder, ',');
        ulap[i].stok = stoi(placeholder);
        getline(file, ulap[i].deskripsi, '\n');
    }
    file.close();
    listLaptop(jumlahDataLaptop);

    cout << "Pilih laptop yang ingin dibeli: ";
    cin >> pilihan;
    cin.clear();
    cin.ignore();

    cout << "Memakai apa anda ingin membayar? (bank dll)";
    cin >> modePembayaran;
    cin.clear();
    cin.ignore();

    // Mengubah string stok mejadi int

    // Mengurangi stok laptop yang dibeli
    ulap[pilihan-1].stok -= 1;
    file.open("Database/DataLaptop.csv", ios::out | ios::trunc);

    for (int i = 0; i < jumlahDataLaptop; ++i)
    {
        file << ulap[i].nama << ",";
        file << ulap[i].harga << ",";
        file << ulap[i].stok << ",";
        file << ulap[i].deskripsi << "\n";
    }

    file.close();

    // Menambahkan riwayat pembelian
    file.open("Database\\DataRiwayat.csv", ios::out | ios::app);

    file << namaUser << ',';
    file << ulap[pilihan-1].nama << ',';
    file << modePembayaran << '\n';

    file.close();
    jumlahDataRiwayat += 1;
}

// Prosedur data riwayat
void listRiwayatUser(string namaUser, int& jumlahDataRiwayat)
{

}

// Menu User
int menuUser(string namaUser, int& jumlahDataLaptop, int&jumlahDataRiwayat)
{
    int pilihan;
    while (true)
    {
        cout << "Menu" << endl;
        cout << "1. Lihat List Laptop" << endl;
        cout << "2. Beli" << endl;
        cout << "3. Lihat Riwayat Pembelian" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter: ";

        cin >> pilihan;
        cin.clear();
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            listLaptop(jumlahDataLaptop);
            break;
        case 2:
            beliLaptop(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
            break;
        case 3:
            break;
        case 0:
            return 0;
        }
    }
}
