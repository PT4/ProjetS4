#ifndef _OBJET_H_
#define _OBJET_H_

class Objet {
	
	private:
		int m_i;
		int m_j;
		bool m_estFranchissable;
		bool m_estDecouvert;

	public:
		Objet();
		Objet(int i, int j, bool estFranchissable);
		~Objet();
		int getI() const;
		int getJ() const;
		bool getFranchissable() const;
		bool getDecouvert() const;
		void setI(int i);
		void setJ(int j);
		void setFranchissable(bool estFranchissable);
		void setDecouvert(bool estDecouvert);
};

#endif

