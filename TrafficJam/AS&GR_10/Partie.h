#ifndef _PARTIE_H_
#define _PARTIE_H_

#include <vector>
#include "Niveau.h"

class Partie
{
	private:
		int m_score;
		int m_niveauEnCours;
		Niveau * m_niveau;
	public:
		Partie();
		~Partie();
		int getScore() const;
		int getNiveauEnCours() const;
		void setScore(int nb);
		void setNiveauEnCours(int nb);
		Niveau * getNiveau() const;
		void genererNiveau();
		void supprimerNiveau();
		int calculerNbRoutes();
		int calculerNbVehicules();
		int calculerTrafficAutorise();
		int calculerNbFeux();
		int calculerScore(int i, int j);
		int calculerObjectif();
		std ::vector <Route*> getRoutes();
};

#endif
