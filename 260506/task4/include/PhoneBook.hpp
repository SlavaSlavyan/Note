#pragma once
#include "Contact.hpp"

class PhoneBook {

    Contact** contacts;
    unsigned int length;

public:

    PhoneBook();

    ~PhoneBook();

    void add(const char* n, const char* hp, const char* wp, const char* i);

    bool remove(int id);

    void find(const char* request);

    void printAll();
};