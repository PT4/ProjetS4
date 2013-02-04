#include "GameModel.h"
#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;


//=======================================
// Constructeurs
//=======================================
GameModel::GameModel() : _w(800), _h(600) 
{
	_jeu = new Jeu (1);
	_accidentX=-100;
	_accidentY=-100;
	_finAnim = false;
}
//=======================================
GameModel::GameModel(int w, int h)
:  _w(w), _h(h) 
{
	_accidentX=-100;
	_accidentY=-100;
	_jeu = new Jeu (1);
	_finAnim = false;
}

//=======================================
// Destructeurs
//=======================================
GameModel::~GameModel()
{
	delete _jeu;
}

//=======================================
// Accesseurs en lecture
//=======================================

void GameModel::getRouteInfo (int &x, int &y, bool &horizontale,int i)
{
	x = _jeu -> getLevel() -> getRouteInfo(i) -> getX();
	y = _jeu -> getLevel() -> getRouteInfo(i) -> getY();
	horizontale = _jeu -> getLevel() -> getRouteInfo(i) -> getHorizontale ();
}
Jeu* GameModel::getJeu () const
{
	return _jeu;
}

//=======================================
// Calcul la prochaine étape
//=======================================
void GameModel::nextStep()
{
	int x, y, vitesse;
	
	
	if(getFinAnim() || _jeu -> getLevel () -> getTraficActuel() > _jeu  -> getLevel ()->getTraficMax())
	{
		_jeu->resetLevel();
		setFinAnim ();
	}
	else if(_jeu->getLevel()->getVoiturePasse()>=_jeu->getLevel()->getObjectif())
	{
		_jeu->setLevel();
	}
	
	if (!_jeu->getLevel()->getAccident())
	{
		collision();
	for (int i = 0; i < _jeu->getLevel()->getNbRoute(); i++)
	{
		_jeu->getLevel()->getRouteInfo(i)->DepartVehicule();
		if(_jeu->getLevel()->getRouteInfo(i)->getHorizontale())
		{
			_jeu->getLevel()->setTraficActuel(0);
			_jeu->getLevel()->setTraficActuel(_jeu->getLevel()->getRouteInfo(i)->getVehicules()+_jeu->getLevel()->getTraficActuel());
		}
		for (int j = 0; j < _jeu->getLevel()->getRouteInfo(i)->getNbVehicule(); j++)
		{
				vitesse=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getVitesse();
				if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getHorizontale ())
				{
					if(_jeu->getLevel()->getRouteInfo(i)->getTrafic()<_jeu->getLevel()->getRouteInfo(i)->getVehicules())
					{
						_jeu->getLevel()->getRouteInfo(i)->setTrafic();
						if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getAvance())
						{
							x=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX();
							x+=vitesse;
							_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setX(x);
							if(x>=798)
							{	
								_jeu->getLevel()->getRouteInfo(i)->setVehicules(_jeu->getLevel()->getRouteInfo(i)->getVehicules()-1);	
								if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getType()==1)
								{
									_jeu->setScore(_jeu->getScore()+3);
									_jeu->getLevel()->setVoiturePasse();
									_jeu->getLevel()->setScore(_jeu->getLevel()->getScore()+3);
								}
								else
								{
									_jeu->getLevel()->setVoiturePasse();
									_jeu->setScore(_jeu->getScore()+1);
									_jeu->getLevel()->setScore(_jeu->getLevel()->getScore()+1);
								}
								_jeu->getLevel()->getRouteInfo(i)->enleverVehicules();
							}
						}
					}
				}
				else if(_jeu->getLevel()->getRouteInfo(i)->getTrafic()<_jeu->getLevel()->getRouteInfo(i)->getVehicules())
				{
					_jeu->getLevel()->getRouteInfo(i)->setTrafic();
					if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getAvance())
					{
						y=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY();
						y+=vitesse;
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setY(y);
						if(y>=590)
						{	
							_jeu->getLevel()->getRouteInfo(i)->setVehicules(_jeu->getLevel()->getRouteInfo(i)->getVehicules()-1);	
							_jeu->getLevel()->getRouteInfo(i)->enleverVehicules();
						}
					}
				}
		}
		
	}
}

}
//=======================================
// Calcul les collisions entre les voitures
//=======================================
void GameModel::collision()
{
	int taille, taille2;
	for (int i = 0; i < _jeu->getLevel()->getNbRoute(); i++)
	{
		for (int j = 0; j < _jeu->getLevel()->getRouteInfo(i)->getNbVehicule(); j++)
		{
			taille=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getTailleVehicule();
			if(j>0 && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j-1)!=NULL)
			{
				if(_jeu->getLevel()->getRouteInfo(i)->getHorizontale())
				{
					if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille>=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j-1)->getX())
					{
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(false);
					}
					else
					{
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(true);
					}
				}	
				else
				{
					if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()+taille>=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j-1)->getY())
					{
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(false);
					}
					else
					{
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(true);
					}
		
				}
			}
			else if(j==0)
			{
				_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(true);
			}
			else if(j>0 && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j-1)==NULL)
			{
				_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(true);
			}
			if(_jeu->getLevel()->getRouteInfo(i)->getHorizontale())
			{
				for (int k = 0; k < _jeu->getLevel()->getNbFeux(); k++)
				{
					if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille<=_jeu->getLevel()->getFeuInfo(k)->getX() 
					   && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille>=_jeu->getLevel()->getFeuInfo(k)->getX()-5 
					   && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()>=_jeu->getLevel()->getFeuInfo(k)->getY()
					   && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()<=_jeu->getLevel()->getFeuInfo(k)->getY()+40
					   &&_jeu->getLevel()->getFeuInfo(k)->getEtat()==false 
					   && _jeu->getLevel()->getFeuInfo(k)->getPresence())
					{
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(false);
					}
					else if (_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille<=_jeu->getLevel()->getFeuInfo(k)->getX() 
							 && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille>=_jeu->getLevel()->getFeuInfo(k)->getX()-5 
							 && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()>=_jeu->getLevel()->getFeuInfo(k)->getY()
							 && _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()<=_jeu->getLevel()->getFeuInfo(k)->getY()+40
							 &&_jeu->getLevel()->getFeuInfo(k)->getEtat()==true 
							 && _jeu->getLevel()->getFeuInfo(k)->getPresence())
					{
						_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(true);
					}
				}
				for (int l = 0; l < _jeu->getLevel()->getNbRoute(); l++)
				{
					if(_jeu->getLevel()->getRouteInfo(l)->getHorizontale()==false)
					{
						for (int m = 0; m < _jeu->getLevel()->getRouteInfo(l)->getNbVehicule(); m++)
						{
							taille2=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getTailleVehicule();
							if(_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille>=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getX() 
							&& _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille<=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getX()+35 
							&& _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()>=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getY() 
							&& _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()<=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getY()+taille2)
							{
								_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(false);
								_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->setAvance(false);
								_jeu->getLevel()->setAccident();
								_accidentX=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getX();
								_accidentY=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getY();
								_dureeCollision.Reset ();
							}
							else if(_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getY()+taille2>=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY() 
							&& _jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getY()+taille2<=_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getY()+35 
							&& _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()<=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getX() 
							&& _jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->getX()+taille>=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getX())
							{
								_jeu->getLevel()->getRouteInfo(i)->getVehiculeInfo(j)->setAvance(false);
								_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->setAvance(false);
								_jeu->getLevel()->setAccident();
								_accidentX=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getX();
								_accidentY=_jeu->getLevel()->getRouteInfo(l)->getVehiculeInfo(m)->getY();
								_dureeCollision.Reset ();
							}
						}
					}	
				}
					
			}	
			
		}
	}
}
//======================================
void GameModel::newJeu ()
{
	delete _jeu;
	_jeu = new Jeu (1);
}

int GameModel::getAccidentX () const
{
	return _accidentX;
}

int GameModel::getAccidentY () const
{
	return _accidentY;
}

float GameModel::getClockCollision ()const
{
	return _dureeCollision.GetElapsedTime();
}

bool GameModel::getFinAnim () const
{
	return _finAnim;
}

void GameModel::setFinAnim ()
{
	if (!_finAnim )
		_finAnim = true;
	else
	_finAnim = false;
}	
