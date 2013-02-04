#include "GameView.h"
#include "GameModel.h"
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(){
	srand(time(NULL));
	GameModel * model = new GameModel(SCREEN_WIDTH, SCREEN_HEIGHT);
	GameView * view = new GameView(SCREEN_WIDTH, SCREEN_HEIGHT);
	view->setModel(model);
	
	
	
	
	while(view->treatEvents())
	{

			
		if(!view->getMenu())
			model->nextStep();
		view->draw();
		
	}
	
	delete view;
	delete model;
	
	return EXIT_SUCCESS;
}
