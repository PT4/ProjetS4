#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <fstream>
#include <string>

#include "Constantes.h"

class GameModel;


class GameView :public sf::Thread{
	private:
		int m_width, m_height;
		bool m_menu, m_optionMenu;
		GameModel * m_model;
		sf::View m_ecranJeu;

		bool m_clic;
		int m_clicX,m_clicY;
		int m_clicTempX,m_clicTempY;

		int m_selectionNbJoueurs;
        std::string m_selectionCarte;
        sf::Shape m_selection;

		sf::RenderWindow * m_window;
		sf::Font m_font;
		
		bool m_thread;

		int m_selectionApercuCarte;

		//Menu
		sf::String m_option;
		sf::String m_nbJoueurs;
		sf::String m_string_joueur2;
		sf::String m_string_joueur3;
		sf::String m_string_joueur4;
		sf::String m_nomCarte;
		sf::String m_string_carte1;
		sf::String m_string_carte2;
		sf::String m_string_barre;
		sf::String m_string_ressources;
		sf::String m_string_population;
		sf::String m_string_bois;
		sf::String m_string_miel;
		sf::String m_string_selection;
		std::string m_string_adresse_carte1;
		std::string m_string_adresse_carte2;
		sf::Image m_image_titre;
		sf::Sprite m_sprite_titre;
		sf::Image m_image_commencer;
		sf::Sprite m_sprite_commencer;
		sf::Image m_image_nouvellePartie;
		sf::Sprite m_sprite_nouvellePartie;
		sf::Image m_image_quitter;
		sf::Sprite m_sprite_quitter;
		sf::Image m_image_apercuVide;
		sf::Sprite m_sprite_apercuVide;
		sf::Image m_image_apercuMC;
		sf::Sprite m_sprite_apercuMC;
		sf::Image m_image_apercuDP;
		sf::Sprite m_sprite_apercuDP;
		sf::Image m_image_bois_sideBar;
		sf::Sprite m_sprite_bois_sideBar;
		sf::Image m_image_miel_sideBar;
		sf::Sprite m_sprite_miel_sideBar;


		// Déclaration des images et des sprites
		sf::Image m_image_base_joueur1;
		sf::Image m_image_base_joueur2;
		sf::Image m_image_base_joueur3;
		sf::Image m_image_base_joueur4;
		sf::Image m_image_caserne_joueur1;
		sf::Image m_image_caserne_joueur2;
		sf::Image m_image_caserne_joueur3;
		sf::Image m_image_caserne_joueur4;
		sf::Image m_image_entrepot_joueur1;
		sf::Image m_image_entrepot_joueur2;
		sf::Image m_image_entrepot_joueur3;
		sf::Image m_image_entrepot_joueur4;
		sf::Image m_image_recolteur_joueur1;
		sf::Image m_image_recolteur_joueur2;
		sf::Image m_image_recolteur_joueur3;
		sf::Image m_image_recolteur_joueur4;
		sf::Image m_image_soldat_joueur1;
		sf::Image m_image_soldat_joueur2;
		sf::Image m_image_soldat_joueur3;
		sf::Image m_image_soldat_joueur4;
		sf::Image m_image_bois;
		sf::Image m_image_herbe;
		sf::Image m_image_miel;
		sf::Image m_image_rocher;

		sf::Sprite m_sprite_base_joueur1;
		sf::Sprite m_sprite_base_joueur2;
		sf::Sprite m_sprite_base_joueur3;
		sf::Sprite m_sprite_base_joueur4;
		sf::Sprite m_sprite_caserne_joueur1;
		sf::Sprite m_sprite_caserne_joueur2;
		sf::Sprite m_sprite_caserne_joueur3;
		sf::Sprite m_sprite_caserne_joueur4;
		sf::Sprite m_sprite_entrepot_joueur1;
		sf::Sprite m_sprite_entrepot_joueur2;
		sf::Sprite m_sprite_entrepot_joueur3;
		sf::Sprite m_sprite_entrepot_joueur4;
		sf::Sprite m_sprite_recolteur_joueur1;
		sf::Sprite m_sprite_recolteur_joueur2;
		sf::Sprite m_sprite_recolteur_joueur3;
		sf::Sprite m_sprite_recolteur_joueur4;
		sf::Sprite m_sprite_soldat_joueur1;
		sf::Sprite m_sprite_soldat_joueur2;
		sf::Sprite m_sprite_soldat_joueur3;
		sf::Sprite m_sprite_soldat_joueur4;
		sf::Sprite m_sprite_bois;
		sf::Sprite m_sprite_herbe;
		sf::Sprite m_sprite_miel;
		sf::Sprite m_sprite_rocher;
		
		sf::Shape m_barreInfo;

	public:
	
		GameView(int width, int height);
		~GameView();

		void setModel(GameModel * model);

		int convertString(std::string number);
		std::string convertInt(int number);
		int clicToZoomArene(float coord, bool coordVertical);
        void verificationInformations();
		void draw();
		void declarationImages();
		void affichageCarte();
		void affichageBaseJoueur(int i, int j);
		void affichageUnitesJoueur();
		void affichageSideBar();
		std::string selectionOptionMenu(sf::String selection);
		bool treatEvents();
		void afficheMiniMap();
};
#endif
