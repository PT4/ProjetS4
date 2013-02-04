#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const int TAILLE_MAP=50;

int main()
{
	string mon_fichier = "MaitreDeLaColline.txt";
	int tab[TAILLE_MAP][TAILLE_MAP];
	int i=0, j=0, val=0;
	
	//initialisation
	for (int i=0; i<TAILLE_MAP; i++)
		for (int j=0; j<TAILLE_MAP; j++)
			tab[i][j]=4;
	
	/*//affichage
	for (int i=0; i<TAILLE_MAP; i++)
	{
		for (int j=0; j<TAILLE_MAP; j++)
			cout << tab[i][j];
		cout << endl;
	}*/
	
	//Traitement
	ifstream fichier("MaitreDeLaColline.txt", ios::in);
	fichier.exceptions(ifstream::eofbit | ifstream::badbit | ifstream::failbit | ifstream::goodbit);
	if(fichier)
	{
		cout << "Ouverture de la map" << endl;
		while (!fichier.eof())
		{
			fichier >> i >> j >> val;
			tab[i-1][j-1]=val;
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	
	cout << "Result : " << i << " " << j << " " << val << endl;
	
	return EXIT_SUCCESS;
}


