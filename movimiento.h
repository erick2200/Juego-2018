#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include "autoSprite.h"
#include<SFML/Audio.hpp>

//------------------------------------------------------
class Tiempo{
	protected:
		Time *tiempo;
	public:
		Tiempo();
		float getTime();
		void setTime();
		void esperarSeg(float tiemp);
};

class SpriteArray:public Tiempo{

	protected:
		int size;
		void redimensionar(const int);
		
	public:
		AutoSprite *escena;
		
		//constructores
		SpriteArray();
		SpriteArray(const SpriteArray&);
		~SpriteArray();
	
		
		void addSprite(AutoSprite);
		void posicionarSprite(const AutoSprite,const int);
		void removeSprite(const int);
		virtual void mostrar(sf::RenderWindow &);
		void setview(sf::RenderWindow&,int);
		virtual void mover(int,int,int)=0;
		bool checkPosition(int,int,int,int);

		int getSize() const ;
};



//--------------------------------------------------------------------------
class Escena : public SpriteArray{
	public:
		int aux , velocidadMov;
		Escena();
		bool upcolision(AutoSprite,int);
		bool downcolision(AutoSprite,int);
		bool leftcolision(AutoSprite,int);
		bool rightcolision(AutoSprite,int);
		void moverentidad(int,int);
		void mover(int,int,int);
};
//---------------------------------------------------------------------------
class EscenarioPrincipal : public Escena{
	private:
		AutoSprite fondo;
		AutoSprite persona;
		AutoSprite casaex;
		AutoSprite tierra;
		bool checkTerreno(float,float);
		public:
			EscenarioPrincipal();
			void changeTerreno(std::string);
			void nextDay();
			
};

//---------------------------------------------------------------------------
class Menu : public SpriteArray{
	protected:
		int filas,columnas;
	public:
		Menu(int,int);
		virtual void mover(int,int,int);
};


//----------------------------------------------------------------------------
class Inventario : public Menu{
	private:
		AutoSprite fondo;
		AutoSprite select;
		AutoSprite hacha;
		AutoSprite pala;
		AutoSprite combo;
		AutoSprite regadera;
		int dinero;
		std::string **matriz;
		int factual,cactual;
	public:
		Inventario(int,int);
		~Inventario();
		
		void mostrarinventario(int&,int&);
		void mover(int,int,int);
		void addItem(AutoSprite autosprite);
		std::string getselect();
};
//----------------------------------------------------------------------
class Tienda : public Menu{
	private:
		AutoSprite fondo;
		AutoSprite select;
		AutoSprite tomate;
		AutoSprite maiz;
		AutoSprite papa;
	public:
		Tienda(int,int);
		AutoSprite comprar();
};


#endif
