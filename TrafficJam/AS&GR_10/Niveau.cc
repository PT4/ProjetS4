#include "Niveau.h"
#include "Constantes.h"
#include "Croisement.h"


using namespace std;

//Constructeurs
Niveau::Niveau():m_nbRoutes(0), m_nbVehicules(0), m_nbFeux(0), m_trafficAutorise(0), m_collision(0), m_objectif(0), m_nbVehiculesPasses(0), m_nbVehiculePresent(0)
{
	m_listeDeRoutes.push_back(new Route());
}
//(Editeur algorithmique de niveau)
Niveau::Niveau(int nbRoutes, int nbVehicules, int trafficAutorise, int nbFeux, int objectif): m_nbRoutes(nbRoutes), m_nbVehicules(nbVehicules), m_nbFeux(nbFeux),
									 m_trafficAutorise(trafficAutorise), m_collision(0), m_objectif(objectif), m_nbVehiculesPasses(0), m_nbVehiculePresent(0)
{
	int nbRouteHorizontale=1, nbRouteVerticale=1, nbFeu=0;
	creerRoute();	
	affecterSensEtCoordonneesRoute(nbRouteHorizontale, nbRouteVerticale);
	creerVehicule();
	affecterSensEtCoordonneesVehicules();
	creerCroisement(nbRouteHorizontale, nbRouteVerticale);
	affecterCoordonneeCroisement();
	creerFeu(nbRouteHorizontale, nbRouteVerticale, nbFeux);
}
//Destructeur
Niveau::~Niveau()
{
	for (int i=0; i<m_listeDeRoutes.size() ; i++)
	{
		delete m_listeDeRoutes[i];
		m_listeDeRoutes[i] = 0;
	}
}

//Accesseurs en lecture
int Niveau::getNbRoutes() const
{
	return m_nbRoutes;
}

int Niveau::getNbVehicules() const
{
	return m_nbVehicules;
}

int Niveau::getTrafficAutorise() const
{
	return m_trafficAutorise;
}

int Niveau::getNbFeux() const
{
	return m_nbFeux;
}

int Niveau::getObjectif() const
{
	return m_objectif;
}

bool Niveau::getCollision() const
{
	return m_collision;
}

int Niveau::getNbVehiculesPasses() const
{
	return m_nbVehiculesPasses;
}

int Niveau::getNbVehiculePresent() const
{
	return m_nbVehiculePresent;
}

vector <Route*> Niveau::getListeDeRoutes() const
{
	return m_listeDeRoutes;
}

//Accesseurs en écriture
void Niveau::setNbRoutes(int nb)
{
	m_nbRoutes=nb;
}

void Niveau::setNbVehicules(int nb)
{
	m_nbVehicules=nb;
}

void Niveau::setTrafficAutorise(int nb)
{
	m_trafficAutorise=nb;
}
void Niveau::setNbFeux(int nb)
{
	m_nbFeux=nb;
}

void Niveau::setCollision(bool b)
{
	m_collision=b;
}

void Niveau::setNbVehiculesPasses(int nb)
{
	m_nbVehiculesPasses=nb;
}

void Niveau::setNbVehiculePresent(int nb)
{
	m_nbVehiculePresent = nb;
}

void Niveau::setObjectif(int nb)
{
	m_objectif=nb;
}

//Methodes
void Niveau:: creerRoute()
{
	for (int i=0; i<m_nbRoutes; i++)																		
		m_listeDeRoutes.push_back(new Route());	
}

void Niveau:: creerVehicule()
{
	for (int i=0; i<m_nbRoutes; i++)																		
		for (int k=0; k<m_nbVehicules;k++)
		{
			m_listeDeRoutes[i]->ajouterVehicule();
				for (int l=0; l<m_listeDeRoutes[i]->getListeDeVehicules().size();l++)
					m_listeDeRoutes[i]->getListeDeVehicules()[l]->setSens(1);
		}
}

void Niveau:: creerCroisement(int nbRouteHorizontale, int nbRouteVerticale)
{
	for (int i=0; i<m_nbRoutes; i++)
	{		
		if (m_listeDeRoutes[i]->getSens()==false)
			for (int j=0; j<nbRouteVerticale-1; j++)
			{
				m_listeDeRoutes[i]->ajouterCroisement();
				m_listeDeRoutes[i]->getListeDeCroisements()[j]->setPosY(m_listeDeRoutes[i]->getPositionY());
			}
		else
			for (int j=0; j<nbRouteHorizontale-1; j++)
			{	
				m_listeDeRoutes[i]->ajouterCroisement();
				m_listeDeRoutes[i]->getListeDeCroisements()[j]->setPosX(m_listeDeRoutes[i]->getPositionX());

			}
		
	}
}

void Niveau:: creerFeu(int nbRouteHorizontale, int nbRouteVerticale, int nbFeux)
{
	int nb=0;
	for (int i=0; i<m_nbRoutes; i++)
	{		
		if (m_listeDeRoutes[i]->getSens()==false)
			for (int j=0; j<nbRouteVerticale-1; j++)
			{
				if (nb<nbFeux)
				{
					m_listeDeRoutes[i]->getListeDeCroisements()[j]->setPresenceFeu(1);
					m_listeDeRoutes[i]->getListeDeCroisements()[j]->genererFeu();
					nb++;
				}
			}
	}
}

void Niveau:: affecterSensEtCoordonneesRoute(int &nbRouteHorizontale, int &nbRouteVerticale)
{
	for (int i=0; i<m_nbRoutes; i++)																			
	{
		if (i%2==1)
			m_listeDeRoutes[i]->setSens(1);
		switch (m_listeDeRoutes[i]->getSens())
		{
			case 0:
			{
				m_listeDeRoutes[i]->setPosY(nbRouteVerticale*ECART_VERTICAL_ROUTES);
				nbRouteHorizontale++;
				break;
			}
			case 1: 
			{
				m_listeDeRoutes[i]->setPosX((nbRouteHorizontale-1)*ECART_HORIZONTAL_ROUTES);
				nbRouteVerticale++;
				break;
			}
			default : break;
		}
	}
}

void Niveau:: affecterSensEtCoordonneesVehicules()
{
	for (int i=0; i<m_nbRoutes; i++)																		
		for (int j=0; j<m_listeDeRoutes[i]->getListeDeVehicules().size();j++)
			switch (m_listeDeRoutes[i]->getSens())
			{
				case 0: 
				{
					m_listeDeRoutes[i]->getListeDeVehicules()[j]->setSens(0);
					m_listeDeRoutes[i]->getListeDeVehicules()[j]->setPosX(m_listeDeRoutes[i]->getPositionX()-128);
					m_listeDeRoutes[i]->getListeDeVehicules()[j]->setPosY(m_listeDeRoutes[i]->getPositionY()+5);
					break;
				}
				case 1: 
				{
					m_listeDeRoutes[i]->getListeDeVehicules()[j]->setSens(1);
					m_listeDeRoutes[i]->getListeDeVehicules()[j]->setPosX(m_listeDeRoutes[i]->getPositionX()+5);
					m_listeDeRoutes[i]->getListeDeVehicules()[j]->setPosY(m_listeDeRoutes[i]->getPositionY()-128);
					break;
				}
				default: break;
			}
}

void Niveau:: affecterCoordonneeCroisement()
{
	for (int i=0; i<m_nbRoutes; i++)
	{
		if (m_listeDeRoutes[i]->getSens() == false)
			for (int j=0 ; j <= m_listeDeRoutes[i]->getListeDeCroisements().size() ; j++)
				if (m_listeDeRoutes[j]->getSens()==true)
					for (int k=0; k<m_listeDeRoutes[i]->getListeDeCroisements().size();k++)	
						m_listeDeRoutes[i]->getListeDeCroisements()[k]->setPosX((k+1)*ECART_HORIZONTAL_ROUTES);
		if (m_listeDeRoutes[i]->getSens() == true)
			for (int j=0 ; j <= m_listeDeRoutes[i]->getListeDeCroisements().size() ; j++)
				if (m_listeDeRoutes[j]->getSens()==false)
					for (int k=0; k<m_listeDeRoutes[i]->getListeDeCroisements().size();k++)	
						m_listeDeRoutes[i]->getListeDeCroisements()[k]->setPosY((k+1)*ECART_VERTICAL_ROUTES);
	}
}
