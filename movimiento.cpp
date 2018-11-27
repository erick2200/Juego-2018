#include "movimiento.h"
#include<SFML/Audio.hpp>

#include <iostream>

Clock reloj;
//----------------------------------------------------------------CLASS SPRITEARRAY
//constructor defecto
SpriteArray::SpriteArray(){
	size=0;
	escena=new AutoSprite[size];

}

//constructor argumento
SpriteArray::SpriteArray(const SpriteArray &_escena){
	size=_escena.getSize();
	escena=new AutoSprite[size];
	for(int i=0;i<size;i++)
		escena[i]=_escena.escena[i];
}

//destructor
SpriteArray::~SpriteArray(){
	delete[] escena;
}

// redimensionar
void SpriteArray::redimensionar(const int _size){
		AutoSprite *temp=new AutoSprite[_size];
		int minsize=(_size>size)?size:size;
		for(int i=0;i<minsize;i++)
			temp[i]=escena[i];
		delete[] escena;
		escena=temp;
		size=_size;
}

//aniadir
void SpriteArray::addSprite(AutoSprite autosprite){
	redimensionar(size+1);
	escena[size-1]=autosprite;
	
}

//aniadir en una posicion
void SpriteArray::posicionarSprite(const AutoSprite autosprite,const int pos){
	redimensionar(size+1);
	for(int i=size-1;i>pos;i--)
		escena[i]=escena[i-1];
	escena[pos]=autosprite;
}

//remover 
void SpriteArray::removeSprite(const int pos){
	for(int i=pos;i<size-1;i++)
		escena[i]=escena[i+1];
	redimensionar(size-1);
}

//ajustar vista
void SpriteArray::setview(sf::RenderWindow&a,int objeto){
	sf::View view(sf::Vector2f(350.f, 300.f), sf::Vector2f(640.f,480.f));
	view.setCenter(sf::Vector2f(escena[objeto].getPosicionX()+escena[objeto].getTamanioX()/2,escena[objeto].getPosicionY()+escena[objeto].getTamanioY()/2));
	a.setView(view);
}

//mostrar 
void SpriteArray::mostrar(sf::RenderWindow &a){
	a.clear();
	for(int i=0;i<size;i++)
		a.draw(escena[i].getSprite());
	a.display();
}

bool SpriteArray::checkPosition(int x1,int x2,int y1,int y2){
	if(escena[size-1].getPosicionX()>x1&&
	   escena[size-1].getPosicionX()<x2&&
	   escena[size-1].getPosicionY()>y1&&
	   escena[size-1].getPosicionY()<y2)
		return true;
	return false;
}

//size
int SpriteArray::getSize()const {
	return size;
}
//--------------------------------------------------------------CLASS ESCENA

Escena::Escena() : SpriteArray(){
	aux=0;
	velocidadMov=10; // a menor numero mas velocidad
}

bool Escena::upcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		if(escena[j].getTamanioX()==0&&escena[j].getTamanioY()==0)
			continue;
		int arrx[5],x=0;
		for(int i=0;i<5;i++){
			arrx[i]=a.getTamanioX()*i/4+a.getPosicionX();
			if(arrx[i]>=escena[j].getPosicionX()&&arrx[i]<=escena[j].getPosicionX()+escena[j].getTamanioX()&&&escena[j]!=&a)
				x++;
		}
		int aux1=a.getPosicionY()-cantidad;
		int aux2=escena[j].getPosicionY()+escena[j].getTamanioY();
		int aux3=a.getPosicionY()+a.getTamanioY();
		int aux4=escena[j].getTamanioY()+escena[j].getPosicionY();
		if(x>0&&aux1<=aux2&&aux3>aux4||a.getPosicionY()<=escena[0].getPosicionY())
			return false;
	}
	return true;
}

bool Escena::downcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		if(escena[j].getTamanioX()==0&&escena[j].getTamanioY()==0)
			continue;
		int arrx[5],x=0;
		for(int i=0;i<5;i++){
			arrx[i]=a.getTamanioX()*i/4+a.getPosicionX();
			if(arrx[i]>=escena[j].getPosicionX()&&arrx[i]<=escena[j].getPosicionX()+escena[j].getTamanioX()&&&escena[j]!=&a)
				x++;
		}
		int aux1=a.getPosicionY()+a.getTamanioY()+cantidad;
		int aux2=escena[j].getPosicionY();
		int aux3=a.getPosicionY();
		int aux4=escena[j].getPosicionY();
		if(x>0&&aux1>=aux2&&aux3<aux4||a.getPosicionY()+a.getTamanioY()>escena[0].getPosicionY()+escena[0].getTamanioY())
			return false;				
	}
	return true;
}

bool Escena::leftcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		if(escena[j].getTamanioX()==0&&escena[j].getTamanioY()==0)
			continue;
		int arry[5],y=0;
		for(int i=0;i<5;i++){
			arry[i]=a.getTamanioY()*i/4+a.getPosicionY();
			if(arry[i]>=escena[j].getPosicionY()&&arry[i]<=escena[j].getPosicionY()+escena[j].getTamanioY()&&&escena[j]!=&a)
				y++;
		}
		int aux1=a.getPosicionX()-cantidad;
		int aux2=escena[j].getPosicionX()+escena[j].getTamanioX();
		int aux3=a.getPosicionX()+a.getTamanioX();
		int aux4=escena[j].getPosicionX()+escena[j].getTamanioX();
		if(y>0&&aux1<=aux2&&aux3>aux4||a.getPosicionX()<escena[0].getPosicionX())
			return false;			
	}
	return true;
}

bool Escena::rightcolision(AutoSprite a,int cantidad){
	for(int j=1;j<size;j++){
		if(escena[j].getTamanioX()==0&&escena[j].getTamanioY()==0)
			continue;
		int arry[5],y=0;
		for(int i=0;i<5;i++){
			arry[i]=a.getTamanioY()*i/4+a.getPosicionY();
			if(arry[i]>=escena[j].getPosicionY()&&arry[i]<=escena[j].getPosicionY()+escena[j].getTamanioY()&&&escena[j]!=&a)
				y++;
		}
		int aux1=a.getPosicionX()+a.getTamanioX()+cantidad;
		int aux2=escena[j].getPosicionX();
		int aux3=a.getPosicionX();
		int aux4=escena[j].getPosicionX();
		if(y>0&&aux1>=aux2&&aux3<aux4||a.getPosicionX()+a.getTamanioX()>escena[0].getPosicionX()+escena[0].getTamanioX())
			return false;	
	}
	return true;
}

//mover personaje
void Escena::mover(int numero,int velocidadx,int velocidady){
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
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&upcolision(escena[numero],velocidady)){
		y-=velocidady;
		escena[numero].ajustarPosicion(x,y);
		img[5]='u';
		escena[numero].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&downcolision(escena[numero],velocidady)){
		y+=velocidady;	
		escena[numero].ajustarPosicion(x,y);
		img[5]='d';
		escena[numero].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&leftcolision(escena[numero],velocidadx)){
		x-=velocidadx;
		escena[numero].ajustarPosicion(x,y);		
		img[5]='l';
		escena[numero].setImagen(img);
		aux++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&rightcolision(escena[numero],velocidadx)){
		x+=velocidadx;	
		escena[numero].ajustarPosicion(x,y);
		img[5]='r';
		escena[numero].setImagen(img);
		aux++;
	}

}

//mover
void Escena::moverentidad(int numero,int velocidad){
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
//----------------------------------------------------CLASS ESCENARIOPRINCIPAL

//constructor
EscenarioPrincipal::EscenarioPrincipal() : Escena(){
	fondo.setImagen("img/fondo.jpg");
	persona.setImagen("img/0dpersona.png");
	casaex.setImagen("img/casaex.jpg");
	tierra.setImagen("img/0dtierra.jpg");
	minijuegos.setImagen("img/carreraFachada.jpg");
	fondo.escalar(1200,1200);
	persona.escalar(50,100);
    persona.ajustarPosicion(600,200);
    casaex.ajustarPosicion(700,0);
    casaex.escalar(500,300);
	minijuegos.escalar(150,200);
	minijuegos.ajustarPosicion(1050,1000);
    //tierra.escalar(100,100);
    addSprite(fondo);
    addSprite(casaex);
	addSprite(minijuegos);
    addSprite(persona);
    for(int i=0;i<6;i++)
    	for(int j=0;j<6;j++){
    		tierra.ajustarPosicion(j*100,600+i*100);
    		posicionarSprite(tierra,size-1);
		}
}

//interaccion del terreno
void EscenarioPrincipal::changeTerreno(std::string img){
	std::string posimg;
	int pos=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			pos++;
			posimg=escena[pos+1].getImagen();
			if(img=="img/pala.png"&&posimg[4]=='0')
				if(checkTerreno(i,j))
					escena[1+pos].setImagen("img/1dtierra.jpg");
			if(img=="img/regadera.png"&&posimg[4]=='1')
				if(checkTerreno(i,j))
					escena[1+pos].setImagen("img/2dtierra.jpg");
			if(img=="img/combo.png"&&(posimg[4]=='1'||posimg[4]=='2'))
				if(checkTerreno(i,j))
					escena[1+pos].setImagen("img/0dtierra.jpg");
		}
	}
}
bool EscenarioPrincipal::checkTerreno(float i,float j){
	std::string direccion=escena[size-1].getImagen();
	int x1=50;
	int x2=110;
	int y1=550;
	int y2=610;
	std::string direcciones="lrud";
	for(int m=0;m<4;m++){
		char dactual=direcciones[m];
		if(m==1){
			x1=-90;x2=-50;
		}
		if(m==2){
			x1=0;x2=50;y1=650;y2=700;
		}
		if(m==3){
			y1=500;y2=550;
		}
		if(checkPosition(j*100+x1,j*100+x2,y1+i*100,y2+i*100)&&
		   dactual==direccion[5])
	  		return true;
	}
	return false;
}

void EscenarioPrincipal::nextDay(){
	std::string posimg;
	int pos=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			pos++;
			posimg=escena[pos+1].getImagen();
			if(posimg=="img/2dtierra.jpg")
				escena[pos+1].setImagen("img/1dtierra.jpg");
		}
	}
}
//------------------------------------------------------CLASS MENU

//constructor
Menu::Menu(int filas,int columnas){
	this->filas=filas;
	this->columnas=columnas;
}

//mover menu
void Menu::mover(int primeraposicion/*(1)*/,int velocidadx,int velocidady){
	int x=escena[size-1].getPosicionX();
	int y=escena[size-1].getPosicionY();
	int fx=escena[primeraposicion].getPosicionX();
	int fy=escena[primeraposicion].getPosicionY();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>fy){
			y-=velocidady;
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<fy+velocidady*(filas-1)){
			y+=velocidady;	
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>fx){
			x-=velocidadx;
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<fx+velocidadx*(columnas-1)){
			x+=velocidadx;	
			escena[size-1].ajustarPosicion(x,y);
			Tiempo::esperarSeg(0.4);
	}
}


//--------------CLASS TIEMPO
Tiempo::Tiempo(){
	tiempo = new Time;
	*tiempo = reloj.getElapsedTime();
}

float Tiempo::getTime(){ // todo esto para que salga 1.1 osea un decimal :v
	float temp=tiempo->asSeconds();
	temp =temp *100000;
	int a = temp/100000;
	temp = temp-(a*100000);
	int b = temp/10000;
	temp = a+b*0.1;
	return temp;
}

void Tiempo::setTime(){
	*tiempo = reloj.getElapsedTime();
}

void Tiempo::esperarSeg(float tiemp){
	*tiempo = reloj.getElapsedTime() ;
	float aux = getTime()+tiemp;

		while(getTime() < aux){

			*tiempo = reloj.getElapsedTime() ;
		}
}

//---------------------------------------------------CLASS INVENTARIO

//constructor de inventario
Inventario::Inventario(int f,int c): Menu(f,c){ 
	factual=0;
	cactual=0;
	dinero=1000;
	matriz = new std::string*[f];
	for(int i=0;i<f;i++)
		matriz[i]=new std::string[c];
	for(int i=0;i<f;i++)
		for(int j=0;j<c;j++)
			matriz[i][j]=" ";
	regadera.setImagen("img/regadera.png");
	pala.setImagen("img/pala.png");
	hacha.setImagen("img/hacha.png");
	combo.setImagen("img/combo.png");
	fondo.setImagen("img/invmenu.jpg");
	addSprite(fondo);
	select.setImagen("img/SELECCIONAR.png");
	select.escalar(100,100);
	select.ajustarPosicion(50,25);
	addSprite(select);
	addItem(hacha);
	addItem(combo);
	addItem(pala);
	addItem(regadera);
}

//cambia el escenario al inventario
void Inventario::mostrarinventario(int &escenario,int &escenariotemp){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		escenariotemp=escenario;
		escenario=3;		
	}
}

//mover inventario
void Inventario::mover(int primeraposicion,int velocidadx,int velocidady){
	int i=0;
	int x=escena[size-1].getPosicionX();
	int y=escena[size-1].getPosicionY();
	int fx=escena[primeraposicion].getPosicionX();
	int fy=escena[primeraposicion].getPosicionY();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>fy){
			y-=velocidady;
			escena[size-1].ajustarPosicion(x,y);
			factual--;
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<fy+velocidady*(filas-1)){
			y+=velocidady;	
			escena[size-1].ajustarPosicion(x,y);
			factual++;
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>fx){
			x-=velocidadx;
			escena[size-1].ajustarPosicion(x,y);
			cactual--;
			Tiempo::esperarSeg(0.4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<fx+velocidadx*(columnas-1)){
			x+=velocidadx;	
			escena[size-1].ajustarPosicion(x,y);
			cactual++;
			Tiempo::esperarSeg(0.4);
	}
}

//aniadir objeto al inventario
void Inventario::addItem(AutoSprite iditem){
	iditem.escalar(100,100);
	for(int i=0;i<filas;i++)
		for(int j=0;j<columnas;j++)
			if(matriz[i][j]==" "){
				matriz[i][j]=iditem.getImagen();
				iditem.ajustarPosicion(50+200*j,25+150*i);
				posicionarSprite(iditem,size-1);
				return;
			}
}

//seleccion actual

std::string Inventario::getselect(){
	return matriz[factual][cactual];
}
//destructor
Inventario::~Inventario(){
	for(int i=0;i<filas;i++)
		delete[] matriz[i];
	delete[] matriz;
}

//-------------------------------------------------CLASS TIENDA

//constructor de tienda
Tienda::Tienda(int filas,int columnas) : Menu(filas,columnas){
	fondo.setImagen("img/fondotienda.jpg");
	select.setImagen("img/SELECCIONAR.png");
	tomate.setImagen("img/tomate.png");
	papa.setImagen("img/papa.png");
	maiz.setImagen("img/maiz.png");
	tomate.ajustarPosicion(100,480);
	papa.ajustarPosicion(300,480);
	maiz.ajustarPosicion(500,480);
	tomate.escalar(100,100);
	papa.escalar(100,100);
	maiz.escalar(100,100);
	select.ajustarPosicion(100,480);
	select.escalar(100,100);
	addSprite(fondo);
	addSprite(tomate);
	addSprite(papa);
	addSprite(maiz);
	addSprite(select);
}


//retorna el autosprite comprado
AutoSprite Tienda::comprar(){
	for(int i=1;i<size-1;i++)
	if(escena[size-1].getPosicionX()==escena[i].getPosicionX())
		return escena[i];
}

