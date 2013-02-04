#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "Route.h"
#include "Feu.h"

#include <vector>

class Level
{
	private :
		std::vector <Route *> _listeRoutes;
		std::vector <Feu *> _listeFeux;
		int _nbRouteV;
		int _nbRouteH;
		int _nbFeu;
		int _nbVoiturePasse;
		int _objectif;
		int _traficMax;
		int _traficActuel;
		bool _accident;
		bool _traffic;
		int _score;
	public :
		Level (int nbRouteV, int nbRouteH,int nbFeu,int objectif) ;
		~Level () ;
		void ajouterRoute(int i);
		void ajouterFeu();
		
		int getNbRoute ();
		Route* getRouteInfo (int numRoute);
		
		int getObjectif () const;
		int getVoiturePasse() const;
		void setVoiturePasse();
		int getTraficMax() const;
		
		int getTraficActuel() const;
		void setTraficActuel(int trafic);
		
		int getNbFeux() const;
		Feu* getFeuInfo (int numFeu);
		
		bool getAccident() const;
		void setAccident();
		
		void setScore(int score);
		int getScore() const;

		int getEmbouteillage () const;
		void setEmbouteillage();
};

#endif
