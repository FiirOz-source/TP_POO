#include "lib.hpp"

int main()
{
    question1();
    question2();
    question3();
    question4();
    question5();
    question6();

    matrice_creuse m(5, 5);

    m(0, 0) = 11;
    m(0, 4) = 22;
    m(2, 2) = 99;
    m(4, 1) = 33;

    m.afficher();

    std::cout << "Éléments réellement stockés : " << m.taille_reelle() << "\n";

    m.set_zero(2, 2);
    m.afficher();

    m(4, 2) = 44;
    m(1, 3) = 55;

    std::cout << m;

    std::cout << "=== Création de deux matrices creuses 3x3 ===\n\n";

    matrice_creuse A(3, 3);
    A(0, 0) = 5;
    A(0, 2) = 8;
    A(1, 1) = 3;
    A(2, 0) = 6;

    matrice_creuse B(3, 3);
    B(0, 2) = 4;
    B(1, 1) = 7;
    B(2, 2) = 9;

    std::cout << "A =\n"
              << A << "\n";
    std::cout << "B =\n"
              << B << "\n";

    // Test de +
    std::cout << "A + B =\n"
              << (A + B) << "\n";

    // Test de -
    std::cout << "A - B =\n"
              << (A - B) << "\n";

    // Test de +=
    matrice_creuse C = A;
    std::cout << "C = A -> C =\n"
              << C << "\n";
    C += B;
    std::cout << "Après C += B -> C =\n"
              << C << "\n";

    // Test de -=
    matrice_creuse D = A;
    std::cout << "D = A -> D =\n"
              << D << "\n";
    D -= B;
    std::cout << "Après D -= B -> D =\n"
              << D << "\n";

    // Test de * (multiplication matrice × matrice)
    matrice_creuse E(3, 3);
    E(0, 0) = 1;
    E(1, 1) = 1;
    E(2, 2) = 1;

    std::cout << "A * E =\n"
              << (A * E) << "\n";

    matrice_creuse F(3, 3);
    F(0, 2) = 6;
    F(1, 2) = 1;
    F(2, 2) = 5;

    std::cout << "A * F =\n"
              << (A * F) << "\n";

    return 0;
}