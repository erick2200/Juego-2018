#include "autosprite.h"

AutoSprite::AutoSprite::AutoSprite(){
	imagen="";
	posicion.x=0;
    posicion.y=0;
    dimensiones.x =0;
    dimensiones.y =0;
}
AutoSprite::AutoSprite(std::string archivo){
    textura.loadFromFile(archivo);
    sprite.setTexture(textura);
	imagen=archivo;
    posicion.x=0;
    posicion.y=0;
    dimensiones.x = textura.getSize().x;
    dimensiones.y = textura.getSize().y;
}

void AutoSprite::ajustarPosicion(float x,float y){
    posicion.x = x;
    posicion.y = y;
    sprite.setPosition(posicion);
}

void AutoSprite::escalar(float x,float y){
	sprite.setScale(x/textura.getSize().x,y/textura.getSize().y);
    dimensiones.x =x;
    dimensiones.y =y;
   
}

void AutoSprite::cambiarColor(int r,int g,int b,int a){
    color.r=r;
    color.g=g;
    color.b=b;
    color.a=a;
    sprite.setColor(color);
}

sf::Sprite AutoSprite::getSprite(){
    return sprite;
}

sf::Texture AutoSprite::getTexture(){
    return textura;
}

void AutoSprite::setImagen(std::string img){
	textura.loadFromFile(img);
    sprite.setTexture(textura);
	imagen=img;
}

std::string AutoSprite::getImagen(){
	return imagen;
}

float AutoSprite::getPosicionX(){
    return posicion.x;
}

float AutoSprite::getPosicionY(){
    return posicion.y;
}

float AutoSprite::getTamanioX(){
    return dimensiones.x;
}

float AutoSprite::getTamanioY(){
    return dimensiones.y;
}


