#include "Camion.h"

using namespace std;

//Contructeur
Camion::Camion(): Vehicule(), m_vitesse(1)
{}

//Destructeur
Camion::~Camion()
{}

//Accesseur en lecture
int Camion::getVitesse() const
{
	return m_vitesse;
}
