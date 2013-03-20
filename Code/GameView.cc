#include "GameView.h"
#include "GameModel.h"
#include "Constantes.h"
#include "Partie.h"
#include "Joueur.h"
#include "Batiment.h"
#include "Unite.h"
#include "Carte.h"

#include <cstdlib>
#include <sstream>
#include <iostream>


using namespace std;
using namespace sf;

// Constructeurs

GameView::GameView(int width, int height): m_width(width), m_height(height), m_menu(true), m_optionMenu(false), m_selectionApercuCarte(0)
{
	m_window = new RenderWindow(sf::VideoMode(width, height, 32), "BearCraft", sf::Style::Close);
	m_ecranJeu.SetFromRect(sf::FloatRect(0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE));

	m_thread = false;

	m_clic=false;
	m_clicX = 0;
	m_clicY = 0;
	m_clicTempX=0;
	m_clicTempY=0;

    m_selectionNbJoueurs = 1;
    m_selectionCarte = "";

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
		 !m_image_base_joueur3.LoadFromFile("images/BaseJoueur3.png") ||
		 !m_image_base_joueur4.LoadFromFile("images/BaseJoueur4.png") ||
		 !m_image_caserne_joueur1.LoadFromFile("images/CaserneJoueur1.png") ||
		 !m_image_caserne_joueur2.LoadFromFile("images/CaserneJoueur2.png") ||
		 !m_image_caserne_joueur3.LoadFromFile("images/CaserneJoueur3.png") ||
		 !m_image_caserne_joueur4.LoadFromFile("images/CaserneJoueur4.png") ||
		 !m_image_entrepot_joueur1.LoadFromFile("images/EntrepotJoueur1.png") ||
		 !m_image_entrepot_joueur2.LoadFromFile("images/EntrepotJoueur2.png") ||
		 !m_image_entrepot_joueur3.LoadFromFile("images/EntrepotJoueur3.png") ||
		 !m_image_entrepot_joueur4.LoadFromFile("images/EntrepotJoueur4.png") ||
		 !m_image_recolteur_joueur1.LoadFromFile("images/RecolteurJoueur1.png") ||
		 !m_image_recolteur_joueur2.LoadFromFile("images/RecolteurJoueur2.png") ||
		 !m_image_recolteur_joueur3.LoadFromFile("images/RecolteurJoueur3.png") ||
		 !m_image_recolteur_joueur4.LoadFromFile("images/RecolteurJoueur4.png") ||
		 !m_image_soldat_joueur1.LoadFromFile("images/soldatJoueur1.png") ||
		 !m_image_soldat_joueur2.LoadFromFile("images/soldatJoueur2.png") ||
		 !m_image_soldat_joueur3.LoadFromFile("images/soldatJoueur3.png") ||
		 !m_image_soldat_joueur4.LoadFromFile("images/soldatJoueur4.png") ||
		 !m_image_bois.LoadFromFile("images/bois.png") ||
		 !m_image_miel.LoadFromFile("images/miel.png") ||
		 !m_image_herbe.LoadFromFile("images/herbe.png") ||
		 !m_image_rocher.LoadFromFile("images/rocher.png") ||
		 !m_image_titre.LoadFromFile("images/bearcraft.png") ||
		 !m_image_commencer.LoadFromFile("images/Commencer.png") ||
		 !m_image_nouvellePartie.LoadFromFile("images/NouvellePartie.png") ||
		 !m_image_quitter.LoadFromFile("images/Quitter.png") ||
		 !m_image_apercuVide.LoadFromFile("images/apercuVierge.png") ||
		 !m_image_apercuMC.LoadFromFile("images/apercuMaitreCollines.png") ||
		 !m_image_apercuDP.LoadFromFile("images/apercuDeuxPasses.png"))
		 cout << "Erreur lors du chargement des images" << endl;

	this->declarationImages();
	
}

// Destructeur
GameView::~GameView()
{
	m_thread = false;
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
		m_sprite_apercuVide = Sprite(m_image_apercuVide);
		m_sprite_apercuMC = Sprite(m_image_apercuMC);
		m_sprite_apercuDP = Sprite(m_image_apercuDP);

		m_sprite_apercuVide.SetPosition(400, 100);
		m_sprite_apercuMC.SetPosition(400, 100);
		m_sprite_apercuDP.SetPosition(400, 100);
		
		m_option.SetText(L"Option de la partie");
		m_option.SetFont(m_font);
		m_option.SetSize(60);
		m_option.SetColor(sf::Color(255,204,0));
		m_option.SetPosition(250,12);

		m_nbJoueurs.SetText("Nombre de joueurs :");
		m_nbJoueurs.SetFont(m_font);
		m_nbJoueurs.SetSize(30);
		m_nbJoueurs.SetColor(sf::Color(255,204,0));
		m_nbJoueurs.SetPosition(150,400);

		m_nomCarte.SetText("Choix de la carte :");
		m_nomCarte.SetFont(m_font);
		m_nomCarte.SetSize(30);
		m_nomCarte.SetColor(sf::Color(255,204,0));
		m_nomCarte.SetPosition(150,500);

		m_string_joueur2.SetText("2");
		m_string_joueur2.SetPosition(350, 450);
		m_string_joueur2.SetFont(m_font);
		m_string_joueur2.SetSize(20);
		m_string_joueur2.SetColor(sf::Color::White);

		m_string_joueur3.SetText("3");
		m_string_joueur3.SetPosition(500, 450);
		m_string_joueur3.SetFont(m_font);
		m_string_joueur3.SetSize(20);
		m_string_joueur3.SetColor(sf::Color::White);

		m_string_joueur4.SetText("4");
		m_string_joueur4.SetPosition(650, 450);
		m_string_joueur4.SetFont(m_font);
		m_string_joueur4.SetSize(20);
		m_string_joueur4.SetColor(sf::Color::White);

		m_string_carte1.SetText("Maitre de la Colline");
		m_string_carte1.SetPosition(400, 550);
		m_string_carte1.SetFont(m_font);
		m_string_carte1.SetSize(20);
		m_string_carte1.SetColor(sf::Color::White);

		m_string_carte2.SetText("Les Deux Passes");
		m_string_carte2.SetPosition(400, 600);
		m_string_carte2.SetFont(m_font);
		m_string_carte2.SetSize(20);
		m_string_carte2.SetColor(sf::Color::White);

		m_sprite_commencer = Sprite(m_image_commencer);
		m_sprite_commencer.SetPosition(370,680);

		m_sprite_recolteur_joueur1 = Sprite(m_image_recolteur_joueur1);
		m_sprite_recolteur_joueur2 = Sprite(m_image_recolteur_joueur2);
		m_sprite_recolteur_joueur3 = Sprite(m_image_recolteur_joueur3);
		m_sprite_recolteur_joueur4 = Sprite(m_image_recolteur_joueur4);

		// Sprites
		m_sprite_base_joueur1 = Sprite(m_image_base_joueur1);
		m_sprite_base_joueur2 = Sprite(m_image_base_joueur2);
		m_sprite_base_joueur3 = Sprite(m_image_base_joueur3);
		m_sprite_base_joueur4 = Sprite(m_image_base_joueur4);
		m_sprite_caserne_joueur1 = Sprite(m_image_caserne_joueur1);
		m_sprite_caserne_joueur2 = Sprite(m_image_caserne_joueur2);
		m_sprite_caserne_joueur3 = Sprite(m_image_caserne_joueur3);
		m_sprite_caserne_joueur4 = Sprite(m_image_caserne_joueur4);
		m_sprite_entrepot_joueur1 = Sprite(m_image_entrepot_joueur1);
		m_sprite_entrepot_joueur2 = Sprite(m_image_entrepot_joueur2);
		m_sprite_entrepot_joueur3 = Sprite(m_image_entrepot_joueur3);
		m_sprite_entrepot_joueur4 = Sprite(m_image_entrepot_joueur4);
		m_sprite_soldat_joueur1 = Sprite(m_image_soldat_joueur1);
		m_sprite_soldat_joueur2 = Sprite(m_image_soldat_joueur2);
		m_sprite_soldat_joueur3 = Sprite(m_image_soldat_joueur3);
		m_sprite_soldat_joueur4 = Sprite(m_image_soldat_joueur4);
		m_sprite_bois = Sprite(m_image_bois);
		m_sprite_miel = Sprite(m_image_miel);
		m_sprite_rocher = Sprite(m_image_rocher);
		
		m_barreInfo = Shape::Rectangle(0, 0, 50, 200, Color(192,192,192));

		// Menu Titre
		m_sprite_titre = Sprite(m_image_titre);
		m_sprite_titre.Resize(1000,800);
		m_sprite_titre.SetPosition(0, 0);

		m_sprite_nouvellePartie = Sprite (m_image_nouvellePartie);
		m_sprite_nouvellePartie.SetPosition(300, 400);

		m_sprite_quitter = Sprite (m_image_quitter);
		m_sprite_quitter.SetPosition(300, 600);
		
}

// Affichage de la carte avec les sprites
void GameView::affichageCarte()
{
	for (int i=0; i<TAILLE_MAP ; i++) {
		for (int j=0 ; j<TAILLE_MAP ; j++)
			switch (m_model->getPartie()->getCarte()->getCaseMatrice(j,i)) {
				case 0 :
					m_sprite_rocher.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_rocher.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
					m_window->Draw(m_sprite_rocher);
					break;
				case 1 :
					m_sprite_bois.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_bois.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
					m_window->Draw(m_sprite_bois);
					break;
				case 2 :
					m_sprite_miel.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_miel.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
					m_window->Draw(m_sprite_miel);
					break;
				case 3 :
					affichageBaseJoueur(i,j);
					break;
				case 4 :
					m_sprite_herbe.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_herbe.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
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
				m_sprite_base_joueur1.Resize(TAILLE_CASE,TAILLE_CASE);
				m_sprite_base_joueur1.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
				m_window->Draw(m_sprite_base_joueur1);
			}
			else if(k==1 && j==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getI() && i==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getJ())
			{
				m_sprite_base_joueur2.Resize(TAILLE_CASE,TAILLE_CASE);
				m_sprite_base_joueur2.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
				m_window->Draw(m_sprite_base_joueur2);
			}
			else if(k==2 && j==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getI() && i==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getJ())
			{
				m_sprite_base_joueur3.Resize(TAILLE_CASE,TAILLE_CASE);
				m_sprite_base_joueur3.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
				m_window->Draw(m_sprite_base_joueur3);
			}
			else if(k==3 && j==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getI() && i==m_model->getPartie()->getListeJoueurs()[k]->getListeBatiments()[l]->getJ())
			{
				m_sprite_base_joueur4.Resize(TAILLE_CASE,TAILLE_CASE);
				m_sprite_base_joueur4.SetPosition(i*TAILLE_CASE,j*TAILLE_CASE);
				m_window->Draw(m_sprite_base_joueur4);
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
					m_sprite_recolteur_joueur1.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_recolteur_joueur1.SetPosition(m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getJ()*TAILLE_CASE,m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getI()*TAILLE_CASE);
					m_window->Draw(m_sprite_recolteur_joueur1);
					break;
				case 1:
					m_sprite_recolteur_joueur2.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_recolteur_joueur2.SetPosition(m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getJ()*TAILLE_CASE,m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getI()*TAILLE_CASE);
					m_window->Draw(m_sprite_recolteur_joueur2);
					break;
				case 2:
					m_sprite_recolteur_joueur3.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_recolteur_joueur3.SetPosition(m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getJ()*TAILLE_CASE,m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getI()*TAILLE_CASE);
					m_window->Draw(m_sprite_recolteur_joueur3);
					break;
				case 3:
					m_sprite_recolteur_joueur4.Resize(TAILLE_CASE,TAILLE_CASE);
					m_sprite_recolteur_joueur4.SetPosition(m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getJ()*TAILLE_CASE,m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[l]->getI()*TAILLE_CASE);
					m_window->Draw(m_sprite_recolteur_joueur4);
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
					m_sprite_herbe.Resize(20,16);
					m_sprite_herbe.SetPosition(i*20,j*16);
					m_window->Draw(m_sprite_herbe);
				}
			m_window->Draw(m_option);
			
			switch (m_selectionApercuCarte) {
				case 0 : 
					m_window->Draw(m_sprite_apercuVide);
					break;
				case 1 :	
					m_window->Draw(m_sprite_apercuMC);
					break;
				case 2 :
					m_window->Draw(m_sprite_apercuDP);
					break;
			}

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
		this->affichageCarte();
		this->affichageUnitesJoueur();
		m_window->Draw(m_selection);
		m_barreInfo.SetPosition(m_ecranJeu.GetCenter().x+75,m_ecranJeu.GetCenter().y-100);
		if (m_clic==true)
		{
			Shape selection=Shape::Rectangle(m_clicX, m_clicY, m_clicTempX, m_clicTempY, sf::Color::Black, .5f, sf::Color::Black);
			selection.EnableFill(false);
			m_window -> Draw(selection);
		}
		m_window -> Draw (m_barreInfo);
	}
	m_window->Display();
}

// Sélection des options de la partie
string GameView::selectionOptionMenu(sf::String selection)
{
	// Tests sur le nombre de joueurs
	if (selection.GetColor() != Color(255,216,43)) {
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
			bool LeftButtonDown = input.IsMouseButtonDown(sf::Mouse::Left);
			if ((event.Type == sf::Event::Closed) ||
				((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape)))
			{
				m_window->Close();
				result = false;
			}

			if (m_menu && !m_optionMenu) {
				// Bouton nouvelle partie
				if (mouse_x >= 300 && mouse_x <= 680 && mouse_y >= 400 && mouse_y <= 530)
				{
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
						m_optionMenu = true;
				}
				// Bouton quitter
				else if (mouse_x >= 300 && mouse_x <= 678 && mouse_y >= 600 && mouse_y <= 723)
				{
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
					{
						m_window->Close();
						result = false;
					}
				}
			}

			else if (m_menu && m_optionMenu) {


			// Gestion des clics du nombre de joueur
				if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left) {
					if (mouse_x >= 350 && mouse_x <= 370 && mouse_y >= 450 && mouse_y <= 470)
							m_selectionNbJoueurs = convertString(selectionOptionMenu(m_string_joueur2));
					else if (mouse_x >= 500 && mouse_x <= 520 && mouse_y >= 450 && mouse_y <= 470)
							m_selectionNbJoueurs = convertString(selectionOptionMenu(m_string_joueur3));
					else if (mouse_x >= 650 && mouse_x <= 670 && mouse_y >= 450 && mouse_y <= 470)
							m_selectionNbJoueurs = convertString(selectionOptionMenu(m_string_joueur4));
					else if (mouse_x >= 400 && mouse_x <= 580 && mouse_y >= 550 && mouse_y <= 570) {
							m_selectionCarte = (selectionOptionMenu(m_string_carte1));
							m_selectionCarte = m_string_adresse_carte1;
							m_selectionApercuCarte = 1;
					}
					else if (mouse_x >= 400 && mouse_x <= 570 && mouse_y >= 600 && mouse_y <= 620) {
							m_selectionCarte = (selectionOptionMenu(m_string_carte2));
							m_selectionCarte = m_string_adresse_carte2;
							m_selectionApercuCarte = 2;
					}
			// Gestion du clic sur le bouton commencer
					else if (mouse_x >= 370 && mouse_x <= 639 && mouse_y >= 680 && mouse_y <= 769) {
                        verificationInformations();
					}
				}
			}
			if (!m_menu)
			{
				// Déplacement de la vue sur la map
				if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Z) || (event.Key.Code == sf::Key::Up))) {
					if (m_ecranJeu.GetCenter().y > 100)
						m_ecranJeu.Move(0, -10);
				}
				else if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::S) || (event.Key.Code == sf::Key::Down))) {
					if (m_ecranJeu.GetCenter().y < 700)
						m_ecranJeu.Move(0, 10);
				}
				else if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::D) || (event.Key.Code == sf::Key::Right))) {
					if (m_ecranJeu.GetCenter().x < 720)
						m_ecranJeu.Move(10, 0);
					else if (m_ecranJeu.GetCenter().x <= 670 && m_ecranJeu.GetCenter().x > 680)
						m_ecranJeu.SetCenter(675, m_ecranJeu.GetCenter().y);
				}
				else if ((event.Type == sf::Event::KeyPressed) && ((event.Key.Code == sf::Key::Q) || (event.Key.Code == sf::Key::Left))) {
					if (m_ecranJeu.GetCenter().x > 130)
						m_ecranJeu.Move(-10, 0);
					else if (m_ecranJeu.GetCenter().x <= 130 && m_ecranJeu.GetCenter().x > 120)
						m_ecranJeu.SetCenter(125, m_ecranJeu.GetCenter().y);
				}
				
				// Sélection des unités avec un clic
				if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left) {
					//~ selectionUnites(mouse_x,mouse_y);
					//~ for (int i=0, i<m_model->getPartie()->getListeJoueurs()[0]->getListeUnites().size(); i++)
						//~ if (m_model->getPartie()->getListeJoueurs()[k]->getListeUnites()[i]->getJ() < 
					cout << (((mouse_x/ZOOM_FENETRE)+m_ecranJeu.GetCenter().x)/TAILLE_CASE)-8 << " " << ((mouse_y/ZOOM_FENETRE+m_ecranJeu.GetCenter().y)/TAILLE_CASE)-6 << endl;
				}

				if (LeftButtonDown)
				{
					m_clic = true;
					if (m_clicX ==0 && m_clicY == 0)
					{
						m_model -> getPartie() -> getListeJoueurs()[0] -> viderSelection();
						m_clicX = clicToZoomArene(mouse_x, false);
						m_clicY = clicToZoomArene(mouse_y, true);
					}
					m_clicTempX = clicToZoomArene(mouse_x, false);
					m_clicTempY = clicToZoomArene(mouse_y, true);
				}
			
				else if (!LeftButtonDown && m_clic == true)
				{
					m_model -> getPartie() -> getListeJoueurs()[0] -> remplirSelection(m_clicX/TAILLE_CASE,m_clicY/TAILLE_CASE,m_clicTempX/TAILLE_CASE,m_clicTempY/TAILLE_CASE);
					m_clic = false;
					m_clicX = 0;
					m_clicY = 0;
					m_clicTempX=0;
					m_clicTempY=0;
				}
				
			}
		}
	}
	return result;
}

//Verification lors du clic sur "commencer" si toute les infos sont valident

void GameView::verificationInformations()
{
    if (m_selectionNbJoueurs > 1 && m_selectionCarte != "")
    {
		m_thread= true;
		DoSomething();
        m_menu = false;
        m_model -> creerPartie (m_selectionNbJoueurs,m_selectionCarte);
        m_window->SetView(m_ecranJeu);
        
        if (m_model->getPartie()->getListeJoueurs()[0]->getListeBatiments()[0]->getJ() == 3) {
			if (m_model->getPartie()->getListeJoueurs()[0]->getListeBatiments()[0]->getI() == 3)
				m_ecranJeu.SetCenter(125,100);
			else if (m_model->getPartie()->getListeJoueurs()[0]->getListeBatiments()[0]->getI() == 46)
				m_ecranJeu.SetCenter(125,700);
		}
		else if (m_model->getPartie()->getListeJoueurs()[0]->getListeBatiments()[0]->getJ() == 46) {
			if (m_model->getPartie()->getListeJoueurs()[0]->getListeBatiments()[0]->getI() == 3)
				m_ecranJeu.SetCenter(725,100);
			else if (m_model->getPartie()->getListeJoueurs()[0]->getListeBatiments()[0]->getI() == 46)
				m_ecranJeu.SetCenter(725,700);
		}
		
        m_ecranJeu.Zoom(ZOOM_FENETRE);
    }
    
    if (m_selectionNbJoueurs == 1)
    {
		m_string_joueur4.SetColor(sf::Color::Red);
		m_string_joueur3.SetColor(sf::Color::Red);
		m_string_joueur2.SetColor(sf::Color::Red);
	}
	
	if (m_selectionCarte == "")
	{
		m_string_carte1.SetColor(sf::Color::Red);
		m_string_carte2.SetColor(sf::Color::Red);
	}
}

int GameView::clicToZoomArene(float coord, bool coordVertical) {
	int coordZoomArene;
	
	if (!coordVertical)
		coordZoomArene = (coord/ZOOM_FENETRE) + m_ecranJeu.GetRect().Left;
	else
		coordZoomArene = (coord/ZOOM_FENETRE) + m_ecranJeu.GetRect().Top;
		
	return coordZoomArene;
}

void GameView::selectionUnites(int selectionDebutX, int selectionUnitesY) {
	const sf::Input& input = m_window->GetInput();

	sf::Event event;
	int mouse_x = input.GetMouseX();
	int mouse_y = input.GetMouseY();
	do {
		cout << "Coucou Emiles while clic enfoncé" << endl;
		m_selection = Shape::Rectangle(selectionDebutX/ZOOM_FENETRE, selectionUnitesY/ZOOM_FENETRE, mouse_x/ZOOM_FENETRE, mouse_y/ZOOM_FENETRE, Color(192,192,192));
	} while (event.Type == Event::MouseButtonReleased && event.MouseButton.Button == Mouse::Left);
}

void GameView::afficheMiniMap()
{
	while (m_thread)
		cout << "MiniMap" << endl;
}


void GameView::Run()
{
   afficheMiniMap();
}

void GameView::DoSomething()
{
	Launch();
}
