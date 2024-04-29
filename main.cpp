#include <iostream>
#include <fstream>
#include "Header\user.h"
using namespace std;

struct user
{
    string nama;
    string password;
};

user us[10];

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


void loginUser()
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
            menuUser();
            break;
        }
    }
    filein.close();
}


int main()
{
    while (true)
    {
        int pilihan;
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
            loginUser();
            break;
        case 2:
            registerUser();
            break;
        case 0:
            return 0;
        }

    }
}
