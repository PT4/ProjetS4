#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "Unite.h"
#include "Batiment.h"

#include <string>
#include <vector>

class Joueur {
	
	private:
		std::string m_nom;
		int m_quantiteMiel;
		int m_quantiteBois;
		int m_population;
		std::vector<Unite*> m_listeUnites;
		std::vector<Batiment*> m_listeBatiments;
		
	public:
		Joueur();
		~Joueur();
};

#endif
