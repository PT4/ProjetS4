#ifndef _ENTREPOT_H_
#define _ENTREPOT_H_

#include "Batiment.h"

class Entrepot: public Batiment {
	
	public:
		Entrepot();
		Entrepot(int i, int j);
		~Entrepot();
		void stocker();
};

#endif

