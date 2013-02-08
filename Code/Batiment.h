#ifndef _BATIMENT_H_
#define _BATIMENT_H_

#include "Entite.h"

#include <string>

class Batiment: public Entite {
	
	protected:
		int m_prixBois;
		bool m_formeUnite;
		
	public:
		Batiment();
		Batiment(std::string nom, int pointsVie, int prixBois, bool formeUnite);
		Batiment(int i, int j, std::string nom, int pointsVie, int prixBois, bool formeUnite);
		~Batiment();
		bool getFormation() const;
		void setFormation(bool formeUnite);
};

#endif
