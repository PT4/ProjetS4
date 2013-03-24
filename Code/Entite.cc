#include "Entite.h"
#include "Joueur.h"
#include <cstdlib>

#include <iostream>

using namespace std;

//Contructeurs
Entite::Entite():Objet()
{}

Entite::Entite(string nom, int pointsVie): Objet(), m_nom(nom), m_pointsVie(pointsVie), m_joueur(0)
{}

Entite::Entite(string nom, int pointsVie, Joueur* joueur): Objet(), m_nom(nom), m_pointsVie(pointsVie), m_joueur(joueur)
{}

Entite::Entite(int i, int j, bool estFranchissable, string nom, int pointsVie, Joueur* joueur):Objet(i, j, estFranchissable), m_nom(nom), m_pointsVie(pointsVie)
{}

//Destructeur
Entite::~Entite()
{
	if(m_joueur!=NULL)
	{
		m_joueur=0;
	}
}

//Accesseurs en lecture
int Entite::getPointsVie() const {
	return m_pointsVie;
}

string Entite::getNom() const {
	return m_nom;
}

//Accesseurs en écriture
void Entite::setPointsVie(int pointsVie) {
	m_pointsVie-=pointsVie;
}
