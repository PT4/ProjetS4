#ifndef _TACHE_H_
#define _TACHE_H_

#include <string>
#include <vector>

class Unite;
class Carte;
class Entite;

class Tache {
	private:
		std::string m_type;
		Unite* m_unite;
		Carte* m_carte;
		bool estActive;
		
	public:
		Tache();
		Tache(std::string type);
		~Tache();
		void attaquer(Entite *entite);
};

#endif
