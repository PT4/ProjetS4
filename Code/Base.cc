#include "Base.h"
#include "Constantes.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Base::Base(): Batiment("Base", POINTS_VIE_BASE, PRIX_BOIS_BASE, 0)
{}

//Destructeur
Base::~Base()
{}

//Methodes
void Base::creerRecolteur() {
	
}
