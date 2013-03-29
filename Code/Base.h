#ifndef _BASE_H_
#define _BASE_H_

#include "Batiment.h"

class Joueur;
class Carte;

class Base: public Batiment {

	public:
		Base();
		Base(Joueur* joueur,Carte* carte);
		Base(int i, int j, Joueur* joueur,Carte* carte);
		~Base();
		void creerRecolteur();
};

#endif
