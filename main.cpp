#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstddef>
#include <iomanip>

#include "Header/user.h"
#include "Header/admin.h"
#include "Header/util.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

//kode warna :
//    3 = tabel
//    10 = tulisan (kecuali eror)
//    6 = inputan
//    4 = eror

struct
{
    string nama = "admin";
    string password = "admin";
} tokenAdmin;


//Prosedur untuk memberikan warna pada output
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Prosedur register
int registerUser()
{
    string namaUserBaru, passwordUserBaru, cekNamaIsTaken, placeholder;

    setColor(3);
    cout << "\t\t\t\t\t\t\t========================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\t\t                REGISTER                " << endl;
    setColor(3);
    cout << "\t\t\t\t\t\t\t========================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\t\t  Masukkan nama user : ";
    setColor(6);
    getline(cin, namaUserBaru);

    setColor(10);
    cout << "\t\t\t\t\t\t\t  Masukkan password : ";
    setColor(6);
    passwordUserBaru = takePassword();

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
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\t\t\t        NAMA USER SUDAH DIGUNAKAN       " << endl;
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            sleep_for(seconds(2));
            system("cls");
            registerUser();
        }

            else if (namaUserBaru == tokenAdmin.nama)
            {
                system("cls");
                setColor(4);
                cout << "\t\t\t\t\t\t\t========================================" << endl;
                cout << "\t\t\t\t\t\t\t     NAMA USER TIDAK DAPAT DIGUNAKAN    " << endl;
                cout << "\t\t\t\t\t\t\t========================================" << endl;
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
    cout << "\t\t\t\t\t\t\t========================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\t\t                 LOGIN                  " << endl;
    setColor(3);
    cout << "\t\t\t\t\t\t\t========================================" << endl;
    setColor(10);
    cout << "\t\t\t\t\t\t\t  Masukkan nama user : ";
    setColor(6);
    getline(cin, namaLogin);

    setColor(10);
    cout << "\t\t\t\t\t\t\t  Masukkan password : ";
    setColor(6);
    passwordLogin = takePassword();


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

    cout << "Loading..." << endl;
    sleep_for(seconds(2));
    system("cls");

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
        system("cls");
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t               MENU LOGIN               " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t    [1] Masuk                            " << endl;
        cout << "\t\t\t\t\t\t\t    [2] Daftar sebagai pengguna          " << endl;
        cout << "\t\t\t\t\t\t\t    [0] Keluar dari program              " << endl;
        setColor(3);
        cout << "\t\t\t\t\t\t\t========================================" << endl;
        setColor(10);
        cout << "\t\t\t\t\t\t\t  Enter >> ";
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
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            setColor(10);
            cout << "\t\t\t\t\t\t\t              TERIMA KASIH              " << endl;
            setColor(3);
            cout << "\t\t\t\t\t\t\t========================================" << endl;
            return 0;
        }

    }
}
