#ifndef _CARTE_H_
#define _CARTE_H_

#include "Constantes.h"

#include <string>
#include <vector>


class Joueur;
class Ressource;
class Obstacle;
class EmplacementDepart;

class Carte {
	
	private:
		int m_matrice[TAILLE_MAP][TAILLE_MAP];
		std::vector<EmplacementDepart*> m_listeEmplacementsDeparts;
		std::vector<Ressource*> m_listeRessources;
		std::vector<Obstacle*> m_listeObstacles;
		
	public:
		Carte();
		Carte(std::string mon_fichier);
		~Carte();
		int getCaseMatrice(int i, int j) const;
		void setCaseMatrice(int i, int j, int val);
		void chargementFichier(std::string mon_fichier);
		void choisirEmplacementDepartJoueur(std::vector<Joueur*> listeJoueurs);
};

#endif
