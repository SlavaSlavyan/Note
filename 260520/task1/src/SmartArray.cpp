#include "../include/SmartArray.hpp"
#include <stdexcept>

template <typename T> // выделяем память, а так же записываем длинну
SmartArray<T>::SmartArray(unsigned int initialCapacity) : length(initialCapacity), size(0)
{
    if (length) {
        data = new T[length];
    }
    else data = nullptr; // случай пустого массива (правда нах он вообще нужен я не знаю)
}

template <typename T> // копирование
SmartArray<T>::SmartArray(const SmartArray<T>& other) : SmartArray<T>(other.length) 
{
    for (unsigned int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
SmartArray<T>::~SmartArray() 
{
    if (data) {
        delete[] data;
        data = nullptr;
    }
}

template <typename T>
T& SmartArray<T>::operator [] (unsigned int index)
{
    if (index >= length) {
        throw std::out_of_range("Индекс выходит за пределы");
    }

    // если длинна изменилась переписываем её
    if (index > size) size = index;

    return data[index];
}

template <typename T>
const T& SmartArray<T>::operator [] (unsigned int index) const
{
    if (index >= length) {
        throw std::out_of_range("Индекс выходит за пределы");
    }

    return data[index];
}

template <typename T>
SmartArray<T>& SmartArray<T>::operator = (const SmartArray<T>& other) 
{
    // удаляем старый массив
    this->~SmartArray();

    // создаём новый
    SmartArray<T>* newArr = new SmartArray<T>(other);

    // переписываем информацию
    data = newArr->data;
    length = newArr->length;
    size = newArr->size;

    return *this;
}

template <typename T>
void SmartArray<T>::push_back(const T& value)
{
    if (size >= length) {
        throw std::out_of_range("Индекс выходит за пределы");
    }

    data[size] = value;

    size++;
}

// на будущее - вся очистка отдельных полей заключается в присваивании им значения -1

template <typename T>
void SmartArray<T>::pop_back()
{
    data[size] = -1;
    size--;
}

template <typename T>
T& SmartArray<T>::back()
{
    return data[size];
}

template <typename T>
unsigned int SmartArray<T>::Size() const
{
    return size;
}

template <typename T>
bool SmartArray<T>::empty() const
{
    if (data) return true;
    return false;
}

template <typename T>
void SmartArray<T>::clear() 
{
    this->~SmartArray();

    SmartArray<T>* newArr = new SmartArray<T>(length);

    data = newArr->data;
    size = 0;
}

template <typename T>
void SmartArray<T>::insert(unsigned int index, const T& value)
{
    if (index >= length) {
        throw std::out_of_range("Индекс выходит за пределы");
    }

    if (index > size) size = index;

    data[index] = value;
}

template <typename T>
void SmartArray<T>::erase(unsigned int index)
{
    if (index >= length) {
        throw std::out_of_range("Индекс выходит за пределы");
    }

    if (index == size) size--;

    data[index] = -1;
}

template <typename T>
int SmartArray<T>::find(const T& value)
{
    for (unsigned int i = 0; i < size; i++) {
        if (data[i] == value) return i;
    }

    return -1;
}

// мне лень чёто обьяснять, всё в целом и так понятно