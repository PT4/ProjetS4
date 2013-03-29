#ifndef _SOLDAT_H_
#define _SOLDAT_H_

#include "Unite.h"

class Joueur;
class Carte;

class Soldat: public Unite {

	private:
		int m_armure;

	public:
		Soldat();
		Soldat(Joueur* joueur,Carte* carte);
		Soldat(int i, int j, Joueur* joueur,Carte* carte);
		~Soldat();
		int getArmure() const;
		void setArmure(int armure);
};

#endif
