#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_

#include <SFML/System.hpp>

class Partie;


class GameModel : private sf::Thread{
	private:
		int m_width, m_height;
		Partie* m_partie;
		bool ok ;
		bool m_thread;

        virtual void Run();
	public:

		GameModel();
		GameModel(int width, int height);
		~GameModel();
		void nextStep();
		Partie* getPartie() const;
		void setPartie(Partie * m_newPartie);
		void DoSomething();
		bool getThread() const;
        bool setThread ();
        void creerPartie(int nbJoueur, std::string carte);
        void deplacementRecolte(int i, int j, int k,int i_dest, int j_dest);

};
#endif
