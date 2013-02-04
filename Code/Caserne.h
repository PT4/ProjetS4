#ifndef _CASERNE_H_
#define _CASERNE_H_

#include "Batiment.h"

class Caserne: public Batiment {
	
	public:
		Caserne();
		~Caserne();
		void creerSoldat();
};

#endif
