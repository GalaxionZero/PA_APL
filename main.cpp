#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstddef>

#include "Header/user.h"
#include "Header/admin.h"
#include "Header/dircheck.h"

using namespace std;
using namespace chrono;
using namespace this_thread;


struct
{
    string nama = "admin";
    string password = "admin";
} tokenAdmin;

//Prosedur untuk memberikan warna pad aoutput
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//Prosedur register
int registerUser()
{
    string namaUserBaru, passwordUserBaru, cekNamaIsTaken, placeholder;

    setColor(3);
    cout << "========================================" << endl;
    cout << "|               REGISTER               |" << endl;
    cout << "========================================" << endl;
    cout << "  Masukkan nama user: ";
    setColor(6);
    getline(cin, namaUserBaru);

    setColor(3);
    cout << "  Masukkan password: ";
    setColor(6);
    getline(cin, passwordUserBaru);

    fstream file;

    file.open("Database\\user_auth.csv", ios::in);
    while (!file.eof())
    {
        getline(file, cekNamaIsTaken, ',');
        getline(file, placeholder, '\n');

        if (namaUserBaru == cekNamaIsTaken)
        {
            system("cls");
            setColor(4);
            cout << "========================================" << endl;
            cout << "|       NAMA USER SUDAH DIGUNAKAN      |" << endl;
            cout << "========================================" << endl;
            sleep_for(seconds(2));
            system("cls");
            registerUser();
        }
    }
    file.close();

    file.open("Database\\user_auth.csv", ios::out | ios::app);
    file << namaUserBaru << ",";
    file << passwordUserBaru << "\n";
    file.close();
    return 0;

}

// Prosedur login
void loginUser(int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    string namaLogin, passwordLogin, cekNama, cekPassword;

    setColor(3);
    cout << "========================================" << endl;
    cout << "|               REGISTER               |" << endl;
    cout << "========================================" << endl;
    cout << "  Masukkan nama user: ";
    setColor(6);
    getline(cin, namaLogin);

    setColor(3);
    cout << "  Masukkan password: ";
    setColor(6);
    getline(cin, passwordLogin);


    fstream file;
    file.open("Database\\user_auth.csv", ios::in);

    while (!file.eof())
    {
        getline(file, cekNama, ',');
        getline(file, cekPassword, '\n');

        if (cekNama == namaLogin && cekPassword == passwordLogin)
        {
            menuUser(namaLogin, jumlahDataLaptop, jumlahDataRiwayat);
            break;
        }
    }
    file.close();

    if (namaLogin == tokenAdmin.nama && passwordLogin == tokenAdmin.password)
    {
        menuAdmin(jumlahDataLaptop, jumlahDataRiwayat);
    }
}

// Driver code
int main()
{
//    std::byte myByte{0};

//    cout << "Loading[--------------------]0%" << endl;
//    sleep_for(seconds(1));
//    system("cls");
//    cout << "Loading[#####---------------]25%" << endl;
//    sleep_for(seconds(1));
//    system("cls");
//    cout << "Loading[##########----------]50%" << endl;
//    sleep_for(seconds(1));
//    system("cls");
//    cout << "Loading[###############-----]75%" << endl;
//    sleep_for(seconds(1));
//    system("cls");
//    cout << "Loading[####################]100%" << endl;
//    sleep_for(seconds(1));
//    system("cls");

    setColor(2);
    cout << "Berhasil memasuki aplikasi..." << endl;
    sleep_for(seconds(2));
    system("cls");

    string placeholder;
    int pilihan, jumlahDataLaptop = 0, jumlahDataRiwayat = 0;
    fstream file;

    // Melakukan pengecekan direktori dan file database
    dirChecker();

    // Mengambil jumlah data yang ada didalam data laptop
    file.open("Database\\laptop.csv", ios::in);
    while (!file.eof())
    {
        getline(file, placeholder, '\n');
        if (placeholder != "")
            jumlahDataLaptop += 1;
    }
    file.close();

    // Mengambil jumlah data yang ada didalam data riwayat
    file.open("Database\\transaction_history.csv", ios::in);
    while (!file.eof())
    {
        getline(file, placeholder, '\n');
        if (placeholder != "")
            jumlahDataRiwayat += 1;
    }
    file.close();

    while (true)
    {
        setColor(3);
        system("cls");
        cout << "========================================" << endl;
        cout << "|              MENU LOGIN              |" << endl;
        cout << "========================================" << endl;
        cout << "|   1. Login                           |" << endl;
        cout << "|   2. Register                        |" << endl;
        cout << "|   0. Exit                            |" << endl;
        cout << "========================================" << endl;
        cout << "    Enter: ";
        setColor(6);

        cin >> pilihan;
        cin.clear();
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            system("cls");
            loginUser(jumlahDataLaptop, jumlahDataRiwayat);
            break;
        case 2:
            system("cls");
            registerUser();
            break;
        case 0:
            system("cls");
            setColor(3);
            cout << "========================================" << endl;
            cout << "|             TERIMA KASIH             |" << endl;
            cout << "========================================" << endl;
            return 0;
        }

    }
}
