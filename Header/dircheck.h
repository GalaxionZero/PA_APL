#include <filesystem>
using namespace filesystem;

// Melakukan mengecekan
int dirChecker()
{
    path p = current_path();
    if (!exists(p/"Database"));
        create_directory(p/"Database");
    if (!exists(p/"Database/DataLaptop.csv"))
        create_directory(p/"Database/DataLaptop.csv");
    if (!exists(p/"Database/DataRiwayat.csv"))
        create_directory(p/"Database/DataUser.csv");
    if (!exists(p/"Database/DataUser.csv"))
        create_directory(p/"Database/DataRiwayat.csv");

    return 0;
}
