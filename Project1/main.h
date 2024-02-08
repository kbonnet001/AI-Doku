// Includes
#include <iostream>
#include <SFML/Graphics.hpp>
#include "case.h"
#include "bouton.h"
#include "boutonClose.h"
#include "Grille.h"
#include "BoutonEcrire.h"

//// Constantes du programme
//const int WIN_WIDTH = 800;s
//const int WIN_HEIGHT = 600;

// Namespaces
using namespace sf;
using namespace std;

//// Prototypes
void ButtonClose(RectangleShape& bouton);
int DonneValeurBouton(Texture sprite);
Grille grilleJeu;
BoutonEcrire essaiBouton(int i, const Vector2f position);
//void LoadFront();
//void SetText(Text& txt, String str);


// Variables
RenderWindow window;
Event event;
RectangleShape square;
Vector2f mousePosition;
Texture num1;
Sprite sprite;