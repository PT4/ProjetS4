#include "Ressource.h"
#include "Constantes.h"

using namespace std;

//Constructeurs
Ressource::Ressource():Objet()
{}

Ressource::Ressource(int i, int j, string type):Objet(i, j, false), m_type(type), m_stock(STOCK_DEPART)
{}

//Destructeur
Ressource::~Ressource()
{}

int Ressource::getStock () const
{
	return m_stock;
}

void Ressource::setStock (int deduction)
{
	m_stock -= deduction;
}
