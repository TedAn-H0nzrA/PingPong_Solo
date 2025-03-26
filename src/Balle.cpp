#include <SFML/Graphics.hpp>
#include <Balle.hpp>
#include <cmath>
using namespace std;
using namespace sf;


// Constructeur
Balle::Balle(float rayon, float speed, float angle) : rayon(rayon), speed(speed), angle(angle){
            shape.setRadius(rayon);
            shape.setFillColor(Color::Red);
            shape.setOrigin(rayon, rayon);

            updateVelocity();
}

// Mise à jour de la vitesse
void Balle::updateVelocity(){
    velocity.x = speed * cos(angle);
    velocity.y = speed * sin(angle);
}

// Assignation du position
void Balle::setPosition(float x, float y){
    shape.setPosition(x, y);
}

// Mouvement de la balle en temps réel
void Balle::move(float deltaTime){
    shape.move(velocity * deltaTime);
}

// Mouvement horizontale
void Balle::mouvementHorizontal(){
    angle = M_PI - angle;

    if (angle < 0) angle += (2 * M_PI);
    if (angle > 2 * M_PI) angle -= (2 * M_PI);
    updateVelocity();    
}

// Mouvement verticale
void Balle::mouvementVerticale(){
    angle = (2*M_PI) - angle;

    if (angle < 0) angle += (2 * M_PI);
    if (angle > 2 * M_PI) angle -= (2 * M_PI);
    updateVelocity();
}

void Balle::collisionFenetre(RenderWindow& window, bool& gameStop){
    auto windowWidth = window.getSize().x;
    auto windowHeight = window.getSize().y;
    auto ballePosition = shape.getPosition();
    auto balleRadius = shape.getRadius();

    // Collision selon l'axe x
    if (ballePosition.x - balleRadius <=0 || ballePosition.x + balleRadius >= windowWidth){
        mouvementHorizontal();
    }

    // Collision avec le bord superieur
    if (ballePosition.y - balleRadius <= 0){
        mouvementVerticale();
    }

    if (ballePosition.y + balleRadius >= windowHeight){
        gameStop = true;
    }
    
}

// Détéction collision de la balle avec la palette
void Balle::collisionPalette(const RectangleShape& palette){
    FloatRect dimensionPalette = palette.getGlobalBounds();
    FloatRect dimensionBalle = shape.getGlobalBounds();

    if (dimensionBalle.intersects(dimensionPalette)){
        // Ajustement de l'angle pour la dynamique du jeu
        float centrePalette = dimensionPalette.left + dimensionPalette.width / 2;
        float centreBalle = dimensionBalle.left + dimensionBalle.width / 2;

        float decalage = centreBalle - centrePalette;
        float maxAngle = M_PI / 3; // Limite d'angle pour éviter des rebonds trop verticaux
        float ratio = decalage / (dimensionPalette.width / 2);
        angle = (M_PI / 2) + ratio * maxAngle;


        updateVelocity();
        
        mouvementVerticale();

    }
}

// Getters
// Position
Vector2f Balle::getPosition() const {
    return shape.getPosition();
}

// Rayon
float Balle::getRadius() const {
    return shape.getRadius();
}

// Boîte englobante dans la repére globale de la balle
FloatRect Balle::getGlobalBounds() const{
    return shape.getGlobalBounds();
}

// Dissigne le ballon sur l'écran
void Balle::draw(RenderWindow& window){
    window.draw(shape);
}
