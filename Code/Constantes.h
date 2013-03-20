#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

//Initialisation de la fenêtre
const int LARGEUR_FENETRE=1000;
const int HAUTEUR_FENETRE=800;
const int ZOOM_FENETRE=4;
const int TAILLE_CASE=16;
const int TAILLE_ZOOM_X=8;
const int TAILLE_ZOOM_Y=6;

//Initialisation de la taille de la barre d'informations (ressources,..)
const int LARGEUR_BARRE=200;
const int HAUTEUR_BARRE=1000;

//Initialisation des propriétés du joueurss
const int NB_RECOLTEUR_DEPART=3;
const int QUANTITE_MIEL_DEPART=0;
const int QUANTITE_BOIS_DEPART=0;

//Initialisation de la carte
const int TAILLE_MAP=50;
const int NB_EMPLACEMENTS_DEPARTS_MAX=4;
const int STOCK_DEPART=100;

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
