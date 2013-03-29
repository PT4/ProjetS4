#include "Joueur.h"
#include "Constantes.h"
#include "Base.h"
#include "Caserne.h"
#include "Entrepot.h"
#include "Recolteur.h"
#include "Soldat.h"
#include "Unite.h"
#include "Batiment.h"
#include "Tache.h"
#include "Entite.h"
#include "Carte.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

//Constructeurs
Joueur::Joueur(Carte* carte)
{
	for (int i=0; i<NB_RECOLTEUR_DEPART; i++)
		m_listeUnites.push_back(new Recolteur(this,carte));
	m_quantiteMiel=QUANTITE_MIEL_DEPART;
	m_quantiteBois=QUANTITE_BOIS_DEPART;
	m_population=NB_RECOLTEUR_DEPART;
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

//Accesseurs en lecture
vector<Batiment*> Joueur::getListeBatiments() const
{
	return m_listeBatiments;
}

vector<Unite*> Joueur::getListeUnites() const
{
	return m_listeUnites;
}

vector<Entite*> Joueur::getSelection() const
{
	return m_selection;
}

//Methodes
void Joueur::ajouterBatiment(int type, int i, int j,Carte* carte)
{
	switch(type)
	{
		case 1: m_listeBatiments.push_back(new Base(i, j,this,carte)); break;
		case 2: m_listeBatiments.push_back(new Caserne(i, j,this,carte)); break;
		case 3: m_listeBatiments.push_back(new Entrepot(i, j,this,carte)); break;
		default: break;
	}
}

void Joueur::ajouterUnite(int type, int i, int j,Carte* carte)
{
	switch(type)
	{
		case 1: m_listeUnites.push_back(new Recolteur(i, j,this,carte));break;
		case 2: m_listeUnites.push_back(new Soldat(i, j,this,carte)); break;
		default: break;
	}
}

void Joueur::viderSelection()
{
	m_selection.clear();
}

void Joueur::inverseCoordonnee(double &a,double &b)
{
	double temp = 0;
	temp = a;
	a  = b;
	b = temp;
}

void Joueur::remplirSelection(double clicX, double clicY, double clicTempX, double clicTempY)
{
	m_selection.clear();

	if (clicX > clicTempX)
		inverseCoordonnee(clicX,clicTempX);
	if (clicY > clicTempY)
		inverseCoordonnee(clicY,clicTempY);

	for (int i = 0; i < m_listeUnites.size();i++)
	{
		if (m_listeUnites[i]->getJ() >= clicX && m_listeUnites[i]->getJ() <= clicTempX
			&& m_listeUnites[i]->getI() >= clicY && m_listeUnites[i]->getI() <= clicTempY)
			{
				m_selection.push_back(m_listeUnites[i]);
			}
	}

	if (m_selection.size() == 0)
		for (int j=0; j<m_listeBatiments.size() ; j++) {
			if (m_listeBatiments[j]->getJ() >= clicX && m_listeBatiments[j]->getJ() <= clicTempX
				&& m_listeBatiments[j]->getI() >= clicY && m_listeBatiments[j]->getI() <= clicTempY) {
				m_selection.clear();
				m_selection.push_back(m_listeBatiments[j]);
			}
		}
	cout << "La selection contient : "<<m_selection.size() << " unites"<<endl;
}

int Joueur::getPopulation() const {
	return m_population;
}

void Joueur::setPopulation(int pop) {
	m_population = pop;
}

int Joueur::getQuantiteMiel() const {
	return m_quantiteMiel;
}

void Joueur::setQuantiteMiel(int miel) {
	m_quantiteMiel = miel;
}

int Joueur::getQuantiteBois() const {
	return m_quantiteBois;
}

void Joueur::setQuantiteBois(int bois) {
	m_quantiteBois = bois;
}

