#ifndef _BATIMENT_H_
#define _BATIMENT_H_

#include "Entite.h"

class Joueur;
class Carte;

class Batiment: public Entite {

	protected:
		int m_prixBois;
		bool m_formeUnite;

	public:
		Batiment();
		Batiment(std::string nom, int pointsVie, int prixBois, bool formeUnite);
		Batiment(std::string nom, int pointsVie, Joueur* joueur, int prixBois, bool formeUnite,Carte* carte);
		Batiment(int i, int j, std::string nom, int pointsVie, Joueur* joueur, int prixBois, bool formeUnite,Carte* carte);
		~Batiment();
		bool getFormation() const;
		void setFormation(bool formeUnite);
};

#endif
