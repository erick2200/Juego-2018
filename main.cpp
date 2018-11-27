#include "movimiento.h"
#include <iostream>
using namespace sf;
using namespace std;
//crea intervalo de tiempo de aprox 1 seg
void wait(){
	int i=clock()+150;
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
	persona.escalar(50,100);
    AutoSprite fondocasa("img/casa.jpg");
    fondocasa.escalar(600,450);
    AutoSprite cama("img/cama.png"); 
    persona.ajustarPosicion(275,350);
    cama.ajustarPosicion(450,0);
    
    Escena casa;
    casa.addSprite(fondocasa);
	casa.addSprite(cama);
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

	//Carrera de cuys
	Escena carrera;
	AutoSprite fondoCarrera("img/fondoCarrera.jpg");
	fondoCarrera.ajustarPosicion(0,0);
	fondoCarrera.escalar(800,600);
	AutoSprite cuy("img/0ucuy.jpg");
	cuy.escalar(110,65);
	cuy.ajustarPosicion(100,100);
	AutoSprite tronco("img/tronco.png");
	tronco.escalar(90,300);
	tronco.ajustarPosicion(300,200);
	carrera.addSprite(fondoCarrera);
	carrera.addSprite(tronco);
	carrera.addSprite(cuy);
	
    int escenario=0;
    int escenariotemp=escenario;
    while(juego.isOpen()){
    	
        Event event;
        while(juego.pollEvent(event)){
            switch(event.type){
            case Event::Closed:
                juego.close();
        	}
    	}
    	tiempo.setTime();
    	cout<<tiempo.getTime()<<endl;
    	// 0)menuprincipal  1)escenario1  2)casa  3)inventario  4)tienda
    	switch(escenario){
    		case(0):{ //menuprincipal
    			menuprincipal.mover(1,0,200);
    			menuprincipal.mostrar(juego);
    			if(menuprincipal.escena[3].getPosicionY()==200&&Keyboard::isKeyPressed(Keyboard::Return))
    				escenario=1;
    			if(menuprincipal.escena[3].getPosicionY()==400&&Keyboard::isKeyPressed(Keyboard::Return))
    				juego.close();
				break;
			}
			case(1):{ //escenario1
				escenario1.mover(escenario1.getSize()-1,3,3);
        		escenario1.mostrar(juego);
				escenario1.setview(juego,escenario1.getSize()-1);
				if(Keyboard::isKeyPressed(Keyboard::C))
					escenario1.changeTerreno(inventario.getselect());
				
				if(escenario1.checkPosition(900,950,285,310)&&Keyboard::isKeyPressed(Keyboard::X)&&
				   escenario1.escena[escenario1.getSize()-1].getImagen()[5]=='u'){
					casa.escena[casa.getSize()-1].setImagen("img/0upersona.png");
					escenario=2;
				}
				if(escenario1.checkPosition(950,1050,1000,1200)&&Keyboard::isKeyPressed(Keyboard::X))
					escenario=5;
					
				inventario.mostrarinventario(escenario,escenariotemp);
				if(Keyboard::isKeyPressed(Keyboard::T))
					escenario=4;

				break;
			}
			case(2):{ // casa
				casa.mover(2,3,3);
        		casa.mostrar(juego);
				casa.setview(juego,2);
				if(casa.checkPosition(275,315,345,355)&&Keyboard::isKeyPressed(Keyboard::X)
				   &&casa.escena[2].getImagen()[5]=='d'){
				   	escenario1.escena[escenario1.getSize()-1].setImagen("img/0dpersona.png");

					escenario=1;
				}
				if(casa.checkPosition(545,555,95,105)&&Keyboard::isKeyPressed(Keyboard::X)){
					escenario1.nextDay();
					casa.escena[casa.getSize()-1].ajustarPosicion(350,200);
					juego.clear();
					juego.display();

				}
					
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
				if(Keyboard::isKeyPressed(Keyboard::X)){
					inventario.addItem(tienda.comprar());

				}
				if(Keyboard::isKeyPressed(Keyboard::C))
					escenario=1;
				break;

			case(5):{
				carrera.mover(2,3,3);
        		carrera.mostrar(juego);
				carrera.setview(juego,2);
				if(Keyboard::isKeyPressed(Keyboard::Escape))
					escenario = 1 ;
				break;
			}
			}
		}
		
	}
    return 0;
}
