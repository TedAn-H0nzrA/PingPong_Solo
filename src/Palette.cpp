#include <Palette.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


// Constructeur
Palette::Palette(float width, float height, float Pspeed) : speed(Pspeed){
                shape.setSize(Vector2f(width, height));
                shape.setFillColor(Color::Blue);
                shape.setOrigin(width / 2.0f, height / 2.0f);
            }

void Palette::setPosition(float x, float y){
    shape.setPosition(x, y);
}

void Palette::moveLeft(float deltaTime){
    // Ensure paddle doesn't move beyond left window boundary
    if (shape.getPosition().x > shape.getSize().x / 2.0f)
    {
        shape.move(-speed * deltaTime, 0);
    }    
}

void Palette::moveRight(float deltaTime, float windowWidth){
    // Ensure paddle doesn't move beyond right window boundary
    if (shape.getPosition().x < windowWidth - shape.getSize().x / 2.0f)
    {
        shape.move(speed * deltaTime, 0);
    }
}

Vector2f Palette::getPosition() const{
    return shape.getPosition();
}

RectangleShape Palette::getShape() const{
    return shape;
}

void Palette::draw(RenderWindow& window){
    window.draw(shape);
}