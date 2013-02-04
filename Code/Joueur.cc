#include "Joueur.h"
#include "Recolteur.h"
#include "Constantes.h"

#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

//Constructeurs
Joueur::Joueur()
{
	cout << "Defaut : Joueur créé" << endl;
	for (int i=0; i<NB_RECOLTEUR_DEPART; i++)
		m_listeEntites.push_back(new Recolteur());
}

//Destructeur
Joueur::~Joueur()
{
	for (int i=0; i<m_listeEntites.size(); i++)
	{
		delete m_listeEntites[i];
		m_listeEntites[i]=0;
	}
}
