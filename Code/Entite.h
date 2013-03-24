#ifndef _ENTITE_H_
#define _ENTITE_H_

#include "Objet.h"

#include <string>

class Joueur;

class Entite : public Objet {
	
	protected:
		std::string m_nom;
		int m_pointsVie;
		Joueur* m_joueur;
		
	public:
		Entite();
		Entite(std::string nom, int pointsVie);
		Entite(std::string nom, int pointsVie, Joueur* joueur);
		Entite(int i, int j, bool estFranchissable, std::string nom, int pointsVie, Joueur* joueur);
		~Entite();
		int getPointsVie() const;
		std::string getNom() const;
		void setPointsVie(int pointsVie);
};

#endif
