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

class Tache {
	private:
		std::string m_type;
		Ressource* m_ressource;
		Recolteur* m_recolteur;
		Soldat* m_soldat;
		Entite* m_cible;
		Carte* m_carte;
		bool estActive;

	public:
		Tache();
		Tache(std::string type,Unite* me,int cibleI,int cibleJ);
		Tache(std::string type,Unite* me,Entite* cible);
		~Tache();
		void attaquer(Entite *entite);
		bool recolter();
		void setCarte(Carte *carte);
		std::string getType() const;
		Carte* getCarte () const;
};

#endif
