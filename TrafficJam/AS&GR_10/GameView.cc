#include <cstdlib>
#include <iostream>
#include <sstream>
#include "GameView.h"
#include "GameModel.h"
#include "Niveau.h"
#include "Constantes.h"
#include "Partie.h"

using namespace std;
using namespace sf;


// Constructeurs

GameView::GameView(int width, int height): m_width(width), m_height(height), m_menu(true), m_animation(true)
{
	m_window = new RenderWindow(sf::VideoMode(width, height, 32), "TrafficJam", sf::Style::Close);
	m_chargement.SetFromRect(sf::FloatRect(0, 0, width, height));
	m_interNiveau.SetFromRect(sf::FloatRect(0,0, width, height));
	
	if (!m_font.LoadFromFile("images/AlteHaasGroteskBold.ttf", 50))
	{
		cout << "Erreur lors du chargement de la police"<<endl;
	}
	else if (!m_image_logo_iut.LoadFromFile("images/logo.jpeg") ||
		 !m_image_bouton_jouer.LoadFromFile("images/bouton_jouer.png") ||
		 !m_image_bouton_highscore.LoadFromFile("images/bouton_highscore.png") ||
		 !m_image_bouton_quitter.LoadFromFile("images/bouton_quitter.png") ||
		 !m_image_h_police.LoadFromFile("images/hpolice.png") || 
		 !m_image_background.LoadFromFile("images/grass2.jpg") ||
		 !m_image_vRoute.LoadFromFile("images/vroad.jpg") ||
		 !m_image_hRoute.LoadFromFile("images/hroad.jpg") ||
		 !m_image_h_voiture.LoadFromFile("images/hcar.png") ||
		 !m_image_h_camion.LoadFromFile("images/hbus.png") ||
		 !m_image_v_police.LoadFromFile("images/vpolice.png") ||
		 !m_image_v_voiture.LoadFromFile("images/vcar.png") ||
		 !m_image_v_camion.LoadFromFile("images/vbus.png") ||
		 !m_image_croisement.LoadFromFile("images/crossroad.jpg") ||
		 !m_image_feu_rouge.LoadFromFile("images/redlight.jpg") ||
		 !m_image_feu_vert.LoadFromFile("images/greenlight.jpg") ||
		 !m_image_ligne.LoadFromFile("images/lightline.jpg") ||
		 !m_image_explosion.LoadFromFile("images/explosion.png"))
	{	
		cout << "Erreur lors du chargement du menu" <<endl;
	}
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

bool GameView::getMenu(GameView * view) const
{
	return m_menu;
}

// Fonction de dessin
string GameView::convertInt(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

void GameView::ecranChargement()
{
	m_window->Clear(sf::Color(37,38,35));
	m_window->Draw (m_intro);
	m_window->Draw (m_sprite_logo_iut);
	
	m_window->SetView(m_chargement);
	m_window->Display();
}

void GameView::ecranInterNiveau()
{
	Event event;
	m_window->Clear(sf::Color(37,38,35));
	if (m_model->getPartie()->getNiveau()->getNbVehiculesPasses() == m_model->getPartie()->getNiveau()->getObjectif())
	{
		m_texte_gagne = "       Niveau Suivant \n\n               " + convertInt(5-horloge.GetElapsedTime());
		m_texte_interNiveau_gagne.SetText(m_texte_gagne);
		m_window->Draw(m_texte_interNiveau_gagne);
	}
	else if (m_model->getPartie()->getNiveau()->getNbVehiculePresent() == m_model->getPartie()->getNiveau()->getTrafficAutorise()
			|| m_model->getPartie()->getNiveau()->getCollision())
	{
		m_texte_perdu = "             Perdu \n\n                 " + convertInt(5-horloge.GetElapsedTime());
		m_texte_interNiveau_perdu.SetText(m_texte_perdu);
		m_window->Draw(m_texte_interNiveau_perdu);
	}
	m_window->SetView(m_interNiveau);
	m_window->Display();
}
	
void GameView::declarationImages()
{
	if (m_menu)
	{
		m_intro.SetText(L"         TrafficJam \n Par Gaëtan Roudeau \n et Anthony Silverio");
		m_intro.SetFont(m_font);
		m_intro.SetSize(60);
		m_intro.SetColor(sf::Color(255,204,102));
		m_intro.SetPosition(100, 100);
		
		m_sprite_logo_iut = Sprite (m_image_logo_iut);
		m_sprite_logo_iut.Resize(125, 100);
		m_sprite_logo_iut.SetPosition(350, 400); 
		
		m_sprite_h_police = Sprite (m_image_h_police);
		m_sprite_h_police.Rotate(45);
		m_sprite_h_police.Resize(300,120);
		m_sprite_h_police.SetPosition(100,400);
		
		m_titre.SetText(L"TrafficJam");
		m_titre.SetFont(m_font);
		m_titre.SetSize(50);
		m_titre.SetColor(sf::Color(255,204,102));
		m_titre.SetPosition(275,50);
		m_titre.SetStyle(sf::String::Underlined);
		
		m_sprite_bouton_jouer = Sprite (m_image_bouton_jouer);
		m_sprite_bouton_jouer.Resize(TAILLE_LARGEUR_BOUTON , TAILLE_HAUTEUR_BOUTON);
		m_sprite_bouton_jouer.SetPosition(500,225);
		m_sprite_bouton_highscore = Sprite (m_image_bouton_highscore);
		m_sprite_bouton_highscore.Resize(TAILLE_LARGEUR_BOUTON , TAILLE_HAUTEUR_BOUTON);
		m_sprite_bouton_highscore.SetPosition(500,325);
		m_sprite_bouton_quitter = Sprite (m_image_bouton_quitter);
		m_sprite_bouton_quitter.Resize(TAILLE_LARGEUR_BOUTON , TAILLE_HAUTEUR_BOUTON);
		m_sprite_bouton_quitter.SetPosition(500,425);
		
		m_sprite_bouton_jouer_agrandi = Sprite (m_image_bouton_jouer_agrandi);
		m_sprite_bouton_jouer_agrandi.Resize(TAILLE_LARGEUR_BOUTON , TAILLE_HAUTEUR_BOUTON);
		m_sprite_bouton_jouer_agrandi.SetPosition(500,225);
		m_sprite_bouton_highscore_agrandi = Sprite (m_image_bouton_highscore_agrandi);
		m_sprite_bouton_highscore_agrandi.Resize(TAILLE_LARGEUR_BOUTON , TAILLE_HAUTEUR_BOUTON);
		m_sprite_bouton_highscore_agrandi.SetPosition(500,325);
		m_sprite_bouton_quitter_agrandi = Sprite (m_image_bouton_quitter_agrandi);
		m_sprite_bouton_quitter_agrandi.Resize(TAILLE_LARGEUR_BOUTON , TAILLE_HAUTEUR_BOUTON);
		m_sprite_bouton_quitter_agrandi.SetPosition(500,425);
	}
	else if (!m_menu && !m_animation)
	{
		// Ecran Inter-Niveau
		m_texte_interNiveau_gagne.SetFont(m_font);
		m_texte_interNiveau_gagne.SetSize(60);
		m_texte_interNiveau_gagne.SetColor(sf::Color(255,204,102));
		m_texte_interNiveau_gagne.SetPosition(100, 100);
		
		m_texte_interNiveau_perdu.SetFont(m_font);
		m_texte_interNiveau_perdu.SetSize(60);
		m_texte_interNiveau_perdu.SetColor(sf::Color(255,204,102));
		m_texte_interNiveau_perdu.SetPosition(100, 100);
		
		// Ecran de jeux regroupant le fond, les routes, les croisements, les voitures
		m_sprite_background = Sprite (m_image_background);
		m_sprite_background.Resize(m_width, m_height);
		m_sprite_background.SetPosition(0,0);
		
		m_sprite_vRoute = Sprite (m_image_vRoute);
		m_sprite_vRoute.Resize(TAILLE_ROUTE, m_height - TAILLE_BARRE_PARTIE);
		
		m_sprite_hRoute = Sprite (m_image_hRoute);
		m_sprite_hRoute.Resize(m_width, TAILLE_ROUTE);
		
		m_sprite_croisement = Sprite (m_image_croisement);
		
		m_sprite_h_voiture = Sprite (m_image_h_voiture);
		m_sprite_h_voiture.Resize(TAILLE_LONGUEUR_VOITURE_ET_POLICE, TAILLE_LARGEUR_VOITURE_ET_POLICE);
		m_sprite_v_voiture = Sprite (m_image_v_voiture);
		m_sprite_v_voiture.Resize(TAILLE_LARGEUR_VOITURE_ET_POLICE, TAILLE_LONGUEUR_VOITURE_ET_POLICE);
		
		m_sprite_h_camion = Sprite (m_image_h_camion);
		m_sprite_h_camion.Resize(TAILLE_LONGUEUR_CAMION, TAILLE_LARGEUR_CAMION);
		m_sprite_v_camion = Sprite (m_image_v_camion);
		m_sprite_v_camion.Resize(TAILLE_LARGEUR_CAMION, TAILLE_LONGUEUR_CAMION);
		
		m_sprite_h_police = Sprite (m_image_h_police);
		m_sprite_h_police.Resize(TAILLE_LONGUEUR_VOITURE_ET_POLICE,TAILLE_LARGEUR_VOITURE_ET_POLICE);
		m_sprite_v_police = Sprite (m_image_v_police);
		m_sprite_v_police.Resize(TAILLE_LARGEUR_VOITURE_ET_POLICE,TAILLE_LONGUEUR_VOITURE_ET_POLICE);
		
		// Barre partie regroupant les infos
		m_barre_partie = sf::Shape::Rectangle(0, 560, 800, 600, sf::Color(0,0,0));

		int niveauCours = m_model->getPartie()->getNiveauEnCours();
		m_niveau = "Niveau : " + convertInt(niveauCours);
		m_niveauEnCours = sf::String (m_niveau, m_font, 25);
		m_niveauEnCours.SetPosition(10,562);
		
		int objectifVoitures = m_model->getPartie()->getNiveau()->getObjectif();
		int nbVehiculesAtteint = m_model->getPartie()->getNiveau()->getNbVehiculesPasses();
		m_objectif = "Vehicules " + convertInt(nbVehiculesAtteint) + "/" + convertInt(objectifVoitures);
		m_nbVehiculesObjectif = sf::String (m_objectif, m_font, 25);
		m_nbVehiculesObjectif.SetPosition(140, 562);
		
		m_traffic = sf::String ("Traffic", m_font, 25);
		m_traffic.SetPosition(320, 562);
		m_barre_traffic = sf::Shape::Rectangle(410, 566, 590, 593, sf::Color::Black, 3, sf::Color::White);
		float traffic_actuel = 410 + (180 * m_model->getPartie()->getNiveau()->getNbVehiculePresent() / m_model->getPartie()->getNiveau()->getTrafficAutorise());
		m_barre_traffic_actuel = sf::Shape::Rectangle(410, 566, traffic_actuel, 593, sf::Color::Green);
		if (traffic_actuel >= 469 && traffic_actuel < 528)
			m_barre_traffic_actuel = sf::Shape::Rectangle(410, 566, traffic_actuel, 593, sf::Color(205, 102, 0));
		else if (traffic_actuel >= 528)
			m_barre_traffic_actuel = sf::Shape::Rectangle(410, 566, traffic_actuel, 593, sf::Color::Red);
		
		int scoreActu = m_model->getPartie()->getScore();
		m_score = "Score : " + convertInt(scoreActu) + " pts" ;
		m_scoreActuel = sf::String (m_score, m_font, 25);
		m_scoreActuel.SetPosition(620 ,562);
	}
}

void GameView::draw()
{
	if (m_menu && m_animation)
	{
		while (horloge.GetElapsedTime() < 2.f)
			ecranChargement();
		m_animation = false;
		m_window->SetView(m_window->GetDefaultView());
	}
	
	else if (m_menu && !m_animation)
	{
		m_window->Clear(sf::Color(37,38,35));
		m_window->Draw (m_sprite_h_police);
		m_window->Draw (m_titre);
		m_window->Draw (m_sprite_bouton_jouer);
		m_window->Draw (m_sprite_bouton_highscore);
		m_window->Draw (m_sprite_bouton_quitter);
		m_window->Display();
	}
	
	else if (!m_menu && !m_animation)
	{
		m_window->Draw (m_sprite_background);
		this->affichageEcran();
		m_window->Draw(m_barre_partie);
		m_window->Draw(m_niveauEnCours);
		m_window->Draw(m_nbVehiculesObjectif);
		m_window->Draw(m_traffic);
		m_window->Draw(m_barre_traffic);
		m_window->Draw(m_barre_traffic_actuel);
		m_window->Draw(m_scoreActuel);
		if (m_model->getPartie()->getNiveau()->getNbVehiculePresent() == m_model->getPartie()->getNiveau()->getTrafficAutorise()
			|| m_model->getPartie()->getNiveau()->getNbVehiculesPasses() == m_model->getPartie()->getNiveau()->getObjectif())
		{
			m_animation = true;
		}
		m_window->Display();
	}
	
	else if (!m_menu && m_animation)
	{
		horloge.Reset();
		while (horloge.GetElapsedTime() < 5.f)
			ecranInterNiveau();
		m_animation = false;
		m_window->SetView(m_window->GetDefaultView());
		if (m_model->getPartie()->getNiveau()->getNbVehiculePresent() == m_model->getPartie()->getNiveau()->getTrafficAutorise()
			|| m_model->getPartie()->getNiveau()->getCollision())
		{
			m_model->getPartie()->supprimerNiveau();
			m_model->getPartie()->setNiveauEnCours(m_model->getPartie()->getNiveauEnCours());
			m_model->getPartie()->genererNiveau();
		}
		else if (m_model->getPartie()->getNiveau()->getNbVehiculesPasses() == m_model->getPartie()->getNiveau()->getObjectif())
		{
			m_model->getPartie()->supprimerNiveau();
			m_model->getPartie()->setNiveauEnCours(m_model->getPartie()->getNiveauEnCours()+1);
			m_model->getPartie()->genererNiveau();
		}
	}
	usleep(500);
}

void GameView::affichageBoutons(bool agrandi)
{
	if (!agrandi)
	{
		m_window->Draw(m_sprite_bouton_jouer);
		m_window->Draw(m_sprite_bouton_highscore);
		m_window->Draw(m_sprite_bouton_quitter);
	}
	else 
	{
		m_window->Draw(m_sprite_bouton_jouer_agrandi);
		m_window->Draw(m_sprite_bouton_highscore_agrandi);
		m_window->Draw(m_sprite_bouton_quitter_agrandi);
	}
}

void GameView::affichageEcran()
{
		for (int i=0; i<m_model->getPartie()->getRoutes().size();i++)
			{
				if (m_model->getPartie()->getRoutes()[i]->getSens())
				{
					m_sprite_vRoute.SetPosition(m_model->getPartie()->getRoutes()[i]->getPositionX(),0);
					m_window->Draw (m_sprite_vRoute);
					
				}
				else
				{
					m_sprite_hRoute.SetPosition(0,m_model->getPartie()->getRoutes()[i]->getPositionY());
					m_window->Draw (m_sprite_hRoute);
					
				}
			}
		for (int i=0; i<m_model->getPartie()->getRoutes().size();i++)
		{
			affichageCroisement(i);
		}
		for (int i=0; i<m_model->getPartie()->getRoutes().size() ; i++)
		{
			for (int j=0 ; j<m_model->getPartie()->getRoutes()[i]->getListeDeVehicules().size() ; j++)
			{
				switch (m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getVitesse())
				{
					case 1 :
					{
						if (!m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getSens())
						{
							m_sprite_h_camion.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX(),
									    m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY());
							m_window->Draw(m_sprite_h_camion);
						}
						else if (m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getSens())
						{
							m_sprite_v_camion.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX(),
									    m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY());
							m_window->Draw(m_sprite_v_camion);
						}
						break;
					}
					case 2 :
					{
						if (!m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getSens())
						{
							m_sprite_h_voiture.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX(),
									    m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY());
							m_window->Draw(m_sprite_h_voiture);
						}
						else if (m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getSens())
						{
							m_sprite_v_voiture.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX(),
									    m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY());
							m_window->Draw(m_sprite_v_voiture);
						}
						break;
					}
					case 3 :
					{
						if (!m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getSens())
						{
							m_sprite_h_police.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX(),
									    m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY());
							m_window->Draw(m_sprite_h_police);
						}
						else if (m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getSens())
						{
							m_sprite_v_police.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX(),
									    m_model->getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY());
							m_window->Draw(m_sprite_v_police);
						}
						break;
					}
				}
			}
		}
		//affichage collision
		if (m_model->getPartie()->getNiveau()->getCollision())
		{
			m_sprite_explosion = Sprite (m_image_explosion);
			float dureeCollision = m_model->getTempsCollision();
			if(dureeCollision<=0.05)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(0,0,65,65));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.1)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(65,0,130,65));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.15)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(130,0,195,65));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.2)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(195,0,256,65));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.25)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(0,65,65,130));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.3)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(65,65,130,130));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.35)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(130,65,195,130));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.40)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(195,65,256,130));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.45)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(0,130,65,195));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.5)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(65,130,130,195));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}				
			else if (dureeCollision<=0.55)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(130,130,195,195));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.6)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(195,130,256,195));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.65)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(0,195,65,256));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.7)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(65,195,130,256));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.75)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(130,195,195,256));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			else if (dureeCollision<=0.8)
			{
				m_sprite_explosion.SetSubRect(sf::IntRect(195,195,256,256));
				m_sprite_explosion.SetPosition(m_model->getXCollision()-10, m_model->getYCollision()-10);
				m_window->Draw (m_sprite_explosion);
			}
			if (dureeCollision >= 0.9)
			{
				m_animation = true;
			}
		}
}

void GameView:: affichageCroisement(int i)
{
	if (!m_model->getPartie()->getRoutes()[i]->getSens())
				for (int j=0; j < m_model->getPartie()->getRoutes()[i]->getListeDeCroisements().size() ; j++)
					{
						m_sprite_croisement.SetPosition(m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionX(), 
										m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionY());
						m_window->Draw (m_sprite_croisement);
						if (m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPresenceFeu())
						{
							switch (m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getFeu()->getCouleurFeu())
							{
								case 0 :
									{
										m_sprite_feu = Sprite (m_image_feu_rouge);
										m_sprite_feu.Resize(TAILLE_LARGEUR_FEU, TAILLE_HAUTEUR_FEU);
										break;
									}
								case 1 :
									{
									 	m_sprite_feu = Sprite (m_image_feu_vert);
										m_sprite_feu.Resize(TAILLE_LARGEUR_FEU, TAILLE_HAUTEUR_FEU);
										break;
									} 
							}
							m_sprite_feu.SetPosition
							(m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionX() - TAILLE_LARGEUR_FEU,
							m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionY() - TAILLE_HAUTEUR_FEU);
							m_window->Draw(m_sprite_feu);
							
							m_sprite_ligne = Sprite (m_image_ligne);
							m_sprite_ligne.Rotate(270);
							m_sprite_ligne.Resize(40, 10);
							m_sprite_ligne.SetPosition
								(m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionX(),
							m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionY());
							m_window->Draw(m_sprite_ligne);

						}
					}
}
// Traitement des evenements
bool GameView::treatEvents(){
	bool result = false;
	const sf::Input& input = m_window->GetInput();
	this->declarationImages();
	
	if(m_window->IsOpened()){
		result = true;
		sf::Event event;
		while (m_window->GetEvent(event)) 
		{
			//~ this->declarationImages();
			int mouse_x = input.GetMouseX();
			int mouse_y = input.GetMouseY();
			if ((event.Type == sf::Event::Closed) ||
				((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))) 
			{
				m_window->Close();
				result = false;
			}
			if (m_menu)
			{
				// Gestion des clics sur les boutons du menu et de la position de la souris sur ceux-ci
				if (mouse_x >= 500 && mouse_x <= 750 && mouse_y >= 225 && mouse_y <= 300)
				{
					m_window->Draw(m_sprite_bouton_jouer_agrandi);
				}
				else if (mouse_x >= 500 && mouse_x <= 750 && mouse_y >= 325 && mouse_y <= 400)
				{
					m_window->Draw(m_sprite_bouton_highscore_agrandi);
				}
				else if (mouse_x >= 500 && mouse_x <= 750 && mouse_y >= 425 && mouse_y <= 500)
				{
					m_window->Draw(m_sprite_bouton_quitter_agrandi);
				}
				
				if((event.Type == sf::Event::MouseButtonPressed) && (event.MouseButton.Button == sf::Mouse::Left))
				{
					if (mouse_x >= 500 && mouse_x <= 750 && mouse_y >= 225 && mouse_y <= 300)
					{
						m_menu=false;
						this->declarationImages();
					}
					if (mouse_x >= 500 && mouse_x <= 750 && mouse_y >= 325 && mouse_y <= 400)
					{
						m_menu=false;
						m_score=true;
					}
					if (mouse_x >= 500 && mouse_x <= 750 && mouse_y >= 425 && mouse_y <= 500)
					{
						m_window->Close();
						result = false;
					}
				}
			}
			else if (!m_menu)
			{
				// Gestion du clic sur les feux
				for (int i=0; i<m_model->getPartie()->getRoutes().size();i++)
				{
					if (!m_model->getPartie()->getRoutes()[i]->getSens())
						for (int j=0; j < m_model->getPartie()->getRoutes()[i]->getListeDeCroisements().size() ; j++)
							if (m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPresenceFeu())
								if((event.Type == sf::Event::MouseButtonPressed) && (event.MouseButton.Button == sf::Mouse::Left))
									if (mouse_x >= m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionX() - TAILLE_LARGEUR_FEU &&
										mouse_y >= m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionY() - TAILLE_HAUTEUR_FEU &&
										mouse_x <= m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionX() &&
										mouse_y <= m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getPositionY())
											m_model->getPartie()->getRoutes()[i]->getListeDeCroisements()[j]->getFeu()->changerCouleurFeu();
				}
			}
		}
		
	}  
	return result;
}

