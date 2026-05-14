#include <iostream>
#include "include/Fraction.hpp"
#include "include/Vector3D.hpp"
#include "include/Matrix.hpp"

int main()
{
    Matrix<int> a({
        {1,2,3},
        {4,5,6}
    }),
    b({
        {5,6},
        {7,8}
    });

    bool test = a != a;

    std::cout << test;

    return 0;
}