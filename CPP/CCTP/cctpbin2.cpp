/********************************************************
* RÔLE : Un programme écrit en C++ de gestion d'une liste chaînée d'étudiants
* le 26/04/2024
*******************************************************/
#include <iostream>  // Flux entrant (saisie) et sortant (affichage)
#include <string>    // Type string
using namespace std;

/////////////// TYPES ///////////////

// Type t_etudiant représentant un étudiant
struct t_etudiant{
    string nom;
    string prenom;
    int age;
};

// Type t_noeud représentant un nœud de la liste chaînée
struct t_noeud{
    t_etudiant etudiant;
    t_noeud* suivant = nullptr; // Pointeur vers le nœud suivant
};

// Type t_liste représentant une liste chaînée d'étudiants
struct t_liste{
    t_noeud* pt = nullptr; // Pointeur vers le premier nœud
};

/////////////// SOUS-PROGRAMMES ///////////////

// Procédure qui ajoute un nouvel étudiant en tête de la liste
// Précondition : nom, prénom et âge doivent être bien définis
void ajouterEnTete(t_liste& liste, const string& nom, const string& prenom, int age){
    t_noeud* nouveauNoeud = new t_noeud;
    nouveauNoeud->etudiant.nom = nom;
    nouveauNoeud->etudiant.prenom = prenom;
    nouveauNoeud->etudiant.age = age;
    nouveauNoeud->suivant = liste.pt;
    liste.pt = nouveauNoeud;

    cout << "Etudiant ajouté : " << nom << " " << prenom << " " << age << endl;
}
// Jeu de tests :
// 1) liste vide, ajout de A -> [A]
// 2) liste [A], ajout de B -> [B, A]

// Procédure qui affiche tous les étudiants de la liste
// Précondition : aucune
void afficherListe(const t_liste& liste){
    t_noeud* temp = liste.pt;
    if(temp == nullptr){
        cout << "(liste vide)" << endl;
    }
    while(temp != nullptr){
        cout << temp->etudiant.nom << " " << temp->etudiant.prenom << " "
             << temp->etudiant.age << endl;
        temp = temp->suivant;
    }
}
// Jeu de tests :
// 1) liste vide -> "(liste vide)"
// 2) liste à plusieurs éléments -> un étudiant par ligne

// Fonction qui cherche l'existence d'un étudiant dans la liste
// Précondition : nom, prénom et âge doivent être bien définis
bool rechercherEtudiant(const t_liste& liste, const string& nom, const string& prenom, int age){
    bool trouve = false;
    t_noeud* temp = liste.pt;
    while(temp != nullptr && !trouve){   // <-- CORRIGÉ : !trouve
        if(temp->etudiant.nom == nom
           && temp->etudiant.prenom == prenom
           && temp->etudiant.age == age){
            trouve = true;
        }
        temp = temp->suivant;
    }
    return trouve;
}
// Jeu de tests :
// 1) étudiant en tête de liste -> true
// 2) étudiant absent -> false
// 3) liste vide -> false

// Procédure qui inverse l'ordre des éléments de la liste chaînée
// Précondition : aucune
void inverserListe(t_liste& liste){
    t_noeud* prev = nullptr;
    t_noeud* courant = liste.pt;
    t_noeud* suivant = nullptr;

    while(courant != nullptr){
        suivant = courant->suivant;
        courant->suivant = prev;
        prev = courant;
        courant = suivant;
    }
    liste.pt = prev;
}
// Jeu de tests :
// 1) liste vide -> reste vide
// 2) un seul élément -> inchangée
// 3) [A, B, C] -> [C, B, A]

// Fonction qui supprime un étudiant de la liste ; renvoie true si supprimé
// Précondition : aucune (renvoie false si l'étudiant n'existe pas)
bool supprimerEtudiant(t_liste& liste, const string& nom, const string& prenom, int age){
    t_noeud* courant = liste.pt;
    t_noeud* precedent = nullptr;

    while(courant != nullptr){
        if(courant->etudiant.nom == nom
           && courant->etudiant.prenom == prenom
           && courant->etudiant.age == age){
            if(precedent != nullptr){
                precedent->suivant = courant->suivant;
            } else {
                liste.pt = courant->suivant;
            }
            delete courant;
            return true;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    return false;
}
// Jeu de tests :
// 1) suppression de la tête
// 2) suppression d'un élément du milieu ou de la fin
// 3) étudiant absent -> false, liste inchangée

// Procédure qui vide la liste de tous ses étudiants
// Précondition : aucune
void viderListe(t_liste& liste){
    t_noeud* temp;
    while(liste.pt != nullptr){
        temp = liste.pt;
        liste.pt = liste.pt->suivant;
        delete temp;
    }
}
// Jeu de tests :
// 1) liste à plusieurs éléments -> liste vide
// 2) liste déjà vide -> reste vide

int main(){
    t_etudiant e1 = {"Dupont", "Jean", 20};
    t_etudiant e2 = {"Martin", "Smith", 22};
    t_etudiant e3 = {"Dubois", "Pierre", 19};

    t_liste liste;

    ajouterEnTete(liste, e1.nom, e1.prenom, e1.age);
    ajouterEnTete(liste, e2.nom, e2.prenom, e2.age);
    ajouterEnTete(liste, e3.nom, e3.prenom, e3.age);

    cout << "Liste des étudiants :" << endl;
    afficherListe(liste);

    // Recherche : un étudiant présent et un étudiant absent
    string tests[2][2] = {{"Martin", "Smith"}, {"Martin", "Marie"}};
    int ages[2] = {22, 22};
    for(int i = 0; i < 2; i++){
        cout << "L'étudiant " << tests[i][0] << " " << tests[i][1]
             << " âgé de " << ages[i] << " ans "
             << (rechercherEtudiant(liste, tests[i][0], tests[i][1], ages[i])
                    ? "est dans la liste." : "n'est pas dans la liste.")
             << endl;
    }

    inverserListe(liste);
    cout << "Liste inversée des étudiants :" << endl;
    afficherListe(liste);

    string nomSuppression = "Martin";
    string prenomSuppression = "Smith";
    int ageSuppression = 22;
    if(supprimerEtudiant(liste, nomSuppression, prenomSuppression, ageSuppression)){
        cout << "Liste après suppression de " << nomSuppression << " "
             << prenomSuppression << " âgé de " << ageSuppression << " ans :" << endl;
    } else {
        cout << "Etudiant à supprimer introuvable." << endl;
    }
    afficherListe(liste);

    viderListe(liste);
    cout << "Liste après vidage :" << endl;
    afficherListe(liste);

    return 0;
}