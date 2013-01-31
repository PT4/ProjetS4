#include "Croisement.h"

using namespace std;

//Constructeur
Croisement::Croisement() : Objet(), m_feu(0), m_presenceFeu(0), m_nbVehiculePresent(0), m_collision(0)
{}

//Destructeur
Croisement::~Croisement()
{
	if (m_presenceFeu)
		delete m_feu;
}

//Accesseurs en lecture
Feu* Croisement::getFeu() const
{
	return m_feu;
}

bool Croisement::getPresenceFeu() const
{
	return m_presenceFeu;
}

int Croisement::getNbVehiculePresent() const
{
	return m_nbVehiculePresent;
}

//Accesseurs en écriture
void Croisement:: setPresenceFeu(bool presenceFeu)
{
	m_presenceFeu=presenceFeu;
}

void Croisement::setPosXCroisement(vector <Croisement*> listeDeCroisement, int posX, int i)/**/
{
	listeDeCroisement[i]->setPosX(posX);
}

void Croisement::setNbVehiculePresent(int nbVehicule)
{
	m_nbVehiculePresent = nbVehicule;
}

//Méthodes
void Croisement::genererFeu()
{
	m_feu=new Feu();
}

bool Croisement::detecterCollision()
{
	if (m_nbVehiculePresent > 1)
	{
		m_collision = 1;
	}
	return m_collision;
}
