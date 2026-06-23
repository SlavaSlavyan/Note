#pragma once
#include "Entity.hpp"

class Animal : public Entity {

    unsigned int age;

public:

    Animal() : Entity(), age(0) {
        SetType("ANIMAL");
    }

    Animal(const Animal& other) : Entity(), age(other.age) {}

    unsigned int GetAge() const { return age; }

    void SetAge(unsigned int newAge) { age = newAge; }
};