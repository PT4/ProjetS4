#include "GameModel.h"
#include "Constantes.h"
#include "Partie.h"
#include "Joueur.h"
#include "Unite.h"
#include "Carte.h"

#include <fstream>

using namespace std;
using namespace sf;

// Constructeurs
GameModel::GameModel() : m_width(LARGEUR_FENETRE), m_height(HAUTEUR_FENETRE)
{
	m_partie=NULL;
	ok = false;

	m_thread = false;
}

GameModel::GameModel(int width, int height): m_width(width), m_height(height)
{
	m_partie=NULL;
	//~ m_partie=NULL;
	m_thread = false;
}


// Destructeurs
GameModel::~GameModel()
{
	if (m_partie!=NULL)
		delete m_partie;
}

void GameModel::nextStep()
{
	setThread();
		if (m_partie != NULL)
				for (int i = 0; i < m_partie -> getListeJoueurs().size() ; i++)
				{
					for (int j = 0; j < m_partie -> getListeJoueurs()[i]->getListeUnites().size(); j++)
					{
						for (int k = 0; k < m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> getListeTaches().size(); k++)
						{
							string tache=m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> getListeTaches()[k]->getType();
							if (tache == "Recolter")
								if (m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> getListeTaches()[k]->recolter() == false)
									m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> viderListeTaches();
							else if ( tache == "Attaquer")
							{
							}
						}
						
					}
					if(ok)
					{
						deplacementRecolte(0,0,0,14,8);
						//deplacementRecolte(0,1,0,22,22);
						
						/*m_partie->getCarte()->calculListeCasesVides();
						m_partie -> getListeJoueurs()[0]->getListeUnites()[1] -> viderListeTaches();	
						m_partie -> getListeJoueurs()[0]->getListeUnites()[1]->creerTache("DeplacementSimple",40,40);
						m_partie -> getListeJoueurs()[0]->getListeUnites()[1] -> getListeTaches()[0]->deplacementSimple(m_partie->getCarte()->getListeCasesVides(),40,40);
						m_partie->getCarte()->calculListeCasesVides();
						m_partie -> getListeJoueurs()[0]->getListeUnites()[2] -> viderListeTaches();	
						m_partie -> getListeJoueurs()[0]->getListeUnites()[2]->creerTache("DeplacementSimple",10,40);
						m_partie -> getListeJoueurs()[0]->getListeUnites()[2] -> getListeTaches()[0]->deplacementSimple(m_partie->getCarte()->getListeCasesVides(),10,40);*/
						ok=false;
					}
					
				}
		
    setThread();
}

Partie* GameModel::getPartie() const
{
	return m_partie;
}

void GameModel::setPartie(Partie * m_newPartie)
{
	m_partie=m_newPartie;
}

bool GameModel::setThread ()
{
    if (m_thread == true)
        m_thread = false;
    else
        m_thread = true;
}
bool GameModel::getThread() const
{
    return m_thread;
}

void GameModel::Run()
{
    nextStep();
}

void GameModel::DoSomething()
{
	Launch();
}

void GameModel::creerPartie(int nbJoueur, string carte)
{
    delete m_partie;
    Partie * p = new Partie (carte,nbJoueur);
    setPartie(p);
    ok = true;
}

void GameModel::deplacementRecolte(int i, int j, int k,int i_dest, int j_dest)
{
	int i_dest2=m_partie -> getListeJoueurs()[0]->getListeUnites()[0]->getI();
	int j_dest2=m_partie -> getListeJoueurs()[0]->getListeUnites()[0]->getJ();
	
	m_partie->getCarte()->calculListeCasesVides();
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> viderListeTaches();	
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j]->creerTache("DeplacementSpe",i_dest, j_dest);
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> getListeTaches()[k]->deplacementSimple(m_partie->getCarte()->getListeCasesVides(),i_dest, j_dest);
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> viderListeTaches();
	//~ m_partie -> getListeJoueurs()[i]->getListeUnites()[j]->creerTache("Recolter",i_dest, j_dest);
	//~ m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> getListeTaches()[k]->recolter();
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> viderListeTaches();
	m_partie->getCarte()->calculListeCasesVides();
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j]->creerTache("DeplacementSpe",i_dest2, j_dest2);
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> getListeTaches()[k]->deplacementSimple(m_partie->getCarte()->getListeCasesVides(),i_dest2, j_dest2);
	m_partie -> getListeJoueurs()[i]->getListeUnites()[j] -> viderListeTaches();
	
	
}
