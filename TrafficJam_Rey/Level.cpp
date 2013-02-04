#include <SFML/System.hpp>
#include <iostream>

#include "Level.h"


using namespace std;
using namespace sf;

Level::Level (int nbRouteV, int nbRouteH,int nbFeu,int objectif)
{
	_score=0;
	_accident=false;
	_nbRouteV = nbRouteV;
	_nbRouteH = nbRouteH;
	_nbFeu = nbFeu;
	_objectif = objectif;
	_nbVoiturePasse = 0;
	_traficMax = _objectif/2+3;
	_traficActuel = 0;
	_traffic= false;
	for (int i = 0; i < _nbRouteH + _nbRouteV; i++) 
	{
		ajouterRoute(i);
	}
	if(_nbRouteH!=0 || _nbRouteV!=0)
	{
		for (int i = 0; i < _nbFeu; i++) 
			ajouterFeu();
	}
}

Level::~Level ()
{
}

void Level::ajouterRoute(int i)
{
	bool horizontale;
	int x;
	int y;
	
	if (_listeRoutes.size() < _nbRouteH) 
	{
		horizontale = true;
		i+=1;
	}
	else 
	{
		horizontale = false;
		i = i - _nbRouteH +1;
	}
	
	switch (horizontale) 
	{
		case true:
			x = 0;
			if (i == 1)
			y = (((555-40*_nbRouteH)/(_nbRouteH+1)));
			else
			y = (i-1)*40+i*((555-40*_nbRouteH)/(_nbRouteH+1));
			break;
			
		case false:
			if (i == 1)
			x = i*(((800-40*_nbRouteV)/(_nbRouteV+1)));
			else
			x = (i-1)*40+i*((800-40*_nbRouteV)/(_nbRouteV+1));
			y = 0;
			break;
			
		default:
			break;
	}
	_listeRoutes.push_back(new Route (x,y,horizontale));
	
}

void Level::ajouterFeu()
{
	int x=0;
	int y=0;
	for (int i = 0; i < _listeRoutes.size(); i++)
	{
		if(!_listeRoutes[i]->getHorizontale())
		{		
			x=_listeRoutes[i]->getX();
			for (int j = 0; j < _listeRoutes.size(); j++)
			{
				if(_listeRoutes[j]->getHorizontale() && _nbFeu>0)
				{
					_nbFeu--;
					y=_listeRoutes[j]->getY();
					_listeFeux.push_back(new Feu (x,y,true,true));
				}
				else if(_listeRoutes[j]->getHorizontale() && _nbFeu<=0)
				{
					y=_listeRoutes[j]->getY();
					_listeFeux.push_back(new Feu (x,y,false,true));
				}
			}
		}
			
	}
	
}

int Level::getNbRoute ()
{
	return _listeRoutes.size ();
}

Route* Level::getRouteInfo (int numRoute)
{
	return _listeRoutes[numRoute];
}

int Level::getVoiturePasse() const
{
	return _nbVoiturePasse;
}

int Level::getObjectif () const
{
	return _objectif;
}

int Level::getTraficMax() const
{
	return _traficMax;
}

int Level::getTraficActuel() const
{
	return _traficActuel;
}

int Level::getNbFeux() const
{
	return _listeFeux.size ();
}

Feu* Level::getFeuInfo (int numFeu)
{
	return _listeFeux[numFeu];
}
void Level::setTraficActuel(int trafic)
{
	_traficActuel=trafic;
}
bool Level::getAccident() const
{
	return _accident;
}
void Level::setAccident()
{
	_accident=true;
}

void Level::setVoiturePasse()
{
	_nbVoiturePasse++;
}
int Level::getScore () const
{
	return _score;
}
void Level::setScore(int score)
{
	_score=score;
}
int Level::getEmbouteillage () const
{
	return _traffic;
}
void Level::setEmbouteillage()
{
	_traffic = true;
}
