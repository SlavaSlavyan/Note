#include "../include/Triangle.hpp"
#include <iostream>
#include <cmath>

Triangle::Triangle(double e1, double e2, double e3) : edges{e1,e2,e3}
{
    if (e1 + e2 <= e3 || e2 + e3 <= e1 || e1 + e3 <= e2) {
        edges[0] = 1;
        edges[1] = 1;
        edges[2] = 1;
    }
}

double Triangle::area() const 
{
    double p = (edges[0] + edges[1] + edges[2]) / 2;

    return sqrt(p * (p - edges[0]) * (p - edges[1]) * (p - edges[2]));
}

double Triangle::perimeter() const 
{
    return edges[0] + edges[1] + edges[2];
}

void Triangle::print() const 
{
    std::cout << "Triangle edges >> [";
    
    for (int i = 0; i < 3; i++) {
        std::cout << edges[i];
        if (i != 2) { std::cout << ','; }
    }

    std::cout << "]\n          area >> " << area()
        << "\n     perimeter >> " << perimeter() << '\n';
}