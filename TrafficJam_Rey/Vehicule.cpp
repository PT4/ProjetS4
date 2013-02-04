#include "Vehicule.h"
#include <cstdlib>
//#include <cstdio>
#include <iostream>

using namespace std ;
Vehicule::Vehicule (int x,int y,int type,bool horizontale)
{
	_avance = true;
	_typeVehicule = type ;
	_X = x;
	_Y = y;
	_horizontale=horizontale;
	if(_horizontale)
	{
		_X-=120;
	}
	else
	{
		_Y-=120;
	}
	switch (_typeVehicule) 
	{
		case 1:
			_vitesse = 1;
			break;
			
		case 2:
			_vitesse = 2;
			break;
			
		case 3:
			_vitesse = 3;
			break;
			
		default:
			break;
	}
}

Vehicule::~Vehicule ()
{
}

int Vehicule::getVitesse() const
{
	return _vitesse;
}
int Vehicule::getType() const
{
	return _typeVehicule;
}
bool Vehicule::getAvance() const
{
	return _avance;
}
void Vehicule::setAvance(bool avance)
{
		_avance=avance;
}
int Vehicule::getTailleVehicule() const
{
	switch (_typeVehicule)
	{
		case 1:
			return 122;
			break;
		case 2:
			return 68;
			break;
		case 3:
			return 78;
			break;
		default:
			break;
			
	}
}
	
