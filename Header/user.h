#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
using namespace chrono;
using namespace this_thread;

//Prosedur untuk memberikan warna pada output
void setColorUser(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);}

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
    setColorUser(3);
    cout << string(139, '=') << endl;
    cout << left << setw(5); setColorUser(10); cout << "No."; setColorUser(3); cout << " | ";
    cout << left << setw(20); setColorUser(10); cout << "Nama"; setColorUser(3); cout << " | ";
    cout << left << setw(40); setColorUser(10); cout << "Harga"; setColorUser(3); cout << " | ";
    cout << left << setw(10); setColorUser(10); cout << "Stok"; setColorUser(3); cout << " | ";
    cout << left << setw(50); setColorUser(10); cout << "Deskripsi"; setColorUser(3); cout << " | " << endl;
    cout << string(139, '=') << endl;

    for (int i = 0; i < jumlahDataLaptop; ++i)
    {
        if (ulap[i].nama != "")
        {
            cout << left << setw(5); setColorUser(10); cout << i + 1; setColorUser(3); cout << " | ";
            cout << left << setw(20); setColorUser(10); cout << ulap[i].nama; setColorUser(3); cout << " | ";
            cout << left << setw(40); setColorUser(10); cout << ulap[i].harga; setColorUser(3); cout << " | ";
            cout << left << setw(10); setColorUser(10); cout << ulap[i].stok; setColorUser(3); cout << " | ";
            cout << left << setw(50); setColorUser(10); cout << ulap[i].deskripsi; setColorUser(3); cout << " | " << endl;
        }
    }
    setColorUser(3);
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
        listLaptop(jumlahDataLaptop, false);

        setColorUser(10);
        cout << "\nPilih laptop yang ingin dibeli >> ";
//
//        cin >> pilihan;
        setColorUser(6);
        while (!(cin >> noskipws >> pilihan && pilihan > 0 && pilihan <= jumlahDataLaptop && ulap[pilihan-1].stok > 0))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
            system("cls");
            setColorUser(4);
            cout << "========================================" << endl;
            cout << "          PILIHAN TIDAK VALID           " << endl;
            cout << "            ATAU STOK HABIS             " << endl;
            cout << "========================================" << endl;
            sleep_for(seconds(2));
            system("cls");
            beliLaptop(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (true)
        {
            system("cls");
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "           METODE PEMBAYARAN            " << endl;
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "    Silakan pilih metode pembayaran     " << endl;
            cout << "    [1] Bank Transfer" << endl;
            cout << "    [2] E-Wallet" << endl;
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "Pilih >> ";
            setColorUser(6);
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
                    setColorUser(4);
                    cout << "========================================" << endl;
                    cout << "           PILIHAN TIDAK VALID          " << endl;
                    cout << "========================================" << endl;
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
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "                   PEMBAYARAN                   " << endl;
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "Silakan transfer ke rekening:\n";
                setColorUser(6);
                cout << "BCAD 000000116413 a.n. Kelompok 4" << endl;
                setColorUser(10);
                cout << "Senilai: ";
                setColorUser(6);
                cout << "Rp" << ulap[pilihan - 1].harga << endl;
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "    [1] SUDAH TRANSFER" << endl;
                cout << "    [2] BATALKAN TRANSAKSI" << endl;
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "    Pilih >> ";

                setColorUser(6);
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
                        setColorUser(4);
                        cout << "========================================" << endl;
                        cout << "           PILIHAN TIDAK VALID          " << endl;
                        cout << "========================================" << endl;
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
                setColorUser(3);
                cout << "========================================" << endl;
                setColorUser(10);
                cout << "          PEMBAYARAN BERHASIL           " << endl;
                setColorUser(3);
                cout << "========================================" << endl;
                break;
            }
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColorUser(4);
                cout << "========================================" << endl;
                cout << "          TRANSAKSI DIBATALKAN          " << endl;
                cout << "========================================" << endl;
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
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "                   PEMBAYARAN                   " << endl;
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "Silakan transfer ke : ";
                setColorUser(6);
                cout << "DANA 08123123123" << endl;
                setColorUser(10);
                cout << "Senilai:";
                setColorUser(6);
                cout << "Rp" << ulap[pilihan - 1].harga << endl;
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "    [1] SUDAH TRANSFER" << endl;
                cout << "    [2] BATALKAN TRANSAKSI" << endl;
                setColorUser(3);
                cout << "================================================" << endl;
                setColorUser(10);
                cout << "    Pilih >> ";

                setColorUser(6);

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
                        setColorUser(4);
                        cout << "========================================" << endl;
                        cout << "           PILIHAN TIDAK VALID          " << endl;
                        cout << "========================================" << endl;
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
                setColorUser(3);
                cout << "========================================" << endl;
                setColorUser(10);
                cout << "          PEMBAYARAN BERHASIL           " << endl;
                setColorUser(3);
                cout << "========================================" << endl;

                break;
            }

            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter yang tersisa dalam buffer
                system("cls");
                setColorUser(4);
                cout << "========================================" << endl;
                cout << "          TRANSAKSI DIBATALKAN          " << endl;
                cout << "========================================" << endl;
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
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "               KONFIRMASI               " << endl;
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "\nApakah Anda ingin membeli lagi? (y/n)";
            setColorUser(6);
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

    setColorUser(3);
    cout << string(139, '=') << endl;
    setColorUser(10); cout << left << setw(25) << "Tanggal Pembelian"; setColorUser(3); cout << " | ";
    setColorUser(10); cout << left << setw(25) << "Waktu Pembelian"; setColorUser(3); cout << " | ";
    setColorUser(10); cout << left << setw(20) << "Laptop"; setColorUser(3); cout << " | ";
    setColorUser(10); cout << left << setw(40) << "Nominal"; setColorUser(3); cout << " | ";
    setColorUser(10); cout << left << setw(15) << "Pembayaran"; setColorUser(3); cout << " | " << endl;
    cout << string(139, '=') << endl;

    // Mencari nama didalam riwayat dan membandingkan dengan namaUser
    // untuk menunjukkan hanya yang di beli oleh user
    for (int i = 0; i < jumlahDataRiwayat; ++i)
    {
        if (namaUser == usp[i].namaUser)
        {
            // to_string digunakan untuk menggabungkan hari, bulan, dan tahun, serta jam, menit, dan detik menjadi satu string yang panjangnya konsisten.
            tm *ltm = localtime(&usp[i].waktuPembelian);
            setColorUser(10);
            cout << left << setw(25) << (to_string(ltm->tm_mday) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(1900 + ltm->tm_year));
            setColorUser(3); cout << " | ";
            setColorUser(10);
            cout << left << setw(25) << (to_string(ltm->tm_hour) + "." + to_string(ltm->tm_min) + "." + to_string(ltm->tm_sec) + " WITA");
            setColorUser(3); cout << " | ";
            setColorUser(10);
            cout << left << setw(20) << usp[i].namaLaptop;
            setColorUser(3); cout << " | ";
            setColorUser(10);
            cout << left << setw(40) << fixed << setprecision(0) << usp[i].nominal;
            setColorUser(3); cout << " | ";
            setColorUser(10);
            cout << left << setw(15) << usp[i].pembayaran;
            setColorUser(3); cout << " | " << endl;
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
        setColorUser(3);
        cout << "========================================" << endl;
        setColorUser(10);
        cout << "             MENU PENGGUNA              " << endl;
        setColorUser(3);
        cout << "========================================" << endl;
        setColorUser(10);
        cout << "    1. Lihat daftar laptop              " << endl;
        cout << "    2. Beli                             " << endl;
        cout << "    3. Lihat riwayat pembelian          " << endl;
        cout << "    0. Keluar dari akun                 " << endl;
        setColorUser(3);
        cout << "========================================" << endl;
        setColorUser(10);
        cout << "    Masukkan pilihan >> ";
        setColorUser(6);

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
                setColorUser(4);
                cout << "========================================" << endl;
                cout << "           PILIHAN TIDAK VALID          " << endl;
                cout << "========================================" << endl;
                sleep_for(seconds(2));
                system("cls");
                cin.clear();
                menuUser(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
            }

        switch (pilihan)
        {
        case 1:
            system("cls");
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "           LIHAT DAFTAR LAPTOP          " << endl;
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "    1. Urutkan berdasarkan nama" << endl;
            cout << "    2. Urutkan berdasarkan harga" << endl;
            setColorUser(3);
            cout << "========================================" << endl;
            setColorUser(10);
            cout << "    Masukkan pilihan >> ";
            setColorUser(6);
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
                    setColorUser(4);
                    cout << "========================================" << endl;
                    cout << "           PILIHAN TIDAK VALID          " << endl;
                    cout << "========================================" << endl;
                    sleep_for(seconds(2));
                    system("cls");
                    cin.clear();
                    menuUser(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
                }

            switch (pilihanSorting)
            {
            case 1:
                system("cls");
                listLaptop(jumlahDataLaptop, true);
                setColorUser(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            case 2:
                system("cls");
                listLaptop(jumlahDataLaptop, false);
                setColorUser(10);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                cin.clear();
                break;
            }
            break;
        case 2:
            system("cls");
            beliLaptop(namaUser, jumlahDataLaptop, jumlahDataRiwayat);
            break;
        case 3:
            system("cls");
            listRiwayatUser(namaUser, jumlahDataRiwayat);
            setColorUser(10);
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
            cin.clear();
            break;
        case 0:
            return 0;
        }
    }
}
