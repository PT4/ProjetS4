#include "Carte.h"
#include "Constantes.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

//Constructeurs
Carte::Carte()
{}

Carte::Carte(string mon_fichier)
{
	chargementFichier(mon_fichier);
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

void Carte::choisirEmplacementDepartJoueur(vector<Joueur*> listeJoueurs)
{
	for (int i=0; i<listeJoueurs.size(); i++)
	{
		int emplacement=Randomizer::Random(1,NB_EMPLACEMENTS_DEPARTS_MAX);
		while(m_listeEmplacementsDeparts[emplacement-1]->getOccupation())
			emplacement=Randomizer::Random(1,NB_EMPLACEMENTS_DEPARTS_MAX);
	
		m_listeEmplacementsDeparts[emplacement-1]->setOccupation(1);
		listeJoueurs[i]->ajouterBatiment(1, m_listeEmplacementsDeparts[emplacement-1]->getI(), m_listeEmplacementsDeparts[emplacement-1]->getJ());
	}
	for(int i=0; i<m_listeEmplacementsDeparts.size(); i++)
		if(!m_listeEmplacementsDeparts[i]->getOccupation())
		{
			setCaseMatrice(m_listeEmplacementsDeparts[i]->getI(), m_listeEmplacementsDeparts[i]->getJ(), 4);
		}
	 
}
