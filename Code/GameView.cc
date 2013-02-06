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
	m_window = new RenderWindow(sf::VideoMode(width, height, 32), "BearCraft", sf::Style::Close);
	
	// chargement des images
	if (!m_image_base_joueur1.LoadFromFile("images/BaseJoueur1.png") ||
		 !m_image_base_joueur2.LoadFromFile("images/BaseJoueur2.png") ||
		 !m_image_caserne_joueur1.LoadFromFile("images/CaserneJoueur1.png") ||
		 !m_image_caserne_joueur2.LoadFromFile("images/CaserneJoueur2.png") ||
		 !m_image_entrepot_joueur1.LoadFromFile("images/EntrepotJoueur1.png") || 
		 !m_image_entrepot_joueur2.LoadFromFile("images/EntrepotJoueur2.png") ||
		 !m_image_recolteur_joueur1.LoadFromFile("images/RecolteurJoueur1.png") ||
		 !m_image_recolteur_joueur2.LoadFromFile("images/RecolteurJoueur2.png") ||
		 !m_image_soldat_joueur1.LoadFromFile("images/soldatJoueur1.png") ||
		 !m_image_soldat_joueur2.LoadFromFile("images/soldatJoueur2.png") ||
		 !m_image_bois.LoadFromFile("images/bois.png") ||
		 !m_image_miel.LoadFromFile("images/miel.png") ||
		 !m_image_herbe.LoadFromFile("images/herbe.png") ||
		 !m_image_rocher.LoadFromFile("images/rocher.png"))
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

// Déclaration des objets graphiques
void GameView::declarationImages() 
{
		// Sprites
		m_sprite_base_joueur1 = Sprite(m_image_base_joueur1);
		m_sprite_base_joueur2 = Sprite(m_image_base_joueur2);
		m_sprite_caserne_joueur1 = Sprite(m_image_caserne_joueur1);
		m_sprite_caserne_joueur2 = Sprite(m_image_caserne_joueur2);
		m_sprite_entrepot_joueur1 = Sprite(m_image_entrepot_joueur1);
		m_sprite_entrepot_joueur2 = Sprite(m_image_entrepot_joueur2);
		m_sprite_recolteur_joueur1 = Sprite(m_image_recolteur_joueur1);
		m_sprite_recolteur_joueur2 = Sprite(m_image_recolteur_joueur2);
		m_sprite_soldat_joueur1 = Sprite(m_image_soldat_joueur1);
		m_sprite_soldat_joueur2 = Sprite(m_image_soldat_joueur2);
		m_sprite_bois = Sprite(m_image_bois);
		m_sprite_herbe = Sprite(m_image_herbe);
		m_sprite_miel = Sprite(m_image_miel);
		m_sprite_rocher = Sprite(m_image_rocher);
		
		// Titre
		m_titre.SetText(L"      BouboursTown \n Par Gaëtan Roudeau \n Emile Rey \n et Anthony Silverio");
		m_titre.SetSize(60);
		m_titre.SetColor(sf::Color(255,204,102));
		m_titre.SetPosition(100, 100);
}

// Affichage de la carte avec les sprites
void GameView::affichageCarte()
{
	for (int i=0; i<TAILLE_MAP ; i++) {
		for (int j=0 ; j<TAILLE_MAP ; j++)
			switch (m_model->getPartie()->getCarte()->getCaseMatrice(j,i)) {
				case 0 :
					m_sprite_rocher.Resize(16,16);
					m_sprite_rocher.SetPosition(i*16,j*16);
					m_window->Draw(m_sprite_rocher);
					break;
				case 1 :
					m_sprite_bois.Resize(16,16);
					m_sprite_bois.SetPosition(i*16,j*16);
					m_window->Draw(m_sprite_bois);
					break;
				case 2 :
					m_sprite_miel.Resize(16,16);
					m_sprite_miel.SetPosition(i*16,j*16);
					m_window->Draw(m_sprite_miel);
					break;
				case 3 :
					m_sprite_base_joueur1.Resize(16,16);
					m_sprite_base_joueur1.SetPosition(i*16,j*16);
					m_window->Draw(m_sprite_base_joueur1);
					break;
				case 4 :
					m_sprite_herbe.Resize(16,16);
					m_sprite_herbe.SetPosition(i*16,j*16);
					m_window->Draw(m_sprite_herbe);
					break;
			}
	}
		
}

// Boucle d'affichage
void GameView::draw()
{
	m_window->Clear(sf::Color(37,38,35));
	this->declarationImages();
	this->affichageCarte();
	//m_window->Draw(m_titre);
	//m_sprite_herbe.SetPosition(600,400);
	//m_window->Draw(m_sprite_herbe);
	
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
