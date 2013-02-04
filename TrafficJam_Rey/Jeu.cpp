#include "Jeu.h"


Jeu::Jeu (int level)
{
	_score = 0 ;
	_numlevel = level ;
	_nbRouteH=1;
	_nbRouteV=1;
	_nbFeu = 1;
	_level = new Level (_nbRouteH,_nbRouteV,_nbFeu,5);
}

Jeu::~Jeu ()
{
}

int Jeu::getScore () const
{
	return _score;
}
void Jeu::setScore(int score)
{
	_score=score;
}
int Jeu::getNiveau () const
{
	return _numlevel;
}

Level* Jeu::getLevel() const
{
	return _level;
}

void Jeu::setLevel ()
{

	delete _level;
	_numlevel ++;
	if (_nbRouteH>_nbRouteV && _nbRouteV != 5)
		_nbRouteV++;
	else if (_nbRouteH != 5)
		_nbRouteH++;

	_level = new Level(_nbRouteV,_nbRouteH,_numlevel,_numlevel*5);
	
}

void Jeu::resetLevel()
{
	_score-=_level->getScore();
	delete _level;
	_level = new Level (_nbRouteV,_nbRouteH,_numlevel,_numlevel*5);
	
	
}
