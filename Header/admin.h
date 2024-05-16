#include <iostream>
#include <fstream>
#include <string>
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


// Prosedur menambahkan data laptop
void tambahkanDataLaptop(int& jumlahDataLaptop)
{
    string nama, deskripsi;
    int harga, stok;
    ofstream file;

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

    // Memasukkan data yang dimasukkan ke dalam csv
    file.open("Database\\laptop.csv", ios::out | ios::ate);

    file << nama << ",";
    file << harga << ",";
    file << stok << ",";
    file << deskripsi << "\n";
    file.close();

    jumlahDataLaptop += 1;
    cout << jumlahDataLaptop;
}

// Prosedur membaca data dari csv
void bacaDataLaptop()
{
    string namaLaptop, hargaLaptop, stokLaptop, descLaptop;
    int i = 1;
    ifstream file;

    file.open("Database\\laptop.csv", ios::in);

    while (!file.eof())
    {
        getline(file, namaLaptop, ',');
        getline(file, hargaLaptop, ',');
        getline(file, stokLaptop, ',');
        getline(file, descLaptop, '\n');

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
    file.close();
}

// Prosedur mengubah data dalam laptop
void ubahDataLaptop(int& jumlahDataLaptop)
{
    string placeholder;
    int pilihan, pilihanData;
    fstream file;
    adminDataLaptop alap[jumlahDataLaptop];

    // Mengambil data dari csv dan menampung ke dalam struct lokal
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

        cout << "Masukkan stok baru: ";
        cin >> alap[pilihan - 1].stok;
        cin.clear();
        cin.ignore();
        cout << "Masukkan deskripsi baru: ";
        getline(cin, alap[pilihan - 1].desc.deskripsi);
    }

    // Mengubah secara keseluruhan dari data dalam csv
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

// Prosedur menghapus data dalam csv
void hapusDataLaptop(int& jumlahDataLaptop)
{
    string placeholder;
    int pilihan, pilihanData;
    fstream file;

    adminDataLaptop alap[jumlahDataLaptop];

    // Mengambil data dari csv ke dalam struct lokal
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

    // Mengubah data yang di pilih menjadi empty string untuk di skip
    alap[pilihan - 1].nama = "";

    // Memasukkan data ke dalam csv yang bukan empty string
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
