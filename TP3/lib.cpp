#include "lib.hpp"
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>

/* Ecrire un programme qui crée un vecteur v1 de 10 float
régulièrement répartis entre 0.0 (inclu) et 1.0 (non compris), créée un
nouveau vecteur v2 égal à v1 et efface élément par élément la
deuxième moitié de v2. */
void question1()
{
    /* Question 1 */
    const int N = 10;
    std::vector<float> v1(N);

    for (int i = 0; i < N; ++i)
    {
        v1[i] = static_cast<float>(i) / N;
    }

    std::cout << "v1 contient :\n";
    for (size_t i = 0; i < v1.size(); ++i)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << "\n";
    }
    /* ====================== */
    std::vector<float> v2 = v1;
    for (int i = 0; i < 5; ++i)
    {
        v2.pop_back();
    }

    std::cout << "v2 contient :\n";
    for (size_t i = 0; i < v2.size(); ++i)
    {
        std::cout << "v2[" << i << "] = " << v2[i] << "\n";
    }
}

/* Ecrire un programme qui crée une liste l1 contenant les 10 premières lettres de l’alphabet, créer une
nouvelle liste l2 égale à l1 et effacer d’un bloc la première moitié de l2 */
void question2()
{
    std::list<char> l1;
    for (int i = 0; i < 10; ++i)
    {
        l1.push_back('A' + i);
    }

    for (size_t i = 0; i < l1.size(); ++i)
    {
        std::cout << "l1[" << i << "] = " << *std::next(l1.begin(), i) << "\n";
    }

    std::list<char> l2 = l1;
    l2.erase(l2.begin(), std::next(l2.begin(), 5));

    std::cout << "l2 contient :\n";
    for (size_t i = 0; i < l2.size(); ++i)
    {
        std::cout << "l2[" << i << "] = " << *std::next(l2.begin(), i) << "\n";
    }
}

/* Ecrire un programme qui crée un ensemble de nom d’élèves de la classe. Afficher les éléments de
l’ensemble. Supprimer les 2 premiers noms suivant l’ordre lexicographique, puis afficher de nouveau
l’ensemble. */
void question3()
{
    std::set<std::string> eleves = {"Alice", "Charlie", "David", "Ahmed", "Eve", "Bob", "Frank", "Grace"};

    std::cout << "Ensemble des élèves :\n";
    for (const auto &nom : eleves)
    {
        std::cout << nom << "\n";
    }

    eleves.erase(eleves.begin(), std::next(eleves.begin(), 2));

    std::cout << "Ensemble des élèves après suppression des 2 premiers noms :\n";
    for (const auto &nom : eleves)
    {
        std::cout << nom << "\n";
    }
}

/* Ecrire un programme qui crée un dictionnaire avec des noms et des numéros de téléphone, le numéro
de téléphone étant représenté par un entier (le premier 0 n’est pas stocké). Afficher le dictionnaire.
Supprimer tous les numéros commençant par 5 et afficher votre dictionnaire. */
void question4()
{
    std::map<std::string, int> dictionnaire = {
        {"Alice", 612345678},
        {"Bob", 567890123},
        {"Charlie", 890123456},
        {"David", 789012345},
        {"Eve", 345678901}};

    std::cout << "Dictionnaire des numéros de téléphone :\n";
    for (const auto &entry : dictionnaire)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    for (auto it = dictionnaire.begin(); it != dictionnaire.end();)
    {
        if (std::to_string(it->second).front() == '5')
        {
            it = dictionnaire.erase(it);
        }
        else
        {
            ++it;
        }
    }

    std::cout << "Dictionnaire après suppression des numéros commençant par 5 :\n";
    for (const auto &entry : dictionnaire)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
}

/* Ecrire un programme qui crée un vecteur de 5 string de longueurs différentes, affiche ces chaînes, les
trie par ordre lexicographique et réaffiche les chaînes triées. */
void question5()
{
    std::vector<std::string> strings = {"je", "foire", "pommes", "ordinateur", "avec"};

    std::cout << "Chaînes avant le tri :\n";
    for (const auto &str : strings)
    {
        std::cout << str << "\n";
    }

    std::sort(strings.begin(), strings.end());

    std::cout << "Chaînes après le tri :\n";
    for (const auto &str : strings)
    {
        std::cout << str << "\n";
    }
}

/* Ecrire un programme qui crée une liste de string représentant la phrase ”il fait beau”, trouver la position
du mot ”beau” et insérer le mot ”tres” à la position précédente. */
void question6()
{
    std::list<std::string> phrase = {"il", "fait", "beau"};

    std::cout << "Phrase avant insertion :\n";
    for (const auto &mot : phrase)
    {
        std::cout << mot << " ";
    }
    std::cout << "\n";

    auto it = std::find(phrase.begin(), phrase.end(), "beau");
    if (it != phrase.end())
    {
        phrase.insert(it, "tres");
    }

    std::cout << "Phrase après insertion :\n";
    for (const auto &mot : phrase)
    {
        std::cout << mot << " ";
    }
    std::cout << "\n";
}

int &matrice_creuse::operator()(int i, int j)
{
    if (i < 0 || i >= nb_lignes || j < 0 || j >= nb_colonnes)
    {
        throw std::out_of_range("Indices hors limites");
    }
    return data[i][j];
}

int matrice_creuse::get(int i, int j) const
{
    if (i < 0 || i >= nb_lignes || j < 0 || j >= nb_colonnes)
    {
        throw std::out_of_range("Indices hors limites");
    }
    auto it_ligne = data.find(i);
    if (it_ligne == data.end())
        return 0;
    auto it_col = it_ligne->second.find(j);
    if (it_col == it_ligne->second.end())
        return 0;
    return it_col->second;
}

void matrice_creuse::set_zero(int i, int j)
{
    auto it_ligne = data.find(i);
    if (it_ligne != data.end())
    {
        it_ligne->second.erase(j);
        if (it_ligne->second.empty())
        {
            data.erase(it_ligne);
        }
    }
}

void matrice_creuse::afficher() const
{
    if (nb_lignes == 0 || nb_colonnes == 0)
    {
        std::cout << "Matrice vide (0x0)\n";
        return;
    }

    for (int i = 0; i < nb_lignes; ++i)
    {
        for (int j = 0; j < nb_colonnes; ++j)
        {
            std::cout << std::setw(4) << get(i, j);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

size_t matrice_creuse::taille_reelle() const
{
    size_t count = 0;
    for (const auto &ligne : data)
    {
        count += ligne.second.size();
    }
    return count;
}

std::ostream &operator<<(std::ostream &os, const matrice_creuse &m)
{
    if (m.nb_lignes == 0 || m.nb_colonnes == 0)
    {
        os << "[Matrice vide " << m.nb_lignes << "×" << m.nb_colonnes << "]\n";
        return os;
    }

    for (int i = 0; i < m.nb_lignes; ++i)
    {
        for (int j = 0; j < m.nb_colonnes; ++j)
        {
            os << std::setw(4) << m.get(i, j); // tous les zéros s'affichent
        }
        os << "\n";
    }
    return os;
}

void matrice_creuse::clear(int i, int j)
{
    auto it = data.find(i);
    if (it != data.end())
    {
        it->second.erase(j);
        if (it->second.empty())
            data.erase(it);
    }
}

matrice_creuse matrice_creuse::operator+(const matrice_creuse &autre) const
{
    if (nb_lignes != autre.nb_lignes || nb_colonnes != autre.nb_colonnes)
    {
        throw std::invalid_argument("Dimensions incompatibles pour +");
    }

    matrice_creuse res(nb_lignes, nb_colonnes);
    for (const auto &[i, row] : data)
        for (const auto &[j, v] : row)
            res(i, j) = v;

    for (const auto &[i, row] : autre.data)
        for (const auto &[j, v] : row)
        {
            int somme = res.get(i, j) + v;
            if (somme != 0)
                res(i, j) = somme;
            else
                res.clear(i, j);
        }
    return res;
}

// Soustraction
matrice_creuse matrice_creuse::operator-(const matrice_creuse &autre) const
{
    if (nb_lignes != autre.nb_lignes || nb_colonnes != autre.nb_colonnes)
    {
        throw std::invalid_argument("Dimensions incompatibles pour -");
    }

    matrice_creuse res(nb_lignes, nb_colonnes);
    for (const auto &[i, row] : data)
        for (const auto &[j, v] : row)
            res(i, j) = v;

    for (const auto &[i, row] : autre.data)
        for (const auto &[j, v] : row)
        {
            int diff = res.get(i, j) - v;
            if (diff != 0)
                res(i, j) = diff;
            else
                res.clear(i, j);
        }
    return res;
}

// +=
matrice_creuse &matrice_creuse::operator+=(const matrice_creuse &autre)
{
    *this = *this + autre;
    return *this;
}

// -=
matrice_creuse &matrice_creuse::operator-=(const matrice_creuse &autre)
{
    *this = *this - autre;
    return *this;
}

// Multiplication matrice × matrice
matrice_creuse matrice_creuse::operator*(const matrice_creuse &droite) const
{
    if (nb_colonnes != droite.nb_lignes)
    {
        throw std::invalid_argument("Dimensions incompatibles pour *");
    }

    matrice_creuse res(nb_lignes, droite.nb_colonnes);

    for (const auto &[i, row_i] : data)
    {
        for (const auto &[k, vik] : row_i)
        {
            auto it = droite.data.find(k);
            if (it == droite.data.end())
            {
                continue;
            }
            for (const auto &[j, vkj] : it->second)
            {
                int nouveau = res.get(i, j) + vik * vkj;
                if (nouveau != 0)
                {
                    res(i, j) = nouveau;
                }
                else
                {
                    res.clear(i, j);
                }
            }
        }
    }
    return res;
}
