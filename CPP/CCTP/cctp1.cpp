/*
* AUTEUR : F-le
* RÔLE : Manipuler des structures de données complexes en utilisant des pointeurs et allocations dynamiques pour gérer des étudiants et leur binôme
* 11/02/2025
*/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Définition du type t_etudiant
struct t_etudiant {
    string nom;
    t_etudiant* p_binome;
    float* p_note;
};

// Procédure: init_etudiant
// Rôle: Initialise un étudiant
// Précondition: Aucune
void init_etudiant(t_etudiant& etu) {
    cout << "Entrez le nom de l'etudiant : ";
    cin >> etu.nom;
    etu.p_binome = nullptr;
    etu.p_note = nullptr;
}

// Procédure: associer_etudiants
// Rôle: Associe deux étudiants en binôme
// Précondition: Les deux étudiants ne doivent pas déjà être associés à un autre binôme
void associer_etudiants(t_etudiant& etu1, t_etudiant& etu2) {
    assert(etu1.p_binome == nullptr && etu2.p_binome == nullptr); // Vérifie que les étudiants ne sont pas déjà associés
    etu1.p_binome = &etu2;
    etu2.p_binome = &etu1;
    cout << "Binome project : " << etu1.nom << " et " << etu2.nom << " sont maintenant associes en binome." << endl;
}

// Procédure: noter_binome
// Rôle: Attribue une note à un étudiant et à son binôme
// Précondition: L'étudiant doit avoir un binôme associé
// Ici, on utilise "new" au lieu de l'adresse(comme dans le pseudo code) pour allouer deux zones mémoire distinctes contenant la même note pour chaque étudiant
void noter_binome(t_etudiant& etu, float note) {
    assert(etu.p_binome != nullptr); // Vérifie que l'étudiant a un binôme
    etu.p_note = new float(note);
    etu.p_binome->p_note = new float(note);
    cout << "Note attribuee : " << note << " pour " << etu.nom << " et " << etu.p_binome->nom << "." << endl;
}

/*
résultat si on utilise "&note":
Informations de l'etudiant : ex2
  Binome : ex1
  Note : 4.59163e-41
Informations de l'etudiant : ex1
  Binome : ex2
  Note : 4.59163e-41
*/

// Procédure: dissocier_binome
// Rôle: Dissocie un étudiant de son binôme
// Précondition: L'étudiant doit avoir un binôme associé
void dissocier_binome(t_etudiant& etu) {
    assert(etu.p_binome != nullptr); // Vérifie que l'étudiant a un binôme
    etu.p_binome->p_binome = nullptr;
    etu.p_binome->p_note = nullptr;
    etu.p_binome = nullptr;
    etu.p_note = nullptr;
    cout << "Dissociation : " << etu.nom << " n'a plus de binome." << endl;
}

// Procédure: afficher_etudiant
// Rôle: Affiche les informations d'un étudiant (nom, binôme, note)
// Précondition: Aucune
void afficher_etudiant(const t_etudiant& etu) {
    cout << "Informations de l'etudiant : " << etu.nom << endl;
    if (etu.p_binome != nullptr) {
        cout << "  Binome : " << etu.p_binome->nom << endl;
    } else {
        cout << "  Binome : Aucun" << endl;
    }
    if (etu.p_note != nullptr) {
        cout << "  Note : " << *etu.p_note << endl;
    } else {
        cout << "  Note : Aucune" << endl;
    }
}

// Fonction: majorer_note
// Rôle: Majore la note d'un étudiant et de son binôme
// Précondition: L'étudiant doit avoir une note attribuée
float majorer_note(t_etudiant& etu, float coeff) {
    assert(etu.p_note != nullptr); // Vérifie que l'étudiant a une note
    *etu.p_note *= (1 + coeff);
    *etu.p_binome->p_note *= (1 + coeff);
    cout << "Majoration appliquee : " << etu.nom << " et " << etu.p_binome->nom << " ont maintenant une note de " << *etu.p_note << "." << endl;
    return *etu.p_note;
}

// Programme principal
int main() {
    cout << "=== Gestion des binomes et des notes ===" << endl;

    // Initialisation de deux étudiants
    t_etudiant etu1, etu2;
    cout << "\nInitialisation des etudiants :" << endl;
    init_etudiant(etu1);
    init_etudiant(etu2);

    // Association des étudiants en binôme
    cout << "\nAssociation des etudiants en binome :" << endl;
    associer_etudiants(etu1, etu2);

    // Saisie et attribution de la note
    float note;
    cout << "\nEntrez la note pour le binome : ";
    cin >> note;
    noter_binome(etu1, note);

    cout << "\nAffichage des etudiants apres attribution de la note :" << endl;
    afficher_etudiant(etu1);
    afficher_etudiant(etu2);

    // Saisie du coefficient de majoration
    float coeff;
    cout << "\nEntrez le coefficient de majoration (ex: 0.1 pour 10%) : ";
    cin >> coeff;

    // Majoration de la note
    majorer_note(etu1, coeff);

    cout << "\nAffichage des etudiants apres majoration :" << endl;
    afficher_etudiant(etu1);
    afficher_etudiant(etu2);

    // Dissociation du binôme
    cout << "\nDissociation du binome :" << endl;
    dissocier_binome(etu1);

    // Affichage des étudiants
    cout << "\nAffichage final des etudiants :" << endl;
    afficher_etudiant(etu1);
    afficher_etudiant(etu2);

}



// === Jeux de test fonctionnels ===
/*
/------------------------------------------------------------------------
Test 1 :
- Initialisation de deux étudiants : Ethan et Marcus
- Association en binôme
- Attribution d'une note de 14
- Majoration de la note de 20%
- Résultat attendu : La note passe à 16.8 pour les deux étudiants
- Dissociation du binôme
- Les pointeurs p_binome et p_note sont réinitialisés à NULL (désallocation)

=== Gestion des binomes et des notes ===

Initialisation des etudiants :
Entrez le nom de l'etudiant : Ethan
Entrez le nom de l'etudiant : Marcus

Association des etudiants en binome :
Binome project : Ethan et Marcus sont maintenant associes en binome.

Entrez la note pour le binome : 14
Note attribuee : 14 pour Ethan et Marcus.

Affichage des etudiants apres attribution de la note :
Informations de l'etudiant : Ethan
  Binome : Marcus
  Note : 14
Informations de l'etudiant : Marcus
  Binome : Ethan
  Note : 14

Entrez le coefficient de majoration (ex: 0.1 pour 10%) : 0.2
Majoration appliquee : Ethan et Marcus ont maintenant une note de 16.8.

Affichage des etudiants apres majoration :
Informations de l'etudiant : Ethan
  Binome : Marcus
  Note : 16.8
Informations de l'etudiant : Marcus
  Binome : Ethan
  Note : 16.8

Dissociation du binome :
Dissociation : Ethan n'a plus de binome.

Affichage final des etudiants :
Informations de l'etudiant : Ethan
  Binome : Aucun
  Note : Aucune
Informations de l'etudiant : Marcus
  Binome : Aucun
  Note : Aucune

/------------------------------------------------------------------------
Test 2 :
- Initialisation d'un étudiant seul : Elliot
- Tentative d'association avec un étudiant non initialisé
- Résultat attendu : Assertion échoue car l'étudiant non initialisé n'a pas de binôme
- Le résultat ne s'affichera pas tant que le nom du binome ne sera pas initialisé

Initialisation des etudiants :
Entrez le nom de l'etudiant : Elliot
Entrez le nom de l'etudiant : 


(et ce jusqu'à ce qu'on initialise le nom du binôme)

/------------------------------------------------------------------------
Test 3 :
- Initialisation de deux étudiants : Roma et Chiyaya
- Association en binôme
- Tentative de majoration de la note sans attribution préalable
- Résultat attendu : Assertion échoue car aucune note n'a été attribuée
- Le résultat ne s'affichera pas tant que la note 

Initialisation des etudiants :
Entrez le nom de l'etudiant : Roma
Entrez le nom de l'etudiant : Chiyaya

Association des etudiants en binome :
Binome project : Roma et Chiyaya sont maintenant associes en binome.

Entrez la note pour le binome : 




(et ce jusqu'à ce qu'une note soit attribuée)
*/