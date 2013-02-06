#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_

#include <SFML/System.hpp>

#include "Partie.h"


class GameModel {
	private:
		int m_width, m_height;
		Partie* m_partie;

	public:
		
		GameModel();
		GameModel(int width, int height);
		~GameModel();
		void nextStep();
		Partie* getPartie() const;
};
#endif
