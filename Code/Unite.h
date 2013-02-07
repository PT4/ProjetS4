#ifndef _UNITE_H_
#define _UNITE_H_

#include "Entite.h"

#include <string>

class Unite: public Entite {
	
	protected:
		int m_prixMiel;
		int m_vitesse;
		int m_degat;
		int m_rayonAttaque;
		bool m_seDeplace;
		bool m_attaque;
	
	public:
		Unite();
		Unite(std::string nom, int pointsVie, int prixMiel, int vitesse, int degat, int rayonAttaque);
		~Unite();
		bool getDeplacement() const;
		bool getAttaque() const;
		/**/int getDegat() const;
		void setDeplacement(bool seDeplace);
		void setAttaque(bool attaque);
		void seDeplacer();
		void attaquer(Entite& cible);
};

#endif
