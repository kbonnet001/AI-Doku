#ifndef GRILLE_H
#define GRILLE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "boutonClose.h"
#include "BoutonEcrire.h"

using namespace sf;
using namespace std;

class Grille
{
public:
    Grille();
    void drawStatique(RenderWindow& window);
    void drawBoutons(RenderWindow& window);
    void drawGrilleJeu(RenderWindow& window);
    BoutonEcrire avoirBoutonEcrire(int i);
    //BoutonEcrire BoutonEcrire(int chiffre, const Vector2f position);

private:
    RectangleShape carre1;
    RectangleShape carre2;
    RectangleShape carre3;
    RectangleShape carre4;
    RectangleShape carre5;
    RectangleShape carre6;
    RectangleShape carre7;
    RectangleShape carre8;
    RectangleShape carre9;
    vector<RectangleShape> carresJeu = {carre1,carre2,carre3, carre4,carre5,carre6,carre7,carre8,carre9}; // contient les 9 carrés de la grille de jeu
    RectangleShape cadreBoutonChiffre;
    Text texte;
    Font font;
    const Vector2f& positionCadreChiffre= Vector2f(17.f, 581.f);
    const Vector2f& dimensionCadreChiffre= Vector2f(330.f, 40.f);
    // Pour la grille de jeu, on a besoin de 9 carrés, ils ont tous la même couleur et la meme taille
    Color couleurGris = Color(217, 217, 217);
    Color noir = Color(0, 0, 0);
    const Vector2f& dimensionCadreJeu=Vector2f(106.f, 106.f);
    // Seule la position change
    
    // Boutons Ecrire

    BoutonEcrire num1 = BoutonEcrire(1, Vector2f(18.31f + 0 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num2 = BoutonEcrire(2, Vector2f(18.31f + 1 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num3 = BoutonEcrire(3, Vector2f(18.31f + 2 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num4 = BoutonEcrire(4, Vector2f(18.31f + 3 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num5 = BoutonEcrire(5, Vector2f(18.31f + 4 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num6 = BoutonEcrire(6, Vector2f(18.31f + 5 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num7 = BoutonEcrire(7, Vector2f(18.31f + 6 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num8 = BoutonEcrire(8, Vector2f(18.31f + 7 * (33.93 + 2.48), 584.3f));
    BoutonEcrire num9 = BoutonEcrire(9, Vector2f(18.31f + 8 * (33.93 + 2.48), 584.3f));
    vector<BoutonEcrire> nums={ num1, num2, num3, num4, num5, num6, num7, num8, num9 };
};

#endif // GRILLE
#pragma once
