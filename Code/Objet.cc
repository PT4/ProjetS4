#include "Objet.h"

using namespace std;

//Constructeurs
Objet::Objet()
{}

Objet::Objet(int i, int j, bool estFranchissable): m_i(i), m_j(j),m_estFranchissable(estFranchissable)
{}

//Destructeur
Objet::~Objet()
{}

//Accesseurs en lecture
int Objet::getI() const
{
	return m_i;
}

int Objet::getJ() const
{
	return m_j;
}

bool Objet::getFranchissable() const
{
	return m_estFranchissable;
}

bool Objet::getDecouvert() const
{
	return m_estDecouvert;
}

//Accesseurs en écriture
void Objet::setI(int i)
{
	m_i=i;
}

void Objet::setJ(int j)
{
	m_j=j;
}

void Objet::setFranchissable(bool estFranchissable)
{
	m_estFranchissable=estFranchissable;
}

void Objet::setDecouvert(bool estDecouvert)
{
	m_estDecouvert=estDecouvert;
}
