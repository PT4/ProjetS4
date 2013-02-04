#include "Recolteur.h"
#include "Constantes.h"

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

//Constructeurs
Recolteur::Recolteur(): Unite("Soldat", POINTS_VIE_RECOLTEUR, PRIX_MIEL_RECOLTEUR, VITESSE_RECOLTEUR, DEGAT_RECOLTEUR, RAYON_ATTAQUE_RECOLTEUR),
									m_poids(0), m_recolte(0)
{cout << "Defaut : Recolteur créé" << endl;}

//Destructeur
Recolteur::~Recolteur()
{}

//Accesseurs en lecture
int Recolteur::getPoids() const {
	return m_poids;
}

//Accesseurs en écriture
void Recolteur::setPoids(int poids) {
	m_poids=poids;
}

//Methodes
void Recolteur::amasser() {

}
