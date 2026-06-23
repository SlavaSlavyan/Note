#pragma once

class Entity {
protected:

    unsigned int id, * list, length;
    char * name, * type;

    char* SetString(const char* data);

    void SetType(const char* newType) { 
        if (type) delete[] type;
        type = SetString(newType); 
    }

public:

    Entity();

    Entity(const Entity& other);

    virtual ~Entity();

    unsigned int GetId() const { return id; }

    unsigned int GetListId(unsigned int listId) const;

    unsigned int Find(unsigned int id) const;

    unsigned int Length() const { return length; }

    const char* GetName() const { return name; }

    const char* GetType() const { return type; }

    void SetId(unsigned int newId) { id = newId; }

    bool Add(unsigned int newId);

    bool Remove(unsigned int listId);

    void SetName(const char* newName) { 
        if (name) delete[] name;
        name = SetString(newName);
    }
};