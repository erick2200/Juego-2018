#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include "autoSprite.h"
#include<SFML/Audio.hpp>


class SpriteArray{
	private:

		int aux,velocidadMov;
		SoundBuffer buffer;
    	Sound sonido;
		Music cancion;

		int size;
		AutoSprite *escena;
		void redimensionar(const int);
		bool upcolision(AutoSprite,int);
		bool downcolision(AutoSprite,int);
		bool leftcolision(AutoSprite,int);
		bool rightcolision(AutoSprite,int);
	public:
		//constructores
		SpriteArray();
		SpriteArray(SpriteArray&);
		~SpriteArray();
	
		void addSprite(const AutoSprite);
		void posicionarSprite(const AutoSprite,const int);
		void removeSprite(const int);
		void mostrar(sf::RenderWindow &);
		void mover(int,int);
		void moverentidad(int,int);
		void setview(RenderWindow&,int);

		int getSize() const ;
};

#endif
