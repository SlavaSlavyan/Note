#pragma once

// базовый класс от которого наследуются все остальные
class Employee {

protected:

    char* name; // имя сотрудника
    unsigned int id, salary; // ID и зарплата

public:

    // главный конструктор
    Employee(const char* n, unsigned int i, unsigned int s);

    // базовый конструктор который создаёт пустого сотрудника без имени и зарплаты
    Employee() : Employee(nullptr, 0, 0) {}

    // конструктор копирования
    Employee(const Employee& other) : Employee(other.name, other.id, other.salary) {}

    // деструктор, который можно переписать
    virtual ~Employee() {
        if (name) {
            delete[] name;
            name = nullptr;
        }
    }

    // виртуальный метод расчёта зарплаты
    virtual unsigned int calculateSalary() const{
        return salary;
    }

    // виртуальный метод вывода информации о сотруднике
    virtual void getInfo(bool customSalary = false) const;

    // сеттер для ID
    void setID(unsigned int newID) {
        id = newID;
    }
};