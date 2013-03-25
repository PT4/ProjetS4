#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>
#include <vector>

class Unite;
class Carte;
class Entite;
class Ressource;

class Tache {
	private:
		std::string m_type;
		Ressource* m_ressource;
		Unite* m_unite;
		Carte* m_carte;
		bool estActive;

	public:
		Tache();
		Tache(std::string type,Unite* me,int cibleI,int cibleJ,Carte* carte);
		~Tache();
		void attaquer(Entite *entite);
		bool Recolter();
		void setCarte(Carte *carte);
		std::string getType() const;
		Carte* getCarte () const;
};

#endif
