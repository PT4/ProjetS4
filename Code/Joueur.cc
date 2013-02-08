#include "Joueur.h"
#include "Recolteur.h"
#include "Constantes.h"

#include <cstdlib>
#include <vector>

using namespace std;

//Constructeurs
Joueur::Joueur()
{
	for (int i=0; i<NB_RECOLTEUR_DEPART; i++)
		m_listeUnites.push_back(new Recolteur());
}

//Destructeur
Joueur::~Joueur()
{
	for (int i=0; i<m_listeUnites.size(); i++)
	{
		delete m_listeUnites[i];
		m_listeUnites[i]=0;
	}
	for (int i=0; i<m_listeBatiments.size(); i++)
	{
		delete m_listeBatiments[i];
		m_listeBatiments[i]=0;
	}
}

//Accesseurs en lecture
vector<Batiment*> Joueur::getListeBatiments() const
{
	return m_listeBatiments;
}

vector<Unite*> Joueur::getListeUnites() const
{
	return m_listeUnites;
}

//Methodes
void Joueur::ajouterBatiment(int type, int i, int j)
{
	switch(type)
	{
		case 1: m_listeBatiments.push_back(new Base(i, j));
		case 2: m_listeBatiments.push_back(new Caserne(i, j));
		case 3: m_listeBatiments.push_back(new Entrepot(i, j));
		default: break;
	}
}

void Joueur::ajouterUnite(int type, int i, int j)
{
	switch(type)
	{
		case 1: m_listeUnites.push_back(new Recolteur(i, j));
		case 2: m_listeUnites.push_back(new Soldat(i, j));
		default: break;
	}
}
