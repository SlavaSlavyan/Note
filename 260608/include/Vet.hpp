#pragma once
#include "Client.hpp"

class Vet : public Client {

    unsigned int experience;

public:

    Vet() : Client(), experience(0) {
        SetType("VET");
    }

    Vet(const Vet& other) : Client(other), experience(other.experience) {}

    unsigned int GetExp() const { return experience; }

    void SetExp(unsigned int newExp) { experience = newExp; }
};