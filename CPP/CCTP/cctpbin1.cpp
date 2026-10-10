#include <iostream>  // Flux entrant (saisie) et sortant (affichage)
#include <cassert>   // Test des préconditions
#include <string>    // Chaînes de caractères
using namespace std;

/////////////// TYPES ///////////////

// Enregistrement Joueur
struct Joueur{
    string nom;
    string prenom;
    int age;
};

// Enregistrement Equipe
struct Equipe{
    string nom;
    int nb;
    Joueur* ptab;
};

/////////////// SOUS-PROGRAMMES ///////////////

// Fonction pour créer une équipe vide
// Précondition : le nom de l'équipe str doit être bien défini
Equipe creer_equipe(const string& str)
{
    Equipe eqp;
    eqp.nom = str;
    eqp.nb = 0;
    eqp.ptab = nullptr;
    return eqp;
}
// Tests :
// str = "Les Aigles" --> eqp = ("Les Aigles" ; 0 ; nullptr)
// str = "Les Verts"  --> eqp = ("Les Verts" ; 0 ; nullptr)

// Procédure pour afficher une équipe
// Précondition : eqp est cohérente (nb >= 0, et ptab non nul si nb > 0)
void afficher_equipe(const Equipe& eqp)
{
    cout << "Le nom de l'équipe : " << eqp.nom << endl;
    cout << "Nombre de joueurs : " << eqp.nb << endl;
    if (eqp.nb == 0)
    {
        cout << "Pas de joueurs" << endl;
    }
    else
    {
        for (int i = 0; i < eqp.nb; i++)
        {
            cout << "Nom : " << eqp.ptab[i].nom << endl;
            cout << "Prénom : " << eqp.ptab[i].prenom << endl;
            cout << "Age : " << eqp.ptab[i].age << endl;
        }
    }
}
// Tests :
// eqp = ("Les Rouges", 2, [("Dupont","Alice",18), ("Durand","Paul",22)])
//   --> affiche le nom, "Nombre de joueurs : 2", puis les 2 joueurs
// eqp = ("Les Verts", 0, nullptr) --> affiche "Pas de joueurs"

// Procédure pour insérer un nouveau joueur jr en dernière position dans eqp
// Précondition : eqp.nb >= 0 et (eqp.ptab != nullptr si eqp.nb > 0)
void inserer_joueur(Equipe& eqp, const Joueur& jr)
{
    assert(eqp.nb >= 0 && (eqp.nb == 0 || eqp.ptab != nullptr));

    Joueur* nouveauptab = new Joueur[eqp.nb + 1];

    // Recopier les joueurs existants dans le nouveau tableau
    for (int i = 0; i < eqp.nb; i++)
    {
        nouveauptab[i] = eqp.ptab[i];
    }
    nouveauptab[eqp.nb] = jr;

    delete[] eqp.ptab;   // sans danger si ptab == nullptr
    eqp.ptab = nouveauptab;
    eqp.nb++;
}
// Tests :
// équipe vide + joueur A --> nb = 1, ptab = [A]
// équipe [A] + joueur B  --> nb = 2, ptab = [A, B]

// Procédure pour vider les données d'une équipe
// Précondition : eqp.ptab est nul ou a été alloué dynamiquement
void detruire_equipe(Equipe& eqp)   // <-- CORRIGÉ : par référence
{
    delete[] eqp.ptab;   // sans danger si ptab == nullptr
    eqp.ptab = nullptr;
    eqp.nom = "";
    eqp.nb = 0;
}
// Tests :
// eqp = ("Les Bleus", 2, [...]) --> eqp = ("" ; 0 ; nullptr)
// eqp = ("Les Verts", 0, nullptr) --> eqp = ("" ; 0 ; nullptr)

/////////////// PROGRAMME PRINCIPAL ///////////////

int main()
{
    // Création d'une équipe vide
    Equipe equipe2 = creer_equipe("Les Lions");
    cout << "Equipe sans joueurs :" << endl;
    afficher_equipe(equipe2);
    detruire_equipe(equipe2);

    // Initialisation des joueurs
    Joueur joueurs[] = {
        {"Dupont", "John", 25},
        {"Leblanc", "Maya", 28}
    };

    Equipe equipe;
    equipe.nom = "Les Aigles";
    equipe.nb = 2;
    equipe.ptab = new Joueur[2];   // Allocation dynamique
    for (int i = 0; i < 2; i++)
    {
        equipe.ptab[i] = joueurs[i];
    }

    cout << "Equipe initiale :" << endl;
    afficher_equipe(equipe);

    // Insertion d'un nouveau joueur
    Joueur nouveau_joueur = {"Lechat", "Lucas", 32};
    inserer_joueur(equipe, nouveau_joueur);
    cout << "Equipe après insertion d'un nouveau joueur :" << endl;
    afficher_equipe(equipe);

    // Destruction de l'équipe
    detruire_equipe(equipe);
    cout << "Equipe après destruction :" << endl;
    afficher_equipe(equipe);

    return 0;
}