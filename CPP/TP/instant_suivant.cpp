#include <iostream>
using namespace std;

struct Instant {
    int heures;
    int minutes;
    int secondes;
};

void saisirInstant(Instant& instant) {
    do {
        cout << "Entrez les heures : ";
        cin >> instant.heures;
        cout << "Entrez les minutes : ";
        cin >> instant.minutes;
        cout << "Entrez les secondes : ";
        cin >> instant.secondes;

        if (instant.heures < 0 || instant.heures > 23 ||
            instant.minutes < 0 || instant.minutes > 59 ||
            instant.secondes < 0 || instant.secondes > 59) {
            cout << "Veuillez entrer un instant valide (heures entre 0 et 23, minutes et secondes entre 0 et 59)." << endl;
        }
    } while (instant.heures < 0 || instant.heures > 23 ||
             instant.minutes < 0 || instant.minutes > 59 ||
             instant.secondes < 0 || instant.secondes > 59);
}

void afficherInstant(const Instant& instant) {
    cout << instant.heures << ":"
         << instant.minutes << ":"
         << instant.secondes << endl;
}

Instant suivantSeconde(const Instant& instant) {
    Instant suivant;
    suivant.secondes = instant.secondes + 1;
    suivant.minutes = instant.minutes;
    suivant.heures = instant.heures;

    if (suivant.secondes > 59) {
        suivant.secondes = 0;
        suivant.minutes++;

        if (suivant.minutes > 59) {
            suivant.minutes = 0;
            suivant.heures++;

            if (suivant.heures > 23) {
                suivant.heures = 0;
            }
        }
    }

    return suivant;
}

int main() {
    Instant instantSouhaite;
    saisirInstant(instantSouhaite);
    afficherInstant(instantSouhaite);

    Instant instantSuivant = instantSouhaite;
    do {
        instantSuivant = suivantSeconde(instantSuivant);
        afficherInstant(instantSuivant);
    } while (true);

    return 0;
}