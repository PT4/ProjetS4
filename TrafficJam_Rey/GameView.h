#ifndef __GAMEVIEW_H__
#define __GAMEVIEW_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include "GameModel.h"

class GameView {
private:
	int _w, _h ;
	bool _chargement;
	bool _menu;
	bool _titre;
	bool _score ;
	bool _save;
	
	float _camionX;
	int _camionY;
	
	sf::RenderWindow * _window;
	
	sf::Font _font;
	
	sf::String _play_texte_bouton;
	sf::String _score_texte_bouton;
	sf::String _quitter_texte_bouton;
	sf::String _titre_texte;
	sf::String _score_titre_texte;
	sf::String _ok_texte_bouton;
	sf::String _annonce;
	
	
	sf::Image _background_image;
	sf::Image _route_V_image;
	sf::Image _police_V_image;
	sf::Image _voiture_V_image;
	sf::Image _camion_V_image;
	sf::Image _route_H_image;
	sf::Image _police_H_image;
	sf::Image _voiture_H_image;
	sf::Image _camion_H_image;
	sf::Image _feuV_image;
	sf::Image _feuR_image;
	sf::Image _lightline_H_image;
	sf::Image _lightline_V_image;
	sf::Image _bouton_V_image;
	sf::Image _bouton_H_image;
	sf::Image _flammes_image;
	
	sf::Sprite _background_sprite;
	sf::Sprite _route_V_sprite;
	sf::Sprite _police_V_sprite;
	sf::Sprite _voiture_V_sprite;
	sf::Sprite _camion_V_sprite;
	sf::Sprite _route_H_sprite;
	sf::Sprite _police_H_sprite;
	sf::Sprite _voiture_H_sprite;
	sf::Sprite _camion_H_sprite;
	sf::Sprite _feuV_sprite;
	sf::Sprite _feuR_sprite;
	sf::Sprite _bouton_V_sprite;
	sf::Sprite _bouton_H_sprite;
	sf::Sprite _lightline_H_sprite;
	sf::Sprite _lightline_V_sprite;
	sf::Sprite _flammes_sprite;
	
	sf::Shape _cadre_trafic;
	sf::Shape _interieur_trafic;
	sf::Shape _barre_info_jeu;
	
	
	GameModel * _model;
	
public:
	
	GameView(int w, int h);
	~GameView();
	
	void setModel(GameModel * model);
	GameModel* getModel() const;
	void draw();
	bool treatEvents();
	int testSouris();
	void afficherTitre();
	void gereBarreInfo();
	bool getMenu() const;
	void afficherScore();
	void afficherChargement ();
	void gereMenuScore ();
	void gereMenu ();
	void afficherEcranSuivant();
	void setScoreFichier();
	void afficherAnimationCollision();
};
#endif
