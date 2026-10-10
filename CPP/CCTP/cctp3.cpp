#include <iostream>
#include <cassert>
using namespace std;

struct couple {
    char ltr;
    char *ptr;
};

/**
 * @brief Permute les valeurs entre la lettre et le caractère pointé d'un couple.
 * @param c : le couple dont les valeurs doivent être permutées.
 * @pre c.ptr doit pointer vers une zone de mémoire valide.
 */
void permuterCouple(couple& c) {
    assert(c.ptr != nullptr);

    char tmp = c.ltr;
    c.ltr = *(c.ptr);
    *(c.ptr) = tmp;
}

/**
 * @brief Saisit et renvoie un couple.
 * @return Un couple dont ptr pointe vers une zone allouée dynamiquement.
 * @pre aucune
 */
couple saisirCouple() {
    couple duo;

    duo.ptr = new char;   // allocation dynamique
    cout << "Entrez la lettre : ";
    cin >> duo.ltr;
    cout << "Entrez le caractère pointé : ";
    cin >> *(duo.ptr);

    return duo;
}

/**
 * @brief Libère la mémoire allouée dynamiquement pour le pointeur du couple.
 * @param c : le couple dont le pointeur doit être libéré.
 * @pre c.ptr doit pointer vers une zone de mémoire allouée dynamiquement.
 */
void libererCouple(couple& c) {
    assert(c.ptr != nullptr);

    delete c.ptr;
    c.ptr = nullptr;
}

/**
 * @brief Affiche les deux lettres d'un couple.
 * @param c : le couple à afficher.
 * @pre c.ptr doit pointer vers une zone de mémoire valide.
 */
void afficherCouple(const couple& c) {
    assert(c.ptr != nullptr);

    cout << "(" << c.ltr << "," << *(c.ptr) << ")" << endl;
}

int main() {
    cout << "Test de saisirCouple:" << endl;
    couple testCouple = saisirCouple();
    cout << endl;

    cout << "Test de afficherCouple:" << endl;
    afficherCouple(testCouple);
    cout << endl;

    cout << "Test de permuterCouple:" << endl;
    permuterCouple(testCouple);
    afficherCouple(testCouple);
    cout << endl;

    cout << "Test de libererCouple:" << endl;
    libererCouple(testCouple);
    // afficherCouple(testCouple); // Décommenter cette ligne déclenche l'assertion

    return 0;
}