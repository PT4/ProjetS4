#include "CaseVide.h"

using namespace std;

//Constructeurs
CaseVide::CaseVide():Objet()
{}

CaseVide::CaseVide(int i, int j):Objet(i, j, false), m_estVisite(false)
{}

//Destructeur
CaseVide::~CaseVide()
{}

//Accesseur en lecture
bool CaseVide::getVisite() const
{
	return m_estVisite;
}

int CaseVide::getParent() const
{
	return m_parent;
}

//Accesseur en écriture
void CaseVide::setVisite(bool estVisite)
{
	m_estVisite=estVisite;
}

void CaseVide::setParent(int parent)
{
	m_parent=parent;
}
