#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_

#include <SFML/System.hpp>

class GameModel {
	private:
		int m_width, m_height;

	public:
		
		GameModel();
		GameModel(int width, int height);
		~GameModel();
};
#endif
