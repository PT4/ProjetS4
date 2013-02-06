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
		
		sf::Image m_image_base_joueur1;
		sf::Image m_image_base_joueur2;
		sf::Image m_image_caserne_joueur1;
		sf::Image m_image_caserne_joueur2;
		sf::Image m_image_entrepot_joueur1;
		sf::Image m_image_entrepot_joueur2;
		sf::Image m_image_recolteur_joueur1;
		sf::Image m_image_recolteur_joueur2;
		sf::Image m_image_soldat_joueur1;
		sf::Image m_image_soldat_joueur2;
		sf::Image m_image_bois;
		sf::Image m_image_herbe;
		sf::Image m_image_miel;
		sf::Image m_image_rocher;
		
		sf::Sprite m_sprite_base_joueur1;
		sf::Sprite m_sprite_base_joueur2;
		sf::Sprite m_sprite_caserne_joueur1;
		sf::Sprite m_sprite_caserne_joueur2;
		sf::Sprite m_sprite_entrepot_joueur1;
		sf::Sprite m_sprite_entrepot_joueur2;
		sf::Sprite m_sprite_recolteur_joueur1;
		sf::Sprite m_sprite_recolteur_joueur2;
		sf::Sprite m_sprite_soldat_joueur1;
		sf::Sprite m_sprite_soldat_joueur2;
		sf::Sprite m_sprite_bois;
		sf::Sprite m_sprite_herbe;
		sf::Sprite m_sprite_miel;
		sf::Sprite m_sprite_rocher;
	
	public:
		GameView(int width, int height);
		~GameView();
	
		void setModel(GameModel * model);
		
		void draw();
		bool treatEvents();
		void declarationImages();
};
#endif
