CC=g++ -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=Voiture.o Camion.o Police.o Vehicule.o Feu.o Objet.o Route.o GameModel.o GameView.o Main.o Niveau.o Partie.o Croisement.o
TARGET=TrafficJam


$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

Voiture.o : Voiture.cc Voiture.h
	$(CC) -c Voiture.cc
	
Camion.o : Camion.cc Camion.h
	$(CC) -c Camion.cc
	
Police.o : Police.cc Police.h
	$(CC) -c Police.cc

Vehicule.o : Vehicule.cc Vehicule.h
	$(CC) -c Vehicule.cc
	
Feu.o : Feu.cc Feu.h
	$(CC) -c Feu.cc
	
Objet.o : Objet.cc Objet.h
	$(CC) -c Objet.cc

Route.o : Route.cc Route.h
	$(CC) -c Route.cc
	
GameModel.o : GameModel.cc GameModel.h
	$(CC) -c GameModel.cc

GameView.o : GameView.cc GameView.h
	$(CC) -c GameView.cc

Main.o : Main.cc GameModel.h GameView.h
	$(CC) -c Main.cc

Niveau.o : Niveau.cc Niveau.h
	$(CC) -c Niveau.cc
	
Partie.o : Partie.cc Partie.h
	$(CC) -c Partie.cc
	
Croisement.o : Croisement.cc Croisement.h
	$(CC) -c Croisement.cc

clean :
	rm -rf *.o $(TARGET)

# do not delete



#~ CXX=g++
#~ CXXFLAGS= -g -Wall -pedantic
#~ LDFLAGS= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
#~ EXEC = TrafficJam
#~ EXECPATH = .
#~ OBJ  = main.o GameModel.o GameView.o 
#~ 
#~ all: $(EXEC)
#~ 
#~ TrafficJam: $(OBJ)
	#~ $(CXX) $(LDFLAGS) -o $(EXECPATH)/$@ $(OBJ) 
#~ 
#~ main.o: main.cc GameView.h GameModel.h
	#~ $(CXX) -o $@ -c $< $(CXXFLAGS)
	#~ 
#~ GameView.o: GameView.cc GameView.h
	#~ $(CXX) -o $@ -c $< $(CXXFLAGS)
#~ 
#~ GameModel.o: GameModel.cc GameModel.h
	#~ $(CXX) -o $@ -c $< $(CXXFLAGS)
#~ 
#~ clean:
	#~ @rm -rf *.o $(EXECPATH)/$(EXEC)
