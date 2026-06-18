#include "../include/Client.hpp"
#include <cstring>
#include <iostream>

Client::Client() : id(0), animals(nullptr), animalsCount(0), name(nullptr) {}

void Client::SetName(const char* newName) 
{
    if (newName) {
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }
    
    else name = nullptr;
}

Client::Client(const Client& other) : Client()
{
    id = other.id;
    animalsCount = other.animalsCount;
    
    if (!animalsCount) 
    {
        animals = new unsigned int[animalsCount];

        for (unsigned int i = 0; i < animalsCount; i++) {
            animals[i] = other.animals[i];
        }
    }

    SetName(other.name);
}

Client::~Client()
{
    if (animals) delete[] animals;
    if (name) delete[] name;
}

unsigned int Client::GetAnimal(unsigned int animalId) const
{
    if (animalId >= animalsCount) return 0;

    return animals[animalId];
}

unsigned int Client::FindAnimal(unsigned animalId) const
{
    for (unsigned int i = 0; i < animalsCount; i++) {
        if (animalId == animals[i]) return i + 1;
    }

    return 0;
}

bool Client::AddAnimal(unsigned int animalId)
{
    if (FindAnimal(animalId)) return false;

    unsigned int* newData = new unsigned int[animalsCount + 1];

    if (animals) {
        for (unsigned int i = 0; i < animalsCount; i++) {
            newData[i] = animals[i];
        }

        delete[] animals;
    }

    newData[animalsCount] = animalId;
    animals = newData;

    animalsCount++;

    return true;
}

bool Client::RemoveAnimal(unsigned animalId) 
{
    if (animalId >= animalsCount) return false;

    if (animalsCount == 1) 
    {
        delete[] animals;
        animals = nullptr;

        animalsCount = 0;

        return true;
    }

    unsigned int* newData = new unsigned int[animalsCount - 1];

    for (unsigned int i = 0; i < animalId; i++) {
        newData[i] = animals[i];
    }

    for (unsigned int i = animalId + 1; i < animalsCount; i++) {
        newData[i - 1] = animals[i];
    }

    delete[] animals;
    animals = newData;

    animalsCount--;

    return true;
}

void Client::Print() 
{
    std::cout << "==============================\n  ID: " << id << "\n  Name: ";
    if (name) std::cout << name;
    else std::cout << "NULL";
    std::cout << "\n  Count of animals: " << animalsCount << '\n';
}