#include "lib.hpp"
#include <iostream>

/* POLYGONE */
polygone::~polygone()
{
    // std::cout << "Destroyed polygone\n";
}

void polygone::print_characteristics()
{
    std::cout << "Nombre de côtés: " << nb_sides << "\n";
}

/* RECTANGLE */
rectangle::rectangle()
{
    nb_sides = 4;
    std::cout << "Created rectangle\n";
}

rectangle::rectangle(float len, float wid)
{
    nb_sides = 4;
    length = len;
    width = wid;
    std::cout << "Created rectangle with length = " << len << "and width =" << wid << "\n";
}

rectangle::~rectangle()
{
    // std::cout << "Destroyed rectangle\n";
}

float rectangle::perimeter()
{
    return ((2 * length) + (2 * width));
}

void rectangle::set_length(float len)
{
    length = len;
}
void rectangle::show_length(void)
{
    std::cout << "Rectangle length: " << length << "cm\n";
}

void rectangle::set_width(float wid)
{
    width = wid;
}
void rectangle::show_width(void)
{
    std::cout << "Rectangle width: " << width << "cm\n";
}

/* SQUARE */
square::square()
{
    nb_sides = 4;
    width = length;
    std::cout << "Created rectangle\n";
}

square::square(float size)
{
    nb_sides = 4;
    length = size;
    width = size;
    std::cout << "Created rectangle with length = " << size << "\n";
}

square::~square()
{
    // std::cout << "Destroyed square\n";
}

void square::set_size(float size)
{
    length = size;
    width = size;
}

void square::show_size(void)
{
    std::cout << "Square size: " << length << "cm\n";
}

/* EQUILATERAL TRIANGLE */
equilateral_triangle::equilateral_triangle()
{
    nb_sides = 3;
    std::cout << "Created rectangle\n";
}

equilateral_triangle::equilateral_triangle(float sz)
{
    nb_sides = 4;
    size = sz;
    std::cout << "Created rectangle with length = " << size << "\n";
}

equilateral_triangle::~equilateral_triangle()
{
    // std::cout << "Destroyed equilateral_triangle\n";
}

void equilateral_triangle::set_size(float sz)
{
    size = sz;
}

void equilateral_triangle::show_size(void)
{
    std::cout << "Equilateral Triangle size: " << size << "cm\n";
}

float equilateral_triangle::perimeter()
{
    return (3 * size);
}

/* CIRCLE */
circle::~circle()
{
    // std::cout << "Destroyed circle\n";
}

circle::circle(float rad)
{
    radius = rad;
}

void circle::print_characteristics()
{
    std::cout << "Radius: " << radius << "\n";
}

void circle::set_radius(float rad)
{
    radius = rad;
}

void circle::show_radius(void)
{
    std::cout << "Circle radius: " << radius << "cm\n";
}

float circle::perimeter()
{
    double pi = 2 * acos(0.0);
    return (2 * pi * radius);
}