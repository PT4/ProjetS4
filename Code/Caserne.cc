#include "Caserne.h"
#include "Constantes.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Caserne::Caserne(): Batiment("Caserne", POINTS_VIE_CASERNE, PRIX_BOIS_CASERNE, 0)
{}

Caserne::Caserne(Joueur* joueur): Batiment("Caserne", POINTS_VIE_CASERNE, joueur, PRIX_BOIS_CASERNE, 0)
{}

Caserne::Caserne(int i, int j, Joueur* joueur): Batiment(i, j, "Caserne", POINTS_VIE_CASERNE,joueur, PRIX_BOIS_CASERNE, 0)
{}

//Destructeur
Caserne::~Caserne()
{}

//Methodes
void Caserne::creerSoldat() {
	
}

