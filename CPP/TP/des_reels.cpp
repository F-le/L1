/*
DATE : 27/01/2022
RÔLE : transcription de l'algorithme de l'exercice 3 du TD 1
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float unNombre, unAutre, *unPointeur;
    unNombre = 7;
    cout<<unNombre<<endl;
    
    unAutre = 5;
    cout<<unAutre<<endl;
    
    unPointeur = &unAutre;
    cout<<unPointeur<<endl;
    
    unNombre = unNombre + *unPointeur;
    cout<<unNombre<<endl;
    
    unPointeur = &unNombre;
    cout<<unPointeur<<endl;
    
    unAutre = *unPointeur - unAutre;
    cout<<unAutre<<endl;
    
    *unPointeur = unNombre - unAutre;
    cout<<unPointeur<<endl;
    
    cout << unNombre << "  " << unAutre << endl;
}
