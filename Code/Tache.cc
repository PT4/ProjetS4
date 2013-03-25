#include "Tache.h"
#include "Joueur.h"
#include "Unite.h"
#include "Entite.h"
#include "Constantes.h"
#include "Ressource.h"
#include "Recolteur.h"
#include "Carte.h"
#include <iostream>

using namespace std;

Tache::Tache():m_type("")
{}

Tache::Tache(string type,Unite* me,int cibleI,int cibleJ,Carte* carte): m_type(type), m_carte(carte),m_unite(me)
{
	cout << "Constructeur tache"<<endl;
	if (m_type == "Recolter")
		for (int i = 0; i < carte -> getListeRessources().size(); i++)
		{
			if (m_carte -> getListeRessources()[i]->getI() == cibleI && m_carte -> getListeRessources()[i]->getJ() == cibleJ)
				m_ressource = m_carte -> getListeRessources()[i];
		}
}

Tache::~Tache()
{
    cout << "Destruction Tache" << endl;
	m_unite = NULL;
	m_carte = NULL;
}

void Tache::attaquer(Entite *entite) {
	entite->setPointsVie(m_unite->getDegat());
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

bool Tache::Recolter()
{
	cout << m_ressource -> getStock()<< endl;
	if (m_ressource -> getStock() <= 0)
	{
		m_carte -> supprime(m_ressource -> getI(),m_ressource -> getJ());
		return false;
	}
	else
	{
		m_ressource -> setStock (POIDS_TRANSPORTE_MAX);
		return true;
	}
}

string Tache::getType() const
{
	return m_type;
}
