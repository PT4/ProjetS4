#include "Batiment.h"

#include <string>
#include <iostream>
using namespace std;

//Contructeurs
Batiment::Batiment(): Entite(), m_formeUnite(0)
{cout << "Defaut : Batiment créé" << endl;}

Batiment::Batiment(string nom, int pointsVie, int prixBois, bool formeUnite):
						Entite(nom, pointsVie), m_prixBois(prixBois), m_formeUnite(formeUnite)
{cout << "Parametré : Batiment créé"<< endl;}

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
