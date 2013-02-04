#ifndef __ROUTE_H__
#define __ROUTE_H__

#include <vector>
#include <SFML/System.hpp>
#include "Objet.h"
#include "Vehicule.h"

using namespace sf;

class Route : public Objet 
{
	private :
		std::vector <Vehicule *> _listeVehicules ;
		int _trafic;
		int _vehicules;
		sf::Clock clock;
		
	public :
		Route (int x, int y,  bool horizontale) ;
		~Route () ;
		void ajouterVoiture ();
		int getNbVehicule();
		Vehicule* getVehiculeInfo (int numVehicule);
		int getTrafic() const;
		void setTrafic(int trafic);
		void enleverVehicules();
		void setTrafic();
		int getVehicules() const;
		void setVehicules(int vehicules);
		void DepartVehicule();
		
		static int sec;
};

#endif
