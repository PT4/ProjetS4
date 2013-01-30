#include "Police.h"

using namespace std;

//Contructeur
Police::Police(): Vehicule(), m_vitesse(3)
{}

//Destructeur
Police::~Police()
{}

//Accesseur en lecture
int Police::getVitesse() const
{
	return m_vitesse;
}
