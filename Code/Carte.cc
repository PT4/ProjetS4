#include "Carte.h"
#include "Joueur.h"
#include "Ressource.h"
#include "Obstacle.h"
#include "EmplacementDepart.h"
#include "Unite.h"
#include "Batiment.h"
#include "CaseVide.h"

#include <cstdlib>
#include <fstream>
#include <SFML/System.hpp>
#include <iostream>

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
	for (int i=0; i<m_listeCasesVides.size() ; i++)
	{
		delete m_listeCasesVides[i];
		m_listeCasesVides[i] = 0;
	}
}

//Accesseurs en lecture
int Carte::getCaseMatrice(int i, int j) const
{
	return m_matrice[i][j];
}

vector<CaseVide*> Carte::getListeCasesVides() const
{
	return m_listeCasesVides;
}

vector<Ressource*> Carte::getListeRessources() const
{
	return m_listeRessources;
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
	//Traitement
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
		for (int i=0; i<TAILLE_MAP; i++)
			for (int j=0; j<TAILLE_MAP; j++)
				if(m_matrice[i][j]==4)
					m_listeCasesVides.push_back(new CaseVide(i,j));
	}
	else
		cerr << "Impossible d'ouvrir la map !" << endl;
}

void Carte::choisirEmplacementDepartJoueur(vector<Joueur*> listeJoueurs)
{
	for (int k=0; k<listeJoueurs.size(); k++)
	{
		//Selection aléatoire de l'emplacement
		int emplacement=Randomizer::Random(1,NB_EMPLACEMENTS_DEPARTS_MAX);
		while(m_listeEmplacementsDeparts[emplacement-1]->getOccupation())
			emplacement=Randomizer::Random(1,NB_EMPLACEMENTS_DEPARTS_MAX);
		//Création de la base et coordonnées
		m_listeEmplacementsDeparts[emplacement-1]->setOccupation(1);
		listeJoueurs[k]->ajouterBatiment(1, m_listeEmplacementsDeparts[emplacement-1]->getI(), m_listeEmplacementsDeparts[emplacement-1]->getJ(),this);
		//Affectation des coordonnées aux récolteurs
		if(emplacement<=2)
			for (int l=0; l<listeJoueurs[k]->getListeUnites().size(); l++)
			{
				listeJoueurs[k]->getListeUnites()[l]->setJ(listeJoueurs[k]->getListeBatiments()[0]->getJ()-1+l);
				listeJoueurs[k]->getListeUnites()[l]->setI(listeJoueurs[k]->getListeBatiments()[0]->getI()-1);
				setCaseMatrice(listeJoueurs[k]->getListeUnites()[l]->getI(),listeJoueurs[k]->getListeUnites()[l]->getJ(),5);
			}
		else
			for (int l=0; l<listeJoueurs[k]->getListeUnites().size(); l++)
			{
				listeJoueurs[k]->getListeUnites()[l]->setJ(listeJoueurs[k]->getListeBatiments()[0]->getJ()-1+l);
				listeJoueurs[k]->getListeUnites()[l]->setI(listeJoueurs[k]->getListeBatiments()[0]->getI()+1);
				setCaseMatrice(listeJoueurs[k]->getListeUnites()[l]->getI(),listeJoueurs[k]->getListeUnites()[l]->getJ(),5);
			}
	}
	for(int k=0; k<m_listeEmplacementsDeparts.size(); k++)
		if(!m_listeEmplacementsDeparts[k]->getOccupation())
			setCaseMatrice(m_listeEmplacementsDeparts[k]->getI(), m_listeEmplacementsDeparts[k]->getJ(), 4);
}


void Carte::calculListeCasesVides()
{
	m_listeCasesVides.clear();
	for (int i=0; i<TAILLE_MAP; i++)
			for (int j=0; j<TAILLE_MAP; j++)
				if(m_matrice[i][j]==4)
					m_listeCasesVides.push_back(new CaseVide(i,j));
}

void Carte::supprime(int i ,int j)
{
		for (int l = 0; l < m_listeRessources.size(); l++)
		{

			if (m_listeRessources[l] -> getI() == i && m_listeRessources[l] -> getJ() == j)
			{
				m_matrice[m_listeRessources[l]->getI()][m_listeRessources[l]->getJ()]=4;
				m_listeRessources.erase(m_listeRessources.begin()+i);
			}
		}


}
