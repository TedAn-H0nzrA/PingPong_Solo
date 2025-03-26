#include <SFML/Graphics.hpp>
#include <Palette.hpp>
#include <Balle.hpp>
#include <Constant.hpp>
#include <string>
using namespace sf;
using namespace std;

class Game{
    private:
        Constant var;
        RenderWindow ecran;
        Balle balle;
        Palette palette;
        bool gameOver;
        Texture backgroundTexture;
        Font font;

    public:
        // Contructeur
        Game();

        // Méthodes
        Sprite background();
        void render();
        void gestionTouche(float& deltatime);
        void gestionCollision(float& deltaTime);
        void gameRun();
        void messageGameOver();
        void gameStop();
};
