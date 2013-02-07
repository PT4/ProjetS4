#include "Entite.h"

#include <string>
#include <cstdlib>

using namespace std;

//Contructeurs
Entite::Entite():Objet()
{}

Entite::Entite(string nom, int pointsVie): m_nom(nom), m_pointsVie(pointsVie)
{}

//Destructeur
Entite::~Entite()
{}

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
