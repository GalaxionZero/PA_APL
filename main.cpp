#include <iostream>
#include <fstream>
#include "Header\user.h"
#include "Header\admin.h"
using namespace std;

struct
{
    string nama = "admin";
    string password = "admin";
} tokenAdmin;


void registerUser()
{
    string namaUserBaru, passwordUserBaru;
    cout << "Masukkan nama user: ";
    getline(cin, namaUserBaru);
    cout << "Masukkan password: ";
    getline(cin, passwordUserBaru);

    ofstream fileout;
    fileout.open("Database\\DataUser.csv", ios::out | ios::app);
    fileout << namaUserBaru << ",";
    fileout << passwordUserBaru << "\n";
    fileout.close();
}

void loginUser(int &jumlahData)
{
    string namaLogin, passwordLogin, cekNama, cekPassword;
    cout << "Masukkan nama user: ";
    getline(cin, namaLogin);
    cout << "Masukkan password: ";
    getline(cin, passwordLogin);

    ifstream filein;
    filein.open("Database\\DataUser.csv", ios::in);

    while (!filein.eof())
    {
        getline(filein, cekNama, ',');
        getline(filein, cekPassword, '\n');

        if (cekNama == namaLogin && cekPassword == passwordLogin)
        {
            menuUser(namaLogin, jumlahData);
            break;
        }
    }
    filein.close();

    if (namaLogin == tokenAdmin.nama && passwordLogin == tokenAdmin.password)
    {
        menuAdmin(jumlahData);
    }
}


int main()
{
    string placeholder;
    int pilihan, jumlahData = 0;
    fstream file;

    file.open("Database\\DataLaptop.csv", ios::in);

    while (!file.eof())
    {
        getline(file, placeholder, 'n');
        jumlahData += 1;
    }

    file.close();
    while (true)
    {
        cout << "Jumlah Data: " << jumlahData << endl;
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
            loginUser(jumlahData);
            break;
        case 2:
            registerUser();
            break;
        case 0:
            return 0;
        }

    }
}
