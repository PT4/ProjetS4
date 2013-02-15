#ifndef _CARTE_H_
#define _CARTE_H_

#include "Constantes.h"

#include <string>

class Carte {
	
	private:
		int m_matrice[TAILLE_MAP][TAILLE_MAP];
		
	public:
		Carte();
		Carte(std::string mon_fichier);
		~Carte();
		int getCaseMatrice(int i, int j) const;
		void setCaseMatrice(int i, int j, int val);
		void chargementFichier(std::string mon_fichier);
		void choisirEmplacementDepartJoueur();
};

#endif
