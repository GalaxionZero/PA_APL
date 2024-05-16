#include <fstream>
#include <filesystem>
#include <string>
using namespace filesystem;
using namespace std;

// Melakukan pengecekan direktori dan file database
int dirChecker()
{
    fstream file;
    path p = current_path();
    if (!exists(p/"Database"));
        create_directory(p/"Database");
    if (!exists("Database\\laptop.csv"))
        file.open("Database\\laptop.csv", ios::out); file.close();
    if (!exists("Database\\transaction_history.csv"))
        file.open("Database\\transaction_history.csv", ios::out); file.close();
    if (!exists("Database\\user_auth.csv"))
        file.open("Database\\user_auth.csv", ios::out); file.close();
    return 0;
}

//
//bool csvChecker(fstream& file)
//{
//    string placeholder;
//    while (!file.eof)
//    {
//        file.open();
//
//    }
//}
