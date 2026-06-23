#pragma once
#include "Entity.hpp"
#include "Report.hpp"

class DataBase {

    Entity** list;
    Report** reports;

    unsigned long length;
    unsigned int reportsCount, reportNewId, vetNewId, clientNewId, animalNewId;

    void IncreaseList();

public:

    DataBase();

    ~DataBase();

    void AddVet();

    void AddClient();

    void AddAnimal();

    void AddReport();

    void RemoveEntity();
};