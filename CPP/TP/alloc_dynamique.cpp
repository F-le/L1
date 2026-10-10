#include <iostream>
using namespace std;

struct couple {
    char ltr;
    char* ptr;
};

int main() {
    char* pcar;
    couple* duo;

    duo = new couple;

    duo->ltr = 'A';
    duo->ptr = new char;
    *(duo->ptr) = 'L';

    pcar = new char;
    *pcar = 'G';
    *(duo->ptr) = 'O';

    cout << duo->ltr << endl;   // A

    delete duo->ptr;   // libère d'abord le char pointé
    delete duo;        // puis la structure

    cout << *pcar << endl;      // G

    delete pcar;
    return 0;
}