#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <windows.h>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

// Melakukan pengecekan direktori dan file yang diperlukan
int dirChecker()
{
    fstream file;
    path p = current_path();
    if (!exists(p/"Database"))
        create_directory(p/"Database");
    if (!exists("Database\\laptop.csv"))
        file.open("Database\\laptop.csv", ios::out); file.close();
    if (!exists("Database\\transaction_history.csv"))
        file.open("Database\\transaction_history.csv", ios::out); file.close();
    if (!exists("Database\\user_auth.csv"))
        file.open("Database\\user_auth.csv", ios::out); file.close();
    return 0;
}

// Prosedur untuk memberikan warna pada output
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string takePassword()
{
    HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;

    GetConsoleMode(hStdInput, &mode);

    SetConsoleMode(hStdInput, mode & (~ENABLE_ECHO_INPUT));

    string password;
    getline(cin, password);
    SetConsoleMode(hStdInput, mode);

    return password;
}

#endif