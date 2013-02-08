#include "EmplacementDepart.h"

using namespace std;

//Constructeurs
EmplacementDepart::EmplacementDepart():Objet()
{}

EmplacementDepart::EmplacementDepart(int i, int j):Objet(i, j, false), m_estOccuper(0)
{}

//Destructeur
EmplacementDepart::~EmplacementDepart()
{}

//Accesseur en lecture
bool EmplacementDepart::getOccupation() const
{
	return m_estOccuper;
}

//Accesseur en écriture
void EmplacementDepart::setOccupation(bool estOccuper)
{
	m_estOccuper=estOccuper;
}
