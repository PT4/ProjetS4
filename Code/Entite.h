#ifndef _ENTITE_H_
#define _ENTITE_H_

#include <string>

class Entite {
	
	protected:
		std::string m_nom;
		int m_pointsVie;
		
	public:
		Entite();
		Entite(std::string nom, int pointsVie);
		~Entite();
		int getPointsVie() const;
		std::string getNom() const;
		void setPointsVie(int pointsVie);
};

#endif
