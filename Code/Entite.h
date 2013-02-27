#ifndef _ENTITE_H_
#define _ENTITE_H_

#include "Objet.h"

#include <string>

class Entite : public Objet {
	
	protected:
		std::string m_nom;
		int m_pointsVie;
		
	public:
		Entite();
		Entite(std::string nom, int pointsVie);
		Entite(int i, int j, bool estFranchissable, std::string nom, int pointsVie);
		~Entite();
		int getPointsVie() const;
		std::string getNom() const;
		void setPointsVie(int pointsVie);
};

#endif
