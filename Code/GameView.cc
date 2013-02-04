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
	m_window = new RenderWindow(sf::VideoMode(width, height, 32), "AnimalsCraft", sf::Style::Close);
	
	// chargement des images
	
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

// Boucle d'affichage
void GameView::draw()
{
	m_window->Clear(sf::Color(37,38,35));
	
	m_titre.SetText(L"      BouboursTown \n Par Gaëtan Roudeau \n Emile Rey \n et Anthony Silverio");
	m_titre.SetSize(60);
	m_titre.SetColor(sf::Color(255,204,102));
	m_titre.SetPosition(100, 100);
	m_window->Draw(m_titre);
	
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
