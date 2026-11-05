/*
DATE : 12/01/2024
RÔLE : transcription de l'algorithme de l'exercice 6 du TD 1
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int unNombre, *unPointeur; //initialisation

    unNombre = 7; //valeur de unNombre = 7
    cout << "Le nombre est : " << unNombre << endl;

    unPointeur = &unNombre; //unPointeur prend l'adresse de unNombre
    cout << unPointeur<<endl;

    *unPointeur = 13; //mémoire unPointeur = 13
    cout << ", mais maintenant il vaut : " << *unPointeur << endl;

    unPointeur = new int; //allocation unPointeur
    cout << unPointeur<<endl;

    *unPointeur = 25; //mémoire unPointeur = 25
    cout << unPointeur <<endl;

    unNombre = *unPointeur + 39; //unNombre = mémoire(unPointeur) + 39
    cout << unNombre<<endl;

    delete unPointeur; //désallocation unPointeur
    cout << unPointeur<<endl;

    unPointeur = &unNombre; //unPointeur = adresse(unNombre)
    cout << unPointeur<<endl;

    cout << unNombre << " " << *unPointeur << endl;
}
