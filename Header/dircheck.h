#include <filesystem>
#include <fstream>
using namespace filesystem;

// Melakukan pengecekan direktori dan file yang diperlukan
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
