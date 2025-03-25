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

    public:
        // Contructeur
        Game();

        // Méthodes
        void render();
        void gestionTouche(float& deltatime);
        void gameRun();
        void gameStop();
};
