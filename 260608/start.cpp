#include <iostream>
#include "include/DataBase.hpp"

int main()
{
    DataBase* db = new DataBase();

    delete db;

    return 0;
}