#ifndef _CROISEMENT_H_
#define _CROISEMENT_H_

#include "Objet.h"
#include "Feu.h"
#include <vector>

class Croisement : public Objet 
{
	private :
		Feu* m_feu;
		bool m_presenceFeu;
		int m_nbVehiculePresent;
		bool m_collision;
	public :
		Croisement();
		~Croisement();
		bool getPresenceFeu() const;
		Feu* getFeu() const;
		int getNbVehiculePresent() const;
		void setPresenceFeu(bool presenceFeu);
		void setPosXCroisement(std::vector <Croisement*> listeDeCroisement, int posX, int i);
		void setNbVehiculePresent(int nbVehicule);
		void genererFeu();
		bool detecterCollision();
};

#endif
