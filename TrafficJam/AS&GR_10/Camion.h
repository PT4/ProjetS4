#ifndef _CAMION_H_
#define _CAMION_H_

#include "Vehicule.h"

class Camion: public Vehicule
{
	private :
		int m_vitesse;
	public :
		Camion();
		~Camion();
		int getVitesse() const;
};

#endif
