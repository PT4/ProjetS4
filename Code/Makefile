CC=g++ -g -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=GameModel.o GameView.o Main.o Partie.o Joueur.o Entite.o Unite.o Recolteur.o Soldat.o Batiment.o Base.o Caserne.o Entrepot.o Carte.o Objet.o Obstacle.o Ressource.o EmplacementDepart.o CaseVide.o Tache.o
TARGET=BearCraft


$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system -g -o $(TARGET)

GameModel.o : GameModel.cc GameModel.h
	$(CC) -c GameModel.cc
	
GameView.o : GameView.cc GameView.h
	$(CC) -c GameView.cc
	
Main.o : Main.cc
	$(CC) -c Main.cc

Partie.o : Partie.cc Partie.h
	$(CC) -c Partie.cc
	
Carte.o : Carte.cc Carte.h
	$(CC) -c Carte.cc
	
Joueur.o : Joueur.cc Joueur.h
	$(CC) -c Joueur.cc
	
Objet.o : Objet.cc Objet.h
	$(CC) -c Objet.cc
	
Entite.o : Entite.cc Entite.h
	$(CC) -c Entite.cc
	
Unite.o : Unite.cc Unite.h
	$(CC) -c Unite.cc
	
Recolteur.o : Recolteur.cc Recolteur.h
	$(CC) -c Recolteur.cc
	
Soldat.o : Soldat.cc Soldat.h 
	$(CC) -c Soldat.cc
	
Batiment.o : Batiment.cc Batiment.h
	$(CC) -c Batiment.cc

Base.o : Base.cc Base.h
	$(CC) -c Base.cc

Caserne.o : Caserne.cc Caserne.h
	$(CC) -c Caserne.cc

Entrepot.o : Entrepot.cc Entrepot.h
	$(CC) -c Entrepot.cc

Obstacle.o : Obstacle.cc Obstacle.h
	$(CC) -c Obstacle.cc
	
EmplacementDepart.o : EmplacementDepart.cc EmplacementDepart.h
	$(CC) -c EmplacementDepart.cc

Ressource.o : Ressource.cc Ressource.h
	$(CC) -c Ressource.cc

CaseVide.o : CaseVide.cc CaseVide.h
	$(CC) -c CaseVide.cc

Tache.o : Tache.cc Tache.h
	$(CC) -c Tache.cc

clean :
	rm -rf *.o $(TARGET)
