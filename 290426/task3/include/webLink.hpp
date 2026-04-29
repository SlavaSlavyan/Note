#pragma once

// образец нашего класса
class WebLink {

    // поля
    char* url;
    char* description;

public:

    // конструктор
    WebLink(const char* linkUrl, const char* linkDesc);

    // деструктор
    ~WebLink() {
        delete[] url;
        delete[] description;
    }

    // вывод информации
    void print();
};