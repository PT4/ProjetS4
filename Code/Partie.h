#ifndef _PARTIE_H_
#define _PARTIE_H_

#include <string>
#include <vector>

class Carte;
class Joueur;

class Partie {
	
	private:
		std::string m_monFichier;
		Carte* m_carte;
		std::vector<Joueur*> m_listeDeJoueurs;
	public:
		Partie();
		Partie(std::string nomMap, int nbJoueurs);
		~Partie();
		Carte* getCarte() const;
		std::vector<Joueur*> getListeJoueurs() const;
};

#endif
