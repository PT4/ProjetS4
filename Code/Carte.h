#ifndef _CARTE_H_
#define _CARTE_H_

#include "Constantes.h"
#include "Joueur.h"
#include "Ressource.h"
#include "Obstacle.h"
#include "EmplacementDepart.h"

#include <string>
#include <vector>

class Carte {
	
	private:
		int m_matrice[TAILLE_MAP][TAILLE_MAP];
		std::vector<Joueur*> m_listeJoueurs;
		std::vector<EmplacementDepart*> m_listeEmplacementsDeparts;
		std::vector<Ressource*> m_listeRessources;
		std::vector<Obstacle*> m_listeObstacles;
		
	public:
		Carte();
		Carte(std::string mon_fichier, std::vector<Joueur*> listeJoueurs);
		~Carte();
		int getCaseMatrice(int i, int j) const;
		void setCaseMatrice(int i, int j, int val);
		void chargementFichier(std::string mon_fichier);
		void choisirEmplacementDepartJoueur();
};

#endif
