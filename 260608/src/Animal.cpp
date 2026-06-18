#include "../include/Animal.hpp"
#include <cstring>
#include <iostream>


Animal::Animal() : id(0), years(0), owner(0), reports(nullptr), reportsCount(0) {}

void Animal::SetName(const char* newName) 
{
    if (newName) {
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }
    
    else name = nullptr;
}

Animal::Animal(const Animal& other) : Animal()
{
    id = other.id;
    years = other.years;
    owner = other.owner;
    reportsCount = other.reportsCount;
    
    if (!reportsCount) 
    {
        reports = new unsigned int[reportsCount];

        for (unsigned int i = 0; i < reportsCount; i++) {
            reports[i] = other.reports[i];
        }
    }

    SetName(other.name);
}

Animal::~Animal()
{
    if (name) delete[] name;
    if (reports) delete[] reports;
}

unsigned int Animal::GetReport(unsigned int listId) const
{
    if (listId >= reportsCount) return 0;

    return reports[listId];
}

unsigned int Animal::FindReport(unsigned int reportId)
{
    for (unsigned int i = 0; i < reportsCount; i++) {
        if (reportId == reports[i]) return i + 1;
    }

    return 0;
}

bool Animal::AddReport(unsigned int reportId)
{
    if (FindReport(reportId)) return false;

    unsigned int* newData = new unsigned int[reportsCount + 1];

    if (reports) {
        for (unsigned int i = 0; i < reportsCount; i++) {
            newData[i] = reports[i];
        }

        delete[] reports;
    }

    newData[reportsCount] = reportId;
    reports = newData;

    reportsCount++;

    return true;
}

bool Animal::RemoveReport(unsigned int listId)
{
    if (listId >= reportsCount) return false;

    if (reportsCount == 1) 
    {
        delete[] reports;
        reports = nullptr;

        reportsCount = 0;

        return true;
    }

    unsigned int* newData = new unsigned int[reportsCount - 1];

    for (unsigned int i = 0; i < listId; i++) {
        newData[i] = reports[i];
    }

    for (unsigned int i = listId + 1; i < reportsCount; i++) {
        newData[i - 1] = reports[i];
    }

    delete[] reports;
    reports = newData;

    reportsCount--;

    return true;
}

void Animal::Print()
{
    std::cout << "==============================\n  ID: " << id << "\n  Name: ";
    if (name) std::cout << name;
    else std::cout << "NULL";
    std::cout << "\n  Years: " << years << "\n  Count of reports: " << reportsCount << '\n';
}