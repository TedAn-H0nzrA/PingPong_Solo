#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow ecran(VideoMode(800,600), "Ping Pond Solo\n", Style::Default);
    ecran.setFramerateLimit(60);
    
    
    // Palette
    RectangleShape palette(Vector2f(100, 20));
    palette.setPosition(Vector2f(350, 550));
    palette.setFillColor(Color::Blue);
    float paletteMove = 15; // Déplacement du palette à chaque appel
    
    // Ballon
    float rayon = 12;
    CircleShape balle(rayon);
    balle.setPosition(394, 306);
    balle.setFillColor(Color::Red);
    Vector2f balleMove (4.f, 4.f);
    
    
    
    Event event;
    // Boucle principale du jeu
    while (ecran.isOpen())
    {
        
        // Gestion des événements
        while (ecran.pollEvent(event))
        {
            if (event.type == Event::Closed) ecran.close();
        }
        
        
        // Gestion des touches de commandes & Détection collision avec la fenêtre
        Vector2u ecranTaille = ecran.getSize();
        Vector2f posPalette = palette.getPosition();
        float posX = posPalette.x + palette.getSize().x;
        if (Keyboard::isKeyPressed(Keyboard::Right) && posX < ecranTaille.x)
        {
            palette.move(paletteMove, 0);
        }else if (Keyboard::isKeyPressed(Keyboard::Left) && posPalette.x > 0)
        {
            palette.move(-paletteMove, 0);
        }
        
        // Déplacement de la balle
        balle.move(balleMove);

        // Détection collision avec la fenêtre
        Vector2f posBalle ((balle.getPosition().x + rayon),( balle.getPosition().y + rayon));
        if (posBalle.x > 0 || posBalle.x < ecranTaille.x)
        {
            
        }
        

        // Détection collision entre les deux objets
        if (balle.getGlobalBounds().intersects(palette.getGlobalBounds()))
        {
            balleMove.y = -balleMove.y;
        }
        

        ecran.clear();
        ecran.draw(palette);
        ecran.draw(balle);
        ecran.display();
        
    }
    
    return 0;
}
