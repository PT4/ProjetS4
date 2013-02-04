#include "Objet.h"


Objet::Objet() 
{
}

Objet::Objet(int x,int y,int taille)
{
	_X = x ;
	_Y = y ;
	_taille = taille ;
}

Objet::~Objet() 
{
}

int Objet::getX () const
{
	return _X;
}

int Objet::getY () const
{
	return _Y;
}

int Objet::getTaille () const
{
	return _taille;
}

bool Objet::getHorizontale () const
{
	return _horizontale;
}

void Objet::setX (int x)
{
	_X = x ;
}

void Objet::setY (int y) 
{
	_Y = y ;
}
