#include <iostream>
#include <string>
using namespace std;

struct tva{
    string nom;
    float taux;
};

struct produit{
    string description;
    float prix_ht;
    tva *taux_tva;
};

tva taux_reduit = {"reduit", 5.5};
tva taux_normal = {"normal", 20.0};
tva taux_particulier = {"particulier", 2.1};

float prix_ttc(const produit &prod){
    return prod.prix_ht + (prod.prix_ht * prod.taux_tva->taux) / 100;
}

produit saisir_produit(tva &cat){
    produit prod;

    cout << "Saisir la description : ";
    cin >> prod.description;
    cout << "Saisir le prix HT : ";
    cin >> prod.prix_ht;
    prod.taux_tva = &cat;

    return prod;
}

void saisir(produit &prod){
    int cat;

    cout << "Saisir une valeur entre 1 et 3 : " << endl;
    cin >> cat;

    if (cat == 1){
        prod = saisir_produit(taux_reduit);
    }
    else if (cat == 2){
        prod = saisir_produit(taux_normal);
    }
    else if (cat == 3){
        prod = saisir_produit(taux_particulier);
    }
    else{
        cerr << "Erreur de saisie" << endl;
    }
}

void affiche_produit(const produit &prod){
    cout << "Description : " << prod.description << endl;
    cout << "Prix HT : " << prod.prix_ht << endl;
    cout << "Taux TVA : " << prod.taux_tva->taux << "%" << endl;
}

int main(){
    produit prod, tarte;

    tarte = {"tarte aux pruneaux", 7.5, &taux_reduit};

    prod = saisir_produit(taux_reduit);

    taux_reduit.taux = 6.0;   // modifie la TVA des deux produits

    affiche_produit(prod);
    affiche_produit(tarte);

    return 0;
}