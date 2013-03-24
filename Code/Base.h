#ifndef _BASE_H_
#define _BASE_H_

#include "Batiment.h"

class Joueur;

class Base: public Batiment {
	
	public:
		Base();
		Base(Joueur* joueur);
		Base(int i, int j, Joueur* joueur);
		~Base();
		void creerRecolteur();
};

#endif
