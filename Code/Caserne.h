#ifndef _CASERNE_H_
#define _CASERNE_H_

#include "Batiment.h"

class Joueur;
class Carte;

class Caserne: public Batiment {

	public:
		Caserne();
		Caserne(Joueur* joueur,Carte* carte);
		Caserne(int i, int j, Joueur* joueur,Carte* carte);
		~Caserne();
		void creerSoldat();
};

#endif
