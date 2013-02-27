#ifndef _SOLDAT_H_
#define _SOLDAT_H_

#include "Unite.h"

class Soldat: public Unite {
	
	private:
		int m_armure;
		
	public:
		Soldat();
		Soldat(int i, int j);
		~Soldat();
		int getArmure() const;
		void setArmure(int armure);
};

#endif
