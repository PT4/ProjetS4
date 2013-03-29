#ifndef _CASEVIDE_H_
#define _CASEVIDE_H_

#include "Objet.h"

class CaseVide : public Objet {
	
	private:
		int m_parent;
		bool m_estVisite;
	public:
		CaseVide();
		CaseVide(int i, int j);
		~CaseVide();
		bool getVisite() const;
		void setVisite(bool estVisite);
		int getParent() const;
		void setParent(int parent);
};

#endif
