#include "movimiento.h"

int main(){
    RenderWindow juego(VideoMode(800,600),"Litle Farm");
    juego.setFramerateLimit(30); 
    AutoSprite fondo("img/fondo.jpg");
    fondo.escalar(800,600);
	AutoSprite llama("img/0dpersona.png");
	llama.escalar(100,100);
    llama.ajustarPosicion(600,200);
    AutoSprite llama2("img/llama.png");
    llama2.escalar(100,100);
    llama2.ajustarPosicion(100,100);
	SpriteArray escena;
    escena.addSprite(fondo);
    escena.addSprite(llama);
    escena.addSprite(llama2);
    while(juego.isOpen()){
        Event event;
        while(juego.pollEvent(event)){
            switch(event.type){
            case Event::Closed:
                juego.close();
			
        	}
    	}
    	juego.clear();
    	escena.mover(1,2);
        escena.mostrar(juego);
		escena.setview(juego,1);
        juego.display();
	}  	
    return 0;
}
