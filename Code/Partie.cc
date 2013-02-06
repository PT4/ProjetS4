#include "Partie.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Partie::Partie():m_monFichier("maps/MaitreDeLaColline.txt")
{
	m_carte=new Carte(m_monFichier);
}

Partie::Partie(string nomMap):m_monFichier(nomMap)
{
	m_carte=new Carte(m_monFichier);
}

//Destructeur
Partie::~Partie()
{}

// Accesseurs en lecture
Carte* Partie::getCarte() const
{
	return m_carte;
}
