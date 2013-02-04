#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include "Route.h"
#include <vector>

using namespace std;
using namespace sf;

int Route::sec = Randomizer::Random(0,5);

Route::Route (int x, int y, bool horizontale)
{
	_vehicules=0;
	_trafic=0;
	_X = x ;
	_Y = y ;
	_horizontale = horizontale ;
	
	for (int i = 0; i < 20; i++) 
	{
		ajouterVoiture ();
	}
	clock.Reset();
	
}

void Route::ajouterVoiture ()
{
	int x;
	int y;
	int type = Randomizer::Random(0, 100);
	if (type <= 70)
		type = 2;
	else if (type > 70 && type <= 90)
		type = 3;
	else 
		type = 1;
	switch (_horizontale) {
		case true:
			x = 0 ;
			y = _Y+5 ;
			break;
			
		case false:
			x = _X+5;
			y = 0;
			break;
		default:
			break;
	}
	_listeVehicules.push_back(new Vehicule (x,y,type,_horizontale));
}

void Route::enleverVehicules()
{
	_listeVehicules.erase(_listeVehicules.begin());
}
int Route::getNbVehicule()
{
	return _listeVehicules.size();
}
Vehicule* Route::getVehiculeInfo (int numVehicule)
{
	return _listeVehicules[numVehicule];
}

int Route::getTrafic() const
{
	return _trafic;
}

void Route::setTrafic(int trafic)
{
	_trafic=trafic;
}

void Route::setTrafic()
{
	_trafic++;
}
void Route::setVehicules(int vehicules)
{
	_vehicules=vehicules;
}
int Route::getVehicules() const
{
	return _vehicules;
}
void Route::DepartVehicule()
{
	float time;
	_trafic=0;

	time = clock.GetElapsedTime();
	if(time>=4+Route::sec)
	{	
		_vehicules++;
		clock.Reset();
		Route::sec = Randomizer::Random(0,5);
		
	}
}
