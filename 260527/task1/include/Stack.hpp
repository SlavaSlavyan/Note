#pragma once

template <typename T>
struct Element
{
    T value;

    Element* next = nullptr;
};

template <typename T>
void push(Element<T>*& stack, T value) 
{
    Element<T>* newElem = new Element<T>;
    newElem->value = value;

    if(!stack) {
        stack = newElem;
    }
    else 
    {
        newElem->next = stack;
        stack = newElem;
    }
}

template <typename T>
bool pop(Element<T>*& stack, T value)
{
    if (!stack) return false;

    Element<T> remove = stack;

    value = stack->value;
    stack = stack->next;

    delete remove;

    return true;
}

template <typename T>
const T* peek(const Element<T>* stack)
{
    if (!stack) return nullptr;

    return &stack->value;
}

template <typename T>
Element<T>* next_elem(const Element<T>* elem)
{
    if (elem) return elem->next;

    return nullptr;
}

template <typename T>
Element<T>* last(const Element<T>* elem)
{
    if (elem) while (elem->next) elem = elem->next;
    
    return (Element<T>*)elem;
}

template <typename T>
void clear(Element<T>*& stack)
{
    while (stack)
    {
        Element<T>* remove = stack;
        stack = stack->next;
        delete remove;
    }
}