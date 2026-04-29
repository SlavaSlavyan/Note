#include "../include/webLink.hpp" // берём наш "образ" класса
#include <iostream>
#include <cstring>

// реализуем конструктор
WebLink::WebLink(const char* linkUrl, const char* linkDesc)
{
     // выделяем память
    this->url = new char[strlen(linkUrl)+1];
    this->description = new char[strlen(linkDesc)+1];

    // копируем инфу
    strcpy_s(this->url, strlen(linkUrl) + 1, linkUrl);
    strcpy_s(this->description, strlen(linkDesc) + 1, linkDesc);
}

// реализуем вывод информации
void WebLink::print() {
    std::cout << "Описание: " << this->description << std::endl;
    std::cout << "Адрес: " << this->url << std::endl;
}