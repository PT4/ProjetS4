#include "Unite.h"

#include <cstdlib>
#include <string>

using namespace std;

//Constructeurs
Unite::Unite(): Entite(), m_seDeplace(0), m_attaque(0)
{}

Unite::Unite(string nom, int pointsVie, int prixMiel, int vitesse, int degat, int rayonAttaque): Entite(nom, pointsVie), 
				m_prixMiel(prixMiel), m_vitesse(vitesse), m_degat(degat), m_rayonAttaque(rayonAttaque), m_seDeplace(0), m_attaque(0)
{}

Unite::Unite(int i, int j, string nom, int pointsVie, int prixMiel, int vitesse, int degat, int rayonAttaque): Entite(i, j, true, nom, pointsVie), 
				m_prixMiel(prixMiel), m_vitesse(vitesse), m_degat(degat), m_rayonAttaque(rayonAttaque), m_seDeplace(0), m_attaque(0)
{}

//Destructeur
Unite::~Unite()
{}

//Accesseurs en lecture
bool Unite::getDeplacement() const {
	return m_seDeplace;
}

bool Unite::getAttaque() const {
	return m_attaque;
}

int Unite::getDegat() const
{
	return m_degat;
}

//Accesseur en écriture
void Unite::setDeplacement(bool seDeplace) {
	m_seDeplace=seDeplace;
}

void Unite::setAttaque(bool attaque) {
	m_attaque=attaque;
}

//Methodes
void Unite::seDeplacer() {

}

void Unite::attaquer(Entite& cible) {
	cible.setPointsVie(cible.getPointsVie()-m_degat);
	cible.setPointsVie(getDegat());
}
