#include "../include/Client.hpp"
#include <cstring>

Client::Client() : id(0), animalsCount(0), animals(nullptr), name(nullptr) {}

Client::Client(unsigned int i, char* n) : Client()
{
    id = i;

    if (n) {
        name = new char[strlen(n + 1)];
        strcpy_s(name, strlen(n + 1), n);
    }
}

Client::Client(const Client& other) : Client(other.id, other.name)
{
    animalsCount = other.animalsCount;

    if (animalsCount) 
    {
        animals = new unsigned int[animalsCount];
    
        for (unsigned int i = 0; i < animalsCount; i++) {
            animals[i] = other.animals[i];
        }
    }
}

Client::~Client() 
{
    if (name) delete[] name;
    if (animals) delete[] animals;

    name = nullptr;
    animals = nullptr;
}

void Client::AddAnimal(unsigned int newId)
{
    unsigned int* oldData = nullptr;

    if (animalsCount) 
    {
        oldData = new unsigned int[animalsCount];
        
        for (unsigned int i = 0; i < animalsCount; i++) {
            oldData[i] = animals[i];
        }

        delete[] animals;
        animals = nullptr;
    }

    animals = new unsigned int[animalsCount + 1];

    if (oldData) 
    {
        for (unsigned int i = 0; i < animalsCount; i++) {
            animals[i] = oldData[i];
        }

        delete[] oldData;
        oldData = nullptr;
    }

    animals[animalsCount] = newId;
    animalsCount++;
}

unsigned int Client::FindAnimal(unsigned int findId)
{
    for (unsigned int i = 0; i < animalsCount; i++) {
        if (animals[i] == findId) return i + 1;
    }

    return 0;
}

bool Client::RemoveAnimal(unsigned int delId)
{
    delId = FindAnimal(delId) - 1;

    if (delId == -1) return false;

    unsigned int* newData = nullptr;

    if (animalsCount - 1) 
    {
        newData = new unsigned int[animalsCount - 1];
        
        for (unsigned int i = 0; i < delId; i++) {
            newData[i] = animals[i];
        }

        for (unsigned int i = delId + 1; i < animalsCount; i++) {
            newData[i - 1] = animals[i];
        }
    }

    delete[] animals;
    animals = newData;

    animalsCount--;

    return true;
}