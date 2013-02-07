#ifndef _RESSOURCE_H_
#define _RESSOURCE_H_

#include "Objet.h"

#include <string>

class Ressource : public Objet {
	
	private:
		std::string m_type;
		int m_stock;
		
	public:
		Ressource();
		Ressource(int i, int j, std::string type);
		~Ressource();
};

#endif
