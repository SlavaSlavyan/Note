# Практика по шаблонным классам

### Цель работы

Научиться создавать и использовать шаблонные классы, реализовывать основные операции с динамическими массивами произвольного типа.

### Условие задачи

Реализуйте шаблонный класс **SmartArray\<T>**, который представляет собой массив фиксированной длинны.

### Требования к классу

1. Основные методы

    - Конструкторы:

        - **SmartArray()** - создает пустой массив
        - **SmartArray(size_t initialCapacity)** - создает массив с указанной начальной емкостью
        - **SmartArray(const SmartArray& other)** - конструктор копирования
        - **~SmartArray()** - деструктор

    - Операторы:

        - **T& operator[](size_t index)** - доступ по индексу с проверкой границ
        - **SmartArray& operator=(const SmartArray& other)** - оператор присваивания

    - Основные методы:

        - **void push_back(const T& value)** - добавление элемента в конец
        - **void pop_back()** - удаление последнего элемента
        - **T& back()** - доступ к последнему элементу
        - **size_t size() const** - получение текущего размера
        - **bool empty() const** - проверка на пустоту
        - **void clear()** - очистка массива

2. Расширенные методы

    - **void insert(size_t index, const T& value)** - вставка элемента по индексу
    - **void erase(size_t index)** - удаление элемента по индексу

3. Алгоритмы поиска (шаблонные методы)

    - **int find(const T& value)** - поиск значения (возвращает индекс)
    
4. Итераторы (опционально, для продвинутых)*

    Реализовать простой итератор для перебора элементов

```cpp
int main() {
    // Работа с целыми числами
    SmartArray<int> intArray;
    
    for (int i = 1; i <= 10; i++) {
        intArray.push_back(i * 10);
    }
        
    std::cout << "Size: " << intArray.size() << std::endl;

    // Поиск элемента
    int index = intArray.find(50);
    if (index !=-1) {
        std::cout << "Found 50 at index: " << index << std::endl;
    }

    // Работа со строками
    SmartArray<std::string> strArray;
    strArray.push_back("Hello");
    strArray.push_back("World");
    strArray.push_back("C++");

    return 0;
}
```

---

Точка входа [**start.cpp**](./start.cpp), включает в себя реализацию класса [**SmartArray.cpp**](./src/SmartArray.cpp) с интерфейсом [**SmartArray.hpp**](./include/SmartArray.hpp).