#pragma once

class Client {

    unsigned int id, animalsCount, * animals;
    char * name;

public:

    Client();

    Client(unsigned int id, char* name);

    Client(const Client& other);

    ~Client();

    void AddAnimal(unsigned int newId);

    unsigned int FindAnimal(unsigned int findId);

    bool RemoveAnimal(unsigned int delId);
};