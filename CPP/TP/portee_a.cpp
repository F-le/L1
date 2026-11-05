#include <iostream>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

string mot;

int frequence(char car){

    int ind, f;

    f=0;

    for (ind=0; ind<mot.length(); ind++) {
        if (mot[ind] == car){
            f++;
        }
    }
    return f;
}

void plus_frequent(char& c, int& f){

    int i, freq;

    f=0;

    for (i=0; i<alphabet.length(); i++){
        freq = frequence(alphabet[i]);

        if(freq > f){
            f = freq;
            c = alphabet[i];
        }
    }
}

int main() {
    char car;
    int freq;

    cout << "Donnez un mot : "<<endl;
    cin >> mot;

    plus_frequent(car, freq);
    cout << "Max : " << car << "(" << freq << ")" <<endl;
}