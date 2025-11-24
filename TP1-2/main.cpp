#include "lib.hpp"
#include <cassert>
#include <iostream>

void print_perimeter(float perimeter)
{
    std::cout << "Perimeter = " << perimeter << "cm\n";
}

int main()
{
    std::cout << "=== Starting Test Session ===\n\n";
    // /* RECTANGLES */
    // rectangle rec1(3, 2);
    // rec1.print_characteristics();
    // rec1.show_length();
    // rec1.show_width();
    // float perimeter = rec1.perimeter();
    // print_perimeter(perimeter);

    // rectangle rec2;
    // rec2.print_characteristics();
    // rec2.set_length(5.3f);
    // rec2.show_length();
    // rec2.set_width(2.2f);
    // rec2.show_width();
    // perimeter = rec2.perimeter();
    // print_perimeter(perimeter);

    // /* SQUARES */
    // square sq1(4.1f);
    // sq1.print_characteristics();
    // sq1.show_size();
    // perimeter = sq1.perimeter();
    // print_perimeter(perimeter);

    // square sq2;
    // sq2.print_characteristics();
    // sq2.set_size(2.3f);
    // sq2.show_size();
    // perimeter = sq2.perimeter();
    // print_perimeter(perimeter);

    // /* EQUILATERAL TRIANGLE */
    // equilateral_triangle et1(3.2f);
    // et1.print_characteristics();
    // et1.show_size();
    // perimeter = et1.perimeter();
    // print_perimeter(perimeter);

    // equilateral_triangle et2;
    // et2.print_characteristics();
    // et2.set_size(2.3f);
    // et2.show_size();
    // perimeter = et2.perimeter();
    // print_perimeter(perimeter);

    // /* CIRCLE */
    // circle cr1;
    // cr1.print_characteristics();
    // cr1.set_radius(3.4f);
    // cr1.show_radius();
    // perimeter = cr1.perimeter();
    // print_perimeter(perimeter);

    // circle cr2(4.1f);
    // cr2.print_characteristics();
    // cr2.show_radius();
    // perimeter = cr2.perimeter();
    // print_perimeter(perimeter);

    /* FIGURE ARRAY */
    std::vector<std::unique_ptr<figure>> figures;

    figures.push_back(std::make_unique<square>(5.0f));
    figures.push_back(std::make_unique<circle>(3.0f, "Blue"));
    figures.push_back(std::make_unique<equilateral_triangle>(6.0f));

    figures.push_back(std::make_unique<circle>(3.0f, "Red"));
    figures.push_back(std::make_unique<rectangle>(4.0f, 7.0f));
    figures.push_back(std::make_unique<circle>(3.0f, "Green"));
    figures.push_back(std::make_unique<square>(10.0f));

    std::cout << "=== PRINTING FIGURES ===\n\n";

    float perimeter;
    for (const auto &fig : figures)
    {
        fig->print_characteristics();
        perimeter = fig->perimeter();
        print_perimeter(perimeter);
        std::cout << std::string(40, '-') << "\n";
    }

    std::cout << "We have: " << figure::get_nbr_figure() << " figures\n";

    /* TEST QUEUE */
    circle *ccl = new circle(3.0f, "Blue");
    equilateral_triangle *eqt = new equilateral_triangle(0.6f);
    rectangle *rcl = new rectangle(0.4f, 0.6f);

    queue<figure *> q1;
    q1.add_figure(ccl);
    std::cout << "Queue size: " << q1.get_nbr_cell() << "\n";
    q1.add_figure(eqt);
    std::cout << "Queue size: " << q1.get_nbr_cell() << "\n";
    q1.add_figure(rcl);
    std::cout << "Queue size: " << q1.get_nbr_cell() << "\n";

    cell<figure *> *current = q1.get_first_cell();

    int index = 1;
    while (current != nullptr)
    {
        figure *fig = current->get_figure();

        std::cout << "Figure " << index << " :\n";
        fig->print_characteristics();
        std::cout << "Périmètre = " << fig->perimeter() << " cm\n";
        if (typeid(*fig) == typeid(circle))
        {
            circle *c = dynamic_cast<circle *>(fig);
            if (c)
            {
                std::cout << "Couleur du cercle : " << c->get_color() << "\n";
            }
        }
        std::cout << std::string(50, '-') << "\n";

        current = current->get_next_cell();
        ++index;
    }

    q1.remove_cell();
    figure *queue_header = q1.get_queue_header();
    std::cout << "Queue header = expected ?\n";
    if (queue_header == ccl)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    std::cout << "Queue size: " << q1.get_nbr_cell() << "\n";
    q1.remove_cell();
    std::cout << "Queue size: " << q1.get_nbr_cell() << "\n";
    q1.remove_cell();
    std::cout << "Queue size: " << q1.get_nbr_cell() << "\n";
    std::cout << "Queue empty: " << q1.is_queue_void() << "\n";
    q1.remove_cell();

    return 0;
}