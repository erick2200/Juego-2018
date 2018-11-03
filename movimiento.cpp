#include "movimiento.h"
#include<SFML/Audio.hpp>


SpriteArray::SpriteArray(){
	size=0;
	escena=new AutoSprite[size];

	aux=0;
	velocidadMov=10; // a menor numero mas velocidad
	buffer.loadFromFile("paso.wav");
    sonido.setBuffer(buffer);
	cancion.openFromFile("fondo.ogg");
	cancion.setVolume(30);
}


SpriteArray::SpriteArray(SpriteArray &_escena){
	size=_escena.getSize();
	escena=new AutoSprite[size];
	for(int i=0;i<size;i++)
		escena[i]=_escena.escena[i];
}

SpriteArray::~SpriteArray(){
	delete[] escena;
}

void SpriteArray::redimensionar(const int _size){
		AutoSprite *temp=new AutoSprite[_size];
		for(int i=0;i<size;i++)
			temp[i]=escena[i];
		delete[] escena;
		escena=temp;
		size=_size;
}


void SpriteArray::addSprite(const AutoSprite autosprite){
	redimensionar(size+1);
	escena[size-1]=autosprite;
	
}

void SpriteArray::posicionarSprite(const AutoSprite autosprite,const int pos){
	redimensionar(size+1);
	for(int i=size-1;i>pos;i--)
		escena[i]=escena[i-1];
	escena[pos]=autosprite;
}

void SpriteArray::removeSprite(const int pos){
	for(int i=pos;i<size-1;i++)
		escena[i]=escena[i+1];
	redimensionar(size-1);
}
int SpriteArray::getSize()const {
	return size;
}

void SpriteArray::setview(RenderWindow&a,int objeto){
	sf::View view(sf::Vector2f(350.f, 300.f), sf::Vector2f(640.f, 480.f));
	view.setCenter(sf::Vector2f(escena[objeto].getPosicionX()+escena[objeto].getTamanioX()/2,escena[objeto].getPosicionY()+escena[objeto].getTamanioY()/2));
	a.setView(view);
}

void SpriteArray::mostrar(sf::RenderWindow &a){
	for(int i=0;i<size;i++)
		a.draw(escena[i].getSprite());
}


bool SpriteArray::upcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		int arrx[5],x=0;
		for(int i=0;i<5;i++){
			arrx[i]=a.getTamanioX()*i/4+a.getPosicionX();
			if(arrx[i]>=escena[j].getPosicionX()&&arrx[i]<=escena[j].getPosicionX()+escena[j].getTamanioX()&&&escena[j]!=&a)
				x++;
		}
		if(x>0&&a.getPosicionY()-cantidad<=escena[j].getPosicionY()+escena[j].getTamanioY()&&a.getPosicionY()+a.getTamanioY()>escena[j].getTamanioY()+escena[j].getPosicionY())
			return false;
	}
	return true;
}

bool SpriteArray::downcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		int arrx[5],x=0;
		for(int i=0;i<5;i++){
			arrx[i]=a.getTamanioX()*i/4+a.getPosicionX();
			if(arrx[i]>=escena[j].getPosicionX()&&arrx[i]<=escena[j].getPosicionX()+escena[j].getTamanioX()&&&escena[j]!=&a)
				x++;
		}
		if(x>0&&a.getPosicionY()+a.getTamanioY()+cantidad>=escena[j].getPosicionY()&&a.getPosicionY()<escena[j].getPosicionY())
			return false;				
	}
	return true;
}

bool SpriteArray::leftcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		int arry[5],y=0;
		for(int i=0;i<5;i++){
			arry[i]=a.getTamanioY()*i/4+a.getPosicionY();
			if(arry[i]>=escena[j].getPosicionY()&&arry[i]<=escena[j].getPosicionY()+escena[j].getTamanioY()&&&escena[j]!=&a)
				y++;
		}
		if(y>0&&a.getPosicionX()-cantidad<=escena[j].getPosicionX()+escena[j].getTamanioX()&&a.getPosicionX()+a.getTamanioX()>escena[j].getPosicionX()+escena[j].getTamanioX())
			return false;			
	}
	return true;
}

bool SpriteArray::rightcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		int arry[5],y=0;
		for(int i=0;i<5;i++){
			arry[i]=a.getTamanioY()*i/4+a.getPosicionY();
			if(arry[i]>=escena[j].getPosicionY()&&arry[i]<=escena[j].getPosicionY()+escena[j].getTamanioY()&&&escena[j]!=&a)
				y++;
		}
		if(y>0&&a.getPosicionX()+a.getTamanioX()+cantidad>=escena[j].getPosicionX()&&a.getPosicionX()<escena[j].getPosicionX())
			return false;	
	}
	return true;
}
void SpriteArray::mover(int numero,int velocidad){
	int x=escena[numero].getPosicionX();
	int y=escena[numero].getPosicionY();
	std::string img =escena[numero].getImagen();

	if(aux<velocidadMov){
		img[4]='1';
	}
	else if (aux<velocidadMov*2){
		img[4]='2';
	}
	else if (aux<velocidadMov*3){
		img[4]='0';
	}
	else{
		aux=0;
		sonido.play();
	}	

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&upcolision(escena[numero],velocidad)){
		y-=velocidad;
		escena[numero].ajustarPosicion(x,y);
		img[5]='u';
		escena[numero].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&downcolision(escena[numero],velocidad)){
		y+=velocidad;	
		escena[numero].ajustarPosicion(x,y);
		img[5]='d';
		escena[numero].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&leftcolision(escena[numero],velocidad)){
		x-=velocidad;
		escena[numero].ajustarPosicion(x,y);		
		img[5]='l';
		escena[numero].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&rightcolision(escena[numero],velocidad)){
		x+=velocidad;	
		escena[numero].ajustarPosicion(x,y);
		img[5]='r';
		escena[numero].setImagen(img);
		aux++;
	}

	if(Keyboard::isKeyPressed(Keyboard::O))
            cancion.play();

	
}
void SpriteArray::moverentidad(int numero,int velocidad){
	int ran=rand()%100+1;
	int x=escena[numero].getPosicionX();
	int y=escena[numero].getPosicionY();
	if (upcolision(escena[numero],velocidad)&&ran==1){
		y-=velocidad;
		escena[numero].ajustarPosicion(x,y);
	}else
	if (downcolision(escena[numero],velocidad)&&ran==2){
		y+=velocidad;	
		escena[numero].ajustarPosicion(x,y);
	}else
	if (leftcolision(escena[numero],velocidad)&&ran==3){
		x-=velocidad;
		escena[numero].ajustarPosicion(x,y);		
	}else
	if (rightcolision(escena[numero],velocidad)&&ran==4){
		x+=velocidad;	
		escena[numero].ajustarPosicion(x,y);
	}

  

}
