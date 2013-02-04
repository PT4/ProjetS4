#include <iostream>
#include <cstdlib>
#include "GameModel.h"
#include "GameView.h"
#include "Constantes.h"


using namespace std;
using namespace sf;

int main()
{
	srand(time(NULL));
	
	GameModel * model = new GameModel(LARGEUR_FENETRE, HAUTEUR_FENETRE);
	GameView * view = new GameView(LARGEUR_FENETRE, HAUTEUR_FENETRE);
	view->setModel(model);
	
	while(view->treatEvents())
	{
		model->nextStep();
		view->draw();
		usleep(11000);
	}
	
	return EXIT_SUCCESS;
}
