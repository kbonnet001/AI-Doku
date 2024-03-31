#ifndef GRILLE_H
#define GRILLE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Include des objets de l'interface
#include "Bouton.h"
#include "boutonClose.h"
#include "BoutonEcrire.h"
#include "Case.h"
#include "Sudoku.h"
#include "IA.h"
#include "IaApparence.h"
#include "BoutonEffacer.h"
#include "BoutonValider.h"
#include "BoutonNavigation.h"

//#include "IaApparence.h"
//#include "GestionDialogue.h"

using namespace sf;
using namespace std;

class Grille
{
public:
    Grille();
    // --------------------------------------- DESSINER L'INTERFACE ---------------------------------------
    void drawStatique(RenderWindow& window);
    void drawBoutons(RenderWindow& window);
    void drawBoutonClose(RenderWindow& window);
    void drawGrilleJeu(RenderWindow& window);
    void drawBoutonNav(RenderWindow& window);
    void drawCase(RenderWindow& window);
    void drawBoutonEffacer(RenderWindow& window);
    void drawBoutonValider(RenderWindow& window);
    BoutonEcrire avoirBoutonEcrire(int i);
    
    void actionGrille(RenderWindow& window,const::Vector2f& mousePosition);
    void actionGrilleIA(RenderWindow& window, const::Vector2f& mousePosition);
    void actionGrilleManuelInitial(RenderWindow& window, const::Vector2f& mousePosition);
    void actionGrilleManuel(RenderWindow& window, const::Vector2f& mousePosition);
    bool reponseAutorise(int a, int b, string reponseUtilisateur);

    //void drawNotes(RenderWindow& window, Sudoku sudoku, int i, int j);

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

    // Bouton Effacer
    BoutonEffacer boutonEffacer;

    // Bouton Valider
    BoutonValider boutonValider;

    // Bouton Nav
    BoutonNavigation boutonSuivant;
    BoutonNavigation boutonPrecedent;

    //Bouton Close
    BoutonClose boutonQuitter;

    // Boutons d'action
    bool effacerClique = false; // true si l'utilisateur a cliqué sur le bouton effacer
    bool noteClique = false; // true si l'utilisateur a cliqué sur le bouton pour prendre des notes

    int valeurClique = 0; // Valeur mémoire du clique
    


    // Paramètres de la grille
    //------------------------
    bool modeIA=false; // Faux par défaut, true si ia, false sinon --> dans ce cas, on affiche pas l'IA
    bool resolutionRapide=false; // false si étape par étape, true l'IA résoud la grille d'un coup
    int niveauGrille=0; // niv de la grille, si 0 grille a rentrer manuellement par l'utilisateur !




    Sudoku sudoku = Sudoku(niveauGrille); // par défaut, mode manuel donc vide
    IA Aidoku = IA(sudoku);
    IaApparence iaDesign = IaApparence();
};

#endif // GRILLE
#pragma once
