#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Palette.hpp>
#include <Balle.hpp>
#include <Constant.hpp>
#include <string>
#include <cmath>
using namespace sf;
using namespace std;

Game::Game() :
    ecran(VideoMode(var.WIDTH, var.HEIGHT), var.TITRE, Style::Default),
    balle(var.bRayon, var.bSpeed, var.bInitialAngle),
    palette(var.pWidth, var.pHeight, var.pSpeed){

        // Frame per Second
        ecran.setFramerateLimit(60);
        
        // Déclaration des positions initiales
        balle.setPosition(ecran.getSize().x / 2.f, ecran.getSize().y / 2.f);
        palette.setPosition(ecran.getSize().x / 2.f, ecran.getSize().y -(palette.getPosition().y + 30));
    }


// Affichage des objets dans le jeu
void Game::render(){
    ecran.clear(Color(125, 125, 125));
    palette.draw(ecran);
    balle.draw(ecran);
    ecran.display();
}

void Game::gestionTouche(float& deltaTime){
    auto ecranWidth = ecran.getSize().x;

    if (Keyboard::isKeyPressed(Keyboard::Right)) palette.moveRight(deltaTime, ecranWidth);
    if (Keyboard::isKeyPressed(Keyboard::Left)) palette.moveLeft(deltaTime);
    
}

void Game::gestionCollision(float& deltaTime){
    balle.move(deltaTime);
    balle.collisionFenetre(ecran, gameOver);
    balle.collisionPalette(palette.getShape());
}

// Lancement du jeu
void Game::gameRun(){
    Clock clock;
    Event event;
    
    while (ecran.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        while (ecran.pollEvent(event))
        {
            if (event.type == Event::Closed) ecran.close();
        }
        

        render();
        gestionTouche(deltaTime);
        gestionCollision(deltaTime);
        gameStop();
    }
    
}

// Déclaration de l'arrêt du jeu
void Game::gameStop(){
    if (gameOver){
        ecran.close();
    }
}