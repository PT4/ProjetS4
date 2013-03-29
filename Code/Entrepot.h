#ifndef _ENTREPOT_H_
#define _ENTREPOT_H_

#include "Batiment.h"

class Joueur;
class Carte;

class Entrepot: public Batiment {

	public:
		Entrepot();
		Entrepot(Joueur* joueur,Carte* carte);
		Entrepot(int i, int j, Joueur* joueur,Carte* carte);
		~Entrepot();
		void stocker();
};

#endif

