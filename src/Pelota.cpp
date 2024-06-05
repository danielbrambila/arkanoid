#include "Pelota.hpp"
#include <cmath>

// Constructor de la clase Pelota
Pelota::Pelota(float radio, const sf::Vector2f & posicion, const sf::Color & color, float velocidad, float angulo)
{
    circulo.setRadius(radio);
    circulo.setPosition(posicion);
    circulo.setFillColor(color);
    circulo.setOrigin(radio, radio);

    this->velocidad = velocidad;
    establecerAngulo(angulo);
}

// Método para establecer el ángulo de la pelota
void Pelota::establecerAngulo(float angulo)
{
    velocidadVector.x = velocidad * std::cos(angulo * M_PI / 180);
    velocidadVector.y = -velocidad * std::sin(angulo * M_PI / 180);
}

// Método para obtener el ángulo de la pelota
float Pelota::obtenerAngulo()
{
    // ángulo en el rango [-180; 180]
    float angulo = std::atan2(-velocidadVector.y, velocidadVector.x) * 180 / M_PI;
    // ángulo en el rango [0; 360]
    if (angulo < 0.f)
        angulo += 360.f;
    return angulo;
}

// Método para verificar colisión con un bloque
bool Pelota::verificarColision(const Bloque & bloque)
{
    if ( (obtenerX() >= bloque.izquierda() && obtenerX() <= bloque.derecha()) ||
         (obtenerY() >= bloque.arriba() && obtenerY() <= bloque.abajo()) )
    {
        if (izquierda() < bloque.derecha() && derecha() > bloque.izquierda() && arriba() < bloque.abajo() && abajo() > bloque.arriba())
        {
            if (obtenerX() < bloque.izquierda() || obtenerX() > bloque.derecha())
            {
                velocidadVector.x *= -1;
            }
            else
            {
                velocidadVector.y *= -1;
            }
            return true;
        }
    }
    else
    {
        auto distancia = [](sf::Vector2f x1, sf::Vector2f x2)->float { return std::sqrt( pow(x1.x - x2.x, 2) + pow(x1.y - x2.y, 2) ); };

        sf::Vector2f esquina;

        if      ( distancia(obtenerPosicion(), sf::Vector2f(bloque.izquierda() , bloque.arriba())   ) <= obtenerRadio() )
            esquina = sf::Vector2f(bloque.izquierda(), bloque.arriba());
        else if ( distancia(obtenerPosicion(), sf::Vector2f(bloque.izquierda() , bloque.abajo())) <= obtenerRadio() )
            esquina = sf::Vector2f(bloque.izquierda(), bloque.abajo());
        else if ( distancia(obtenerPosicion(), sf::Vector2f(bloque.derecha(), bloque.arriba())   ) <= obtenerRadio() )
            esquina = sf::Vector2f(bloque.derecha(), bloque.arriba());
        else if ( distancia(obtenerPosicion(), sf::Vector2f(bloque.derecha(), bloque.abajo())) <= obtenerRadio() )
            esquina = sf::Vector2f(bloque.derecha(), bloque.abajo());
        else
            return false;

        float a = (-obtenerY() + esquina.y) / (obtenerX() - esquina.x);
        a = -1 / a;
        float alpha = std::atan(a) * 180 / M_PI;
        if (alpha < 0)
            alpha += 180;
        float beta = obtenerAngulo();

        // ángulo en el rango [0; 360]
        float angulo = 2 * alpha - beta;
        // ángulo en el rango [-180; 180]
        if (angulo > 180.f)
            angulo -= 360.f;
        else if (angulo <= -180.f)
            angulo += 360.f;

        if (angulo <= 0.f && angulo > -8.f)
            angulo = -8.f;
        else if (angulo > 0.f && angulo < 8.f)
            angulo = 8.f;

        establecerAngulo(angulo);

        return true;
    }

    return false;
}

// Método para verificar colisión con la paleta
bool Pelota::verificarColision(const Paleta & paleta)
{
    if (izquierda() < paleta.derecha() && derecha() > paleta.izquierda() && arriba() < paleta.abajo() && abajo() >= paleta.arriba())
    {
        float desviacion = 50.f;
        bool ladoIzquierdo = obtenerX() < paleta.getPosition().x;
        float distanciaDelCentro = std::abs(obtenerX() - paleta.getPosition().x);
        float porcentaje = distanciaDelCentro / (paleta.getSize().x / 2.f);
        float angulo = 90.f - porcentaje * desviacion * (ladoIzquierdo ? -1.f : 1.f);
        establecerAngulo(angulo);

        return true;
    }
    return false;
}

// Método para actualizar la posición de la pelota
void Pelota::Actualizar(float tiempoDelta)
{
    circulo.move(velocidadVector * tiempoDelta);
    if (izquierda() <= 0.f)
        velocidadVector.x = -velocidadVector.x;
    if (derecha() >= ObjetosGlobales::anchoVentana)
        velocidadVector.x = -velocidadVector.x;
    if (arriba() <= 0.f)
        velocidadVector.y = -velocidadVector.y;
}

// Método para dibujar la pelota en la ventana
void Pelota::Dibujar(sf::RenderWindow & ventana)
{
    ventana.draw(circulo);
}