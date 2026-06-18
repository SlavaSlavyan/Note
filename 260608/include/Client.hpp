#pragma once

class Client {

    unsigned int id, * animals, animalsCount;
    char * name;

public:

    Client();

    Client(const Client& other);

    ~Client();

    unsigned int GetId() const { return id; }

    const unsigned int * GetAllAnimals() const { return animals; }

    unsigned int GetAnimal(unsigned int animalId) const;

    unsigned int GetAnimalsCount() const { return animalsCount; }

    const char * GetName() const { return name; }

    void SetId(unsigned int newId) { id = newId; }

    bool AddAnimal(unsigned int animalId);

    bool RemoveAnimal(unsigned animalId);

    unsigned int FindAnimal(unsigned animalId) const;

    void SetName(const char* newName);

    void Print();
};