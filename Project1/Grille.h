#ifndef GRILLE_H
#define GRILLE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Include des objets de l'interface
#include "boutonClose.h"
#include "BoutonEcrire.h"
#include "Case.h"
#include "Sudoku.h"
#include "IA.h"

using namespace sf;
using namespace std;

class Grille
{
public:
    Grille();
    void drawStatique(RenderWindow& window);
    void drawBoutons(RenderWindow& window);
    void drawBoutonClose(RenderWindow& window);
    void drawGrilleJeu(RenderWindow& window);
    BoutonEcrire avoirBoutonEcrire(int i);
    void drawCase(RenderWindow& window);
    void ActionGrille(RenderWindow& window,const::Vector2f& mousePosition);
    void ActionGrilleIA(RenderWindow& window, const::Vector2f& mousePosition);

private:
    
    // Carre gris contour noir - On range dans un tableau 3x3
    RectangleShape carresJeu[3][3];
    Color couleurTurquoise = Color(13,120,113);
    Color couleurTurquoiseClair = Color(188, 255, 253);
    Color couleurGris = Color(217, 217, 217);
    Color couleurRouge = Color(188, 32, 32);
    const Vector2f& dimensionCadreJeu = Vector2f(105.f, 105.f);

    // Boutons Ecrire - On range dans un tableau 9
    BoutonEcrire nums[9];

    //Case (81) - On va les rangers dans un tableau de 9x9
    Case cases[9][9];
    int caseClique[2]={ -1,-1 }; // coordonnée de la case de la grille cliqué, si il n'y en a pas -1,-1

    //Bouton Close
    BoutonClose boutonQuitter;

    int valeurClique = 0; // Valeur mémoire du clique

    Sudoku sudoku=Sudoku(3);
    IA Aidoku = IA(sudoku);


};

#endif // GRILLE
#pragma once
