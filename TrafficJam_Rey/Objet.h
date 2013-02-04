#ifndef __OBJET_H__
#define __OBJET_H__

class Objet 
{
	protected :
	
		int _X;
		int _Y;
		int _taille;
		bool _horizontale;
	
	public :
		Objet() ;
		Objet(int x,int y,int taille) ;
		~Objet() ;
	
		int getX () const;
		int getY () const;
		int getTaille () const;
		bool getHorizontale () const;
	
		void setX (int x) ;
		void setY (int y) ;
};

#endif
