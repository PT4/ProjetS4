#ifndef _SOLDAT_H_
#define _SOLDAT_H_

#include "Unite.h"

#include <string>

class Soldat: public Unite {
	
	private:
		int m_armure;
		
	public:
		Soldat();
		~Soldat();
		int getArmure() const;
		void setArmure(int armure);
};

#endif
