#include "movimiento.h"
#include <iostream>
using namespace sf;
using namespace std;

//crea intervalo de tiempo de aprox 1 seg
void wait(){
	int i=clock()+80000;
	while(i>clock()){}
}

	


int main(){
    RenderWindow juego(VideoMode(800,600),"Litle Farm");
    sf::View view(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f,600.f));
	juego.setFramerateLimit(60);
	//juego escenario1    
    EscenarioPrincipal escenario1;
    
    //juego casa
	AutoSprite persona("img/0upersona.png"); 
    AutoSprite fondocasa("img/casa.jpg");
    fondocasa.escalar(600,600);
    Escena casa;
    casa.addSprite(fondocasa);
    persona.ajustarPosicion(10,10);
    casa.addSprite(persona);
    
    
    //menuprincipal
    AutoSprite fondo("img/fondo.jpg");
    AutoSprite menusalir("img/MENUSALIR.jpg");
    menusalir.ajustarPosicion(250,400);
    menusalir.escalar(200,60);
    AutoSprite menujugar("img/MENUJUGAR.jpg");
    menujugar.ajustarPosicion(250,200);
    menujugar.escalar(200,60);
    AutoSprite seleccionar("img/SELECCIONAR.png");
    seleccionar.ajustarPosicion(250,200);
    seleccionar.escalar(200,60);
    Menu menuprincipal(2,1);
    menuprincipal.addSprite(fondo);	
    menuprincipal.addSprite(menujugar);    
    menuprincipal.addSprite(menusalir);
	menuprincipal.addSprite(seleccionar);    
	
	//INVENTARIO
	Inventario inventario(4,4);
	
		
	//TIENDA SEEDS
	Tienda tienda(1,3);	

	//Tiempo
	Tiempo tiempo;
	
    unsigned long i=0;
    int escenario=0;
    int escenariotemp=escenario;
    while(juego.isOpen()){
		
		tiempo.setTime();
		cout << tiempo.getTime() << endl;

        Event event;
        while(juego.pollEvent(event)){
            switch(event.type){
            case Event::Closed:
                juego.close();
        	}
    	}
    	// 0)menuprincipal  1)escenario1  2)casa  3)inventario  4)tienda
    	switch(escenario){
    		case(0):{ //menuprincipal
    			menuprincipal.mover(1,0,200);
    			menuprincipal.mostrar(juego);
    			if(menuprincipal.escena[3].getPosicionY()==200&&Keyboard::isKeyPressed(Keyboard::X))
    				escenario=1;
    				wait();
    			if(menuprincipal.escena[3].getPosicionY()==400&&Keyboard::isKeyPressed(Keyboard::X))
    				juego.close();
				break;
			}
			case(1):{ //escenario1
				escenario1.mover(escenario1.getSize()-1,3,3);
        		escenario1.mostrar(juego);
				escenario1.setview(juego,escenario1.getSize()-1);
				if(Keyboard::isKeyPressed(Keyboard::C))
					escenario1.changeTerreno(inventario.getselect());
				
				if(escenario1.checkPosition(895,920,285,310)&&Keyboard::isKeyPressed(Keyboard::X))
					escenario=2;
				inventario.mostrarinventario(escenario,escenariotemp);
				if(Keyboard::isKeyPressed(Keyboard::T))
					escenario=4;
				if(Keyboard::isKeyPressed(Keyboard::N))
					escenario1.nextDay();
				break;
			}
			case(2):{ // casa
				casa.mover(1,3,3);
        		casa.mostrar(juego);
				casa.setview(juego,1);
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					escenario=1;
				inventario.mostrarinventario(escenario,escenariotemp);

				break;
			}
			case(3):{ // inventario
				juego.setView(view);
				inventario.mover(1,200,150);
				inventario.mostrar(juego);
				if(Keyboard::isKeyPressed(Keyboard::C)){
					escenario=escenariotemp;
				}
				break;
			}
			case(4):{ // tienda
				juego.setView(view);
				tienda.mover(1,200,200);
				tienda.mostrar(juego);
				if(Keyboard::isKeyPressed(Keyboard::X))
					inventario.addItem(tienda.comprar());		
				if(Keyboard::isKeyPressed(Keyboard::C))
					escenario=1;
				break;
			}
		}
		
	}
    return 0;
}
