#include "autoSprite.h"

int main(){
    RenderWindow juego(VideoMode(800,600),"Litle Farm");
    AutoSprite fondo("fondo.jpg");
    fondo.escalar(800,600);
    AutoSprite *personaje;
    personaje = new AutoSprite("personaje.png");
    personaje->escalar(100,120);
    personaje->cambiarColor(61,207,222,255);
    AutoSprite *llama;
    llama = new AutoSprite("llama.png");
    llama->escalar(100,120);
    llama->ajustarPosicion(400,300);



    while(juego.isOpen()){
        Event event;
        while(juego.pollEvent(event)){
            switch(event.type){
            case Event::Closed:
                juego.close();
                exit(1);
                break;

            case Event::KeyPressed:
                int velocidad=7;
                if (Keyboard::isKeyPressed(Keyboard::Up)){
                    personaje->ajustarPosicion(personaje->getPosicionX(),personaje->getPosicionY()-velocidad);
                   
                }
                else if (Keyboard::isKeyPressed(Keyboard::Down)){
                    personaje->ajustarPosicion(personaje->getPosicionX(),personaje->getPosicionY()+velocidad);
                }
                else if (Keyboard::isKeyPressed(Keyboard::Left)){
                    personaje->ajustarPosicion(personaje->getPosicionX()-velocidad,personaje->getPosicionY());
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right)){
                    personaje->ajustarPosicion(personaje->getPosicionX()+velocidad,personaje->getPosicionY());
                }
                break;
            }
        }
        juego.clear();
        juego.draw(fondo.getSprite());
        juego.draw(llama->getSprite());
        juego.draw(personaje->getSprite());
        juego.display();
    }
    delete personaje;
    return 0;
}
