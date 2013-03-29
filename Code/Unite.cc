#include "Unite.h"
#include "Joueur.h"
#include "Carte.h"

#include <cstdlib>

using namespace std;

//Constructeurs
Unite::Unite(): Entite(), m_seDeplace(0), m_attaque(0)
{}

Unite::Unite(string nom, int pointsVie, int prixMiel, int vitesse, int degat, int rayonAttaque): Entite(nom, pointsVie),
				m_prixMiel(prixMiel), m_vitesse(vitesse), m_degat(degat), m_rayonAttaque(rayonAttaque), m_seDeplace(0), m_attaque(0)
{}

Unite::Unite(string nom, int pointsVie, Joueur* joueur, int prixMiel, int vitesse, int degat, int rayonAttaque,Carte* carte): Entite(nom, pointsVie, joueur,carte),
				m_prixMiel(prixMiel), m_vitesse(vitesse), m_degat(degat), m_rayonAttaque(rayonAttaque), m_seDeplace(0), m_attaque(0)
{}

Unite::Unite(int i, int j, string nom, int pointsVie, Joueur* joueur, int prixMiel, int vitesse, int degat, int rayonAttaque,Carte* carte): Entite(i, j, true, nom, pointsVie, joueur,carte),
				m_prixMiel(prixMiel), m_vitesse(vitesse), m_degat(degat), m_rayonAttaque(rayonAttaque), m_seDeplace(0), m_attaque(0)
{}

//Destructeur
Unite::~Unite()
{
	m_listeTaches.clear();
}

//Accesseurs en lecture
bool Unite::getDeplacement() const {
	return m_seDeplace;
}

bool Unite::getAttaque() const {
	return m_attaque;
}

int Unite::getDegat() const
{
	return m_degat;
}

//Accesseur en écriture
void Unite::setDeplacement(bool seDeplace) {
	m_seDeplace=seDeplace;
}

void Unite::setAttaque(bool attaque) {
	m_attaque=attaque;
}

//Methodes
void Unite::seDeplacer() {

}

void Unite::attaquer(Entite& cible) {
	cible.setPointsVie(cible.getPointsVie()-m_degat);
	cible.setPointsVie(getDegat());
}

void Unite::creerTache(string type,int i,int j) {
	m_listeTaches.push_back(new Tache(type,this,i,j));
}

vector<Tache*> Unite::getListeTaches() const
{
	return m_listeTaches;
}

void Unite::supprimerTache(int indice) {
	m_listeTaches.erase(m_listeTaches.begin()+indice);
}

void Unite::viderListeTaches()
{
	m_listeTaches.clear();
}
