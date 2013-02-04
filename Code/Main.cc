#include <iostream>
#include <cstdlib>

#include "GameModel.h"
#include "GameView.h"
#include "Constantes.h"

<<<<<<< HEAD
#include "Soldat.h"
#include "Entrepot.h"
=======
>>>>>>> origin/master

using namespace std;
using namespace sf;

int main()
{
	srand(time(NULL));
	
	GameModel * model = new GameModel(LARGEUR_FENETRE, HAUTEUR_FENETRE);
	GameView * view = new GameView(LARGEUR_FENETRE, HAUTEUR_FENETRE);
	view->setModel(model);
	
<<<<<<< HEAD
	Soldat s1, s2;
	
	cout << " Avant attaque " << endl;
	cout << "Soldat1 : " << "Vie " << s1.getPointsVie()  << " " << "Armure " << s1.getArmure() << " " << "Degat " << s1.getDegat() << endl;
	cout << "Soldat2 : " << "Vie " << s2.getPointsVie() << endl;
	
	s1.attaquer(s2);
	
	cout << " Après attaque " << endl;
	cout << "Soldat1 : " << "Vie " << s2.getPointsVie() << endl;
	
	while(view->treatEvents()){
		/*if (!view->getMenu(view))
			model->nextStep();*/
=======
	while(view->treatEvents())
	{
		model->nextStep();
>>>>>>> origin/master
		view->draw();
		usleep(11000);
	}
	
	return EXIT_SUCCESS;
}
