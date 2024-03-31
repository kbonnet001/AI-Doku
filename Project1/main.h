// Includes
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grille.h"


//// Constantes du programme
const int WIN_WIDTH = 360;
const int WIN_HEIGHT = 800;

// Namespaces
using namespace sf;
using namespace std;

//// Prototypes
//Grille grilleJeu;


// Variables
RenderWindow window;
Event event;
RectangleShape square;
Vector2f mousePosition;
Texture num1;
Sprite sprite;