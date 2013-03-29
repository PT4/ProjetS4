#ifndef _ENTITE_H_
#define _ENTITE_H_

#include "Objet.h"

#include <string>

class Joueur;
class Carte;

class Entite : public Objet {

	protected:
		std::string m_nom;
		int m_pointsVie;
		Joueur* m_joueur;
		Carte* m_carte;

	public:
		Entite();
		Entite(std::string nom, int pointsVie);
		Entite(std::string nom, int pointsVie, Joueur* joueur,Carte* carte);
		Entite(int i, int j, bool estFranchissable, std::string nom, int pointsVie, Joueur* joueur,Carte* carte);
		virtual ~Entite();
		int getPointsVie() const;
		std::string getNom() const;
		void setPointsVie(int pointsVie);
		Carte* getCarte() const;
};

#endif
