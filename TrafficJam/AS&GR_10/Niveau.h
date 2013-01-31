#ifndef _NIVEAU_H_
#define _NIVEAU_H_

#include <vector>
#include "Route.h"

class Niveau
{
	private:
		int m_nbRoutes;
		int m_nbVehicules;
		int m_nbFeux;
		int m_trafficAutorise;
		bool m_collision;
		int m_objectif;
		int m_nbVehiculesPasses;
		int m_nbVehiculePresent;
		std::vector <Route*> m_listeDeRoutes;
	public:
		Niveau();
		Niveau(int nbRoutes, int nbVehicules, int trafficAutorise, int nbFeux, int objectif);
		~Niveau();
		std::vector <Route*> getListeDeRoutes() const;
		int getNbRoutes() const;
		int getNbVehicules() const;
		int getTrafficAutorise() const;
		int getNbFeux() const;
		int getObjectif() const;
		bool getCollision() const;
		int getNbVehiculesPasses() const;
		int getNbVehiculePresent() const;
		void setNbRoutes(int nb);
		void setNbVehicules(int nb);
		void setTrafficAutorise(int nb);
		void setNbFeux(int nb);
		void setCollision(bool b);
		void setNbVehiculesPasses(int nb);
		void setObjectif(int nb);
		void setNbVehiculePresent(int nb);
		void creerRoute();
		void creerVehicule();
		void creerCroisement(int nbRouteHorizontale, int nbRouteVerticale);
		void creerFeu(int nbRouteHorizontale, int nbRouteVerticale, int nbFeu);
		void affecterSensEtCoordonneesRoute(int &nbRouteHorizontale, int &nbRouteVerticale);
		void affecterSensEtCoordonneesVehicules();
		void affecterCoordonneeCroisement();
};

#endif
