#include "GameModel.h"
#include "Constantes.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

// Constructeurs
GameModel::GameModel() : m_width(LARGEUR_FENETRE), m_height(HAUTEUR_FENETRE)
{}

GameModel::GameModel(int width, int height): m_width(width), m_height(height)
{}


// Destructeurs
GameModel::~GameModel()
{}
