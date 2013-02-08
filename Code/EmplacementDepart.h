#ifndef _EMPLACEMENTDEPART_H_
#define _EMPLACEMENTDEPART_H_

#include "Objet.h"

class EmplacementDepart : public Objet {
	
	private:
		bool m_estOccuper;
	public:
		EmplacementDepart();
		EmplacementDepart(int i, int j);
		~EmplacementDepart();
		bool getOccupation() const;
		void setOccupation(bool estOccuper);
};

#endif
