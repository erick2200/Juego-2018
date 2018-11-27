#include "SFML/Graphics.hpp"

using namespace sf;

class AutoSprite{

private:

    Texture textura;
    Sprite sprite;
    Vector2f posicion;
    Vector2f dimensiones;
    std::string imagen;
    Color color;

public:

	AutoSprite();
    AutoSprite(std::string);
    void ajustarPosicion(float,float);
    void escalar(float,float);
    void cambiarColor(int,int,int,int);
	void setImagen(std::string);
	
    Texture getTexture();
    Sprite getSprite();
    std::string getImagen();
    float getTamanioX();
    float getTamanioY();
    float getPosicionX();
    float getPosicionY();

} ;
