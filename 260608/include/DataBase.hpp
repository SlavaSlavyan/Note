#pragma once
#include "Client.hpp"
#include "Animal.hpp"
#include "Report.hpp"

class DataBase {

    Client** clients;
    Animal** animals;
    Report** reports;

    unsigned int ListCounts[3], NewId[3];

public:

    DataBase();

    ~DataBase();

    void AddClient();

    void RemoveClient();

    void FindClient();

    void AddAnimal();

    void RemoveAnimal();

    void FindAnimal();

    void AddReport();

    void RemoveReport();

    void FindReport();
};