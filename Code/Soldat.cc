#include "Soldat.h"
#include "Constantes.h"
#include "Joueur.h"
#include "Tache.h"
#include "Carte.h"
#include <cstdlib>

using namespace std;

//Constructeurs
Soldat::Soldat():Unite("Soldat", POINTS_VIE_SOLDAT, PRIX_MIEL_SOLDAT, VITESSE_SOLDAT, DEGAT_SOLDAT, RAYON_ATTAQUE_SOLDAT), m_armure(ARMURE_SOLDAT)
{}

Soldat::Soldat(Joueur* joueur,Carte* carte):Unite("Soldat", POINTS_VIE_SOLDAT,joueur, PRIX_MIEL_SOLDAT, VITESSE_SOLDAT, DEGAT_SOLDAT, RAYON_ATTAQUE_SOLDAT,carte), m_armure(ARMURE_SOLDAT)
{}

Soldat::Soldat(int i, int j, Joueur* joueur,Carte* carte):Unite(i, j, "Soldat", POINTS_VIE_SOLDAT,joueur, PRIX_MIEL_SOLDAT, VITESSE_SOLDAT, DEGAT_SOLDAT, RAYON_ATTAQUE_SOLDAT,carte), m_armure(ARMURE_SOLDAT)
{}

//Destructeur
Soldat::~Soldat()
{}

//Accesseur en lecture
int Soldat::getArmure() const {
	return m_armure;
}

//Accesseur en écriture
void Soldat::setArmure(int armure) {
	m_armure=armure;
}
