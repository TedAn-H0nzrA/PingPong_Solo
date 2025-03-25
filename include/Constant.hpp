#pragma once

#include <string>
#include <cmath>
using namespace std;

class Constant{
    public:
        // Constant variable pour écran
        const string TITRE = "Ping Pong";
        const int FPS = 60;
        const int WIDTH = 800, HEIGHT = 600;

        // Constante variable pour balle
        const float bRayon = 15;
        const float bSpeed = 250;
        float bInitialAngle = M_PI;

        // Constante variable pour palette
        const float pWidth = 100;
        const float pHeight = 20;
        const float pSpeed = 500;
};