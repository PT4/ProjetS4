#include "Caserne.h"
#include "Constantes.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Constructeurs
Caserne::Caserne(): Batiment("Caserne", POINTS_VIE_CASERNE, PRIX_BOIS_CASERNE, 0)
{cout << "Defaut : Caserne créée" << endl;}

//Destructeur
Caserne::~Caserne()
{}

//Methodes
void Caserne::creerSoldat() {
	
}

