#include <iostream>
using namespace std;

struct couple {
    char ltr;
    char *ptr;
};

void permuter(couple& con) {
    char temp = con.ltr;
    con.ltr = *(con.ptr);
    *(con.ptr) = temp;
}

couple saisie_couple() {
    couple duo;
    cout << "Saisir un caractère: ";
    cin >> duo.ltr;

    duo.ptr = new char;
    cout << "Saisir un autre caractère: ";
    cin >> *duo.ptr;

    return duo;
}

void copie_couple(const couple& cpl1, couple& cpl2) {
    cpl2.ltr = cpl1.ltr;
    cpl2.ptr = new char(*cpl1.ptr);
}

int main() {
    couple firstCouple = saisie_couple();
    couple secondCouple;

    copie_couple(firstCouple, secondCouple);

    cout << "Before permutation:\n";
    cout << "First couple: " << firstCouple.ltr << " " << *firstCouple.ptr << endl;
    cout << "Second couple: " << secondCouple.ltr << " " << *secondCouple.ptr << endl;

    permuter(firstCouple);

    cout << "After permutation:\n";
    cout << "First couple: " << firstCouple.ltr << " " << *firstCouple.ptr << endl;
    cout << "Second couple: " << secondCouple.ltr << " " << *secondCouple.ptr << endl;

    delete firstCouple.ptr;
    delete secondCouple.ptr;

    return 0;
}