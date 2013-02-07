#include "Joueur.h"
#include "Recolteur.h"
#include "Constantes.h"

#include <cstdlib>
#include <vector>

using namespace std;

//Constructeurs
Joueur::Joueur()
{
	for (int i=0; i<NB_RECOLTEUR_DEPART; i++)
		m_listeUnites.push_back(new Recolteur());
}

//Destructeur
Joueur::~Joueur()
{
	for (int i=0; i<m_listeUnites.size(); i++)
	{
		delete m_listeUnites[i];
		m_listeUnites[i]=0;
	}
	for (int i=0; i<m_listeBatiments.size(); i++)
	{
		delete m_listeBatiments[i];
		m_listeBatiments[i]=0;
	}
}
