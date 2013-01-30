#include "GameModel.h"
#include "Constantes.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

// Constructeurs
GameModel::GameModel() 
: m_width(LARGEUR_FENETRE), m_height(HAUTEUR_FENETRE), m_nbVehicules_Horizontal(0), m_nbVehicules_Vertical(0), time_horizontal(0), time_vertical(0), m_xCollision(0), m_yCollision(0), m_tempsCollision(0), m_nbAlea(Randomizer::Random(1,3))
{}

GameModel::GameModel(int width, int height)
:  m_width(width), m_height(height), m_nbVehicules_Horizontal(0), m_nbVehicules_Vertical(0), time_horizontal(0), time_vertical(0), m_xCollision(0), m_yCollision(0), m_tempsCollision(0), m_nbAlea(Randomizer::Random(0,2))
{
	m_partie=new Partie();
	m_partie->genererNiveau();
}


// Destructeurs
GameModel::~GameModel()
{
	delete m_partie;
}

//Accesseurs en lecture
Partie* GameModel ::getPartie() const
{
	return m_partie;
}

float GameModel::getTemps() const
{
	return horloge_collision.GetElapsedTime();
}

float GameModel:: getTempsCollision() const
{
	return m_tempsCollision;
}

int GameModel:: getXCollision() const
{
	return m_xCollision;
}

int GameModel:: getYCollision() const
{
	return m_yCollision;
}

// Calcul la prochaine étape
void GameModel::nextStep()
{
	collision();
	for (int i=0; i<getPartie()->getRoutes().size() ; i++)
	{
			time_horizontal = horloge_horizontal.GetElapsedTime();
			time_vertical = horloge_vertical.GetElapsedTime();
			if (m_nbVehicules_Horizontal <= getPartie()->getNiveauEnCours() && getPartie()->getRoutes()[i]->getNumeroVehicule() < getPartie()->getRoutes()[i]->getListeDeVehicules().size())
			{
				if (time_horizontal > 2)
				{
					if (!getPartie()->getRoutes()[i]->getSens())
					{
						for (int t=0 ; t < getPartie()->getRoutes().size() ; t++)
						{
							if (!getPartie()->getRoutes()[t]->getSens())
							{
								getPartie()->getRoutes()[t]->getListeDeVehicules()[getPartie()->getRoutes()[t]->getNumeroVehicule()]->setEtatVehicule(1);
								getPartie()->getRoutes()[t]->setNumeroVehicule(getPartie()->getRoutes()[t]->getNumeroVehicule()+1);
							}
						}
						m_nbVehicules_Horizontal++;
						horloge_horizontal.Reset();
						time_horizontal = 0;
						if (m_nbVehicules_Horizontal == getPartie()->getNiveauEnCours())
						{
							m_nbVehicules_Horizontal = 0;
						}
					}
				}
				else if (time_vertical > m_nbAlea)
				{
					for (int f=0 ; f < getPartie()->getRoutes().size(); f++)
					{
					if (getPartie()->getRoutes()[f]->getSens())
					{
						getPartie()->getRoutes()[f]->getListeDeVehicules()[getPartie()->getRoutes()[f]->getNumeroVehicule()]->setEtatVehicule(1);
						getPartie()->getRoutes()[f]->setNumeroVehicule(getPartie()->getRoutes()[f]->getNumeroVehicule()+1);
						m_nbVehicules_Vertical++;
						horloge_vertical.Reset();
						time_vertical = 0;
						m_nbAlea = Randomizer::Random(1,4);
						if (m_nbVehicules_Vertical == getPartie()->getNiveauEnCours()/2)
						{
							m_nbVehicules_Vertical = 0;
						}
					}
					}
				}
				else
				{
					for (int v=0 ; v < getPartie()->getRoutes()[i]->getListeDeVehicules().size() ; v++)
					{
						if (v >= getPartie()->getRoutes()[i]->getNumeroVehicule())
							getPartie()->getRoutes()[i]->getListeDeVehicules()[v]->setEtatVehicule(0);
					}
				}
			}
		for (int j=0 ; j<getPartie()->getRoutes()[i]->getListeDeVehicules().size() ; j++)
		{
			if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getEtatVehicule())
			{
				if (getPartie()->getRoutes()[i]->getSens())
					switch (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getVitesse())
					{
						case 1 :
						{
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosY
							(getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()+BASE_VITESSE*1.5);
							break;
						}
						case 2 :
						{
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosY
							(getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()+BASE_VITESSE*2);
							break;
						}
						case 3 :
						{
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosY
							(getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()+BASE_VITESSE*3);
							break;
						}
					}
				else if (!getPartie()->getRoutes()[i]->getSens())
					switch (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getVitesse())
					{
						case 1 :
						{
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosX
							(getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()+BASE_VITESSE*1.5);
							break;
						}
						case 2 :
						{
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosX
							(getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()+BASE_VITESSE*2);
							break;
						}
						case 3 :
						{
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosX
							(getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()+BASE_VITESSE*3);
							break;
						}
					}	
			}
			if (!getPartie()->getRoutes()[i]->getSens())
			{
				if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()==LARGEUR_FENETRE ||
					getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()==LARGEUR_FENETRE+2)
				{
					getPartie()->getNiveau()->setNbVehiculesPasses(getPartie()->getNiveau()->getNbVehiculesPasses()+1);
					getPartie()->setScore(getPartie()->calculerScore(i,j));
					getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setPosX(1200);
					getPartie()->getNiveau()->setNbVehiculePresent(getPartie()->getNiveau()->getNbVehiculePresent()-1);
				}
				
				if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() == -2)
						getPartie()->getNiveau()->setNbVehiculePresent(getPartie()->getNiveau()->getNbVehiculePresent()+1);
			}
		}
	}
	if (getPartie()->getNiveau()->getNbVehiculesPasses() == getPartie()->getNiveau()->getObjectif())
	{
		horloge_horizontal.Reset();
		horloge_vertical.Reset();
	}
}

void GameModel:: collision()
{
		float taille_vehicule;
		for (int i=0 ; i < getPartie()->getRoutes().size() ; i++)
		{
			for (int j=0 ; j < getPartie()->getRoutes()[i]->getListeDeVehicules().size() ; j++)
			{
				switch (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getVitesse())
				{
					case 1 : taille_vehicule = TAILLE_LONGUEUR_CAMION; break;
					case 2 : taille_vehicule = TAILLE_LONGUEUR_VOITURE_ET_POLICE; break;
					case 3 : taille_vehicule = TAILLE_LONGUEUR_VOITURE_ET_POLICE; break;
					default : break;
				}
				if (j>0 && getPartie()->getRoutes()[i]->getListeDeVehicules()[j-1] != NULL)
				{
					if (!getPartie()->getRoutes()[i]->getSens())
					{
						if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() + taille_vehicule 
							>= getPartie()->getRoutes()[i]->getListeDeVehicules()[j-1]->getPositionX())
								getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(0);
						else
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(1);
					}
					else if (getPartie()->getRoutes()[i]->getSens())
					{
						if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY() + taille_vehicule 
							>= getPartie()->getRoutes()[i]->getListeDeVehicules()[j-1]->getPositionY())
								getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(0);
						else
							getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(1);
					}
				}
				else if (j==0)
					getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(1);
				else if (j>0 && getPartie()->getRoutes()[i]->getListeDeVehicules()[j-1] == NULL)
					getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(1);
				
				if (!getPartie()->getRoutes()[i]->getSens())
				{
					for (int k=0 ; k<getPartie()->getRoutes()[i]->getListeDeCroisements().size() ; k++)
					{
						if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() + taille_vehicule 
							<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX()
							&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() + taille_vehicule
							>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX()- 10
							&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()
							>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY()
							&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()
							<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY() + 40
							&& getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPresenceFeu()
							&& !getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getFeu()->getCouleurFeu())
								getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(0);
						
						else if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() + taille_vehicule 
							<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX()
							&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() + taille_vehicule
							>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX()- 10
							&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY() 
							>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY()
							&&getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()
							<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY() + 40
							&& getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPresenceFeu()
							&& getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getFeu()->getCouleurFeu())
								getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(1);
						
						else if (getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX() + taille_vehicule
								>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX()
								&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()
								>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX() - taille_vehicule
								&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionX()
								<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX() + TAILLE_ROUTE
								&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()
								> getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY()
								&& getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->getPositionY()
								<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY() + TAILLE_ROUTE)
						{
							if (getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getNbVehiculePresent() == 1)
								for (int l=0 ; l<getPartie()->getRoutes().size() ; l++)
									if(getPartie()->getRoutes()[l]->getSens())
									for (int v=0 ; v < getPartie()->getRoutes()[l]->getListeDeVehicules().size() ; v++)
										if (getPartie()->getRoutes()[l]->getListeDeVehicules()[v]->getPositionY() + taille_vehicule
											>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY()
											&& getPartie()->getRoutes()[l]->getListeDeVehicules()[v]->getPositionY()
											>= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY() - taille_vehicule
											&& getPartie()->getRoutes()[l]->getListeDeVehicules()[v]->getPositionY()
											<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY() + TAILLE_ROUTE
											&& getPartie()->getRoutes()[l]->getListeDeVehicules()[v]->getPositionX()
											> getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX()
											&& getPartie()->getRoutes()[l]->getListeDeVehicules()[v]->getPositionX()
											<= getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX() + TAILLE_ROUTE)
										{
											if (getTemps() > 2)
												horloge_collision.Reset();
											m_xCollision = getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionX();
											m_yCollision = getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->getPositionY();
											m_tempsCollision = getTemps();
											getPartie()->getNiveau()->setCollision(1);
											horloge_horizontal.Reset();
											horloge_vertical.Reset();
										}
							else
								getPartie()->getRoutes()[i]->getListeDeCroisements()[k]->setNbVehiculePresent(1);
						}
					}
				}
			}
		}
			
		if (getPartie()->getNiveau()->getCollision())
				for (int i=0; i<getPartie()->getRoutes().size(); i++)
					for (int j=0; j<getPartie()->getRoutes()[i]->getListeDeVehicules().size(); j++)
						getPartie()->getRoutes()[i]->getListeDeVehicules()[j]->setEtatVehicule(0);
}
