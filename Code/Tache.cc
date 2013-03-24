#include "Tache.h"
#include "Joueur.h"
#include "Unite.h"
#include <iostream>

using namespace std;

Tache::Tache():m_type("")
{}

Tache::Tache(string type): m_type(type)
{
	cout << "Destruction Tache" << endl;
}

Tache::~Tache()
{
	m_unite = NULL;
	m_carte = NULL;
}
