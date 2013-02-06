#include "Partie.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Partie::Partie():m_monFichier("maps/MaitreDeLaColline.txt")
{
	m_carte=new Carte(m_monFichier);
}

//Destructeur
Partie::~Partie()
{}
