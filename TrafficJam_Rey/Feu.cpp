#include <iostream>
#include <cstdlib>

#include "Feu.h"

using namespace std;

Feu::Feu (int x, int y, bool presence,bool horizontale)
{
	_X = x;
	_Y = y;
	_vert = true;
	_presence=presence;
	_horizontale=horizontale;
	
}

Feu::~Feu ()
{
}

bool Feu::getEtat ()
{
	return _vert;
}

void Feu::setEtat ()
{
	if (_vert == true) 
		_vert = false;
	else 
		_vert = true;

}
bool Feu::getPresence() const
{
	return _presence;
}
