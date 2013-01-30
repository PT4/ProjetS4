#ifndef _VOITURE_H_
#define _VOITURE_H_

#include "Vehicule.h"

class Voiture: public Vehicule
{
	private :
		int m_vitesse;
	public :
		Voiture();
		~Voiture();
		int getVitesse() const;
};

#endif
