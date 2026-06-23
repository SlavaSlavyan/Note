#pragma once
#include "Entity.hpp"

class Client : public Entity {

    char * number, * email;

public:

    Client() : Entity(), number(nullptr), email(nullptr) {
        SetType("CLIENT");
    }

    Client(const Client& other) : Entity(other) 
    {
        number = SetString(other.number);
        email = SetString(other.email);
    }

    ~Client() override 
    {
        if (number) delete number;
        if (email) delete email;

        number = nullptr;
        email = nullptr;
    }

    const char* GetNumber() const { return number; }

    const char* GetEmail() const { return email; }

    void SetNumber(const char* newNumber) { 
        if (number) delete[] number;
        number = SetString(newNumber); 
    }

    void SetEmail(const char* newEmail) {
        if (email) delete[] email;
        email = SetString(newEmail); 
    }
};