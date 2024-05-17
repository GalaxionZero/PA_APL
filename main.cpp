#include <iostream>
#include <fstream>
#include "Header/user.h"
#include "Header/admin.h"
#include "Header/dircheck.h"
using namespace std;

struct
{
    string nama = "admin";
    string password = "admin";
} tokenAdmin;

//Prosedur register
void registerUser()
{
    string namaUserBaru, passwordUserBaru;
    fstream file;

    cout << "Masukkan nama user: ";
    getline(cin, namaUserBaru);
    cout << "Masukkan password: ";
    getline(cin, passwordUserBaru);

    file.open("Database\\user_auth.csv", ios::out | ios::ate);
    file << namaUserBaru << ",";
    file << passwordUserBaru << "\n";
    file.close();
}

// Prosedur login
void loginUser(int& jumlahDataLaptop, int& jumlahDataRiwayat)
{
    string namaLogin, passwordLogin, cekNama, cekPassword;
    cout << "Masukkan nama user: ";
    getline(cin, namaLogin);
    cout << "Masukkan password: ";
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
        jumlahDataLaptop += 1;
        cout << jumlahDataLaptop << endl;
    }
    file.close();

    // Mengambil jumlah data yang ada didalam data riwayat
    file.open("Database\\transaction_history.csv", ios::in);
    while (!file.eof())
    {
        getline(file, placeholder, '\n');
        jumlahDataRiwayat += 1;
        cout << jumlahDataRiwayat << endl;
    }
    file.close();

    while (true)
    {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter: ";

        cin >> pilihan;
        cin.clear();
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            loginUser(jumlahDataLaptop, jumlahDataRiwayat);
            break;
        case 2:
            registerUser();
            break;
        case 0:
            return 0;
        }

    }
}
