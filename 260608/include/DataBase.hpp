#pragma once
#include "Client.hpp"
#include "Animal.hpp"
#include "Report.hpp"

class DataBase {

    Client** clients;
    Animal** animals;
    Report** reports;

    unsigned int clientCount, animalCount, reportCount;

public:

    DataBase();

    ~DataBase();
};