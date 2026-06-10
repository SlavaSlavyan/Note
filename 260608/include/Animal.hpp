#pragma once

class Animal {

    unsigned int id, reportsCount, * reports, years, owner;
    char * name;

public:

    Animal();

    Animal(unsigned int id, char* name, unsigned int years, unsigned int owner);

    Animal(const Animal& other);

    ~Animal();

    void AddReport(unsigned int newId);

    unsigned int FindReport(unsigned int findId);

    bool RemoveReport(unsigned int delId);
};