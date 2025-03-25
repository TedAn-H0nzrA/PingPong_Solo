#include <iostream>
#include <SFML/Graphics.hpp>
#include <Game.hpp>
using namespace sf;
using namespace std;

int main(int argc, char const *argv[])
{
    Game game;
    try{
        game.gameRun();
    }
    catch(const std::exception& e){
        cerr << e.what() << '\n';
    }
    
    return 0;
}
