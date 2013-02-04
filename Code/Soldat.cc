#include "Soldat.h"
#include "Constantes.h"

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

//Constructeurs
Soldat::Soldat():Unite("Soldat", POINTS_VIE_SOLDAT, PRIX_MIEL_SOLDAT, VITESSE_SOLDAT, DEGAT_SOLDAT, RAYON_ATTAQUE_SOLDAT), m_armure(ARMURE_SOLDAT)
{cout << "Defaut : Soldat créé" << endl;}

//Destructeur
Soldat::~Soldat()
{}

//Accesseur en lecture
int Soldat::getArmure() const {
	return m_armure;
}

//Accesseur en écriture
void Soldat::setArmure(int armure) {
	m_armure=armure;
}
