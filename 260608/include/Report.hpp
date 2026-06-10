#pragma once

class Report {

    unsigned int id, animal;
    char* data;

public:

    Report();

    Report(unsigned int id, char* data, unsigned int animal);

    Report(const Report& other);

    ~Report();
};