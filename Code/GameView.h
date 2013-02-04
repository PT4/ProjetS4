#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_

#include "GameModel.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <string>


class GameView {
	private:
		int m_width, m_height;
		GameModel * m_model;
	
		sf::RenderWindow * m_window;
		sf::String m_titre;
		
		sf::Image m_image_chateau_bleu;
		sf::Image m_image_chateau_rouge;
		sf::Image m_image_caserne_bleu;
		sf::Image m_image_caserne_rouge;
		
		sf::Sprite m_sprite_logo_iut;

	
	public:
		GameView(int width, int height);
		~GameView();
	
		void setModel(GameModel * model);
		
		void draw();
		bool treatEvents();
};
#endif
