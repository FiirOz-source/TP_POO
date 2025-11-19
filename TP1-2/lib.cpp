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