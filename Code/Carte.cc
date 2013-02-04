#include "Carte.h"
#include "Constantes.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//Constructeurs
Carte::Carte()
{}

Carte::Carte(string mon_fichier) 
{
	chargementFichier(mon_fichier);
}

//Destructeur
Carte::~Carte()
{}

//Méthodes	
void Carte::chargementFichier(string mon_fichier) 
{
	int tab[TAILLE_MAP][TAILLE_MAP];
	int i=0, j=0, val=0;
	
	//initialisation (dans la cas ou on travaille avec une matrice)
	for (int i=0; i<TAILLE_MAP; i++)
		for (int j=0; j<TAILLE_MAP; j++)
			tab[i][j]=4;
	
	//Traitement (remplacer "maitreDeLaColline.txt par mon_fichier)
	ifstream fichier("MaitreDeLaColline.txt", ios::in);
	if(fichier)
	{
		cout << "Ouverture de la map" << endl;
		while (!fichier.eof())
		{
			fichier >> i >> j >> val;
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir la map !" << endl;
}
