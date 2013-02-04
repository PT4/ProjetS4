#include <cstdlib>
#include <iostream>
#include "GameView.h"
#include "GameModel.h"

using namespace std;
using namespace sf;

//=======================================
// Constructeur
//=======================================
GameView::GameView(int w, int h): _w(w), _h(h)
{
	_window = new RenderWindow(sf::VideoMode(w, h, 32), "TrafficJam", sf::Style::Close);
	_menu = false ;
	_titre = false ;
	_score = false ;
	_save = false;
	_chargement = true;
	
	_camionX = -425;
	_camionY = 5;

	
	if (!_background_image.LoadFromFile("images/grass2.jpg") ||
		!_route_V_image.LoadFromFile("images/vroad.jpg") ||
		!_police_V_image.LoadFromFile("images/vpolice.png") || 
		!_voiture_V_image.LoadFromFile("images/vcar.png") ||
		!_camion_V_image.LoadFromFile("images/vbus.png") ||
		!_route_H_image.LoadFromFile("images/hroad.jpg") ||
		!_police_H_image.LoadFromFile("images/hpolice.png") || 
		!_voiture_H_image.LoadFromFile("images/hcar.png") ||
		!_camion_H_image.LoadFromFile("images/hbus.png") ||
		!_feuV_image.LoadFromFile("images/greenlight.jpg") ||
		!_feuR_image.LoadFromFile("images/redlight.jpg") ||
		!_bouton_V_image.LoadFromFile("images/vbuttons.png") ||
		!_bouton_H_image.LoadFromFile("images/buttons.png") ||
		!_lightline_H_image.LoadFromFile("images/hlightline.jpg") ||
		!_lightline_V_image.LoadFromFile("images/vlightline.jpg") ||
		!_flammes_image.LoadFromFile("images/collisions/fire.png") ||
		!_font.LoadFromFile("Antique_Olive.ttf",50)) 
	{
		cout << "Erreur lors du chargement de l'image ou de la police"<<endl;
	}
	else 
	{
		_background_sprite = Sprite (_background_image);
		_background_sprite.Resize(_w, _h-45);
		_background_sprite.SetPosition(0,0);
		
		_route_V_sprite = Sprite (_route_V_image);
		_route_V_sprite.Resize(40,_h-45);
		_route_H_sprite = Sprite (_route_H_image);
		_route_H_sprite.Resize(_w,40);
		
		_police_V_sprite = Sprite (_police_V_image);
		_police_V_sprite.Resize(70,200);
		_police_H_sprite = Sprite (_police_H_image);
		
		_voiture_V_sprite = Sprite (_voiture_V_image);
		_voiture_V_sprite.Resize(30,66);
		_voiture_H_sprite = Sprite (_voiture_H_image);
		_voiture_H_sprite.Resize(66,30);
		
		_camion_V_sprite = Sprite (_camion_V_image);
		_camion_H_sprite = Sprite (_camion_H_image);
		
		
		_feuR_sprite = Sprite (_feuR_image);
		_feuR_sprite.Resize (20,40);
		_feuV_sprite = Sprite (_feuV_image);
		_feuV_sprite.Resize (20,40);
		
		_bouton_H_sprite = Sprite (_bouton_H_image);
		_bouton_H_sprite.Resize (380,75);
		_bouton_H_sprite.SetSubRect(IntRect(150, 0, 300, 80));
		
		_titre_texte.SetText(L"");
		_titre_texte.SetFont(_font);
		_titre_texte.SetSize(80);
		_titre_texte.SetPosition(187,0);
		
		_score_titre_texte.SetText(L"Meilleurs Scores");
		_score_titre_texte.SetFont(_font);
		_score_titre_texte.SetSize(50);
		_score_titre_texte.SetPosition(210,10);
		
		_ok_texte_bouton = String(L"OK",_font,50);
		_ok_texte_bouton.SetPosition (372,500); 
		
		_barre_info_jeu = Shape::Rectangle(800,45,0,0,Color::Black);
		_barre_info_jeu.SetPosition(0,600-45);
		
		_lightline_H_sprite = Sprite(_lightline_H_image);
		_lightline_H_sprite.Resize(10,40);
		_lightline_V_sprite = Sprite(_lightline_V_image);
		
		_flammes_image.CreateMaskFromColor(Color::Black);
		_flammes_sprite = Sprite(_flammes_image);
		//_flammes_sprite.Resize (50,100);
	}
}

//=======================================
// Destructeur
//=======================================
GameView::~GameView()
{
	if(_window!= NULL)
		delete _window;
}

//=======================================
// Accesseurs en écriture
//=======================================
void GameView::setModel(GameModel * model)
{
	_model = model;
}

GameModel* GameView::getModel() const
{
	return _model;
}

//=======================================
// Fonction de dessin
//=======================================
void GameView::draw()
{
	int x ;
	int y ;
	int type;
	bool horizontale ;
	
	
	_window->Clear();
	
	if (_chargement) 
	{
		afficherChargement ();
	}
	else
	{
	switch (_menu)
	{
		case true:
			if (_score)
				gereMenuScore ();
			else
				gereMenu ();
		break;
		
		case false :
			if ( !_model->getFinAnim()  
			&& _model -> getJeu() -> getLevel()-> getVoiturePasse() < _model -> getJeu () -> getLevel () -> getObjectif () 
			&& !_save 
			&& _model -> getJeu () -> getLevel () -> getTraficActuel() <= _model -> getJeu () -> getLevel ()->getTraficMax())
			{
			_police_V_sprite.Resize(30,75);
			_police_H_sprite.Resize(75,30);
			_camion_V_sprite.Resize(38,120);
			_camion_H_sprite.Resize(120,38);
			_window->Draw(_background_sprite);
			
			for (int i = 0; i < _model -> getJeu () -> getLevel()->getNbRoute(); i++) 
			{
				_model -> getRouteInfo(x, y, horizontale, i);
				
				switch (horizontale) 
				{
					case true:_route_H_sprite.SetPosition (x,y);_window -> Draw (_route_H_sprite);break;
					case false:_route_V_sprite.SetPosition (x,y);_window -> Draw (_route_V_sprite);break;
					default:break;
				}
		
			}

			for (int i = 0; i < _model->getJeu()->getLevel()->getNbFeux(); i++)
			{
				if (_model->getJeu()->getLevel()->getFeuInfo(i)->getEtat() && _model->getJeu()->getLevel()->getFeuInfo(i)->getPresence())
				{
					x=_model->getJeu()->getLevel()->getFeuInfo(i)->getX()-20;
					y=_model->getJeu()->getLevel()->getFeuInfo(i)->getY()-40;
					_feuV_sprite.SetPosition (x,y);
					_window -> Draw (_feuV_sprite);

				}
				else if(_model->getJeu()->getLevel()->getFeuInfo(i)->getPresence())
				{
					x=_model->getJeu()->getLevel()->getFeuInfo(i)->getX()-20;
					y=_model->getJeu()->getLevel()->getFeuInfo(i)->getY()-40;
					_feuR_sprite.SetPosition (x,y);
					_window -> Draw (_feuR_sprite);
				}
				_lightline_H_sprite.SetPosition(x+15,y+40);
				_window -> Draw(_lightline_H_sprite);
			}

			for (int j = 0; j < _model->getJeu()->getLevel()->getNbRoute(); j++)
			{
				for (int k = 0; k < _model->getJeu()->getLevel()->getRouteInfo(j)->getNbVehicule(); k++)
				{
					type=_model->getJeu()->getLevel()->getRouteInfo(j)->getVehiculeInfo(k)->getType();
					x=_model->getJeu()->getLevel()->getRouteInfo(j)->getVehiculeInfo(k)->getX();
					y=_model->getJeu()->getLevel()->getRouteInfo(j)->getVehiculeInfo(k)->getY();
					if(_model->getJeu()->getLevel()->getRouteInfo(j)->getVehiculeInfo(k)->getHorizontale ())
					{
						switch (type) 
						{
							case 1:_camion_H_sprite.SetPosition (x,y-5);_window -> Draw (_camion_H_sprite);break;
							case 2:_voiture_H_sprite.SetPosition (x,y);_window -> Draw (_voiture_H_sprite);break;
							case 3:_police_H_sprite.SetPosition (x,y);_window -> Draw (_police_H_sprite);							
							break;
							default:break;
						}

					}
					else
					{
						switch (type) 
						{
							case 1:_camion_V_sprite.SetPosition (x-5,y);_window -> Draw (_camion_V_sprite);	break;
							case 2:_voiture_V_sprite.SetPosition (x,y);_window -> Draw (_voiture_V_sprite);	break;
							case 3:_police_V_sprite.SetPosition (x,y);_window -> Draw (_police_V_sprite);break;
							default:break;
						}
					}
				}
		
			}
			if (_model -> getJeu() -> getLevel () -> getAccident())
				afficherAnimationCollision();

			_window -> Draw (_barre_info_jeu);
			gereBarreInfo();
			_window -> SetFramerateLimit(60);
		}
		
		else if(_save)
			setScoreFichier();


		if (_model -> getFinAnim () == true 
		|| _model -> getJeu () -> getLevel () -> getTraficActuel() > _model -> getJeu () -> getLevel ()->getTraficMax()
		|| _model -> getJeu() -> getLevel()-> getVoiturePasse() >= _model -> getJeu () -> getLevel () -> getObjectif ())
		{
			if (_model -> getJeu () -> getLevel () -> getTraficActuel() > _model -> getJeu () -> getLevel ()->getTraficMax())
				_model -> getJeu () -> getLevel () -> setEmbouteillage ();
				
			afficherEcranSuivant();
		}
			
		break;
	}
	}

	_window->Display();
	usleep(500);
}
	
//=======================================
// Traitement des evenements
// Retourne false si un evenement de fin est reçu
//=======================================
bool GameView::treatEvents(){
	bool result = false;
	const sf::Input& input = _window -> GetInput ();
	if(_window->IsOpened())
	{
		result = true;
		sf::Event event;
		while (_window->GetEvent(event)) 
		{
			int sourisX = input.GetMouseX ();
			int sourisY = input.GetMouseY ();
			
			if ((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))) 
			{
				_window->Close();
				result = false;
			}
			if (_menu && _score == false)
			{
				if (sourisX >= 520 && sourisX <= 710 && sourisY >= 388 && sourisY <= 463)
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
						result = false;
				if (sourisX >= 520 && sourisX <= 710 && sourisY >= 280 && sourisY <= 355)
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
						_score = true;
				if (sourisX >= 520 && sourisX <= 710 && sourisY >= 168 && sourisY <= 243)
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
						_menu = false;
			}
			else if (_score)
			{
				if (sourisX >= 308 && sourisX <= 498 && sourisY >= 500 && sourisY <= 575)
					if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
					{
						_score = false;
						_titre = true;
					}
			}
			else if(!_menu && _model->getJeu()->getLevel()->getFeuInfo(1)!=NULL)
			{
				int sourisX = input.GetMouseX ();
				int sourisY = input.GetMouseY ();
				for (int i = 0; i < _model->getJeu()->getLevel()->getNbFeux(); i++)
				{
					if(sourisX >= _model->getJeu()->getLevel()->getFeuInfo(i)->getX()-20 && sourisX <= _model->getJeu()->getLevel()->getFeuInfo(i)->getX() && sourisY >= _model->getJeu()->getLevel()->getFeuInfo(i)->getY()-40 && sourisY <= _model->getJeu()->getLevel()->getFeuInfo(i)->getY() && _model->getJeu()->getLevel()->getFeuInfo(i)->getPresence())
					{
						if (event.Type == Event::MouseButtonPressed && event.MouseButton.Button == Mouse::Left)
						{
							_model->getJeu()->getLevel()->getFeuInfo(i)->setEtat ();
						}
					}
				}
			}
			
		}
	} 
	return result;
}

int GameView::testSouris()
{
	const sf::Input& input = _window -> GetInput ();
	int sourisX = input.GetMouseX ();
	int sourisY = input.GetMouseY ();
	
	if (_score)
	{
		if (sourisX >= 308 && sourisX <= 498 && sourisY >= 500 && sourisY <= 575)
			return 1;	
	}
	
	else if (_menu)
	{		
		if (sourisX >= 520 && sourisX <= 710 && sourisY >= 168 && sourisY <= 243)
			return 1;
		else if (sourisX >= 520 && sourisX <= 710 && sourisY >= 278 && sourisY <= 353)
			return 2;
		else if (sourisX >= 520 && sourisX <= 710 && sourisY >= 388 && sourisY <= 463)
			return 3;
				
	}

	return 0;
}

void GameView::afficherTitre()
{
	_camion_H_sprite.Resize(425,100);
	if (_camionX <= 800)
	{
		_camion_H_sprite.SetPosition (_camionX,_camionY);
		_window -> Draw (_camion_H_sprite);
		_camionX = _camionX + 0.5;
	

			if(_camionX==207.0)
				_titre_texte.SetText(L"T");

			else if(_camionX==245.0)
				_titre_texte.SetText(L"Tr");

			else if(_camionX==283.0)
				_titre_texte.SetText(L"Tra");

			else if(_camionX==321.0)
				_titre_texte.SetText(L"Traf");

			else if(_camionX==359.0)
				_titre_texte.SetText(L"Traff");

			else if(_camionX==397.0)
				_titre_texte.SetText(L"Traffi");

			else if(_camionX==435.0)
				_titre_texte.SetText(L"Traffic");

			else if(_camionX==473.0)
				_titre_texte.SetText(L"Traffic ");

			else if(_camionX==511.0)
				_titre_texte.SetText(L"Traffic J");

			else if(_camionX==549.0)
				_titre_texte.SetText(L"Traffic Ja");

			else if(_camionX==587.0)
				_titre_texte.SetText(L"Traffic Jam");


	}
	else
	{
		_titre = false ;
	}
}

void GameView::gereBarreInfo()
{
	int score = getModel() -> getJeu() -> getScore ();
	int level = getModel() -> getJeu() -> getNiveau();
	int voitureOk = getModel() -> getJeu() -> getLevel() -> getVoiturePasse();
	int objectif = getModel() -> getJeu() -> getLevel() -> getObjectif();
	float trafic = 424+(getModel() -> getJeu() -> getLevel() -> getTraficActuel () * 100 / getModel() -> getJeu() -> getLevel() -> getTraficMax ())*1.65;
	Color c ;
	stringstream Info;
	String BarreInfo;

	Info << "Niveau : "<< level;
	Info << "   Vehicule : "<< voitureOk;
	Info << "/"<< objectif;
	Info << "   Trafic : ";
	Info << "                          Score : "<< score <<" Pts";
	
	BarreInfo.SetText(Info.str());
	BarreInfo.SetFont(_font);
	BarreInfo.SetSize(25);		
	BarreInfo.SetPosition(5,600-40);
	
	_window -> Draw (BarreInfo);
	
	_cadre_trafic = Shape::Rectangle(425,600-35, 590, 600-10, Color::Black, 2, Color::White);
	if (trafic-424 < 55)
		c = Color::Green;
	else if (trafic-424 > 55 && trafic-424 < 110)
		c = Color(255,130,18);
	else 
		c = Color::Red;
		
	_interieur_trafic = Shape::Rectangle(427,600-33, trafic, 600-12, c);
	
	_window -> Draw (_cadre_trafic);
	_window -> Draw (_interieur_trafic);
	
}

bool GameView::getMenu() const
{
	return _menu;
}

void GameView::afficherScore()
{
	ifstream fichier_score ("scores.csv", ios::in);
	
	if (! fichier_score)
		cout << "impossible de charger le fichier des scores"<< endl;
		
	else
	{
		string ligne;
		String resultat;
		int y = 100;
		int x = 500;
		int cpt = 0;
        while (!fichier_score.eof() && cpt < 20)
        {
			fichier_score >> ligne;
			resultat = String (ligne,_font,40);
			if (x == 500) 
				x = 250;
			else
				x = 500;
			resultat.SetPosition(x,y);
			_window -> Draw (resultat);
			if (x == 500)
				y+=40;
			cpt ++;
			
		}
        
        
		fichier_score.close();
	}
}

void GameView::afficherEcranSuivant()
{
	Clock clock;
	float temps;
	char time[5];
	String result;
	Event event;
	while (clock.GetElapsedTime() < 5.f && (_window->GetEvent(event) || !_save))
	{
		_window -> Clear ();
		_annonce = String (L"Appuyez sur q pour quitter",_font,40);
		_annonce.SetPosition(200,500);
		_window -> Draw (_annonce);
		
		if (_model -> getJeu() -> getLevel () -> getAccident() || _model -> getJeu () -> getLevel () -> getEmbouteillage ())
			_annonce = String (L"Perdu !",_font,60);
		else if (_model -> getJeu() -> getLevel()-> getVoiturePasse() >= _model -> getJeu () -> getLevel () -> getObjectif ())
			_annonce = String (L"Bien Joué !",_font,60);
		else
			_annonce = String (L"Perdu !",_font,60);
		

		temps = 5- clock.GetElapsedTime();
		sprintf(time,"%f",temps);
		result = String (time,_font,40);
		result.SetPosition (300,300);
	
		_annonce.SetPosition(300,100);
	
		_window -> Draw (_annonce);
		_window -> Draw (result);
		_window -> Display ();
		if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Q))
		{
			_save = true;
		}
		else if (_model -> getJeu () -> getLevel () -> getTraficActuel() > _model -> getJeu () -> getLevel ()->getTraficMax())
			_model -> getJeu () ->resetLevel ();
	}
}

void GameView::gereMenuScore ()
{
	_window -> Draw (_score_titre_texte);
	_bouton_H_sprite.SetPosition (308,500);
	afficherScore();
	
	if (testSouris()==1)
		_window -> Draw (_bouton_H_sprite);	
		
	_window -> Draw (_ok_texte_bouton);
}

void GameView::gereMenu ()
{
	_police_V_sprite.Resize(200,400);
	_police_V_sprite.SetPosition (100,150);
	_window -> Draw (_police_V_sprite);
	_play_texte_bouton = String(L"Jouer",_font,50);
	_play_texte_bouton.SetPosition(550,170);
	_score_texte_bouton = String(L"Score",_font,50);
	_score_texte_bouton.SetPosition(550,280);
	_quitter_texte_bouton = String(L"Quitter",_font,50);
	_quitter_texte_bouton.SetPosition(530,390);			
	if (_titre)
		afficherTitre();
		
	switch (testSouris())
	{
		case 1: _bouton_H_sprite.SetPosition (520,168);_window -> Draw (_bouton_H_sprite);break;
		case 2: _bouton_H_sprite.SetPosition (520,278);_window -> Draw (_bouton_H_sprite);break;
		case 3: _bouton_H_sprite.SetPosition (520,388);_window -> Draw (_bouton_H_sprite);break;
	}
	_window -> Draw (_titre_texte);
	_window -> Draw (_play_texte_bouton);
	_window -> Draw (_score_texte_bouton);
	_window -> Draw (_quitter_texte_bouton);
	_window -> SetFramerateLimit(390);
}

void GameView::setScoreFichier()
{
	string str;
	String nom;
	string nomFichier[10];
	int scoreFichier[10];
	Event event;
	int score = _model -> getJeu() -> getScore();
	int cptnom = 0;
	int cptscore = 0;
	int emplacement = -1;
	
	ifstream fichier_score ("scores.csv", ios::in);
	for (int i = 1; i<21; i++) 
	{
		if (cptnom == cptscore)
		{
			fichier_score >> nomFichier[cptnom];
			cptnom++;
		}
		else 
		{
			fichier_score >> scoreFichier[cptscore];
			if (scoreFichier[cptscore]<score)
				if (emplacement == -1)
					emplacement = cptscore;
			cptscore ++;
		}
		

	}
	fichier_score.close();
	if (emplacement != -1)
	{
		while (_window->GetEvent(event) || !((event.Type == sf::Event::KeyReleased) && (event.Key.Code == sf::Key::Return))) 
		{
			_window -> Clear();
			nom = String ("Veuillez entrer votre nom : ",_font,50);
			nom.SetPosition(100,100);
			_window -> Draw (nom);
		
			switch(event.Type)
			{
				case Event::KeyPressed:
				str += static_cast<char>(event.Text.Unicode);
				break;
			}
			nom.SetText(str);
			nom.SetPosition(300,250);
			_window -> Draw (nom);
			_window -> Display ();
		}
		ofstream fichier("scores.csv", ios::out | ios::trunc);

		bool changement = false;
		for (int i = 0; i<10; i++) 
		{

			if (i == emplacement)
			{
				fichier << str <<" "<<score << endl;
				changement = true;
			}
			else if (changement)
				fichier << nomFichier[i-1] <<" "<<scoreFichier[i-1] << endl;
			else
				fichier << nomFichier[i] <<" "<<scoreFichier[i] << endl;
			
		}
		fichier.close(); 
	}
	
	_menu = true;
	_model->newJeu();
	_save = false;
}

void GameView::afficherChargement ()
{
	Clock clock;
	Image logo_IUT_image;
	Sprite logo_IUT_sprite;
	String chargement;
	
	
	logo_IUT_image.LoadFromFile("images/logo.jpeg");
	logo_IUT_sprite = Sprite (logo_IUT_image);
	
	chargement = String ("Chargement ...",_font,40);
	chargement.SetPosition (270,500);
	while (clock.GetElapsedTime()<5)
	{
		_window -> Clear ();
		logo_IUT_sprite.Resize(250, 250);
		logo_IUT_sprite.SetPosition(275,175);

		
		_window -> Draw (logo_IUT_sprite);
		_window -> Draw (chargement);
		_window -> Display ();
		usleep(100000);
	}
	_chargement = false;
	_menu = true;
	_titre = true;
}

void GameView::afficherAnimationCollision()
{
	float duree = _model->getClockCollision ();
			if(duree<=0.10)
				_flammes_sprite.SetSubRect(sf::IntRect(0,0,48,52));
			else if (duree<=0.20)
				_flammes_sprite.SetSubRect(sf::IntRect(50,0,98,52));
			else if (duree<=0.30)
				_flammes_sprite.SetSubRect(sf::IntRect(100,0,148,52));
			else if (duree<=0.40)
				_flammes_sprite.SetSubRect(sf::IntRect(150,0,198,52));
			else if (duree<=0.50)
				_flammes_sprite.SetSubRect(sf::IntRect(200,0,248,52));
			else if (duree<=0.60)
				_flammes_sprite.SetSubRect(sf::IntRect(250,0,298,52));
			else if (duree<=0.70)
				_flammes_sprite.SetSubRect(sf::IntRect(300,0,348,52));
			else if (duree<=0.80)
				_flammes_sprite.SetSubRect(sf::IntRect(350,0,398,52));
			else if (duree<=0.90)
				_flammes_sprite.SetSubRect(sf::IntRect(400,0,448,52));
			else if (duree<=1.00)
				_flammes_sprite.SetSubRect(sf::IntRect(450,0,498,52));				
			else if (duree<=1.10)
				_flammes_sprite.SetSubRect(sf::IntRect(500,0,548,52));
			else if (duree<=1.20)
				_flammes_sprite.SetSubRect(sf::IntRect(550,0,598,52));
			else if (duree<=1.30)
				_flammes_sprite.SetSubRect(sf::IntRect(600,0,648,52));
			else if (duree<=1.40)
				_flammes_sprite.SetSubRect(sf::IntRect(650,0,698,52));
			else if (duree<=1.50)
				_flammes_sprite.SetSubRect(sf::IntRect(700,0,748,52));
			else if (duree<=1.60)
				_flammes_sprite.SetSubRect(sf::IntRect(750,0,798,52));
			
			_flammes_sprite.SetPosition(_model->getAccidentX ()-15, _model->getAccidentY ()+5);
			_window->Draw (_flammes_sprite);
			_window -> Display (); 
	if (duree >=1.75)
		_model -> setFinAnim();
}
