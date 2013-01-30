#ifndef _OBJET_H_
#define _OBJET_H_

class Objet
{
	protected :
		float m_posX;
		float m_posY;
		bool m_estVertical;
	public:
		Objet();
		Objet(float posX, float posY);
		Objet(float posX, float posY, bool estVertical);
		~Objet();
		float getPositionX() const;
		float getPositionY() const;
		bool getSens() const;
		void setPosX(float posX);
		void setPosY(float posY);
		void setSens(bool estVertical);
};

#endif
