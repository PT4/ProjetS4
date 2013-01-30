#include "Objet.h"
#include <cstdlib>

using namespace std;

//Constructeurs
Objet::Objet():m_posX(0), m_posY(0), m_estVertical(0)
{}
Objet::Objet(float posX, float posY):m_posX(posX), m_posY(posY), m_estVertical(0)
{}
Objet::Objet(float posX, float posY, bool estVertical):m_posX(posX), m_posY(posY), m_estVertical(estVertical)
{}

//Destructeur
Objet::~Objet()
{}

//Accesseurs en lecture
float Objet::getPositionX() const
{
	return m_posX;
}

float Objet::getPositionY() const
{
	return m_posY;
}

bool Objet::getSens() const
{
	return m_estVertical;
}

//Accesseurs en écriture
void Objet::setPosX(float posX)
{
	m_posX=posX;
}

void Objet::setPosY(float posY)
{
	m_posY=posY;
}

void Objet::setSens(bool estVertical)
{
	m_estVertical=estVertical;
}
