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
}

GameModel::GameModel(int width, int height): m_width(width), m_height(height)
{
}


// Destructeurs
GameModel::~GameModel()
{}

void GameModel::nextStep()
{
	Soldat s1,s2;
	
	cout << " Avant attaque " << endl;
	cout << "Soldat1 : " << "Vie " << s1.getPointsVie()  << " " << "Armure " << s1.getArmure() << " " << "Degat " << s1.getDegat() << endl;
	cout << "Soldat2 : " << "Vie " << s2.getPointsVie() << endl;
	
	s1.attaquer(s2);
	
	cout << " Après attaque " << endl;
	cout << "Soldat1 : " << "Vie " << s2.getPointsVie() << endl;
}
