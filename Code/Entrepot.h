#ifndef _ENTREPOT_H_
#define _ENTREPOT_H_

#include "Batiment.h"

class Joueur;

class Entrepot: public Batiment {
	
	public:
		Entrepot();
		Entrepot(Joueur* joueur);
		Entrepot(int i, int j, Joueur* joueur);
		~Entrepot();
		void stocker();
};

#endif

