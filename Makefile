all: autoSprite.o movimiento.o main.o
	rm -f main
	g++ main.o autoSprite.o movimiento.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o

main.o: main.cpp
	g++ -c main.cpp

autoSprite.o: autoSprite.h autoSprite.cpp
	g++ -c autoSprite.cpp

movimiento.o: movimiento.h movimiento.cpp
	g++ -c movimiento.cpp

