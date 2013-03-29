#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include <string>
#include <vector>

class Unite;
class Batiment;
class Tache;
class Entite;
class Carte;

class Joueur {

	private:
		std::string m_nom;
		int m_quantiteMiel;
		int m_quantiteBois;
		int m_population;
		std::vector<Unite*> m_listeUnites;
		std::vector<Batiment*> m_listeBatiments;
		std::vector<Entite*> m_selection;

	public:
		Joueur(Carte* carte);
		~Joueur();
		std::vector<Batiment*> getListeBatiments() const;
		std::vector<Unite*> getListeUnites() const;
		std::vector<Entite*> getSelection() const;
		void ajouterBatiment(int type, int i, int j,Carte* carte);
		void ajouterUnite(int type, int i, int j,Carte* carte);
		void inverseCoordonnee(double &a,double &b);
		void remplirSelection(double clicX, double clicY, double clicTempX, double clicTempY);
		void viderSelection();

		int getPopulation() const;
		void setPopulation(int pop);
		int getQuantiteMiel() const;
		void setQuantiteMiel(int miel);
		int getQuantiteBois() const;
		void setQuantiteBois(int bois);
};

#endif
