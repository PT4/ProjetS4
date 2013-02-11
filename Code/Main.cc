#include <iostream>
#include <cstdlib>

#include "GameModel.h"
#include "GameView.h"
#include "Constantes.h"

#include "Soldat.h"
#include "Entrepot.h"

using namespace std;
using namespace sf;

int main()
{
	srand(time(NULL));
	
	GameModel * model = new GameModel(LARGEUR_FENETRE, HAUTEUR_FENETRE);
	GameView * view = new GameView(LARGEUR_FENETRE, HAUTEUR_FENETRE);
	view->setModel(model);
	
	while(view->treatEvents()){
		/*if (!view->getMenu(view))
			model->nextStep();*/
		view->draw();
		usleep(11000);
	}
	
	delete view;
	delete model;
	
	return EXIT_SUCCESS;
}
