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
<<<<<<< HEAD
	m_partie=new Partie("maps/MaitreDeLaColline.txt", 2);
=======
	m_partie=new Partie("maps/LesDeuxPasses.txt", 2);
	thread =false;
>>>>>>> origin/master
}

GameModel::GameModel(int width, int height): m_width(width), m_height(height)
{
<<<<<<< HEAD
	m_partie=new Partie("maps/MaitreDeLaColline.txt", 2);
=======
	m_partie=new Partie("maps/LesDeuxPasses.txt", 2);
	thread =false;
>>>>>>> origin/master
}


// Destructeurs
GameModel::~GameModel()
{
	if (m_partie!=NULL)
		delete m_partie;
}

void GameModel::nextStep()
<<<<<<< HEAD
{}
=======
{
    setThread();
    setThread();
}
>>>>>>> origin/master

Partie* GameModel::getPartie() const
{
	return m_partie;
}

bool GameModel::setThread ()
{
    if (thread == true)
        thread = false;
    else
        thread = true;
}
bool GameModel::getThread() const
{
    return thread;
}

void GameModel::Run()
{
    nextStep();
}
