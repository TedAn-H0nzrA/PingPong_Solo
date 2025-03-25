#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Balle{
    private:
        CircleShape shape;
        float rayon;
        float speed;
        float angle; // en radian
        Vector2f velocity;

    public:
        Balle(float rayon, float speed, float angle);

        // Méthodes
        void updateVelocity();
        void setPosition(float x, float y);
        void move(float deltaTime);
        void movementHorizontal();
        void movementVerticale();
        void collisionPalette(const RectangleShape& palette);
        Vector2f getPosition() const;
        float getRayon() const;
        FloatRect getGlobalBounds() const;
        void draw(RenderWindow& window);

};