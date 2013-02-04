#include <cstdlib>
#include <iostream>
#include <sstream>
#include "GameView.h"
#include "GameModel.h"
#include "Constantes.h"

using namespace std;
using namespace sf;

// Constructeurs

GameView::GameView(int width, int height): m_width(width), m_height(height)
{
	m_window = new RenderWindow(sf::VideoMode(m_width, m_height, 32), "AnimalsCraft", sf::Style::Close);
	
	// chargement des images
	if (!m_image_recolteur_joueur1.LoadFromFile("images/RecolteurJoueur1.png") ||
		 !m_image_recolteur_joueur2.LoadFromFile("images/RecolteurJoueur2.png") ||
		 !m_image_soldat_joueur1.LoadFromFile("images/soldatJoueur1.png") ||
		 !m_image_soldat_joueur2.LoadFromFile("images/soldatJoueur2.png") ||
		 !m_image_base_joueur1.LoadFromFile("images/BaseJoueur1.png") || 
		 !m_image_base_joueur2.LoadFromFile("images/BaseJoueur2.png") ||
		 !m_image_entrepot_joueur1.LoadFromFile("images/EntrepotJoueur1.png") ||
		 !m_image_entrepot_joueur2.LoadFromFile("images/EntrepotJoueur2.png") ||
		 !m_image_caserne_joueur1.LoadFromFile("images/CaserneJoueur1.png") ||
		 !m_image_caserne_joueur2.LoadFromFile("images/CaserneJoueur2.png") ||
		 !m_image_bois.LoadFromFile("images/bois.png") ||
		 !m_image_miel.LoadFromFile("images/miel.png") ||
		 !m_image_rocher.LoadFromFile("images/rocher.png") ||
		 !m_image_herbe.LoadFromFile("images/herbe.png"))
		 cout << "Erreur lors du chargement des images" << endl;
}

// Destructeur
GameView::~GameView()
{
	if(m_window!= NULL)
		delete m_window;
}

// Accesseurs en écriture
void GameView::setModel(GameModel * model)
{
	m_model = model;
}

// Déclaration des images et initialisation
void GameView::declarationImages()
{
	// Sprites de jeu
	m_sprite_recolteur_joueur1 = Sprite(m_image_recolteur_joueur1);
	m_sprite_recolteur_joueur2 = Sprite(m_image_recolteur_joueur2);
	m_sprite_soldat_joueur1 = Sprite(m_image_soldat_joueur1);
	m_sprite_soldat_joueur2 = Sprite(m_image_soldat_joueur2);
	m_sprite_base_joueur1 = Sprite(m_image_base_joueur1);
	m_sprite_base_joueur2 = Sprite(m_image_base_joueur2);
	m_sprite_entrepot_joueur1 = Sprite(m_image_entrepot_joueur1);
	m_sprite_entrepot_joueur2 = Sprite(m_image_entrepot_joueur2);
	m_sprite_caserne_joueur1 = Sprite(m_image_caserne_joueur1);
	m_sprite_caserne_joueur2 = Sprite(m_image_caserne_joueur2);
	m_sprite_bois = Sprite(m_image_bois);
	m_sprite_miel = Sprite(m_image_miel);
	m_sprite_rocher = Sprite(m_image_rocher);
	m_sprite_herbe = Sprite(m_image_herbe);
}


// Boucle d'affichage
void GameView::draw()
{
	m_window->Clear(sf::Color(37,38,35));
	
	/*m_titre.SetText(L"      BouboursTown \n Par Gaëtan Roudeau \n Emile Rey \n et Anthony Silverio");
	m_titre.SetSize(60);
	m_titre.SetColor(sf::Color(255,204,102));
	m_titre.SetPosition(100, 100);
	m_window->Draw(m_titre);*/
	
	this->declarationImages();
	m_sprite_recolteur_joueur1.SetPosition(100,100);
	m_sprite_soldat_joueur1.SetPosition(200,100);
	m_sprite_base_joueur1.SetPosition(300,100);
	m_sprite_entrepot_joueur1.SetPosition(400,100);
	m_sprite_caserne_joueur1.SetPosition(500,100);
	m_window->Draw(m_sprite_recolteur_joueur1);
	m_window->Draw(m_sprite_soldat_joueur1);
	m_window->Draw(m_sprite_entrepot_joueur1);
	m_window->Draw(m_sprite_caserne_joueur1);
	
	m_window->Display();
}

bool GameView::treatEvents() 
{
	bool result = false;
	const sf::Input& input = m_window->GetInput();
	
	if(m_window->IsOpened()){
		result = true;
		sf::Event event;
		while (m_window->GetEvent(event)) 
		{
			int mouse_x = input.GetMouseX();
			int mouse_y = input.GetMouseY();
			if ((event.Type == sf::Event::Closed) ||
				((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))) 
			{
				m_window->Close();
				result = false;
			}
		}
	}
	return result;
}
