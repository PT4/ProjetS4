#ifndef __JEU_H__
#define __JEU_H__

#include "Level.h"

class Jeu 
{
	private :
		int _numlevel;
		int _score;
		int _nbRouteV;
		int _nbRouteH;
		int _nbFeu;
		int _nbVoiture;
	
		Level *_level;
	
	public :
		Jeu (int level);
		~Jeu ();
		int getScore () const;
		int getNiveau () const;
		Level* getLevel() const;
		void setScore(int score);
		void setLevel ();
		void resetLevel();
		
	
};

#endif
