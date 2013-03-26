#include "Entrepot.h"
#include "Constantes.h"
#include "Joueur.h"
#include "Carte.h"
#include <cstdlib>

using namespace std;

//Constructeurs
Entrepot::Entrepot(): Batiment("Entrepot", POINTS_VIE_ENTREPOT, PRIX_BOIS_ENTREPOT, 0)
{}

Entrepot::Entrepot(Joueur* joueur,Carte* carte): Batiment("Entrepot", POINTS_VIE_ENTREPOT, joueur, PRIX_BOIS_ENTREPOT, 0,carte)
{}

Entrepot::Entrepot(int i, int j, Joueur* joueur,Carte* carte): Batiment(i, j, "Entrepot", POINTS_VIE_ENTREPOT,joueur, PRIX_BOIS_ENTREPOT, 0,carte)
{}

//Destructeur
Entrepot::~Entrepot()
{}

//Methodes
void Entrepot::stocker() {

}

