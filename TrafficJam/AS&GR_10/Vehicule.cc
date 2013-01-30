#include "Vehicule.h"

using namespace std;


//Constructeur
Vehicule::Vehicule(): Objet(), m_roule(0)
{}

//Destructeur
Vehicule::~Vehicule()
{}

//Accesseurs en lecture

bool Vehicule::getEtatVehicule() const
{
	return m_roule;
}

void Vehicule::setEtatVehicule(bool etat)
{
	m_roule = etat;
}
//Methodes
void Vehicule::deplacement()
{
	if(m_roule)
		switch (m_estVertical)
		{
			case 0: m_posX+=getVitesse(); break;
			case 1: m_posY+=getVitesse(); break;
		}
}

int Vehicule::getVitesse() const
{
	return getVitesse();
}


	
