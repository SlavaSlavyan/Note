#include "../include/Animal.hpp"
#include <cstring>

Animal::Animal() : id(0), reportsCount(0), reports(nullptr), name(nullptr), years(0) {}

Animal::Animal(unsigned int i, char* n, unsigned int y, unsigned int o) : Animal()
{
    id = i;
    years = y;
    owner = o;

    if (n) {
        name = new char[strlen(n + 1)];
        strcpy_s(name, strlen(n + 1), n);
    }
}

Animal::Animal(const Animal& other) : Animal(other.id, other.name, other.years, other.owner)
{
    reportsCount = other.reportsCount;

    if (reportsCount) 
    {
        reports = new unsigned int[reportsCount];
    
        for (unsigned int i = 0; i < reportsCount; i++) {
            reports[i] = other.reports[i];
        }
    }
}

Animal::~Animal() 
{
    if (name) delete[] name;
    if (reports) delete[] reports;
    
    name = nullptr;
    reports = nullptr;
}

void Animal::AddReport(unsigned int newId)
{
    unsigned int* oldData = nullptr;

    if (reportsCount) 
    {
        oldData = new unsigned int[reportsCount];
        
        for (unsigned int i = 0; i < reportsCount; i++) {
            oldData[i] = reports[i];
        }

        delete[] reports;
        reports = nullptr;
    }

    reports = new unsigned int[reportsCount + 1];

    if (oldData) 
    {
        for (unsigned int i = 0; i < reportsCount; i++) {
            reports[i] = oldData[i];
        }

        delete[] oldData;
        oldData = nullptr;
    }

    reports[reportsCount] = newId;
    reportsCount++;
}

unsigned int Animal::FindReport(unsigned int findId)
{
    for (unsigned int i = 0; i < reportsCount; i++) {
        if (reports[i] == findId) return i + 1;
    }

    return 0;
}

bool Animal::RemoveReport(unsigned int delId)
{
    delId = FindReport(delId) - 1;

    if (delId == -1) return false;

    unsigned int* newData = nullptr;

    if (reportsCount - 1) 
    {
        newData = new unsigned int[reportsCount - 1];
        
        for (unsigned int i = 0; i < delId; i++) {
            newData[i] = reports[i];
        }

        for (unsigned int i = delId + 1; i < reportsCount; i++) {
            newData[i - 1] = reports[i];
        }
    }

    delete[] reports;
    reports = newData;

    reportsCount--;
    
    return true;
}