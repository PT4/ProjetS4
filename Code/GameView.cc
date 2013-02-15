#include <cstdlib>
#include <iostream>
#include <sstream>
#include "GameView.h"
#include "GameModel.h"
#include "Constantes.h"

using namespace std;
using namespace sf;

// Constructeurs

GameView::GameView(int width, int height): m_width(width), m_height(height), m_menu(true), m_optionMenu(false)
{
	m_window = new RenderWindow(sf::VideoMode(width, height, 32), "BearCraft", sf::Style::Close);
	
	m_string_adresse_carte1 = "maps/MaitreDeLaColline.txt";
	m_string_adresse_carte2 = "maps/LesDeuxPasses.txt";
	
	//chargement de la police
	if (!m_font.LoadFromFile("images/TheKingsoftheHouse-Regular.ttf", 50))
	{
		cout << "Erreur lors du chargement de la police"<<endl;
	}
	// chargement des images
	else if (!m_image_base_joueur1.LoadFromFile("images/BaseJoueur1.png") ||
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
		 !m_image_rocher.LoadFromFile("images/rocher.png") ||
		 !m_image_titre.LoadFromFile("images/bearcraft.png") ||
		 !m_image_commencer.LoadFromFile("images/Commencer.png") ||
		 !m_image_nouvellePartie.LoadFromFile("images/NouvellePartie.png") ||
		 !m_image_quitter.LoadFromFile("images/Quitter.png"))
		 cout << "Erreur lors du chargement des images" << endl;
	
	this->declarationImages();
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

// Fonction de dessin
int GameView::convertString(string number)
{
	int ss;
	istringstream (number) >> ss;
	return ss;
}

// Déclaration des objets graphiques
void GameView::declarationImages() 
{
		m_sprite_herbe = Sprite(m_image_herbe);
		
		m_option.SetText(L"Option de la partie");
		m_option.SetFont(m_font);
		m_option.SetSize(60);
		m_option.SetColor(sf::Color(255,204,0));
		m_option.SetPosition(150,12);
		
		m_miniMap = sf::Shape::Rectangle(250, 100, 550, 400, sf::Color::Black, 3, sf::Color(102,102,102));
		
		m_nbJoueurs.SetText("Nombre de joueurs :");
		m_nbJoueurs.SetFont(m_font);
		m_nbJoueurs.SetSize(30);
		m_nbJoueurs.SetColor(sf::Color(255,204,0));
		m_nbJoueurs.SetPosition(50,400);
		
		m_nomCarte.SetText("Choix de la carte :");
		m_nomCarte.SetFont(m_font);
		m_nomCarte.SetSize(30);
		m_nomCarte.SetColor(sf::Color(255,204,0));
		m_nomCarte.SetPosition(50,500);
		
		m_string_joueur2.SetText("2");
		m_string_joueur2.SetPosition(250, 450);
		m_string_joueur2.SetFont(m_font);
		m_string_joueur2.SetSize(20);
		m_string_joueur2.SetColor(sf::Color::White);
		
		m_string_joueur3.SetText("3");
		m_string_joueur3.SetPosition(400, 450);
		m_string_joueur3.SetFont(m_font);
		m_string_joueur3.SetSize(20);
		m_string_joueur3.SetColor(sf::Color::White);
		
		m_string_joueur4.SetText("4");
		m_string_joueur4.SetPosition(550, 450);
		m_string_joueur4.SetFont(m_font);
		m_string_joueur4.SetSize(20);
		m_string_joueur4.SetColor(sf::Color::White);
		
		m_string_carte1.SetText("Maitre de la Colline");
		m_string_carte1.SetPosition(300, 550);
		m_string_carte1.SetFont(m_font);
		m_string_carte1.SetSize(20);
		m_string_carte1.SetColor(sf::Color::White);
		
		m_string_carte2.SetText("Les Deux Passes");
		m_string_carte2.SetPosition(300, 600);
		m_string_carte2.SetFont(m_font);
		m_string_carte2.SetSize(20);
		m_string_carte2.SetColor(sf::Color::White);
		
		m_sprite_commencer = Sprite(m_image_commencer);
		m_sprite_commencer.SetPosition(270,680);
		
		m_sprite_recolteur_joueur1 = Sprite(m_image_recolteur_joueur1);
		m_sprite_recolteur_joueur2 = Sprite(m_image_recolteur_joueur2);
		
		// Sprites
		m_sprite_base_joueur1 = Sprite(m_image_base_joueur1);
		m_sprite_base_joueur2 = Sprite(m_image_base_joueur2);
		m_sprite_caserne_joueur1 = Sprite(m_image_caserne_joueur1);
		m_sprite_caserne_joueur2 = Sprite(m_image_caserne_joueur2);
		m_sprite_entrepot_joueur1 = Sprite(m_image_entrepot_joueur1);
		m_sprite_entrepot_joueur2 = Sprite(m_image_entrepot_joueur2);
		m_sprite_soldat_joueur1 = Sprite(m_image_soldat_joueur1);
		m_sprite_soldat_joueur2 = Sprite(m_image_soldat_joueur2);
		m_sprite_bois = Sprite(m_image_bois);
		m_sprite_miel = Sprite(m_image_miel);
		m_sprite_rocher = Sprite(m_image_rocher);
		
		// Titre
		m_sprite_titre = Sprite(m_image_titre);
		m_sprite_titre.SetPosition(0, 0);
		
		m_sprite_nouvellePartie = Sprite (m_image_nouvellePartie);
		m_sprite_nouvellePartie.SetPosition(200, 400);
		
		m_sprite_quitter = Sprite (m_image_quitter);
		m_sprite_quitter.SetPosition(200, 600);
}

// Affichage de la carte avec les sprites
void GameView::affichageCarte(bool apercu)
{
	if (apercu)
		for (int i=0; i<TAILLE_MAP ; i++) {
			for (int j=0 ; j<TAILLE_MAP ; j++)
				switch (m_model->getPartie()->getCarte()->getCaseMatrice(j,i)) {
					case 0 :
						m_sprite_rocher.Resize(6,6);
						m_sprite_rocher.SetPosition(250+i*6,100+j*6);
						m_window->Draw(m_sprite_rocher);
						break;
					case 1 :
						m_sprite_bois.Resize(6,6);
						m_sprite_bois.SetPosition(250+i*6,100+j*6);
						m_window->Draw(m_sprite_bois);
						break;
					case 2 :
						m_sprite_miel.Resize(6,6);
						m_sprite_miel.SetPosition(250+i*6,100+j*6);
						m_window->Draw(m_sprite_miel);
						break;
					case 3 :
						m_sprite_base_joueur1.Resize(6,6);
						m_sprite_base_joueur1.SetPosition(250+i*6,100+j*6);
						m_window->Draw(m_sprite_base_joueur1);
						break;
					case 4 :
						m_sprite_herbe.Resize(6,6);
						m_sprite_herbe.SetPosition(250+i*6,100+j*6);
						m_window->Draw(m_sprite_herbe);
						break;
				}
		}
	
	else
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
						affichageBaseJoueur(i,j);
						break;
					case 4 :
						m_sprite_herbe.Resize(16,16);
						m_sprite_herbe.SetPosition(i*16,j*16);
						m_window->Draw(m_sprite_herbe);
						break;
				}
		}
		
}

void GameView::affichageBaseJoueur(int i, int j)
{
	for (int k=0; k<m_model->getPartie()->getListeJoueurs().size(); k++)
	{
		for (int l=0; l<m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments().size(); l++)
		{
			if(k==0 && j==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getI() && i==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getJ())
			{
				m_sprite_base_joueur1.Resize(16,16);
				m_sprite_base_joueur1.SetPosition(i*16,j*16);
				m_window->Draw(m_sprite_base_joueur1);
			}
			else if(k==1 && j==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getI() && i==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getJ())
			{
				m_sprite_base_joueur2.Resize(16,16);
				m_sprite_base_joueur2.SetPosition(i*16,j*16);
				m_window->Draw(m_sprite_base_joueur2);
			}
		}
	}
}

void GameView::affichageUnitesJoueur()
{
	for (int k=0; k<m_model->getPartie()->getListeJoueurs().size(); k++)
		for (int l=0; l<m_model->getPartie()->getListeJoueurs()[k]->getListeUnites().size(); l++)
			switch(k)
			{
				case 0:
					m_sprite_recolteur_joueur1.Resize(16,16);
					m_sprite_recolteur_joueur1.SetPosition(m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getJ()*16,m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getI()*16);
					m_window->Draw(m_sprite_recolteur_joueur1);
					break;
				case 1:
					m_sprite_recolteur_joueur2.Resize(16,16);
					m_sprite_recolteur_joueur2.SetPosition(m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getJ()*16,m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getI()*16);
					m_window->Draw(m_sprite_recolteur_joueur2);
					break;
			}
}

// Boucle d'affichage
void GameView::draw()
{
	if (m_menu) {
		m_window->Clear(sf::Color::Black);
		if (!m_optionMenu) {
			m_window->Draw(m_sprite_titre);
			m_window->Draw(m_sprite_nouvellePartie);
			m_window->Draw(m_sprite_quitter);
		}
		else if (m_optionMenu) {
			for (int i=0; i<TAILLE_MAP ; i++) 
				for (int j=0 ; j<TAILLE_MAP ; j++) {
					m_sprite_herbe.Resize(16,16);
					m_sprite_herbe.SetPosition(i*16,j*16);
					m_window->Draw(m_sprite_herbe);
			}
			m_window->Draw(m_miniMap);
			this->affichageCarte(true);
			m_window->Draw(m_option);
			
			m_window->Draw(m_nbJoueurs);
			m_window->Draw(m_string_joueur2);
			m_window->Draw(m_string_joueur3);
			m_window->Draw(m_string_joueur4);
			
			m_window->Draw(m_nomCarte);
			m_window->Draw(m_string_carte1);
			m_window->Draw(m_string_carte2);
			
			m_window->Draw(m_sprite_commencer);	
		}
	}
	else if (!m_menu) {
		m_window->Clear(sf::Color::Black);
		this->affichageCarte(false);
		this->affichageUnitesJoueur();
	}
	m_window->Display();
}

// Sélection des options de la partie
string GameView::selectionOptionMenu(sf::String selection)
{
	// Tests sur le nombre de joueurs
	if (selection.GetColor() == Color::White) {
		if ((((string)selection.GetText()).compare((string)m_string_joueur2.GetText()))==0) {
			m_string_joueur2.SetColor(sf::Color(255,216,43));
			m_string_joueur3.SetColor(sf::Color::White);
			m_string_joueur4.SetColor(sf::Color::White);
		}
		else if ((((string)selection.GetText()).compare((string)m_string_joueur3.GetText()))==0) {
			m_string_joueur3.SetColor(sf::Color(255,216,43));
			m_string_joueur2.SetColor(sf::Color::White);
			m_string_joueur4.SetColor(sf::Color::White);
		}
		else if ((((string)selection.GetText()).compare((string)m_string_joueur4.GetText()))==0) {
			m_string_joueur4.SetColor(sf::Color(255,216,43));
			m_string_joueur3.SetColor(sf::Color::White);
			m_string_joueur2.SetColor(sf::Color::White);
		}
	
		// Tests sur le nom de la carte
		else if ((((string)selection.GetText()).compare((string)m_string_carte1.GetText()))==0) {
			m_string_carte1.SetColor(sf::Color(255,216,43));
			m_string_carte2.SetColor(sf::Color::White);
		}
		else if ((((string)selection.GetText()).compare((string)m_string_carte2.GetText()))==0) {
			m_string_carte2.SetColor(sf::Color(255,216,43));
			m_string_carte1.SetColor(sf::Color::White);
		}
	}
	return selection.GetText();
}


// Traitement des evenements
bool GameView::treatEvents() 
{
	bool result = false;
	const sf::Input& input = m_window->GetInput();
	//this->declarationImages();
	
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
			
			if (m_menu && !m_optionMenu) {
				// Bouton nouvelle partie
				if (mouse_x >= 200 && mouse_x <= 580 && mouse_y >= 400 && mouse_y <= 530)
				{
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
						m_optionMenu = true;
				}
				// Bouton quitter
				else if (mouse_x >= 200 && mouse_x <= 578 && mouse_y >= 600 && mouse_y <= 723)
				{
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left) 
					{
						m_window->Close();
						result = false;
					}
				}
			}
			
			else if (m_menu && m_optionMenu) {
				int nbJoueurs=1;
				string carte="";
			// Gestion des clics du nombre de joueur
				if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left) {
					if (mouse_x >= 250 && mouse_x <= 270 && mouse_y >= 450 && mouse_y <= 470)
							nbJoueurs = convertString(selectionOptionMenu(m_string_joueur2));
					else if (mouse_x >= 400 && mouse_x <= 420 && mouse_y >= 450 && mouse_y <= 470)
							nbJoueurs = convertString(selectionOptionMenu(m_string_joueur3));
					else if (mouse_x >= 550 && mouse_x <= 570 && mouse_y >= 450 && mouse_y <= 470)
							nbJoueurs = convertString(selectionOptionMenu(m_string_joueur4));
					else if (mouse_x >= 300 && mouse_x <= 420 && mouse_y >= 550 && mouse_y <= 570) {
							carte = (selectionOptionMenu(m_string_carte1));
							carte = m_string_adresse_carte1;
						}
					else if (mouse_x >= 300 && mouse_x <= 570 && mouse_y >= 600 && mouse_y <= 620) {
							carte = (selectionOptionMenu(m_string_carte2));
							carte = m_string_adresse_carte2;
						}
			// Gestion du clic sur le bouton commencer
					else if (mouse_x >= 270 && mouse_x <= 539 && mouse_y >= 680 && mouse_y <= 769) {
							m_menu = false;
					}
				}
			}
		}
	}
	return result;
}
