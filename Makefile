all: autosprite.o movimiento.o main.o 
	rm -f main
	g++ main.o autosprite.o movimiento.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o

main.o: main.cpp
	g++ -c main.cpp

autosprite.o: autosprite.h autosprite.cpp
	g++ -c autosprite.cpp

movimiento.o: movimiento.h movimiento.cpp
	g++ -c movimiento.cpp
	
tiempo.o : tiempo.cpp
	g++ -c tiempo.cpp
