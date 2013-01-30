#include "Feu.h"

using namespace std;

//Constructeur
Feu::Feu(): m_estVert(0)
{}

//Destructeur
Feu::~Feu()
{}

//Accesseur en lecture
bool Feu::getCouleurFeu() const
{
	return m_estVert;
}

//Accesseur en écriture
void Feu::changerCouleurFeu()
{
	switch (m_estVert)
	{
		case 0: m_estVert=1; break;
		case 1: m_estVert=0; break;
	}
}
