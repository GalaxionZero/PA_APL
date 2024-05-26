#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "util.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

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


void selectionSort(userDataLaptop ulap[], int& jumlahDataLaptop)
{
    int i, j, minimum;
    for (i = 0; i < jumlahDataLaptop - 1; i++)
    {
        minimum = i;
        for (j = i+1; j < jumlahDataLaptop; j++)
        {
            if (ulap[j].nama < ulap[minimum].nama)
            {
                minimum = j;
            }
        }

        if (minimum != i)
        {
        userDataLaptop temp = ulap[minimum];
        ulap[minimum] = ulap[i];
        ulap[i] = temp;
        }
    }
}


void shellSort(userDataLaptop ulap[], int& jumlahDataLaptop)
{
    for (int gap = jumlahDataLaptop / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < jumlahDataLaptop; i++)
        {
            userDataLaptop temp = ulap[i];
            int j;
            for (j = i; j >= gap && ulap[j-gap].harga > temp.harga; j -= gap)
            {
                ulap[j] = ulap[j - gap];
            }
            ulap[j] = temp;
        }
    }
}

// Prosedur read laptop
void listLaptop(int &jumlahDataLaptop, bool sortByName)
{
    string placeholder;
    fstream file;
    userDataLaptop ulap[jumlahDataLaptop];

    // Mengambil data
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

    // Sorting secara nama menggunakan selection
    if (sortByName)
        selectionSort(ulap, jumlahDataLaptop);
    // Sorting secara harga menggunakan shell sort
    else
        shellSort(ulap, jumlahDataLaptop);

    // Header tabel
    setColor(3);
    cout << string(139, '=') << endl;
    cout << left << setw(5); setColor(10); cout << "No."; setColor(3); cout << " | ";
    cout << left << setw(20); setColor(10); cout << "Nama"; setColor(3); cout << " | ";
    cout << left << setw(40); setColor(10); cout << "Harga"; setColor(3); cout << " | ";
    cout << left << setw(10); setColor(10); cout << "Stok"; setColor(3); cout << " | ";
    cout << left << setw(50); setColor(10); cout << "Deskripsi"; setColor(3); cout << " | " << endl;
    cout << string(139, '=') << endl;

    for (int i = 0; i < jumlahDataLaptop; ++i)
    {
        if (ulap[i].nama != "")
        {
            cout << left << setw(5); setColor(10); cout << i + 1; setColor(3); cout << " | ";
            cout << left << setw(20); setColor(10); cout << ulap[i].nama; setColor(3); cout << " | ";
            cout << left << setw(40); setColor(10); cout << ulap[i].harga; setColor(3); cout << " | ";
            cout << left << setw(10); setColor(10); cout << ulap[i].stok; setColor(3); cout << " | ";
            cout << left << setw(50); setColor(10); cout << ulap[i].deskripsi; setColor(3); cout << " | " << endl;
        }
    }
    setColor(3);
    cout << string(139, '=') << endl;
}

// Prosedur membeli laptop
void beliLaptop(string namaUser, int &jumlahDataLaptop, int &jumlahDataRiwayat)
{
    struct userDataLaptop ulap[jumlahDataLaptop];
    int pilihan, metodePembayaran;
    string placeholder;
    char ulang = 'y';
    fstream file;

    do
    {
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
        shellSort(ulap, jumlahDataLaptop);

        while (true)
        {
            listLaptop(jumlahDataLaptop, false);
            setColor(10);
            cout << "\nPilih laptop yang ingin dibeli >> ";
            setColor(6);
            if (cin >> noskipws >> pilihan && pilihan > 0 && pilihan <= jumlahDataLaptop && ulap[pilihan-1].stok > 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t          PILIHAN TIDAK VALID           " << endl;
                    cout << "\t\t\t\t\t\t\t            ATAU STOK HABIS             " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");
                }
        }

        while (true)
        {
            system("cls");
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t           METODE PEMBAYARAN            " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t    Silakan pilih metode pembayaran     " << endl;
            cout << "\t\t\t\t\t\t\t    [1] Bank Transfer" << endl;
            cout << "\t\t\t\t\t\t\t    [2] E-Wallet" << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t  Pilih >> ";
            setColor(6);
            if (cin >> noskipws >> metodePembayaran && metodePembayaran > 0 && metodePembayaran <= 2)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t           PILIHAN TIDAK VALID          " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");
                }
        }
        switch (metodePembayaran)
        {
        case 1:
        {
            int statusPembayaran;
            while (true)
            {
                system("cls");
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t                   PEMBAYARAN                   " << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\tSilakan transfer ke rekening:\n";
                cout << "\t\t\t\t\t\tBCAD";
                setColor(6);
                cout << " 000000116413 ";
                setColor(10);
                cout << "a.n. Kelompok 4" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\tSenilai: ";
                setColor(6);
                cout << "Rp" << ulap[pilihan - 1].harga << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t    [1] SUDAH TRANSFER" << endl;
                cout << "\t\t\t\t\t\t    [2] BATALKAN TRANSAKSI" << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t  Pilih >> ";

                setColor(6);
                if (cin >> noskipws >> statusPembayaran && statusPembayaran > 0 && statusPembayaran <= 2)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                    else
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                        system("cls");
                        setColor(4);
                        cout << "\t\t\t\t\t\t\t========================================" << endl;
                        cout << "\t\t\t\t\t\t\t           PILIHAN TIDAK VALID          " << endl;
                        cout << "\t\t\t\t\t\t\t========================================" << endl;
                        sleep_for(seconds(2));
                        system("cls");
                        cin.clear();
                    }
            }

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

                system("cls");
                setColor(7);
                cout << "Memproses..." << endl;
                sleep_for(seconds(2));
                system("cls");
                setColor(3);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t\t          PEMBAYARAN BERHASIL           " << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                break;
            }
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColor(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t          TRANSAKSI DIBATALKAN          " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
                cin.clear();
                break;
            }

            break;
        }
        case 2:
        {
            int statusPembayaran;
            while (true)
            {
                system("cls");
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t                   PEMBAYARAN                   " << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\tSilakan transfer ke : " << endl;
                cout << "\t\t\t\t\t\tDANA";
                setColor(6);
                cout << " 08123123123" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\tSenilai:";
                setColor(6);
                cout << "Rp" << ulap[pilihan - 1].harga << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t    [1] SUDAH TRANSFER" << endl;
                cout << "\t\t\t\t\t\t    [2] BATALKAN TRANSAKSI" << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t================================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t  Pilih >> ";

                setColor(6);

                if (cin >> noskipws >> statusPembayaran && statusPembayaran > 0 && statusPembayaran <= 2)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                    else
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                        system("cls");
                        setColor(4);
                        cout << "\t\t\t\t\t\t\t========================================" << endl;
                        cout << "\t\t\t\t\t\t\t           PILIHAN TIDAK VALID          " << endl;
                        cout << "\t\t\t\t\t\t\t========================================" << endl;
                        sleep_for(seconds(2));
                        system("cls");
                        cin.clear();
                    }
            }

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

                system("cls");
                setColor(7);
                cout << "Memproses..." << endl;
                sleep_for(seconds(2));
                system("cls");
                setColor(3);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                setColor(10);
                cout << "\t\t\t\t\t\t\t          PEMBAYARAN BERHASIL           " << endl;
                setColor(3);
                cout << "\t\t\t\t\t\t\t========================================" << endl;

                break;
            }

            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColor(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t          TRANSAKSI DIBATALKAN          " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
                cin.clear();
                break;
            }

            break;
        }

        default:
            break;
        }

        while (true)
        {
            system("cls");
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t               KONFIRMASI               " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\n\t\t\t\t\t\t\tApakah Anda ingin membeli lagi? (y/n)";
            setColor(6);
            if (cin >> noskipws >> ulang && ulang == 'y')
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                break;
            }
            else if (ulang == 'n')
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
            }
        }
        system("cls");
    } while (ulang == 'y');
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

    setColor(3);
    cout << string(139, '=') << endl;
    setColor(10); cout << left << setw(25) << "Tanggal Pembelian"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(25) << "Waktu Pembelian"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(20) << "Laptop"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(40) << "Nominal"; setColor(3); cout << " | ";
    setColor(10); cout << left << setw(15) << "Pembayaran"; setColor(3); cout << " | " << endl;
    cout << string(139, '=') << endl;

    // Mencari nama didalam riwayat dan membandingkan dengan namaUser
    // untuk menunjukkan hanya yang di beli oleh user
    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        if (namaUser == usp[i].namaUser)
        {
            // to_string digunakan untuk menggabungkan hari, bulan, dan tahun, serta jam, menit, dan detik menjadi satu string yang panjangnya konsisten.
            tm *ltm = localtime(&usp[i].waktuPembelian);
            setColor(10);
            cout << left << setw(25) << (to_string(ltm->tm_mday) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(1900 + ltm->tm_year));
            setColor(3); cout << " | ";
            setColor(10);
            cout << left << setw(25) << (to_string(ltm->tm_hour) + "." + to_string(ltm->tm_min) + "." + to_string(ltm->tm_sec) + " WITA");
            setColor(3); cout << " | ";
            setColor(10);
            cout << left << setw(20) << usp[i].namaLaptop;
            setColor(3); cout << " | ";
            setColor(10);
            cout << left << setw(40) << fixed << setprecision(0) << usp[i].nominal;
            setColor(3); cout << " | ";
            setColor(10);
            cout << left << setw(15) << usp[i].pembayaran;
            setColor(3); cout << " | " << endl;
        }
    }
    cout << string(139, '=') << endl;
}

// Menu User
int menuUser(string namaUser, int &jumlahDataLaptop, int &jumlahDataRiwayat)
{
    int pilihan, pilihanSorting;
    while (true)
    {
        system("cls");
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t             MENU PENGGUNA              " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t    [1] Lihat daftar laptop              " << endl;
        cout << "\t\t\t\t\t\t\t    [2] Beli                             " << endl;
        cout << "\t\t\t\t\t\t\t    [3] Lihat riwayat pembelian          " << endl;
        cout << "\t\t\t\t\t\t\t    [0] Keluar dari akun                 " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t  Masukkan pilihan >> ";
        setColor(6);

        if (cin >> noskipws >> pilihan && pilihan >= 0 && pilihan <= 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColor(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t           PILIHAN TIDAK VALID          " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
                cin.clear();
                menuUser(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
            }

        switch (pilihan)
        {
        case 1:
            system("cls");
            setColor(7);
            cout << "Loading..." << endl;
            sleep_for(seconds(2));
            system("cls");
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t           LIHAT DAFTAR LAPTOP          " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t    [1] Urutkan berdasarkan nama" << endl;
            cout << "\t\t\t\t\t\t\t    [2] Urutkan berdasarkan harga" << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t  Masukkan pilihan >> ";
            setColor(6);
            if (cin >> noskipws >> pilihanSorting && pilihanSorting > 0 && pilihanSorting <= 2)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                    system("cls");
                    setColor(4);
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    cout << "\t\t\t\t\t\t\t           PILIHAN TIDAK VALID          " << endl;
                    cout << "\t\t\t\t\t\t\t========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");
                    cin.clear();
                    menuUser(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
                }

            switch (pilihanSorting)
            {
            case 1:
                system("cls");
                setColor(7);
                cout << "Loading..." << endl;
                sleep_for(seconds(2));
                system("cls");
                listLaptop(jumlahDataLaptop, true);
                setColor(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            case 2:
                system("cls");
                setColor(7);
                cout << "Loading..." << endl;
                sleep_for(seconds(2));
                system("cls");
                listLaptop(jumlahDataLaptop, false);
                setColor(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            }
            break;
        case 2:
            system("cls");
            setColor(7);
            cout << "Loading..." << endl;
            sleep_for(seconds(2));
            system("cls");
            beliLaptop(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
            break;
        case 3:
            system("cls");
            setColor(7);
            cout << "Loading..." << endl;
            sleep_for(seconds(2));
            system("cls");
            listRiwayatUser(namaUser, jumlahDataRiwayat);
            setColor(10);
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
            cin.clear();
            break;
        case 0:
            system("cls");
            setColor(7);
            cout << "Keluar dari menu pengguna..." << endl;
            sleep_for(seconds(2));
            system("cls");
            return 0;
        }
    }
}
