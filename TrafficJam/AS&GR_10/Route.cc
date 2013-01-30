#include "Route.h"
#include "Voiture.h"
#include "Camion.h"
#include "Police.h"
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

//Constructeurs
Route::Route():Objet(), m_listeDeVehicules(0), m_listeDeCroisements(0), m_numeroVehicule(0)
{}

//Destructeur
Route::~Route()
{
	for (int i=0; i<m_listeDeVehicules.size() ; i++)
	{
		delete m_listeDeVehicules[i];
		m_listeDeVehicules[i] = 0;
	}
	for (int i=0; i<m_listeDeCroisements.size(); i++)
	{
		delete m_listeDeCroisements[i];
		m_listeDeCroisements[i]=0;
	}
}

//Accesseurs en lecture
vector <Vehicule*> Route::getListeDeVehicules() const
{
	return m_listeDeVehicules;
}

vector <Croisement*> Route::getListeDeCroisements() const
{
	return m_listeDeCroisements;
}

int Route::getNumeroVehicule() const
{
	return m_numeroVehicule;
}

//Accesseur en écriture
void Route::setNumeroVehicule (int nb)
{
	m_numeroVehicule = nb;
}

//Methodes
void Route::ajouterVehicule()
{
	int nbAlea=Randomizer::Random(1,8);
	if (1<=nbAlea && nbAlea<=6)
		m_listeDeVehicules.push_back(new Voiture());
	else if (nbAlea==7)
		m_listeDeVehicules.push_back(new Camion());
	else
		m_listeDeVehicules.push_back(new Police());
}

void Route::ajouterCroisement()
{
		m_listeDeCroisements.push_back(new Croisement());
}

