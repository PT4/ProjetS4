#ifndef _VEHICULE_H_
#define _VEHICULE_H_

#include "Objet.h"

class Vehicule: public Objet
{
	protected :
		bool m_roule;
	public : 
		Vehicule();
		virtual ~Vehicule();
		bool getEtatVehicule() const;
		void setEtatVehicule(bool etat);
		virtual int getVitesse() const;
		void deplacement();

};

#endif
