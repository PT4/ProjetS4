CC=g++ -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=Vehicule.o Feu.o Objet.o Route.o GameModel.o GameView.o main.o Level.o Jeu.o
TARGET=TrafficJam


$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

Vehicule.o : Vehicule.cpp Vehicule.h
	$(CC) -c Vehicule.cpp
	
Feu.o : Feu.cpp Feu.h
	$(CC) -c Feu.cpp
	
Objet.o : Objet.cpp Objet.h
	$(CC) -c Objet.cpp

Route.o : Route.cpp Route.h
	$(CC) -c Route.cpp
	
GameModel.o : GameModel.cpp GameModel.h
	$(CC) -c GameModel.cpp

GameView.o : GameView.cpp GameView.h
	$(CC) -c GameView.cpp

main.o : main.cpp GameModel.h GameView.h
	$(CC) -c main.cpp

Level.o : Level.cpp Level.h
	$(CC) -c Level.cpp
	
Jeu.o : Jeu.cpp Jeu.h
	$(CC) -c Jeu.cpp
	

clean :
	rm -rf *.o

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
