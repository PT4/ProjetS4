#include "Base.h"
#include "Constantes.h"
#include "Joueur.h"
#include "Carte.h"
#include <cstdlib>

using namespace std;

//Constructeurs
Base::Base(): Batiment("Base", POINTS_VIE_BASE, PRIX_BOIS_BASE, 0)
{}

Base::Base(Joueur* joueur,Carte* carte): Batiment("Base", POINTS_VIE_BASE, joueur, PRIX_BOIS_BASE, 0,carte)
{}

Base::Base(int i, int j, Joueur* joueur,Carte* carte): Batiment(i, j,"Base", POINTS_VIE_BASE,joueur, PRIX_BOIS_BASE, 0,carte)
{}

//Destructeur
Base::~Base()
{}

//Methodes
void Base::creerRecolteur() {

}
