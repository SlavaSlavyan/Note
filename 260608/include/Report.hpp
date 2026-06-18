#pragma once

class Report {

    unsigned int id, animal;
    char * date, * info;

public:

    Report();

    Report(const Report& other);

    ~Report();

    unsigned int GetId() { return id; }

    unsigned int GetAnimal() { return animal; }

    const char * GetDate() { return date; }

    const char * GetInfo() { return info; }

    void SetId(unsigned int newId) { id = newId; }

    void SetAnimal(unsigned int newAnimal) { animal = newAnimal; }

    void SetDate(const char* newDate);

    void SetInfo(const char* newInfo);

    void Print();
};