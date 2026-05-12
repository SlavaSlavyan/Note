#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

PhoneBook::PhoneBook() 
{
    contacts = new Contact*[0];
    length = 0;
}

PhoneBook::~PhoneBook()
{
    for (int i = 0; i < length; i++) {
        delete contacts[i];
    }

    delete[] contacts;
}

void PhoneBook::add(const char* n, const char* hp, const char* wp, const char* i)
{
    Contact** oldData = new Contact*[length];

    for (int i = 0; i < length; i++) {
        oldData[i] = new Contact(*contacts[i]);
    }

    contacts = new Contact*[length + 1];

    for (int i = 0; i < length; i++) {
        contacts[i] = new Contact(*oldData[i]);
        delete oldData[i];
    }

    contacts[length] = new Contact(n, hp, wp, i);

    delete[] oldData;

    length++;
}

bool PhoneBook::remove(int id) 
{
    if (id > -1 && id < length) 
    {
        Contact** oldData = new Contact*[length];

        for (int i = 0; i < length; i++) {
            oldData[i] = new Contact(*contacts[i]);
        }

        contacts = new Contact*[length - 1];

        for (int i = 0; i < id; i++) {
            contacts[i] = new Contact(*oldData[i]);
            delete oldData[i];
        }

        for (int i = id; i < length - 1; i++) {
            contacts[i] = new Contact(*oldData[i + 1]);
            delete oldData[i + 1];
        }

        delete oldData[id];
        delete[] oldData;

        length--;

        return true;
    }

    return false;
}

void PhoneBook::find(const char* request)
{
    int count = 0;

    for (int i = 0; i < length; i++) {

        bool found = false;

        for (int j = 0; j < strlen(request); j++) {
            if (contacts[i]->getName()[i] == request[i]) {
                found = true;
            }
            else {
                found = false;
                break;
            }
        }

        if (found) {
            std::cout << i + 1 << '.' << contacts[i]->getName() << " - [" << contacts[i]->getWorkPhone() << ']' << std::endl;
            count++;
        }
    }

    if (!count) {
        std::cout << "No results.\n";
    }
};

void PhoneBook::printAll() 
{
    if (length) {
        for (int i = 0; i < length; i++) {
            std::cout << i + 1 << '.' << contacts[i]->getName() << " - [" << contacts[i]->getWorkPhone() << ']' << std::endl;
        }

        return;
    }
    
    std::cout << "Zero contacts.\n";
}