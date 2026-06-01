#pragma once
#include <string>

template <typename T>
class SmartArray {

    // вся заполняемая информация
    T* data;

    // максимальная длинна массива и настоящий размер
    unsigned int length, size;

public:

    // три конструктора

    SmartArray(unsigned int initialCapacity);

    SmartArray() : SmartArray(0) {};

    SmartArray(const SmartArray& other);

    // деструктор
    ~SmartArray();

    // парочка операторов

    T& operator [] (unsigned int index);

    const T& operator [] (unsigned int index) const;

    SmartArray& operator = (const SmartArray& other);

    // и хуева кукуева разных методов X﹏X

    void push_back(const T& value);

    void pop_back();

    T& back();

    unsigned int Size() const;

    bool empty() const;

    void clear();

    void insert(unsigned int index, const T& value);

    void erase(unsigned int index);

    int find(const T& value);
};

// доступные типы данных

template class SmartArray<int>;
template class SmartArray<float>;
template class SmartArray<double>;
template class SmartArray<std::string>;