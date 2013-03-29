#ifndef _RECOLTEUR_H_
#define _RECOLTEUR_H_

#include "Unite.h"

class Joueur;
class Carte;

class Recolteur: public Unite {

	private:
		int m_poids;
		bool m_recolte;

	public:
		Recolteur();
		Recolteur(Joueur* joueur,Carte* carte);
		Recolteur(int i, int j, Joueur* joueur,Carte* carte);
		~Recolteur();
		int getPoids() const;
		void setPoids(int poids);
		void amasser();
};

#endif
