#include <iostream>
#include <windows.h>

using namespace std;

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