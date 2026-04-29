#pragma once

// наш класс
class LightBulb {

    // поле переключателя
    bool isOn = false;

public:

    // метод вкллючения
    void turnOn() { isOn = true; }

    // методы выключения
    void turnOff() { isOn = false; }

    // метод переключения
    void toggle() { isOn = !isOn; }

    // метод получения состояния
    const char* getState() 
    {
        if (isOn) {
            return "ON";
        }
        else {
            return "OFF";
        }
    }
};