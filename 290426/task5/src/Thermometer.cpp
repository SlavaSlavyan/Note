#include "../include/Thermometer.hpp"
#include <iostream>
#include <cstring>

// реализация всех трёх конструкторов ->

Thermometer::Thermometer() 
{
    this->celsius = 0.0;
    this->location = new char[8];
    strcpy_s(this->location, 8, "Unknown");
}

Thermometer::Thermometer(double tempCelsius)
{
    this->celsius = tempCelsius;
    this->location = new char[8];
    strcpy_s(this->location, 8, "Unknown");
}

Thermometer::Thermometer(const char* place, double tempCelsius)
{
    this->celsius = tempCelsius;
    this->location = new char[strlen(place) + 1];
    strcpy_s(this->location, strlen(place) + 1, place);
}

// реализация метода получения фаренгейта
double Thermometer::getFahrenheit() {
    return this->celsius * 9 / 5 + 32;
}

// реализация вывода информации
void Thermometer::printInfo() 
{
    std::cout << "==========================\n";
    std::cout << "Temperature: " << this->celsius << " °C\n";
    std::cout << "Location: " << this->location << std::endl;
}