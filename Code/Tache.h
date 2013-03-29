#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>
#include <vector>

class Unite;
class Carte;
class Entite;
class Ressource;
class Recolteur;
class Soldat;
class CaseVide;

class Tache {
	private:
		std::string m_type;
		Ressource* m_ressource;
		Recolteur* m_recolteur;
		Soldat* m_soldat;
		Entite* m_cible;
		Carte* m_carte;
		Unite* m_unite;
		CaseVide* m_dest;
		bool estActive;

	public:
		Tache();
		Tache(std::string type,Unite* me,int cibleI,int cibleJ);
		Tache(std::string type,Unite* me,Entite* cible);
		~Tache();
		void attaquer(Entite *entite);
		bool recolter();
		void deplacementSimple(std::vector<CaseVide*> listeCasesVides, int i_dest, int j_dest);
		void deplacementSpe(std::vector<CaseVide*> v, int i_dest, int j_dest);
		int reccupererIDcaseCoord(std::vector<CaseVide*> &v,int x, int y);
		int reccupererIDcase(std::vector<CaseVide*> &v, CaseVide* c);
		void initialisation(std::vector<CaseVide*> &v);
		std::vector<CaseVide*> trouverCasesVoisines(std::vector<CaseVide*> &v, CaseVide* d);
		void testCoins(std::vector<CaseVide*> &v, CaseVide* d, int i, std::vector<CaseVide*> &result);
		void testBords(std::vector<CaseVide*> &v, CaseVide* d, int i, std::vector<CaseVide*> &result);
		void testAilleurs(std::vector<CaseVide*> &v, CaseVide* d, int i, std::vector<CaseVide*> &result);
		void setCarte(Carte *carte);
		std::string getType() const;
		Carte* getCarte () const;
};

#endif
