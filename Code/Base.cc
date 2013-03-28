#include "Base.h"
#include "Constantes.h"
#include "Joueur.h"
#include "Carte.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//Constructeurs
Base::Base(): Batiment("Base", POINTS_VIE_BASE, PRIX_BOIS_BASE, 0)
{}

Base::Base(Joueur* joueur,Carte* carte): Batiment("Base", POINTS_VIE_BASE, joueur, PRIX_BOIS_BASE, 0,carte)
{}

Base::Base(int i, int j, Joueur* joueur,Carte* carte): Batiment(i, j,"Base", POINTS_VIE_BASE, joueur, PRIX_BOIS_BASE, 0,carte)
{}

//Destructeur
Base::~Base()
{}

//Methodes
void Base::creerRecolteur() {
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
		m_joueur->ajouterUnite(1, coordI, coordJ, m_carte);
		m_carte->setCaseMatrice(coordI, coordJ, 5);
		m_joueur->setQuantiteMiel(PRIX_MIEL_RECOLTEUR);
	}
}
