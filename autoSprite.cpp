#include "autoSprite.h"


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
	sprite.setScale(x/dimensiones.x,y/dimensiones.y);
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

Sprite AutoSprite::getSprite(){
    return sprite;
}

Texture AutoSprite::getTexture(){
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

