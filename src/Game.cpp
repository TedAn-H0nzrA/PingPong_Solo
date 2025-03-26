#include <iostream>
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

        gameOver = false;

        // Frame per Second
        ecran.setFramerateLimit(60);
        
        // Déclaration des positions initiales
        balle.setPosition(ecran.getSize().x / 2.f, ecran.getSize().y / 2.f);
        palette.setPosition(ecran.getSize().x / 2.f, ecran.getSize().y -(palette.getPosition().y + 30));

        // Chargement de l'image
        if(!backgroundTexture.loadFromFile(IMAGES_DIR + var.backgound)){
            cerr << "Impossible de charger l'image de font!" << endl;
        } 

        // Chargement font
        if (!font.loadFromFile(FONTS_DIR + var.gFont)) {
            cerr << "Impossible de charger la police !\n";
        }
        
    }


// Chargement et manipulation du backgroung image
Sprite Game::background(){    
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    
    // Modélisation de l'image pour l'adaptation à l'écran
    Vector2u textureSize = backgroundTexture.getSize();
    // Calcul du scale pour adapter à la fenêtre
    float scaleX = static_cast<float>(ecran.getSize().x) / textureSize.x;
    float scaleY = static_cast<float>(ecran.getSize().y) / textureSize.y;
    
    backgroundSprite.setScale(scaleX, scaleY);
    
    return backgroundSprite;
}

// Affichage des objets dans le jeu
void Game::render(){
    ecran.clear(Color(125, 125, 125));
    auto backgroundSprite = background();
    ecran.draw(backgroundSprite);
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
        

        gameStop();
        render();
        gestionTouche(deltaTime);
        gestionCollision(deltaTime);
    }
    
}

void Game::messageGameOver(){
    Text gameOverText;
    
    // Configuration texte 
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(Color(128, 0, 128));
    gameOverText.setString(var.gTextOver);
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, gameOverText.getLocalBounds().height / 2);
    gameOverText.setPosition(ecran.getSize().x / 2, ecran.getSize().y / 2);

    ecran.draw(gameOverText);
    ecran.display();

    sleep(seconds(3));
       
}

// Déclaration de l'arrêt du jeu
void Game::gameStop(){
    if (gameOver){
        
        messageGameOver();
    }
}