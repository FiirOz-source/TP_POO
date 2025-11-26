#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();

class matrice_creuse;
std::ostream &operator<<(std::ostream &os, const matrice_creuse &m);

class matrice_creuse
{
public:
    matrice_creuse(int lignes = 0, int colonnes = 0)
        : nb_lignes(lignes), nb_colonnes(colonnes)
    {
    }
    int &operator()(int i, int j);
    int get(int i, int j) const;
    void set_zero(int i, int j);
    void afficher() const;
    size_t taille_reelle() const;
    void clear(int i, int j);
    friend std::ostream &operator<<(std::ostream &os, const matrice_creuse &m);

    // Addition
    matrice_creuse operator+(const matrice_creuse &autre) const;

    // Soustraction
    matrice_creuse operator-(const matrice_creuse &autre) const;

    // +=
    matrice_creuse &operator+=(const matrice_creuse &autre);

    // -=
    matrice_creuse &operator-=(const matrice_creuse &autre);

    // Multiplication matrice × matrice
    matrice_creuse operator*(const matrice_creuse &droite) const;

private:
    std::map<int, std::map<int, int>> data;
    int nb_lignes = 0;
    int nb_colonnes = 0;
};

#endif // LIB_HPP