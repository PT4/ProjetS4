#ifndef _POLICE_H_
#define _POLICE_H_

#include "Vehicule.h"

class Police: public Vehicule
{
	private :
		int m_vitesse;
	public :
		Police();
		~Police();
		int getVitesse() const;
};

#endif
