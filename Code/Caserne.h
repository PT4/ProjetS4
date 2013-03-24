#ifndef _CASERNE_H_
#define _CASERNE_H_

#include "Batiment.h"

class Joueur;

class Caserne: public Batiment {
	
	public:
		Caserne();
		Caserne(Joueur* joueur);
		Caserne(int i, int j, Joueur* joueur);
		~Caserne();
		void creerSoldat();
};

#endif
