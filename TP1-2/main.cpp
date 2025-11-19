#include "lib.hpp"
#include <cassert>
#include <iostream>

void print_perimeter(float perimeter)
{
    std::cout << "Perimeter = " << perimeter << "\n";
}

int main()
{
    std::cout << "=== Starting Test Session ===\n\n";
    /* RECTANGLES */
    rectangle rec1(3, 2);
    rec1.print_characteristics();
    rec1.show_length();
    rec1.show_width();
    float perimeter = rec1.perimeter();
    print_perimeter(perimeter);

    rectangle rec2;
    rec2.print_characteristics();
    rec2.set_length(5.3);
    rec2.show_length();
    rec2.set_width(2.2);
    rec2.show_width();
    perimeter = rec2.perimeter();
    print_perimeter(perimeter);

    /* SQUARES*/
    square sq1(4.1);
    sq1.print_characteristics();
    sq1.show_size();
    perimeter = sq1.perimeter();
    print_perimeter(perimeter);

    square sq2;
    sq2.print_characteristics();
    sq2.set_size(2.3);
    sq2.show_size();
    perimeter = sq2.perimeter();
    print_perimeter(perimeter);

    return 0;
}