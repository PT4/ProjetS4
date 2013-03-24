#include "Base.h"
#include "Constantes.h"
#include "Joueur.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Base::Base(): Batiment("Base", POINTS_VIE_BASE, PRIX_BOIS_BASE, 0)
{}

Base::Base(Joueur* joueur): Batiment("Base", POINTS_VIE_BASE, joueur, PRIX_BOIS_BASE, 0)
{}

Base::Base(int i, int j, Joueur* joueur): Batiment(i, j,"Base", POINTS_VIE_BASE,joueur, PRIX_BOIS_BASE, 0)
{}

//Destructeur
Base::~Base()
{}

//Methodes
void Base::creerRecolteur() {
	
}
