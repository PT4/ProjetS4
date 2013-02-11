#include "GameModel.h"
#include "Constantes.h"

#include "Soldat.h"
#include "Entrepot.h"

#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

// Constructeurs
GameModel::GameModel() : m_width(LARGEUR_FENETRE), m_height(HAUTEUR_FENETRE)
{
	m_partie=new Partie("maps/MaitreDeLaColline.txt", 2);
	m_thread = false;
}

GameModel::GameModel(int width, int height): m_width(width), m_height(height)
{
	m_partie=new Partie("maps/MaitreDeLaColline.txt", 2);
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
    setThread();
}

Partie* GameModel::getPartie() const
{
	return m_partie;
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
