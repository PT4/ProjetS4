#include "Carte.h"
#include "Constantes.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//Constructeurs
Carte::Carte()
{}

Carte::Carte(string mon_fichier, vector<Joueur*> listeJoueurs): m_listeJoueurs(listeJoueurs)
{
	chargementFichier(mon_fichier);
	choisirEmplacementDepartJoueur();
}

//Destructeur
Carte::~Carte()
{
	for (int i=0; i<m_listeObstacles.size() ; i++)
	{
		delete m_listeObstacles[i];
		m_listeObstacles[i] = 0;
	}
	for (int i=0; i<m_listeRessources.size() ; i++)
	{
		delete m_listeRessources[i];
		m_listeRessources[i] = 0;
	}
	for (int i=0; i<m_listeEmplacementsDeparts.size() ; i++)
	{
		delete m_listeEmplacementsDeparts[i];
		m_listeEmplacementsDeparts[i] = 0;
	}
}

//Accesseurs en lecture
int Carte::getCaseMatrice(int i, int j) const
{
	return m_matrice[i][j];
}

//Accesseur en écriture
void Carte::setCaseMatrice(int i, int j, int val) 
{
	m_matrice[i][j]=val;
}

//Méthodes	
void Carte::chargementFichier(string mon_fichier) 
{
	int tab[TAILLE_MAP][TAILLE_MAP];
	int i=0, j=0, val=0;
	//initialisation
	for (int i=0; i<TAILLE_MAP; i++)
		for (int j=0; j<TAILLE_MAP; j++)
			m_matrice[i][j]=4;
	
	//Traitement (remplacer "maitreDeLaColline.txt par mon_fichier)
	ifstream fichier(mon_fichier.c_str(), ios::in);
	if(fichier)
	{
		while (!fichier.eof())
		{
			fichier >> i >> j >> val;
			m_matrice[i-1][j-1]=val;
			switch(val)
			{
				case 0: m_listeObstacles.push_back(new Obstacle(i-1, j-1)); break;
				case 1: m_listeRessources.push_back(new Ressource(i-1, j-1, "Bois")); break;
				case 2: m_listeRessources.push_back(new Ressource(i-1, j-1, "Miel")); break;
				case 3: m_listeEmplacementsDeparts.push_back(new EmplacementDepart(i-1, j-1)); break;
				default: break;
			}
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir la map !" << endl;
}

void Carte::choisirEmplacementDepartJoueur()
{
	for (int i=0; i<m_listeJoueurs.size(); i++)
	{
		int emplacement=0;
		cout << m_listeJoueurs.size() << endl;
		emplacement=(rand()%3)+1;
		
	}
	 
}
