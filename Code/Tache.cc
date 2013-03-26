#include "Tache.h"
#include "Joueur.h"
#include "Unite.h"
#include "Entite.h"
#include "Soldat.h"
#include "Constantes.h"
#include "Ressource.h"
#include "Recolteur.h"
#include "Carte.h"
#include <iostream>

using namespace std;

Tache::Tache():m_type("")
{}

Tache::Tache(string type,Unite* me,int cibleI,int cibleJ,Carte* carte): m_type(type), m_carte(carte)
{
	cout << "Constructeur tache"<<endl;
	
	m_recolteur=dynamic_cast<Recolteur*>(me);
	m_soldat=dynamic_cast<Soldat*>(me);
    if (m_type == "Recolter" && m_recolteur != NULL)
	{
		m_soldat = NULL;
		m_cible = NULL;
		for (int i = 0; i < carte -> getListeRessources().size(); i++)
		{
			if (m_carte -> getListeRessources()[i]->getI() == cibleI && m_carte -> getListeRessources()[i]->getJ() == cibleJ)
				m_ressource = m_carte -> getListeRessources()[i];
		}
	}
	
	else if (m_type == "Attaquer" && m_soldat != NULL)
	{
		m_ressource = NULL;
		m_recolteur = NULL;
	}
}

Tache::~Tache()
{
    cout << "Destruction Tache" << endl;
	m_recolteur = NULL;
	m_carte = NULL;
}

void Tache::attaquer(Entite *entite) {
	entite->setPointsVie(m_soldat->getDegat());
	if (entite->getPointsVie() == 0)
		delete entite;
}

void Tache::setCarte(Carte *carte)
{
	m_carte = carte;
	cout << m_carte << endl;
}

Carte* Tache::getCarte() const
{
	return m_carte;
}

bool Tache::recolter()
{
	if (m_ressource -> getStock() <= 0)
	{
		m_carte -> supprime(m_ressource -> getI(),m_ressource -> getJ());
		return false;
	}
	else
	{
		m_ressource -> setStock (POIDS_TRANSPORTE_MAX);
		m_recolteur -> setPoids (POIDS_TRANSPORTE_MAX);
		return true;
	}
}

string Tache::getType() const
{
	return m_type;
}
