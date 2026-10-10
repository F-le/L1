/**************************************************************************************************
*
*	Nantes Université 2024/2025
*
*	02/04/2025
*
*	Mini-projet permettant de manipuler les tableaux de N entiers positifs 
*
**************************************************************************************************/

#include<iostream>	
using namespace std;	

//----------------------------------------------------------------------
// 1 - Procédure permettant de remplir un tableau de N entiers positifs
// Précondition: N > 0 
void remplir(int* tab, int N){
	int i;
	
	for(i=0; i<N; i++){
		do{
			cout<<"Entrez l'entier n° "<<i+1<<": ";
			cin>>tab[i];
			if(tab[i]<0){
				cout<<"L'entier doit être strictement positf!";
			}
			
		}while(tab[i]<0);
	}	
}

//----------------------------------------------------------------------
// 2 - Procédure affichant tous les éléments du tableau
// Précondition: N > 0
void affiche_tab(int* tab, int N){
	int i;
	
	cout<<"[";
	for(i=0; i<N; i++){
		cout<<tab[i];
		if(i<N-1){
			cout<<", ";
		}
	}
	cout<<"]"<<endl;
}

//----------------------------------------------------------------------
// 3 - Fonction qui permet de savoir si le tableau est symétrique ou non (1 = N?, 2 = N-1? ...)
// Précondition: N > 0
bool mirror(int* tab, int N){
	int i;
	
	for(i=0; i<N/2; i++){
		if(tab[i] != tab[N-1-i]){
			return false;
		}
	}
	return true;
}

//----------------------------------------------------------------------
// 4 - Procédure permettant d'inverser les éléments du tableau
// Précondition: N > 0
void inv_tab(int* tab, int N){
	int i, temp;
	
	for(i=0; i<N/2; i++){
		temp = tab[i];
		tab[i] = tab[N-1-i];
		tab[N-1-i] = temp;
	}
}

//----------------------------------------------------------------------
// 5 - Procédure permettant de trier les éléments du tableau de manière croissante
// Précondition: N > 0
void trie_tab(int* tab, int N){
	int i, j, temp;
	
	for(i=0; i<N-1; i++){
		int ind_min = i;
		for(j=i+1; j<N; j++){
			if(tab[j] < tab[ind_min]){
				ind_min = j;
			}
		}
		temp = tab[i];
		tab[i] = tab[ind_min];
		tab[ind_min] = temp;
	}
}

//----------------------------------------------------------------------
// 6 - Fontion qui renvoie l'un des entiers les plus fréquents du tableau
// Précondition: N<0
int freq_max(int* tab, int N){
    int max_freq = 0, plus_freq = tab[0];
    for(int i=0; i<N; i++){
        int freq = 0;
        for(int j=0; j<N; j++){
            if(tab[j] == tab[i]) freq++;
        }
        if(freq > max_freq){
            max_freq = freq;
            plus_freq = tab[i];
        }
    }
    return plus_freq;
}

//----------------------------------------------------------------------
// ALGORITHME PRINCIPAL
int main(){
	int N; 
	
	//Saisie de la taille du tableau
	do{
    	cout<<"Entrez la taille N du tableau (N>0): ";
    	cin>>N;
    	if(N<=0){
        	cout<<"La taille doit être strictement supérieure à 0"<<endl;
    	}
	} while(N<=0);
	
	//Création (allocation) d'un nouveau tableau
	int* tableau = new int[N];
	
	//1-Remplissage du tableau
	cout<<">>>>>>1 - Remplissage du tableau:"<<endl;
	remplir(tableau, N);
	
	//2-Affichage du tableau
	cout<<">>>>>>2 - Affichage du tableau:"<<endl;
	affiche_tab(tableau, N);
	
	//3-Tester la symétrie
	cout << ">>>>>>3 - Test de symetrie:" << endl;
    	if (mirror(tableau, N)) {
        	cout << "Le tableau est symetrique" << endl;
    	} else {
        	cout << "Le tableau n'est pas symetrique" << endl;
    	}
    	
    	//4-Inverser les éléments du tableau
    	cout<<">>>>>>4 - Inversion des éléments:"<<endl;
    	inv_tab(tableau, N);
    	affiche_tab(tableau, N);
    	
    	//5-Trier les éléments dans l'ordre croissant
    	cout<<">>>>>>>5 - Tri croissant des éléments du tableau:"<<endl;
    	trie_tab(tableau, N);
    	affiche_tab(tableau, N);
    	
    	//6-L'entier le plus fréquent du tableau
    	cout<<">>>>>>>6 - L'entier le plus fréquent du tableau:"<<endl;
    	cout << "L'element le plus frequent est: " << freq_max(tableau, N) << endl;
    	
    	//Libération de la mémoire
    	delete[] tableau;
}
