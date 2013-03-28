#include "Recolteur.h"
#include "Constantes.h"
#include "Joueur.h"
#include "Carte.h"
#include "Tache.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Recolteur::Recolteur(): Unite("Recolteur", POINTS_VIE_RECOLTEUR, PRIX_MIEL_RECOLTEUR, VITESSE_RECOLTEUR, DEGAT_RECOLTEUR, RAYON_ATTAQUE_RECOLTEUR),
									m_poids(0), m_recolte(0)
{}

Recolteur::Recolteur(Joueur* joueur,Carte* carte): Unite("Recolteur", POINTS_VIE_RECOLTEUR, joueur, PRIX_MIEL_RECOLTEUR, VITESSE_RECOLTEUR, DEGAT_RECOLTEUR, RAYON_ATTAQUE_RECOLTEUR,carte),
									m_poids(0), m_recolte(0)
{}

Recolteur::Recolteur(int i, int j, Joueur* joueur,Carte* carte): Unite(i, j,"Recolteur", POINTS_VIE_RECOLTEUR,joueur, PRIX_MIEL_RECOLTEUR, VITESSE_RECOLTEUR, DEGAT_RECOLTEUR, RAYON_ATTAQUE_RECOLTEUR,carte),
									m_poids(0), m_recolte(0)
{
    m_carte -> setCaseMatrice (i,j,5);
}

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
