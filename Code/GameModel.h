#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_

#include <SFML/System.hpp>

#include "Partie.h"


class GameModel : public sf::Thread{
	private:
		int m_width, m_height;
		bool thread;
		Partie* m_partie;

	public:

		GameModel();
		GameModel(int width, int height);
		~GameModel();
		void nextStep();
		Partie* getPartie() const;
		virtual void Run();
		bool getThread() const;
        bool setThread ();

};
#endif
