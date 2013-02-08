#include "Entrepot.h"
#include "Constantes.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Entrepot::Entrepot(): Batiment("Entrepot", POINTS_VIE_ENTREPOT, PRIX_BOIS_ENTREPOT, 0)
{}

Entrepot::Entrepot(int i, int j): Batiment(i, j, "Entrepot", POINTS_VIE_ENTREPOT, PRIX_BOIS_ENTREPOT, 0)
{}

//Destructeur
Entrepot::~Entrepot()
{}

//Methodes
void Entrepot::stocker() {
	
}

