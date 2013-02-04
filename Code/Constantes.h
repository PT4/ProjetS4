#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

//Initialisation de la fenêtre
const int LARGEUR_FENETRE=800;
const int HAUTEUR_FENETRE=600;

//Initialisation des propriétés du joueurs
const int NB_RECOLTEUR_DEPART=4;
const int QUANTITE_MIEL_DEPART=0;
const int QUANTITE_BOIS_DEPART=0;

//Initialisation de la carte
const int TAILLE_MAP=50;

/******UNITES*******/
//Initialisation des propriétés des récolteurs
const int POINTS_VIE_RECOLTEUR=25;
const int PRIX_MIEL_RECOLTEUR=10;
const int VITESSE_RECOLTEUR=1;
const int DEGAT_RECOLTEUR=3;
const int RAYON_ATTAQUE_RECOLTEUR=5;
const int POIDS_TRANSPORTE_MAX=20;

//Initialisation des propriétés des soldats
const int POINTS_VIE_SOLDAT=50;
const int PRIX_MIEL_SOLDAT=20;
const int VITESSE_SOLDAT=2;
const int DEGAT_SOLDAT=7;
const int RAYON_ATTAQUE_SOLDAT=10;
const int ARMURE_SOLDAT=20;

/******BATIMENTS*****/
//Initialisation des batiments
const int LIMITE_PRODUCTION=10;

//Initialisation des bases
const int POINTS_VIE_BASE=200;
const int PRIX_BOIS_BASE=200;

//Initialisation des casernes
const int POINTS_VIE_CASERNE=150;
const int PRIX_BOIS_CASERNE=150;

//Initialisation des entrepôts
const int POINTS_VIE_ENTREPOT=70;
const int PRIX_BOIS_ENTREPOT=70;


#endif
