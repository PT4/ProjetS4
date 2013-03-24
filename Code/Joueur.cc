#include "Joueur.h"
#include "Constantes.h"
#include "Base.h"
#include "Caserne.h"
#include "Entrepot.h"
#include "Recolteur.h"
#include "Soldat.h"
#include "Unite.h"
#include "Batiment.h"
#include "Tache.h"

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

//Constructeurs
Joueur::Joueur()
{
	for (int i=0; i<NB_RECOLTEUR_DEPART; i++)
		m_listeUnites.push_back(new Recolteur(this));
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
		case 1: m_listeBatiments.push_back(new Base(i, j,this)); break;
		case 2: m_listeBatiments.push_back(new Caserne(i, j,this)); break;
		case 3: m_listeBatiments.push_back(new Entrepot(i, j,this)); break;
		default: break;
	}
}

void Joueur::ajouterUnite(int type, int i, int j)
{
	switch(type)
	{
		case 1: m_listeUnites.push_back(new Recolteur(i, j,this));break;
		case 2: m_listeUnites.push_back(new Soldat(i, j,this)); break;
		default: break;
	}
}

void Joueur::viderSelection()
{
	m_selection.clear();
}

void Joueur::inverseCoordonnee(double &a,double &b)
{
	double temp = 0;
	temp = a;
	a  = b;
	b = temp;
}

void Joueur::remplirSelection(double clicX, double clicY, double clicTempX, double clicTempY)
{
	
	if (clicX > clicTempX)
		inverseCoordonnee(clicX,clicTempX);
	if (clicY > clicTempY)
		inverseCoordonnee(clicY,clicTempY);
		
	for (int i = 0; i < m_listeUnites.size();i++)
	{
		if (m_listeUnites[i]->getJ() >= clicX && m_listeUnites[i]->getJ() <= clicTempX
			&& m_listeUnites[i]->getI() >= clicY && m_listeUnites[i]->getI() <= clicTempY)
			{
				m_selection.push_back(m_listeUnites[i]);
			}
	}
	
	cout << "La selection contient : "<<m_selection.size() << " unites"<<endl;
}
