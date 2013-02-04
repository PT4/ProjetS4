#ifndef __FEU_H__
#define __FEU_H__

#include "Objet.h"

class Feu : public Objet
{
	private :
	
		bool _vert;
		bool _presence;
	public : 
		Feu (int x, int y,bool presence,bool horizontale);
		~Feu ();
		bool getEtat ();
		void setEtat ();
		bool getPresence() const;
};

#endif
