#ifndef _RECOLTEUR_H_
#define _RECOLTEUR_H_

#include "Unite.h"

class Recolteur: public Unite {
	
	private:
		int m_poids;
		bool m_recolte;
		
	public:
		Recolteur();
		Recolteur(int i, int j);
		~Recolteur();
		int getPoids() const;
		void setPoids(int poids);
		void amasser();
};

#endif
