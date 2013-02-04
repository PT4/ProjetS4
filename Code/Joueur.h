#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "Entite.h"

#include <string>
#include <vector>

class Joueur {
	
	private:
		std::string m_nom;
		int m_quantiteMiel;
		int m_quantiteBois;
		int m_population;
		std::vector<Entite*> m_listeEntites;
		
	public:
		Joueur();
		~Joueur();
};

#endif
