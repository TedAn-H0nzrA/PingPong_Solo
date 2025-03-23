#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow ecran(VideoMode(800,600), "Ping Pond Solo\n", Style::Default);


    // Palette
    RectangleShape palette(Vector2f(100, 20));
    palette.setPosition(Vector2f(350, 550));
    palette.setFillColor(Color::Blue);
    float dx = 5; // Déplacement du palette à chaque appel

    // Ballon
    float rayon = 12;
    CircleShape balle(rayon);
    balle.setPosition(394, 306);
    balle.setFillColor(Color::Red);
    
    
    Event event;
    // Boucle principale du jeu
    while (ecran.isOpen())
    {
        // Gestion des événements
        while (ecran.pollEvent(event))
        {
            if (event.type == Event::Closed) ecran.close();

            // Gestion des touches de commandes
            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Right){
                    palette.move(dx, 0);
                }

                if (event.key.code == Keyboard::Left){
                    palette.move(-dx, 0);
                }
            }
            
        }


        ecran.clear();
        ecran.draw(palette);
        ecran.draw(balle);
        ecran.display();
        
    }
    
    return 0;
}
