#pragma once

class Animal {

    unsigned int id, years, owner, * reports, reportsCount;
    char* name;

public:

    Animal();

    Animal(const Animal& other);

    ~Animal();

    unsigned int GetId() const { return id; }

    unsigned int GetYears() const { return years; }

    unsigned int GetOwner() const { return owner; }

    const unsigned int * GetAllReports() const { return reports; }

    unsigned int GetReport(unsigned int listId) const;

    unsigned int GetReportsCount() const { return reportsCount; }

    const char * GetName() const { return name; }

    void SetId(unsigned int newId) { id = newId; }

    void SetYears(unsigned int newYears) { years = newYears; }

    void SetOwner(unsigned int newOwner) { owner = newOwner; }

    bool AddReport(unsigned int reportId);

    bool RemoveReport(unsigned int listId);

    unsigned int FindReport(unsigned int reportId);

    void SetName(const char* newName);

    void Print();
};