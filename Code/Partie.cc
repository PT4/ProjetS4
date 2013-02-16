#include "Partie.h"

#include <cstdlib>
#include <iostream>

using namespace std;

//Constructeurs
Partie::Partie()
{
}

Partie::Partie(string nomMap, int nbJoueurs):m_monFichier(nomMap)
{
	m_carte=new Carte(m_monFichier);
	//Ne pas oublier de faire un test sur le nombre maximal de joueur.
	for (int i=0;i<nbJoueurs;i++)
	{
		m_listeDeJoueurs.push_back(new Joueur());
	}
	m_carte->choisirEmplacementDepartJoueur(m_listeDeJoueurs);
}

//Destructeur
Partie::~Partie()
{
	for (int i=0; i<m_listeDeJoueurs.size(); i++)
	{
		delete m_listeDeJoueurs[i];
		m_listeDeJoueurs[i]=0;
	}
	if (m_carte!=NULL)
	{
		delete m_carte;
		m_carte=0;
	}
}

// Accesseurs en lecture
Carte* Partie::getCarte() const
{
	return m_carte;
}

vector<Joueur*> Partie:: getListeJoueurs() const
{
	return m_listeDeJoueurs;
}
