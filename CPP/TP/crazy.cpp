/*
DATE : 27/01/2022
RÔLE : comprendre le fonctionnement des pointeurs en C++
*/

/* & = adresse ; * = mémoire*/

#include <iostream>
using namespace std;

int main () {
    int a = 1, b = 2, c = 3; //a, b, c prennent respectiveent les valeurs 1, 2, 3
    
    int *p1, *p2; //declaration des pointeurs p1 et p2
    
    p1 = &a; //p1 pointe vers a
    cout<< "p1 = " << p1<<endl;
    
    p2 = &c; //p2 pointe vers c
    cout<<"p2 = " << p2<<endl;
    
    *p1 = (*p2)++; //a = c; c est maintenant incrémenté à 4 : a = 3; b = 2; c = 4
    cout<<"*p1 = " << *p1<<endl;
    
    p1 = p2; //p1 pointe vers c
    cout<<"p1 = " << p1<<endl;
    
    p2 = &b; //p2 pointe vers b
    cout<<"p2 = " << p2<<endl;
    
    *p1 -= *p2; //c = c - b = 4 - 2 = 2; a = 3; b = 2; c = 2 (p1 pointe vers c et p2 pointe vers b)
    cout<<"*p1 = " << *p1<<endl;
    
    *p1 *= *p2; //c = c * b = 2 * 2 = 4; a = 3; b = 2; c = 4 (p1 pointe vers c et p2 pointe vers b)
    cout<<"*p1 = " << *p1<<endl;
    
    a = *p2 * *p1; //a = b * c = 2 * 4 = 8; a = 8; b = 2; c = 4
    cout<<"a = " << a<<endl;
    
    p1 = &a; //p1 pointe vers a
    cout<<"p1 = " << p1<<endl;
    
    *p1 /= *p2; //a = a/b = 8/2 = 4; a = 4; b = 2; c = 4
    cout<<"*p1 = " << *p1<<endl;
}
