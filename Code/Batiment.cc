#include "Batiment.h"

#include <string>

using namespace std;

//Contructeurs
Batiment::Batiment(): Entite(), m_formeUnite(0)
{}

Batiment::Batiment(string nom, int pointsVie, int prixBois, bool formeUnite):
						Entite(nom, pointsVie), m_prixBois(prixBois), m_formeUnite(formeUnite)
{}

//Destructeur
Batiment::~Batiment()
{}

//Accesseur en lecture
bool Batiment::getFormation() const {
	return m_formeUnite;
}

//Accesseur en écriture
void Batiment::setFormation(bool formeUnite) {
	m_formeUnite=formeUnite;
}
