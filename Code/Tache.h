#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>
#include <vector>
#include <SFML/System.hpp>

class Unite;
class Carte;
class Entite;
class Ressource;
class Recolteur;
class Soldat;
class CaseVide;

class Tache : public sf::Thread{
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
		bool m_thread;

		 virtual void Run();
	public:
		Tache();
		Tache(std::string type,Unite* me,int cibleI,int cibleJ);
		Tache(std::string type,Unite* me,Entite* cible);
		~Tache();
		void attaquer(Entite *entite);
		bool recolter();
		void deplacementSimple();
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
		void DoSomething();
		bool getThread() const;
        bool setThread ();
        void suppressionTache();
};

#endif
