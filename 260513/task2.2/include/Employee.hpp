#pragma once

class Employee {

protected:

    char* name;
    unsigned int id, salary;

public:

    Employee(const char* n, unsigned int i, unsigned int s);

    Employee() : Employee(nullptr, 0, 0) {}

    Employee(const Employee& other) : Employee(other.name, other.id, other.salary) {}

    virtual ~Employee() {
        delete[] name;
    }

    virtual unsigned int calculateSalary() const{
        return salary;
    }

    virtual void getInfo(bool customSalary = false) const;

    void setID(unsigned int newID) {
        id = newID;
    }
};