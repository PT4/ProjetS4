#ifndef _ENTREPOT_H_
#define _ENTREPOT_H_

#include "Batiment.h"
#include "Joueur.h"

class Entrepot: public Batiment {
	
	public:
		Entrepot();
		~Entrepot();
		void stocker();
};

#endif

