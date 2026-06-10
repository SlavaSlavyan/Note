#include "../include/DataBase.hpp"
#include "../include/Client.hpp"
#include "../include/Animal.hpp"
#include "../include/Report.hpp"

DataBase::DataBase() : clients(nullptr), animals(nullptr), reports(nullptr), clientCount(0), animalCount(0), reportCount(0) {};

DataBase::~DataBase()
{
    if (clients) {
        for (unsigned int i = 0; i < clientCount; i++) delete clients[i];
        delete[] clients;
    }
    if (animals) {
        for (unsigned int i = 0; i < animalCount; i++) delete animals[i];
        delete[] animals;
    }
    if (reports) {
        for (unsigned int i = 0; i < reportCount; i++) delete reports[i];
        delete[] reports;
    }

    clients = nullptr;
    animals = nullptr;
    reports = nullptr;
}

