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
		bool m_menu, m_optionMenu;
		GameModel * m_model;
		sf::View m_ecranJeu;
		
		sf::RenderWindow * m_window;
		sf::Font m_font;
	
		//Menu
		sf::String m_option;
		sf::String m_nbJoueurs;
		sf::String m_string_joueur2;
		sf::String m_string_joueur3;
		sf::String m_string_joueur4;
		sf::String m_nomCarte;
		sf::String m_string_carte1;
		sf::String m_string_carte2;
		std::string m_string_adresse_carte1;
		std::string m_string_adresse_carte2;
		sf::Shape m_miniMap;
		sf::Image m_image_titre;
		sf::Sprite m_sprite_titre;
		sf::Image m_image_commencer;
		sf::Sprite m_sprite_commencer;
		sf::Image m_image_nouvellePartie;
		sf::Sprite m_sprite_nouvellePartie;
		sf::Image m_image_quitter;
		sf::Sprite m_sprite_quitter;
		
		
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
		
		int convertString(std::string number);
		
		void draw();
		void declarationImages();
		void affichageCarte(bool apercu);
		void affichageBaseJoueur(int i, int j);
		void affichageUnitesJoueur();
		std::string selectionOptionMenu(sf::String selection);
		
		bool treatEvents();
};
#endif
