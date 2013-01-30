#ifndef _FEU_H_
#define _FEU_H_

#include "Objet.h"

class Feu: public Objet
{
	private:
		bool m_estVert;
	public:
		Feu();
		~Feu();
		bool getCouleurFeu() const;
		void changerCouleurFeu();
};

#endif
