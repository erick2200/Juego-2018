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

    AutoSprite(std::string);
    void ajustarPosicion(float,float);
    void escalar(float,float);
    void cambiarColor(int,int,int,int);

    Texture getTexture();
    Sprite getSprite();
    float getTamanioX();
    float getTamanioY();
    float getPosicionX();
    float getPosicionY();

} ;
