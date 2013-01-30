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
	bool m_menu, m_animation;
	
	sf::RenderWindow * m_window;
	sf::Font m_font;

	sf::Clock horloge;
	sf::View m_chargement;
	sf::View m_interNiveau;
	
	sf::Image m_image_logo_iut;
	sf::Image m_image_background;
	sf::Image m_image_vRoute;
	sf::Image m_image_hRoute;
	sf::Image m_image_croisement;
	sf::Image m_image_ligne;
	sf::Image m_image_feu_rouge;
	sf::Image m_image_feu_vert;
	sf::Image m_image_h_police;
	sf::Image m_image_h_voiture;
	sf::Image m_image_h_camion;
	sf::Image m_image_v_police;
	sf::Image m_image_v_voiture;
	sf::Image m_image_v_camion;
	sf::Image m_image_explosion;
	
	sf::Sprite m_sprite_logo_iut;
	sf::Sprite m_sprite_background;
	sf::Sprite m_sprite_vRoute;
	sf::Sprite m_sprite_hRoute;
	sf::Sprite m_sprite_croisement;
	sf::Sprite m_sprite_ligne;
	sf::Sprite m_sprite_feu;
	sf::Sprite m_sprite_police;
	sf::Sprite m_sprite_voiture;
	sf::Sprite m_sprite_camion;
	sf::Sprite m_sprite_h_police;
	sf::Sprite m_sprite_h_voiture;
	sf::Sprite m_sprite_h_camion;
	sf::Sprite m_sprite_v_police;
	sf::Sprite m_sprite_v_voiture;
	sf::Sprite m_sprite_v_camion;
	sf::Sprite m_sprite_explosion;
	
	GameModel * m_model;
	
	//Introduction
	sf::String m_intro;
	
	//Menu
	sf::String m_titre;
	sf::Image m_image_bouton_jouer;
	sf::Image m_image_bouton_highscore;
	sf::Image m_image_bouton_quitter;
	sf::Sprite m_sprite_bouton_jouer;
	sf::Sprite m_sprite_bouton_highscore;
	sf::Sprite m_sprite_bouton_quitter;
	sf::Image m_image_bouton_jouer_agrandi;
	sf::Image m_image_bouton_highscore_agrandi;
	sf::Image m_image_bouton_quitter_agrandi;
	sf::Sprite m_sprite_bouton_jouer_agrandi;
	sf::Sprite m_sprite_bouton_highscore_agrandi;
	sf::Sprite m_sprite_bouton_quitter_agrandi;
	
	//Jeu
	sf::Shape m_barre_traffic;
	sf::Shape m_barre_traffic_actuel;
	sf::String m_niveauEnCours;
	sf::String m_nbVehiculesObjectif;
	sf::String m_traffic;
	sf::String m_scoreActuel;
	sf::Shape m_barre_partie;
	std::string m_niveau;
	std::string m_score;
	std::string m_objectif;
	
	//Inter-Niveau
	sf::String m_texte_interNiveau_gagne;
	sf::String m_texte_interNiveau_perdu;
	std::string m_texte_gagne;
	std::string m_texte_perdu;
	
	
public:
	GameView(int width, int height);
	~GameView();
	
	void setModel(GameModel * model);
	bool getMenu(GameView * view) const;
	
	std::string convertInt(int number);
	
	void ecranChargement();
	void ecranInterNiveau();
	void declarationImages();
	void draw();
	void affichageBoutons(bool agrandi);
	void affichageEcran();
	void affichageCroisement(int i);
	
	bool treatEvents();
	
	void afficherHighscore();
	void setHighscoreFichier();
};
#endif
