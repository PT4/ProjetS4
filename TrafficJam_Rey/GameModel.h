#ifndef _GAME_MODEL_
#define _GAME_MODEL_

#include <SFML/System.hpp>

#include "Jeu.h"


class GameModel {
private:
	int _w, _h;
	Clock _dureeCollision;
	bool _finAnim;
	int _accidentX;
	int _accidentY;
	Jeu *_jeu;
	
	
public:
	
	GameModel();
	GameModel(int w, int h);
	~GameModel();
	
	void nextStep();
	
	int getNbRoute () const;
	void getRouteInfo (int &x, int &y, bool &horizontale,int i);
	void collision();
	void newJeu();
	Jeu* getJeu () const; 
	int getAccidentX () const;
	int getAccidentY () const;
	float getClockCollision ()const;
	bool getFinAnim () const;
	void setFinAnim () ;
};
#endif
