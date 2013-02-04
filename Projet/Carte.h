#ifndef _CARTE_H_
#define _CARTE_H_

#include <string>

class Carte {
	
	private:
		int nb_point_depart;
		
	public:
		Carte();
		Carte(std::string mon_fichier);
		~Carte();
		void chargementFichier(std::string mon_fichier);
};

#endif
