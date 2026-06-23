#include "../include/DataBase.hpp"
#include "../include/Entity.hpp"

DataBase::DataBase() : list(nullptr), reports(nullptr), length(0), reportsCount(0),
                       reportNewId(1), vetNewId(1), clientNewId(1), animalNewId(0) {}

DataBase::~DataBase()
{
    if (list) {
        for (unsigned long i = 0; i < length; i++) {
            delete list[i];
        }

        delete[] list;
        list = nullptr;
    }
    if (reports) {
        for (unsigned int i = 0; i < reportsCount; i++) {
            delete reports[i];
        }

        delete[] reports;
        reports = nullptr;
    }
}

void DataBase::IncreaseList() 
{
    Entity** newData = new Entity*[length + 1];

    if (list)
    {
        for (unsigned long i = 0; i < length; i++) {
            newData[i] = list[i];
        }

        delete[] list;
        list = newData;
    }

    length++;
}