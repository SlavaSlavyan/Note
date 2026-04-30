# Задача 6: «Прямоугольник» (Inline-методы + спецификатор const) 

### Условие: 

Создайте класс **Rectangle** для геометрических расчётов. Короткие методы реализуйте прямо в теле класса (как **inline**), руководствуясь разделом **10 PDF**. 

### Задание: 

1. Создайте класс **Rectangle** со скрытыми полями: 

    - **double width** — ширина 
    - **double height** — высота 

2. Реализуйте конструктор, принимающий ширину и высоту (проверьте,что они положительные; если нет — установите **1.0**).

3. Реализуйте inline-методы прямо в теле класса: 

    - **double getWidth() const { return width; }**
    - **double getHeight() const { return height; }**
    - **double getArea() const { return width \* height; }**
    - **double getPerimeter() const { return 2 \* (width + height); }**
    - **bool isSquare() const { return width == height; }**

    Обратите внимание на const после имени метода — это означает, что метод не изменяет поля объекта **(инспектор)**. 

4. Реализуйте метод void printInfo() const для вывода: 

    - Прямоугольник: **\<width> x \<height>** 
    - Площадь: **\<area>**
    - Периметр: **\<perimeter>**
    - Является квадратом: **\<да/нет>**

5. В **main()** создайте два объекта: 

    - Прямоугольник **5.0 x 3.0**
    - Квадрат **4.0 x 4.0**

6. Выведите информацию о каждом.

---

Точка входа [**start.cpp**](./start.cpp), включает в себя класс [**Rectangle.cpp**](./src/Rectangle.cpp) с заголовком [**Rectangle.hpp**](./include/Rectangle.hpp).