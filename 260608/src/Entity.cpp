#include "../include/Entity.hpp"
#include <cstring>

char* Entity::SetString(const char* data)
{
    if (!data) {
        return nullptr;
    }

    char* string = new char[strlen(data) + 1];
    strcpy_s(string, strlen(data) + 1, data);

    return string;
}

Entity::Entity() : id(0), list(nullptr), length(0), name(nullptr), type(nullptr) {}

Entity::Entity(const Entity& other) : id(other.id), length(other.length)
{
    SetType(other.type);
    SetName(other.name);

    if (!other.list) {
        list = nullptr;
        return;
    }

    list = new unsigned int[length];

    for (unsigned int i = 0; i < length; i++) {
        list[i] = other.list[i];
    }
}

Entity::~Entity()
{
    if (list) delete[] list;
    if (name) delete[] name;
    if (type) delete[] type;

    list = nullptr;
    name = nullptr;
    type = nullptr;
}

unsigned int Entity::GetListId(unsigned int listId) const 
{
    if (listId >= length) return 0;

    return list[listId];
}

unsigned int Entity::Find(unsigned int id) const 
{
    for (unsigned int i = 0; i < length; i++) {
        if (list[i] == id) return i + 1;
    }

    return 0;
}

bool Entity::Add(unsigned int newId)
{
    if (Find(newId)) return false;

    unsigned int* newData = new unsigned int[length + 1];
    newData[length] = newId;

    if (list) {
        for (unsigned int i = 0; i < length; i++) {
            newData[i] = list[i];
        }

        delete[] list;
    }

    list = newData;
    length++;

    return true;
}

bool Entity::Remove(unsigned int listId)
{
    if (listId >= length) return false;

    if (length != 1) 
    {
        unsigned int* newData = new unsigned int[length - 1];

        for (unsigned int i = 0; i < listId; i++) {
            newData[i] = list[i];
        }

        for (unsigned int i = listId + 1; i < length; i++) {
            newData[i - 1] = list[i];
        }

        delete[] list;
        list = newData;
    }
    else list = nullptr;

    length--;

    return true;
}

