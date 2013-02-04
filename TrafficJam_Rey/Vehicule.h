#ifndef __VEHICULE_H__
#define __VEHICULE_H__

#include "Objet.h"

class Vehicule : public Objet
{
	private:
	
		bool _avance;
		float _vitesse;
		int _typeVehicule;
	
	public:
		
		Vehicule (int x,int y,int type,bool horizontale);
		~Vehicule ();
		int getVitesse() const;
		int getType() const;
		bool getAvance() const;		
		void setAvance(bool avance);
		int getTailleVehicule() const;
};



#endif
