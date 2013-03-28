#include "Caserne.h"
#include "Constantes.h"
#include "Carte.h"
#include "Joueur.h"
#include <cstdlib>

using namespace std;

//Constructeurs
Caserne::Caserne(): Batiment("Caserne", POINTS_VIE_CASERNE, PRIX_BOIS_CASERNE, 0)
{}

Caserne::Caserne(Joueur* joueur,Carte* carte): Batiment("Caserne", POINTS_VIE_CASERNE, joueur, PRIX_BOIS_CASERNE, 0,carte)
{}

Caserne::Caserne(int i, int j, Joueur* joueur,Carte* carte): Batiment(i, j, "Caserne", POINTS_VIE_CASERNE,joueur, PRIX_BOIS_CASERNE, 0,carte)
{}

//Destructeur
Caserne::~Caserne()
{}

//Methodes
void Caserne::creerSoldat() {
	int coordI = 0; 
	int coordJ = 0;
	for (int i=0; i<TAILLE_MAP; i++)
		for (int j=0; j<TAILLE_MAP; j++)
			if ((abs(i-this->getI()) < 2) && (abs(j-this->getJ()) < 2))
				if (m_carte->getCaseMatrice(i, j) == 4) {
					coordI = i;
					coordJ = j;
				}
	
	if ((coordI != 0) && (coordJ != 0)) {
		m_joueur->ajouterUnite(2, coordI, coordJ, m_carte);
		m_carte->setCaseMatrice(coordI, coordJ, 5);
		m_joueur->setQuantiteMiel(PRIX_MIEL_SOLDAT);
	}
}

