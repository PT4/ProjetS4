#ifndef _ROUTE_H_
#define _ROUTE_H_

#include <vector>
#include "Vehicule.h"
#include "Croisement.h"

class Route : public Objet
{
	private :
		std::vector <Vehicule*> m_listeDeVehicules;
		std::vector <Croisement*> m_listeDeCroisements;
		int m_numeroVehicule;
	public :
		Route();
		~Route();
		std::vector <Vehicule*> getListeDeVehicules() const;
		std::vector <Croisement*> getListeDeCroisements() const;
		int getNumeroVehicule() const;
		void setNumeroVehicule (int nb);
		void ajouterVehicule();
		void ajouterCroisement();
};

#endif
