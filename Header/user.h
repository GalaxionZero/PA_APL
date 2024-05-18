#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// Mengambil dan save data dari dan ke csv dataLaptop
struct userDataLaptop
{
    string nama;
    int harga;
    int stok;
    string deskripsi;
};

// Mengambil dan save data dari dan ke csv dataRiwayat
struct userSejarahPembelian
{
    time_t waktuPembelian;
    string namaUser;
    string namaLaptop;
    int nominal;
    string pembayaran;
};

// Prosedur read laptop
void listLaptop(int &jumlahDataLaptop)
{
    string namaLaptop, placeholder, descLaptop;
    int i = 1, stokLaptop, hargaLaptop;
    fstream file;

    file.open("Database\\laptop.csv", ios::in);

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
            cout << "No. " << i << endl
                 << "Nama: " << namaLaptop << endl;
            cout << "Harga: " << hargaLaptop << endl;
            cout << "Stok: " << stokLaptop << endl;
            cout << descLaptop << endl
                 << "|||" << endl;
        }
        i++;
    }
    file.close();
}

// Prosedur membeli laptop
void beliLaptop(string namaUser, int &jumlahDataLaptop, int &jumlahDataRiwayat)
{
    struct userDataLaptop ulap[jumlahDataLaptop];
    int pilihan, metodePembayaran;
    string placeholder;
    fstream file;

    // Mengambil data dari csv dan menampung ke struct lokal
    file.open("Database\\laptop.csv", ios::in);
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
        cout << "Senilai: Rp" << ulap[pilihan - 1].harga << endl;
        cout << "[1] SUDAH TRANSFER" << endl;
        cout << "[2] BATALKAN TRANSAKSI" << endl;
        cout << "Pilih >> ";
        cin >> statusPembayaran;
        switch (statusPembayaran)
        {
        case 1:
        {
            file.open("Database\\transaction_history.csv", ios::out | ios::app);

            time_t now = time(0);
            file << now << ',';
            file << namaUser << ',';
            file << ulap[pilihan - 1].nama << ',';
            file << ulap[pilihan - 1].harga << ',';
            file << "bank" << '\n';
            file.close();

            jumlahDataRiwayat += 1;

            ulap[pilihan - 1].stok -= 1;

            file.open("Database\\laptop.csv", ios::out | ios::trunc);
            for (int i = 0; i < jumlahDataLaptop; ++i)
            {
                file << ulap[i].nama << ',';
                file << ulap[i].harga << ',';
                file << ulap[i].stok << ',';
                file << ulap[i].deskripsi << '\n';
            }
            file.close();

            cout << "Pembayaran berhasil" << endl;
            break;
        }
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
        cout << "Senilai: Rp" << ulap[pilihan - 1].harga << endl;
        cout << "[1] SUDAH TRANSFER" << endl;
        cout << "[2] BATALKAN TRANSAKSI" << endl;
        cout << "Pilih >> ";
        cin >> statusPembayaran;
        switch (statusPembayaran)
        {
        case 1:
        {
            file.open("Database\\transaction_history.csv", ios::out | ios::app);

            time_t now = time(0);
            file << now << ',';
            file << namaUser << ',';
            file << ulap[pilihan - 1].nama << ',';
            file << ulap[pilihan - 1].harga << ',';
            file << "wallet" << '\n';
            file.close();
            jumlahDataRiwayat += 1;

            ulap[pilihan - 1].stok -= 1;

            file.open("Database\\laptop.csv", ios::out | ios::trunc);
            for (int i = 0; i < jumlahDataLaptop; ++i)
            {
                file << ulap[i].nama << ',';
                file << ulap[i].harga << ',';
                file << ulap[i].stok << ',';
                file << ulap[i].deskripsi << '\n';
            }
            file.close();

            cout << "Pembayaran berhasil" << endl;
            break;
        }
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

// Prosedur data riwayat
void listRiwayatUser(string namaUser, int &jumlahDataRiwayat)
{
    fstream file;
    string placeholder;
    userSejarahPembelian usp[jumlahDataRiwayat];

    // Mengambil data riwayat dari csv
    file.open("Database\\transaction_history.csv", ios::in);
    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        getline(file, placeholder, ',');
        usp[i].waktuPembelian = stoi(placeholder);
        getline(file, usp[i].namaUser, ',');
        getline(file, usp[i].namaLaptop, ',');
        getline(file, placeholder, ',');
        usp[i].nominal = stoi(placeholder);
        getline(file, usp[i].pembayaran, '\n');
    }
    file.close();

    // Mencari nama didalam riwayat dan membandingkan dengan namaUser
    // untuk menunjukkan hanya yang di beli oleh user
    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        if (namaUser == usp[i].namaUser)
        {
            tm *ltm = localtime(&usp[i].waktuPembelian);
            cout << "Waktu Pembelian: " << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << " pukul " << ltm->tm_hour << "." << ltm->tm_min << "." << ltm->tm_sec << endl;
            cout << usp[i].namaLaptop << endl;
            cout << usp[i].nominal << endl;
            cout << usp[i].pembayaran << endl;
        }
    }
}

// Menu User
int menuUser(string namaUser, int &jumlahDataLaptop, int &jumlahDataRiwayat)
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
            listRiwayatUser(namaUser, jumlahDataRiwayat);
            break;
        case 0:
            return 0;
        }
    }
}
