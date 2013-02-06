#ifndef _PARTIE_H_
#define _PARTIE_H_

#include "Carte.h"

#include <cstring>

class Partie {
	
	private:
		std::string m_monFichier;
		Carte* m_carte;
	public:
		Partie();
		Partie(std::string nomMap);
		~Partie();
		Carte* getCarte() const;
};

#endif
