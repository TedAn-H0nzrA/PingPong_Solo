#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Palette{
    private:
        RectangleShape shape;
        float speed;

    public:
        Palette(float width, float height, float Pspeed);

        // Méthode
        void setPosition(float x, float y);
        void moveLeft(float deltaTime);
        void moveRight(float deltaTime, float windowWidth);
        Vector2f getPosition() const ;
        RectangleShape getShape() const;
        void draw(RenderWindow& window);
};