#include <iostream>
#include <conio.h>
#include "include/SimpleFraction.hpp"

int main()
{
    // небольшой показ того, какой будет дробь изначально

    SimpleFraction *frac = new SimpleFraction();

    frac->print();

    delete frac;

    // создаём две дроби 3/4 и 4/3
    SimpleFraction *frac1 = new SimpleFraction(3,4),
                   *frac2 = new SimpleFraction(4,3);

    // ко второй дроби прибавляем первую и получаем 25/12
    frac2->addition(frac1);

    frac2->print();

    // в одном действии сначала отнимаем 3/4 и после умножаем на 3
    frac2->subtraction(frac1).multiplication(3);

    frac2->print();

    delete frac1, frac2;

    getch();

    return 0;
}