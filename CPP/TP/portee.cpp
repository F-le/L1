/*
DATE : 19/01/2022
RÔLE : illustrer le fonctionnement de la portée des identifiants en C++
*/
#include <iostream>
#include <cmath>
using namespace std;

// Point nommé en coordonnées cartésiennes
struct t_point { /*enregistrement*/
    string nom; /*paramètre entrée*/
    float x,y; /*paramètre entrée*/
};

// Nombre de points
const int max = 4; /*constante globale*/

// Point origine du repère
t_point origine = {"O",0.0f,0.0f}; /*variable locale*/

//--------------------------------------------------------------------
// Fonction retournant la distance d'un point p donné à l'origine
// pré : le point p est correctement initialisé
float rayon(t_point p) { /*Fonction*/
    return static_cast<float>(sqrt(pow(origine.x-p.x,2)+pow(origine.y-p.y,2)));
}

//--------------------------------------------------------------------
// Procédure permettant l'initialisation d'un point p donné par des saisies
// pré : aucune (le point p sera écrasé s'il était déjà initialisé)
void saisir(t_point & p) { /*Procédure*/
    cin >> p.nom >> p.x >> p.y;
}

//--------------------------------------------------------------------
// programme principal demandant à l'utilisateur max points
// et affichant le plus distant de l'origine
int main() {
    float max = 0.0f; // distance maximale à l'origine /*variable locale*/
    string nom; // nom du point le plus distant /*variable locale*/
    t_point pt; /*variable locale*/
    cout << "Donner " << ::max << " points (nom,x,y):" << endl;
    // répétitive de saisie des points avec maintient du plus distant
    for (int i=0 ; i<::max ; i++ ) {
        saisir(pt);
        float rayon = ::rayon(pt); /*variable locale*/
        // mise à jour du point le plus distant ?
        if (rayon > max) {
            max = rayon;
            nom = pt.nom;
        }
    }
    // affichage du résultat
    cout << "Rayon maxi : " << nom << "(" << max << ")" << endl;
}
 /*
  -Confusion entre la constante globale "max" et la variable locale "max" --- "declaration of ‘max’ shadows a global declaration" --- ::max
  -Confusion entre la fonction "rayon" et la variable "rayon" --- "error: ‘rayon’ cannot be used as a function" --- ::rayon
  */


