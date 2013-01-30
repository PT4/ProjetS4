#include "Voiture.h"

using namespace std;

//Contructeur
Voiture::Voiture(): Vehicule(), m_vitesse(2)
{}

//Destructeur
Voiture::~Voiture()
{}

//Accesseur en lecture
int Voiture::getVitesse() const
{
	return m_vitesse;
}
