#include "Entrepot.h"
#include "Constantes.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Constructeurs
Entrepot::Entrepot(): Batiment("Entrepot", POINTS_VIE_ENTREPOT, PRIX_BOIS_ENTREPOT, 0)
{cout << "Defaut : Entrepot créée" << endl;}

//Destructeur
Entrepot::~Entrepot()
{}

//Methodes
void Entrepot::stocker() {
	
}

