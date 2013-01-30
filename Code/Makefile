CC=g++ -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=GameModel.o GameView.o Main.o
TARGET=AnimalsCraft


$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

GameModel.o : GameModel.cc GameModel.h
	$(CC) -c GameModel.cc
	
GameView.o : GameView.cc GameView.h
	$(CC) -c GameView.cc	

Main.o : Main.cc
	$(CC) -c Main.cc

clean :
	rm -rf *.o $(TARGET)
