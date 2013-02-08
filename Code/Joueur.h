#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "Recolteur.h"
#include "Soldat.h"
#include "Base.h"
#include "Entrepot.h"
#include "Caserne.h"

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
		std::vector<Batiment*> getListeBatiments() const;
		std::vector<Unite*> getListeUnites() const;
		void ajouterBatiment(int type, int i, int j);
		void ajouterUnite(int type, int i, int j);
};

#endif
