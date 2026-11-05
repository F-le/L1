#include <iostream>
#include <string>

using namespace std;

// Définition de la classe Etudiant
struct Etudiant {
    string nom;
    Etudiant* p_binome;
    float* p_note;

    // Constructeur par défaut
    Etudiant() : p_binome(nullptr), p_note(nullptr) {}

    // Méthode pour former un binôme
    void formerBinome(Etudiant* binome) {
        p_binome = binome;
    }

    // Méthode pour affecter une note commune
    void affecterNoteCommune(float note) {
        if (p_note != nullptr) {
            *(p_note) = note;
        }
        if (p_binome != nullptr && p_binome->p_note != nullptr) {
            *(p_binome->p_note) = note;
        }
    }

    // Méthode pour afficher l'étudiant et son binôme avec leur note
    void afficherBinomeEtNote() {
        cout << "Etudiant 1 : " << nom << ", Note : " << *(p_note) << endl;

        if (p_binome != nullptr) {
            cout << "Etudiant 2 : " << p_binome->nom << ", Note : " << *(p_binome->p_note) << endl;
        }
    }

    // Méthode pour dissocier le binôme et retirer leur note
    void dissocierBinome() {
        if (p_binome != nullptr) {
            p_binome->p_binome = nullptr;
            p_binome->p_note = nullptr;
            p_binome = nullptr;
            p_note = nullptr;
        }
    }
};

int main() {
    Etudiant etudiant1, etudiant2;

    etudiant1.nom = "Jean";
    etudiant2.nom = "Marie";

    float note;

    cout << "Entrez la note pour le binome: ";
    cin >> note;

    etudiant1.formerBinome(&etudiant2);

    etudiant1.p_note = &note;
    etudiant2.p_note = &note;

    cout << "Binome forme : " << endl;
    etudiant1.afficherBinomeEtNote();

    etudiant1.dissocierBinome();

    cout << "Binome dissocie :" << endl;
    etudiant1.afficherBinomeEtNote();

    return 0;
}
