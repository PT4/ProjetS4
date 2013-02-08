#ifndef _BASE_H_
#define _BASE_H_

#include "Batiment.h"

class Base: public Batiment {
	
	public:
		Base();
		Base(int i, int j);
		~Base();
		void creerRecolteur();
};

#endif
