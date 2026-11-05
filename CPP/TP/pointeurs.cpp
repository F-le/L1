#include <iostream>

using namespace std;

struct couple {
    char ltr;
    char *ptr;
};

void desReels() {
    float unNombre, unAutre, *unPointeur;

    unNombre = 7;
    cout << unNombre << endl;                // 7

    unAutre = 5;
    cout << unAutre << endl;                 // 5

    unPointeur = &unAutre;
    cout << *unPointeur << endl;             // 5

    unNombre = unNombre + *unPointeur;
    cout << unNombre << endl;                // 12

    unPointeur = &unNombre;
    cout << *unPointeur << endl;             // 12

    unAutre = *unPointeur - unAutre;
    cout << unAutre << endl;                 // 7

    *unPointeur = unNombre - unAutre;
    cout << *unPointeur << endl;             // 5

    cout << unNombre << "  " << unAutre << endl;   // 5  7
}

void desCaracteres() {
    char uneLettre;
    char *unPointeur = nullptr;

    couple unePaire;
    couple *unAutre;

    uneLettre = 'a';

    unePaire.ltr = uneLettre;
    unePaire.ptr = unPointeur;

    unAutre = &unePaire;
    unPointeur = &uneLettre;

    uneLettre = 'b';

    unePaire.ltr = *unPointeur;
    unePaire.ptr = unPointeur;
    unPointeur = &unePaire.ltr;

    unAutre->ltr = 'c';
    *unPointeur = unePaire.ltr;
    *(*unAutre).ptr = 'd';

    cout << uneLettre << " " << unePaire.ltr << endl;   // d c
}

int main() {
    desReels();
    desCaracteres();
    return 0;
}