#include "Base.h"
#include "Constantes.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Constructeurs
Base::Base(): Batiment("Base", POINTS_VIE_BASE, PRIX_BOIS_BASE, 0)
{cout << "Defaut : Base créée" << endl;}

//Destructeur
Base::~Base()
{}

//Methodes
void Base::creerRecolteur() {
	
}
