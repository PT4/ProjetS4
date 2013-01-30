#include "Partie.h"
#include "Constantes.h"

using namespace std;

//Constructeur
Partie::Partie(): m_score(0), m_niveauEnCours(1)
{
	m_niveau=new Niveau(1, 15, 13, 1, 5);
}

//Destructeur
Partie::~Partie()
{
	delete m_niveau;
}

//Accesseurs en lecture
int Partie::getScore() const
{
	return m_score;
}

Niveau * Partie::getNiveau() const
{
	return m_niveau;
}

int Partie::getNiveauEnCours() const
{
	return m_niveauEnCours;
}

vector <Route*> Partie::getRoutes()
{
	return m_niveau->getListeDeRoutes();
}
//Accesseurs en écriture
void Partie::setScore(int nb)
{
	m_score+=nb;
}

void Partie::setNiveauEnCours(int nb)
{
	m_niveauEnCours=nb;
}

//Méthodes
void Partie::genererNiveau()
{
	m_niveau=new Niveau(calculerNbRoutes(), calculerNbVehicules(), calculerTrafficAutorise(),calculerNbFeux(), calculerObjectif());
}

void Partie:: supprimerNiveau()
{
	delete m_niveau;
}

int Partie::calculerNbRoutes()
{
	if (m_niveauEnCours<4)
		return m_niveauEnCours+1;
	else if (m_niveauEnCours>=4 && m_niveauEnCours<NB_ROUTES_MAX)
			return m_niveauEnCours;
	else
		return NB_ROUTES_MAX;
}

int Partie::calculerNbVehicules()
{
	return m_niveauEnCours+5;
}

int Partie::calculerTrafficAutorise()
{
	return (m_niveau->getObjectif() + m_niveau->getObjectif()*2/3);
}

int Partie:: calculerNbFeux()
{
	return m_niveauEnCours;
}

int Partie:: calculerScore(int i, int j)
{
	switch (getRoutes()[i]->getListeDeVehicules()[j]->getVitesse())
	{
		case 1 : return 3; break;
		case 2 : return 1; break;
		case 3 : return 1; break;
	}
}

int Partie:: calculerObjectif()
{
	return m_niveauEnCours*5;
}
