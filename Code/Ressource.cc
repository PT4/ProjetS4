#include "Ressource.h"
#include "Constantes.h"

using namespace std;

//Constructeurs
Ressource::Ressource():Objet()
{}

Ressource::Ressource(int i, int j, string type):Objet(i, j, 0), m_type(type), m_stock(STOCK_DEPART)
{}

//Destructeur
Ressource::~Ressource()
{}

