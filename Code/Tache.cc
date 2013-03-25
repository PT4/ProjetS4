#include "Tache.h"
#include "Joueur.h"
#include "Unite.h"
#include "Entite.h"
#include <iostream>

using namespace std;

Tache::Tache():m_type("")
{}

Tache::Tache(string type): m_type(type)
{
	cout << "Destruction Tache" << endl;
}

Tache::~Tache()
{
	m_unite = NULL;
	m_carte = NULL;
}

void Tache::attaquer(Entite *entite) {
	entite->setPointsVie(m_unite->getDegat());
	if (entite->getPointsVie() == 0)
		delete entite;
}

