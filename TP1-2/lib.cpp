#include "lib.hpp"
#include <iostream>

int figure::nbr_figure = 0;

/* FIGURE */
figure::figure()
{
    std::cout << "Created figure\n";
    nbr_figure++;
    std::cout << "Nbr figures : " << nbr_figure << "\n";
}

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
    std::cout << "Created rectangle with length = " << len << " and width = " << wid << "\n";
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

circle::circle(float rad, std::string col)
{
    radius = rad;
    color = col;
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

/* COLORABLE */
colorable::colorable(std::string col)
{
    color = col;
}

void colorable::set_color(std::string col)
{
    color = col;
}

std::string colorable::get_color()
{
    return color;
}

cell::cell()
{
    previous_cell = nullptr;
    next_cell = nullptr;
}
cell::cell(cell *next)
{
    previous_cell = nullptr;
    next_cell = next;
}

queue::queue(cell *first, cell *last, int nbr)
{
    first_cell = first;
    last_cell = last;
    nbr_cell = nbr;
}

queue::~queue()
{
    for (int i = 0; i < nbr_cell; i++)
    {
        remove_cell();
    }
}

void queue::add_cell(cell *c)
{
    last_cell->next_cell = c;
    c->previous_cell = last_cell;
    last_cell = c;
    nbr_cell++;
}
void queue::remove_cell()
{
    if (last_cell->previous_cell == nullptr)
    {
        cell *t = last_cell;
        last_cell = nullptr;
        first_cell = nullptr;
        free(t);
    }
    else
    {
        last_cell = last_cell->previous_cell;
        free(last_cell->next_cell);
        last_cell->next_cell = nullptr;
        nbr_cell--;
    }
}

int queue::is_queue_void(void)
{
    if (last_cell == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int queue::get_nbr_cell()
{
    return nbr_cell;
}

cell *queue::get_queue_header()
{
    return first_cell;
}