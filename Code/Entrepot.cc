#include "Entrepot.h"
#include "Constantes.h"
#include "Joueur.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Entrepot::Entrepot(): Batiment("Entrepot", POINTS_VIE_ENTREPOT, PRIX_BOIS_ENTREPOT, 0)
{}

Entrepot::Entrepot(Joueur* joueur): Batiment("Entrepot", POINTS_VIE_ENTREPOT, joueur, PRIX_BOIS_ENTREPOT, 0)
{}

Entrepot::Entrepot(int i, int j, Joueur* joueur): Batiment(i, j, "Entrepot", POINTS_VIE_ENTREPOT,joueur, PRIX_BOIS_ENTREPOT, 0)
{}

//Destructeur
Entrepot::~Entrepot()
{}

//Methodes
void Entrepot::stocker() {
	
}

