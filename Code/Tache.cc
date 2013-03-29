#include "Tache.h"
#include "Joueur.h"
#include "Unite.h"
#include "Entite.h"
#include "Soldat.h"
#include "Constantes.h"
#include "Ressource.h"
#include "Recolteur.h"
#include "Carte.h"
#include "CaseVide.h"
#include <cmath>
#include <iostream>

using namespace std;

Tache::Tache():m_type("")
{}

Tache::Tache(string type,Unite* me,int cibleI,int cibleJ): m_type(type)
{
	cout << "Constructeur tache"<<endl;

	m_recolteur=dynamic_cast<Recolteur*>(me);

    if (m_type == "Recolter" && m_recolteur != NULL)
	{
		m_soldat = NULL;
		m_cible = NULL;
		for (int i = 0; i < m_recolteur -> getCarte() -> getListeRessources().size(); i++)
		{
			if (m_recolteur -> getCarte() -> getListeRessources()[i]->getI() == cibleI && m_carte -> getListeRessources()[i]->getJ() == cibleJ)
				m_ressource = m_carte -> getListeRessources()[i];
		}
	}
	else if (m_type=="DeplacementSimple")
	{
		m_unite=me;
		for(int i=0;i<m_unite->getCarte()->getListeCasesVides().size();i++)
			if(m_unite->getCarte()->getListeCasesVides()[i]->getI()==cibleI && m_unite->getCarte()->getListeCasesVides()[i]->getJ()==cibleJ)
				m_dest=m_unite->getCarte()->getListeCasesVides()[i];
	}
	else if(m_type=="DeplacementSpe")
	{
		m_unite=me;
		for(int i=0;i<m_unite->getCarte()->getListeCasesVides().size();i++)
			if(m_unite->getCarte()->getListeCasesVides()[i]->getI()==cibleI && m_unite->getCarte()->getListeCasesVides()[i]->getJ()==cibleJ)
				m_dest=m_unite->getCarte()->getListeCasesVides()[i];
	}
}

Tache::Tache(string type,Unite* me,Entite* cible): m_type(type) , m_cible(cible)
{
	m_type = "Attaquer";
	m_soldat=dynamic_cast<Soldat*>(me);
	if (m_soldat == NULL)
	{
		cout << "Erreur ce n'est pas un soldat" << endl;
	}
	m_ressource = NULL;
	m_recolteur = NULL;
}

Tache::~Tache()
{
    cout << "Destruction Tache" << endl;
	m_recolteur = NULL;
	m_carte = NULL;
}

void Tache::attaquer(Entite *entite) {
	entite->setPointsVie(m_soldat->getDegat());
	if (entite->getPointsVie() == 0)
		delete entite;
}

void Tache::setCarte(Carte *carte)
{
	m_carte = carte;
	cout << m_carte << endl;
}

Carte* Tache::getCarte() const
{
	return m_carte;
}

bool Tache::recolter()
{
	if (m_ressource -> getStock() <= 0)
	{
		m_recolteur -> getCarte() -> supprime(m_ressource -> getI(),m_ressource -> getJ());
		return false;
	}
	else
	{
		m_ressource -> setStock (POIDS_TRANSPORTE_MAX);
		m_recolteur -> setPoids (POIDS_TRANSPORTE_MAX);
		return true;
	}
}

int Tache::reccupererIDcase(vector<CaseVide*> &v, CaseVide* c)
{
	int result=-1;
	for (int i=0;i<v.size();i++)
	{
		if (v[i]->getI()==c->getI() && v[i]->getJ()==c->getJ())
			result = i;
	}
	return result;
}

int Tache::reccupererIDcaseCoord(vector<CaseVide*> &v,int x, int y)
{
	int result=-1;
	for (int i=0;i<v.size();i++)
	{
		if (v[i]->getI()==x && v[i]->getJ()==y)
			result = i;
	}
	return result;
}

void Tache::initialisation(vector<CaseVide*> &v)
{
	for (int i=0;i<v.size();i++)
		v[i]->setVisite(false);
}

void Tache::testCoins(vector<CaseVide*> &v, CaseVide* d, int i, vector<CaseVide*> &result)
{
	//Haut gauche
	if(d->getI()==0 && d->getJ()==0)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()+1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()+1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
	//Haut droite
	if(d->getI()==0 && d->getJ()==49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()-1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()+1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
	//Bas droite
	if(d->getI()==49 && d->getJ()==49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()-1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()-1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
	//Bas gauche
	if(d->getI()==0 && d->getJ()==49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()+1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()-1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
}

void Tache::testBords(vector<CaseVide*> &v, CaseVide* d, int i, vector<CaseVide*> &result)
{
	//Haut
	if(d->getI()==0 && d->getJ()!=0 && d->getJ()!=49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()+1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()-1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()+1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
	//Bas
	if(d->getI()==49 && d->getJ()!=0 && d->getJ()!=49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()+1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()-1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()-1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
	//Gauche
	if(d->getI()!=0 && d->getI()!=49 && d->getJ()==0)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()+1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()+1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()-1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
	//Droite
	if(d->getI()!=0 && d->getI()!=49 && d->getJ()==49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()-1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()+1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()-1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
}

void Tache::testAilleurs(vector<CaseVide*> &v, CaseVide* d, int i, vector<CaseVide*> &result)
{
	
	if(d->getI()!=0 && d->getI()!=49 && d->getJ()!=0 && d->getJ()!=49)
	{
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()-1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI() && v[i]->getJ()==d->getJ()+1)
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()-1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
		if(v[i]->getI()==d->getI()+1 && v[i]->getJ()==d->getJ())
			result.push_back(v[i]);
	}
}

vector<CaseVide*> Tache::trouverCasesVoisines(vector<CaseVide*> &v, CaseVide* d)
{
	vector<CaseVide*> result;
	for (int i=0;i<v.size();i++)
	{
		testCoins(v,d,i,result);
		testBords(v,d,i,result);
		testAilleurs(v,d,i,result);
	}
	return result;
}

void Tache::deplacementSimple(vector<CaseVide*> v, int i_dest, int j_dest)
{
	int f=reccupererIDcaseCoord(v,m_dest->getI(),m_dest->getJ()),id=f, taille=v.size(),d=reccupererIDcaseCoord(v,m_unite->getI(),m_unite->getJ());
	bool trouver1=false, trouver2=false;
	vector<CaseVide*> voisins;
	initialisation(v);
	int i=id;
	while(id!=d && taille!=0)
	{
		trouver1=false;
		trouver2=false;
		v[id]->setVisite(true);
		//Calcul des cases libres voisines
		voisins=trouverCasesVoisines(v,v[id]);
		//Choix de la prochaine case
		double d_min = 10000000;
		int k_min = -1;
		for (int k=0; k<voisins.size(); k++) {
			if(voisins[k]->getVisite()==false) {
				double dist = sqrt((voisins[k]->getI() - v[d]->getI()) * (voisins[k]->getI() - v[d]->getI())
					            + (voisins[k]->getJ() - v[d]->getJ()) * (voisins[k]->getJ() - v[d]->getJ()));
			    if (dist < d_min) {
					d_min = dist;
					k_min = k;
				}
			}
		}
		
		if (k_min != -1) {
				v[reccupererIDcase(v,voisins[k_min])]->setParent(id);
				id=reccupererIDcase(v,voisins[k_min]);
				v[id]->setVisite(true);
				taille--;
				trouver1=true;
		}
		//Sinon prend la première case de la liste avec une case voisine de libre
		if(!trouver1)
		{
			while(!trouver2 && i<v.size())
			{
				if(v[i]->getVisite()==true)
				{
					id=i;
					trouver2=true;
				}
				i++;
				if(i==v.size())
					i=0;
			}
		}
	}
	if(id==d)
	{
		while(v[id]->getParent()!=f)
		{
			m_unite->setI(v[v[id]->getParent()]->getI());
			m_unite->setJ(v[v[id]->getParent()]->getJ());
			sleep(1);
			id=v[id]->getParent();
		}
		m_unite->setI(v[v[id]->getParent()]->getI());
		m_unite->setJ(v[v[id]->getParent()]->getJ());
		voisins.clear();
	}
	
}

void Tache::deplacementSpe(vector<CaseVide*> v, int i_dest, int j_dest)
{
	m_unite -> getCarte()->calculListeCasesVides();
	
	int f=reccupererIDcaseCoord(v,m_dest->getI(),m_dest->getJ()),id=f, taille=v.size(),d=reccupererIDcaseCoord(v,m_unite->getI(),m_unite->getJ());
	bool trouver1=false, trouver2=false;
	vector<CaseVide*> voisins;
	initialisation(v);
	int i=id;
	while(id!=d && taille!=0)
	{
		trouver1=false;
		trouver2=false;
		v[id]->setVisite(true);
		//Calcul des cases libres voisines
		voisins=trouverCasesVoisines(v,v[id]);
		//Choix de la prochaine case
		double d_min = 10000000;
		int k_min = -1;
		for (int k=0; k<voisins.size(); k++) {
			if(voisins[k]->getVisite()==false) {
				double dist = sqrt((voisins[k]->getI() - v[d]->getI()) * (voisins[k]->getI() - v[d]->getI())
					            + (voisins[k]->getJ() - v[d]->getJ()) * (voisins[k]->getJ() - v[d]->getJ()));
			    if (dist < d_min) {
					d_min = dist;
					k_min = k;
				}
			}
		}
		
		if (k_min != -1) {
				v[reccupererIDcase(v,voisins[k_min])]->setParent(id);
				id=reccupererIDcase(v,voisins[k_min]);
				v[id]->setVisite(true);
				taille--;
				trouver1=true;
		}
		//Sinon prend la première case de la liste avec une case voisine de libre
		if(!trouver1)
		{
			while(!trouver2 && i<v.size())
			{
				if(v[i]->getVisite()==true)
				{
					id=i;
					trouver2=true;
				}
				i++;
				if(i==v.size())
					i=0;
			}
		}
	}
	if(id==d)
	{
		while(v[id]->getParent()!=f)
		{
			m_unite -> getCarte() -> setCaseMatrice(m_unite->getI(),m_unite->getJ(),4);
			m_unite->setI(v[v[id]->getParent()]->getI());
			m_unite->setJ(v[v[id]->getParent()]->getJ());
			m_unite -> getCarte() -> setCaseMatrice(m_unite->getI(),m_unite->getJ(),5);
			sleep(1);
			id=v[id]->getParent();
		}
		voisins.clear();
	}
	
}

string Tache::getType() const
{
	return m_type;
}
