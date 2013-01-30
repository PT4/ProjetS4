#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_

#include <SFML/System.hpp>
#include "Partie.h"

class GameModel {
private:
	int m_width, m_height;
	int m_nbVehicules_Horizontal;
	int m_nbVehicules_Vertical;
	int m_xCollision, m_yCollision;
	float m_tempsCollision;
	bool m_collisionFinie;
	
	sf::Clock horloge_horizontal;
	sf::Clock horloge_vertical;
	sf::Clock horloge_collision;
	float time_horizontal;
	float time_vertical;
	int m_nbAlea;
	Partie* m_partie;
	
	
	
public:
	
	GameModel();
	GameModel(int width, int height);
	~GameModel();
	Partie* getPartie() const;
	float getTemps() const;
	float getTempsCollision() const;
	int getXCollision() const;
	int getYCollision() const;
	void nextStep();
	void collision();
	
	
};
#endif
